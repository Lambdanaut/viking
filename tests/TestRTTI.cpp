#include <vector>
#include <iostream>
#include <cassert>
#include <map>

#include "viking/HashedString.hpp"

namespace vik
{

// interface to the RTTI (RunTime Type Information) of a class
// Not to be created directly, use the macro below.
class Class
{
public:
	Class(const char* className, const std::vector<const Class*>& parents):
	className(className),
  	parents(parents)
	{
	}

	const char* getName() const
	{
		return className;
	}

	bool instanceOf(const Class& r) const
	{
		if ( this == &r )
		{
			return true;
		}

		for ( unsigned i = 0; i < parents.size(); ++i )
		{
			if ( parents[i]->instanceOf( r ) )
			{
				return true;
			}
		}

		return false;
	}
private:
	const char* className;
	const std::vector<const Class*> parents;
};

// global static table for the RTTI system
class Reflection
{
public:
	~Reflection()
	{
		const std::map<HashedString, Class*>::const_iterator end = classTable.end();
		for (std::map<HashedString, Class*>::iterator it = classTable.begin(); it != end; ++it)
		{
			delete (*it).second;
		}
	}

	// add new class definition and return it
	// if class already exists, will return the already existing instance of it.
	template<class Derived, class... Parents>
	static const Class* addClass(const char* className)
	{
		if (const Class* found = findClass(className))
		{
			return found;
		}

		Class* newClass = new Class(className, { &Parents::getClass()... });
		getSingleton().classTable[HashedString(className)] = newClass;

		return newClass;
	}

	// lookup class definition from hashed name
	static const Class* findClass(const HashedString& hash)
	{
		std::map<HashedString, Class*>::const_iterator it = getSingleton().classTable.find(hash);

		if (it == getSingleton().classTable.end())
		{
			return 0;
		}

		return getSingleton().classTable[hash];
	}

	// lookup class definition from name
	static const Class* findClass(const char* className)
	{
		return findClass(HashedString(className));
	}

	// for debugging the RTTI system
	static void debugPrint()
	{
		std::cout << "address : class name" << std::endl;

		const std::map<HashedString, Class*>::const_iterator end = getSingleton().classTable.end();
		for (std::map<HashedString, Class*>::iterator it = getSingleton().classTable.begin(); it != end; ++it)
		{
			std::cout << (*it).second << " : " << std::flush;
			std::cout << (*it).second->getName() << std::endl;
		}
	}
private:
	static Reflection& getSingleton()
	{
		static Reflection refl;
		return refl;
	}

	Reflection() = default;

	// mapping of hashed strings of class names to their RTTI objects
	std::map<HashedString, Class*> classTable;
};

// Declares necessary members for RTTI. To be used within the class declaration.
// Watch out: ClassInfo(SomeClass::Nested) creates a different definition than ClassInfo(Nested) but both are accepted.
#define ClassInfo(ThisClass, Parents...) \
	virtual const Class& getInstanceClass() const \
	{ \
		return ThisClass::getClass(); \
	} \
	static const Class& getClass() \
	{ \
		static const Class& r = *Reflection::addClass<ThisClass,##Parents>(#ThisClass); \
		return r; \
	} 

} // end namespace vik

using namespace vik;

// Unit tests
class UnitTest
{
	class StaffMember
	{
	public:
		ClassInfo(StaffMember);
	};

	class Librarian : virtual public StaffMember
	{
	public:
		ClassInfo(Librarian,StaffMember);
	};

	class Teacher : virtual public StaffMember
	{
	public:
		ClassInfo(Teacher,StaffMember);
	};

	class TeachingLibrarian : public Teacher, public Librarian
	{
	public:
		ClassInfo(TeachingLibrarian,Teacher,Librarian);
	};

	class Sailboat
	{
	public:
		ClassInfo(Sailboat);
	};

	void classlessRTTITest()
	{
		const Class vehicleType("Vehicle", {});
		const Class landVehicleType("LandVehicle", { &vehicleType });
		const Class waterVehicleType("WaterVehicle", { &vehicleType });
		const Class amphibiousVehicleType("AmphibiousVehicle", { &landVehicleType, &waterVehicleType });
		const Class fruitType("Fruit", {});

		// class name
		assert(std::string(vehicleType.getName()) == "Vehicle");

		// single inheritance valid upcast
		assert(landVehicleType.instanceOf(vehicleType));

		// single inheritance invalid upcast
		assert(landVehicleType.instanceOf(fruitType) == false);

		// single inheritance invalid cross-cast
		assert(landVehicleType.instanceOf(waterVehicleType) == false);

		// multiple inheritance 1 level valid upcast
		assert(amphibiousVehicleType.instanceOf(landVehicleType));

		// multiple inheritance 2 level valid upcast
		assert(amphibiousVehicleType.instanceOf(vehicleType));

		// multiple inheritance 1 level invalid upcast
		assert(amphibiousVehicleType.instanceOf(fruitType) == false);

		std::cout << "Classless tests successful" << std::endl;
	}

	void classfulRTTITest()
	{
		StaffMember* staff = new StaffMember();
		StaffMember* librarian = new Librarian();
		StaffMember* teacher = new Teacher();
		StaffMember* teachingLibrarian = new TeachingLibrarian();
		Sailboat* sailboat = new Sailboat();

		// bogus line to make the compiler not give warnings about unused variables in release builds
		(void)staff, (void)librarian, (void)teacher, (void)teachingLibrarian, (void)sailboat;

		// class name
		assert(std::string(staff->getInstanceClass().getName()) == "StaffMember");

		// single inheritance valid upcast
		assert(librarian->getInstanceClass().instanceOf(staff->getInstanceClass()));

		// single inheritance valid upcast through static member
		assert(librarian->getInstanceClass().instanceOf(StaffMember::getClass()));

		// single inheritance invalid upcast
		assert(librarian->getInstanceClass().instanceOf(sailboat->getInstanceClass()) == false);

		// single inheritance invalid cross-cast
		assert(librarian->getInstanceClass().instanceOf(teacher->getInstanceClass()) == false);

		// multiple inheritance 1 level valid upcast
		assert(teachingLibrarian->getInstanceClass().instanceOf(librarian->getInstanceClass()));

		// multiple inheritance 2 level valid upcast
		assert(teachingLibrarian->getInstanceClass().instanceOf(staff->getInstanceClass()));

		// multiple inheritance 1 level invalid upcast
		assert(teachingLibrarian->getInstanceClass().instanceOf(sailboat->getInstanceClass()) == false);

		delete staff;
		delete librarian;
		delete teacher;
		delete teachingLibrarian;
		delete sailboat;

		std::cout << "Classful tests successful" << std::endl;
	}

	// must be called AFTER the classful test to be valid
	void reflectionTest()
	{
		// getting existing class by name
		assert(Reflection::findClass("Sailboat") == &Sailboat::getClass());

		// getting nonexistant class by name
		assert(Reflection::findClass("ASFJasdf") == 0);

		// getting existing class by hashed name
		assert(Reflection::findClass(HashedString("Sailboat")) == &Sailboat::getClass());

		// getting nonexistant class by hashed name
		assert(Reflection::findClass(HashedString("ASFJasdf")) == 0);

		// print all classes for sanity check
		std::cout << "reflection debug information:" << std::endl;
		Reflection::debugPrint();

		std::cout << "Reflection tests successful" << std::endl;
	}

public:
	void testAll()
	{
		classlessRTTITest();
		classfulRTTITest();
		reflectionTest();
	}
};

int main()
{
	UnitTest test;
	test.testAll();
	std::cout << "All tests successful" << std::endl;
}

