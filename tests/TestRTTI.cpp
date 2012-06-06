#include <vector>
#include <iostream>
#include <cassert>

// interface to the RTTI (RunTime Type Information) of a class
// Not to be created directly, use the RTTI_DECLARE/DEFINE macros below.
class RTTI
{
public:
	RTTI( const char* className, const std::vector<const RTTI*>& parents ):
	className( className ),
  	parents( parents )
	{
	}

	const char* getName() const
	{
		return className;
	}

	bool derivesFrom( const RTTI& r ) const
	{

		if ( this == &r )
		{
			return true;
		}

		for ( int i = static_cast<int>(parents.size()) - 1; i >= 0; --i )
		{
			if ( parents[i]->derivesFrom( r ) )
			{
				return true;
			}
		}

		return false;
	}

private:
	const char* className;
	const std::vector<const RTTI*> parents;
};

// generates parameters for the RTTI constructor by expanding a variadic template into an array
template<class Derived, class ... Parents>
class RTTIInfo : public RTTI
{
public:
	RTTIInfo( const char* className ):
	RTTI( className, { &Parents::getClass()... } ) 
	{
	}
};

// declares necessary members for RTTI. To be used within the class declaration.
#define ClassInfo(ThisClass, Parents...) \
	virtual const RTTI& getInstanceClass() const \
	{ \
		return ThisClass::getClass(); \
	} \
	static const RTTI& getClass() \
	{ \
		static const RTTI typeInfo = RTTIInfo<ThisClass, ##Parents>(#ThisClass); \
		return typeInfo; \
	} 

// Unit tests

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
	assert(librarian->getInstanceClass().derivesFrom(staff->getInstanceClass()));

	// single inheritance valid upcast through static member
	assert(librarian->getInstanceClass().derivesFrom(StaffMember::getClass()));

	// single inheritance invalid upcast
	assert(librarian->getInstanceClass().derivesFrom(sailboat->getInstanceClass()) == false);

	// single inheritance invalid cross-cast
	assert(librarian->getInstanceClass().derivesFrom(teacher->getInstanceClass()) == false);

	// multiple inheritance 1 level valid upcast
	assert(teachingLibrarian->getInstanceClass().derivesFrom(librarian->getInstanceClass()));

	// multiple inheritance 2 level valid upcast
	assert(teachingLibrarian->getInstanceClass().derivesFrom(staff->getInstanceClass()));

	// multiple inheritance 1 level invalid upcast
	assert(teachingLibrarian->getInstanceClass().derivesFrom(sailboat->getInstanceClass()) == false);

	delete staff;
	delete librarian;
	delete teacher;
	delete teachingLibrarian;
	delete sailboat;

	std::cout << "Classful tests successful" << std::endl;
}

void classlessRTTITest()
{
	const RTTI vehicleType("Vehicle", {});
	const RTTI landVehicleType("LandVehicle", { &vehicleType });
	const RTTI waterVehicleType("WaterVehicle", { &vehicleType });
	const RTTI amphibiousVehicleType("AmphibiousVehicle", { &landVehicleType, &waterVehicleType });
	const RTTI fruitType("Fruit", {});

	// class name
	assert(std::string(vehicleType.getName()) == "Vehicle");

	// single inheritance valid upcast
	assert(landVehicleType.derivesFrom(vehicleType));

	// single inheritance invalid upcast
	assert(landVehicleType.derivesFrom(fruitType) == false);

	// single inheritance invalid cross-cast
	assert(landVehicleType.derivesFrom(waterVehicleType) == false);

	// multiple inheritance 1 level valid upcast
	assert(amphibiousVehicleType.derivesFrom(landVehicleType));

	// multiple inheritance 2 level valid upcast
	assert(amphibiousVehicleType.derivesFrom(vehicleType));

	// multiple inheritance 1 level invalid upcast
	assert(amphibiousVehicleType.derivesFrom(fruitType) == false);

	std::cout << "Classless tests successful" << std::endl;
}

int main()
{
	classlessRTTITest();
	classfulRTTITest();

	std::cout << "All tests successful" << std::endl;
}

