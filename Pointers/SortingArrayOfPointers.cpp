/*****************************************************************************
 *
 * This example demonstrates the difference between the program time
 *
 * Sorting objects:
 *
 * 20 000 = 0.66
 *
 * Sorting pointers:
 *
 * 20 000 = 0.35
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

inline void sortPointer (Person*& p1, Person*& p2)
{
    //Fast
    Person *temp = p1;
    p1 = p2;
    p2 = temp;
}

inline void sortObject (Person*& p1, Person*& p2)
{
    //Slowly
    Person temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sort(Person **person, int n, void (*f)(Person*&, Person*&))
{
    for (int i = 0; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n-i; j++)
        {
            if (person[i]->data > person[j]->data)
            {
                swapped = true;
                //Sorting through a given function
                f(person[i], person[j]);
            }
        }
    }
}

int main()
{
    void (*sortPointerPtr) (Person*&, Person*&) = &sortPointer;
    void (*sortObjectPtr) (Person*&, Person*&) = &sortObject;

    const int n = 20000;

    //Array pointers of objects
    Person* person[n];

    //Creating objects and add pointers in array
    for (int i = 0; i < n; i++)
    {
        person[i] = new Person(i, i, i, i);
    }

    cout << "Run sort. Last element: " << person[n - 1]->data << " | " << person[n - 1]->data2 << endl;

    sort(person, n, sortPointerPtr);
    //sort(person, n, sortObjectPtr);

        cout << "End sort. Last element: " << endl;

        //Printing last 50 element
        for (int i = n - 50; i < n; i++)
        {
            cout << person[i]->data << " | " << person[i]->data2 << endl;
        }

    cout << clock() << endl;

    system("pause");
    return 0;
}
