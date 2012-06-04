#include <vector>
#include <iostream>
#include <cassert>

namespace vik
{

// TODO: Try instead of declaring a TypeInfo variable declaring a static function that returns a local static variable.
class RTTI
{
public:
	RTTI(const char* className, const std::vector<const RTTI*>& parents):
	thisClassName(className),
	parentRTTI(parents)
	{
	}
	
	const char* getClassName() const
	{
		return thisClassName;
	}

	bool derivesFrom(const RTTI& r) const
	{
		if (this == &r)
		{
			return true;
		}
		for (int i = static_cast<int>(parentRTTI.size()) - 1; i >= 0; --i)
		{
			if ( parentRTTI[i]->derivesFrom(r) )
			{
				return true;
			}
		}
		return false;
	}
private:
	const char* thisClassName;
	const std::vector<const RTTI*> parentRTTI;
};

// declares typeinfo member variables/functions to be used within a class declaration
#define RTTI_DECLARE() \
	public: static const RTTI typeInfo; \
	public:  virtual const RTTI& getTypeInfo() const { return typeInfo; }

// defines static typeinfo variables, to be used in a source file and to match an RTTI_DECLARE within a class declaration elsewhere.

// For base classes
#define RTTI_DEFINE0(ThisClass) \
	const RTTI ThisClass::typeInfo(#ThisClass, {})

// For classes which use single inheritance
#define RTTI_DEFINE1(ThisClass, ParentClass) \
	const RTTI ThisClass::typeInfo(#ThisClass, { &ParentClass::typeInfo })

// For classes which use multiple inheritance with 2 parents
#define RTTI_DEFINE2(ThisClass, ParentClass1, ParentClass2) \
	const RTTI ThisClass::typeInfo(#ThisClass, { &ParentClass1::typeInfo, &ParentClass2::typeInfo })

// For classes which use multiple inheritance with 3 parents
#define RTTI_DEFINE3(ThisClass, ParentClass1, ParentClass2, ParentClass3) \
	const RTTI ThisClass::typeInfo(#ThisClass, { &ParentClass1::typeInfo, &ParentClass2::typeInfo , &ParentClass3::typeInfo })

// For classes which use multiple inheritance with 4 parents
#define RTTI_DEFINE4(ThisClass, ParentClass1, ParentClass2, ParentClass3, ParentClass4) \
	const RTTI ThisClass::typeInfo(#ThisClass, { &ParentClass1::typeInfo, &ParentClass2::typeInfo , &ParentClass3::typeInfo, &ParentClass4::typeInfo })

// For classes which use multiple inheritance with 5 parents
#define RTTI_DEFINE5(ThisClass, ParentClass1, ParentClass2, ParentClass3, ParentClass4, ParentClass5) \
	const RTTI ThisClass::typeInfo(#ThisClass, { &ParentClass1::typeInfo, &ParentClass2::typeInfo , &ParentClass3::typeInfo, &ParentClass4::typeInfo, &ParentClass5::typeInfo })

// TODO: Add more copy and pasted versions if ever necessary

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

RTTI_DEFINE0(StaffMember);
RTTI_DEFINE1(Librarian,StaffMember);
RTTI_DEFINE1(Teacher,StaffMember);
RTTI_DEFINE2(TeachingLibrarian,Teacher,Librarian);
RTTI_DEFINE0(Sailboat);

void classfulRTTITest()
{
	// these will leak memory but I don't care for this test
	StaffMember* staff = new StaffMember();
	StaffMember* librarian = new Librarian();
	StaffMember* teacher = new Teacher();
	StaffMember* teachingLibrarian = new TeachingLibrarian();
	Sailboat* sailboat = new Sailboat();

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

}

int main()
{
	vik::classlessRTTITest();
	vik::classfulRTTITest();

	std::cout << "All tests successful" << std::endl;
}
