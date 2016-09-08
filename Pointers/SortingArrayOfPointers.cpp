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
	int data3;
	int data4;

	Person ()
	{}

	Person(int data, int data2, int data3, int data4) : data(data), data2(data2), data3(data3), data4(data4)
	{}
};

inline void sortPointer (Person *p1, Person *p2)
{
	Person *temp = p1;
	//Элемент массива под индексом p1 теперь хранит другой адрес, из p2
	*p1 = *p2;
	*p2 = *temp;
}

inline void sortObject (Person *p1, Person *p2)
{
	//Извлекаем (разыменовываем) объект Person
	Person temp = *p1;

	//ИСПРАВИТЬ
	p1->data = p2->data;
	p1->data2 = p2->data2;
	p2->data = temp->data;
	p2->data2 = temp->data2;
}

void sort(Person **person, int n, void (*f)(Person*, Person*))
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (person[i]->data > person[j]->data)
			{
				//Передаем 2 указателя на ячейки памяти в которых хранятся объекты типа Person
				f(person[i], person[j]);
			}
		}
	}
}

int main()
{
	void (*sortPointerPtr) (Person*, Person*) = &sortPointer;
	void (*sortObjectPtr) (Person*, Person*) = &sortObject;

	const int n = 20000;

	//Array pointers of objects
	Person* person[n];

	//Creating objects and add pointers in array
	for (int i = 0; i < n; i++)
	{
		person[i] = new Person(i, i, i, i);
	}

	//Хранит адрес объекта Person
	cout << person[10] << endl;

	cout << "Run sort. Last element: " << person[n - 1]->data << " | " << person[n - 1]->data2 << endl;

	//sort(person, n, sortPointerPtr);
	sort(person, n, sortObjectPtr);

	cout << "End sort. Last element: " << person[n - 1]->data << " | " << person[n - 1]->data2 << endl;

	cout << clock() << endl;

	system("pause");
	return 0;
}
