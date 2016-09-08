/*****************************************************************************
 *
 * This example demonstrates the difference between the program time
 *
 * Sorting objects:
 *
 * 10 000 = 1082
 * 30 000 = 10300
 * 100 000 = 164260
 *
 * Sorting pointers:
 *
 * 10 000 = 574
 * 30 000 = 5070
 * 100 000 = 119731
 *
 * Code&Robots site:       http://codrob.ru/
 * YouTube Channel:        https://www.youtube.com/channel/UCTGS5FRyz564wwiyNs8J54A
 * Social networks:        https://vk.com/codrob
 *                         https://www.facebook.com/groups/295824740787675/
 *
 * This example code is in public domain and licensed under MIT license
*****************************************************************************/

#include <iostream>
#include <ctime>

using namespace std;

class Person {
public:
	int data;
	int data2;

	Person()
	{
		data = 0;
		data2 = 0;
	}
};

inline void sortPointer (Person *p1, Person *p2)
{
	Person *temp = p1;
	*p1 = *p2;
	*p2 = *temp;
}

inline void sortObject (Person *p1, Person *p2)
{
	Person *temp = p1;
	p1 = p2;
	p2 = temp;
}

void sort(Person **person, int n, void (*f)(Person*, Person*))
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (person[i]->data > person[j]->data)
			{
				f(person[i], person[j]);
			}
		}
	}
}

int main()
{
	void (*sortPointerPtr) (Person*, Person*) = &sortPointer;
	void (*sortObjectPtr) (Person*, Person*) = &sortObject;

	const int n = 30000;

	//Array pointers of objects
	Person *person[n];

	//Creating objects and add pointers in array
	for (int i = 0; i < n; i++)
	{
		person[i] = new Person();
		person[i]->data = i;
		person[i]->data2 = i;
	}

	cout << "Run sort. Last element: " << person[n - 1]->data << " | " << person[n - 1]->data2 << endl;

	sort(person, n, sortPointerPtr);
	//sort(person, n, sortObjectPtr);

	cout << "End sort. Last element: " << person[n - 1]->data << " | " << person[n - 1]->data2 << endl;

	cout << clock() << endl;

	system("pause");
	return 0;
}