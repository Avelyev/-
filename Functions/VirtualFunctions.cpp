/*****************************************************************************
 * This example demonstrates work of virtual methods
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/channel/UCTGS5FRyz564wwiyNs8J54A
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>

using namespace std;

class Employee
{
private:
//Creating virtual method
	virtual char* display ()
	{
		return "It's base class.";
	}
public:
	Employee ()
	{}
	void run ()
	{
		cout << "Run: " << display() << endl;
	}
};

class Designer : public Employee
{
private:
	//To display this inscription, the display method in the class Employee must be virtual
	char* display ()
	{
		return "Designer.";
	}
};

class Programmer : public Employee
{
private:
	//To display this inscription, the display method in the class Employee must be virtual
	char* display ()
	{
		return "Programmer.";
	}
};

int main()
{
	Employee empl;
	Designer des;
	Programmer prog;

	//If display does not virtual method, 3 times will be displayed: "Run: It's base class."
	empl.run();
	des.run();
	prog.run();

	//If display is virtual method, despite the fact that pointers are of type Employee, the display method will be called from the derived class
	//If display does not virtual method, even if the pointers are created by the type of object, the method will be called from class Employee
	Employee *ptrEmployee = &empl;
	Employee *ptrDesigner = &des;
	Employee *ptrProgrammer = &prog;

	ptrEmployee->run();
	ptrDesigner->run();
	ptrProgrammer->run();
}
