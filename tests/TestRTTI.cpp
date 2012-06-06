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

	const char* getClassName() const
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
template<typename Derived, typename... Parents>
class RTTIInfo : public RTTI
{
public:
	RTTIInfo( const char* className ):
	RTTI( className, { &Parents::typeInfo... } ) 
	{
	}
};

// declares necessary members for RTTI. To be used within the class declaration.
#define RTTI_DECLARE() \
	public: static const RTTI typeInfo; \
	public: virtual const RTTI& getTypeInfo() const { return typeInfo; }

// defines the members declared in a class declaration for RTTI. To be used in the .cpp file associated with the class declaration.
#define RTTI_DEFINE(ThisClass, Parents...) \
	const RTTI ThisClass::typeInfo = RTTIInfo<ThisClass, ##Parents>(#ThisClass);

// Unit tests

class StaffMember
{
	RTTI_DECLARE();
};

class Librarian : virtual public StaffMember
{
	RTTI_DECLARE();
};

class Teacher : virtual public StaffMember
{
	RTTI_DECLARE();
};

class TeachingLibrarian : public Teacher, public Librarian
{
	RTTI_DECLARE();
};

class Sailboat
{
	RTTI_DECLARE();
};

RTTI_DEFINE(StaffMember);
RTTI_DEFINE(Librarian,StaffMember);
RTTI_DEFINE(Teacher,StaffMember);
RTTI_DEFINE(TeachingLibrarian,Teacher,Librarian);
RTTI_DEFINE(Sailboat);

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
	assert(std::string(staff->getTypeInfo().getClassName()) == "StaffMember");

	// single inheritance valid upcast
	assert(librarian->getTypeInfo().derivesFrom(staff->getTypeInfo()));

	// single inheritance valid upcast through static member
	assert(librarian->getTypeInfo().derivesFrom(StaffMember::typeInfo));

	// single inheritance invalid upcast
	assert(librarian->getTypeInfo().derivesFrom(sailboat->getTypeInfo()) == false);

	// single inheritance invalid cross-cast
	assert(librarian->getTypeInfo().derivesFrom(teacher->getTypeInfo()) == false);

	// multiple inheritance 1 level valid upcast
	assert(teachingLibrarian->getTypeInfo().derivesFrom(librarian->getTypeInfo()));

	// multiple inheritance 2 level valid upcast
	assert(teachingLibrarian->getTypeInfo().derivesFrom(staff->getTypeInfo()));

	// multiple inheritance 1 level invalid upcast
	assert(teachingLibrarian->getTypeInfo().derivesFrom(sailboat->getTypeInfo()) == false);

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
	assert(std::string(vehicleType.getClassName()) == "Vehicle");

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

