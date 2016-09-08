/*****************************************************************************
 *
 * This example demonstrates how to transfer the function to the function
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

//Sorting Functions
void lessMySort (int &x, int &y)
{
	int temp = 0;
	if (x > y)
	{
		temp = x;
		x = y;
		y = temp;
	}
}

void greaterMySort (int &x, int &y)
{
	int temp = 0;
	if (x < y)
	{
		temp = x;
		x = y;
		y = temp;
	}
}

//Run sorting
void sort (int *arr, int n, void (*f)(int&, int&))
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			f(arr[i], arr[j]);
		}
	}
}

int main()
{
	//Declare and initialize references to functions
	void (*lessPtr) (int&, int&) = &lessMySort;
	void (*greaterPtr) (int&, int&) = &greaterMySort;

	int arr[5] = {10, 32, 15, 93, 42};

	//Sorting less
	sort (arr, 5, lessPtr);
	//Viev
	for (int i = 0; i < 5; i++)
		cout << arr[i] << endl;

	cout << "   ---   " << endl;

	//Sorting greater
	sort (arr, 5, greaterPtr);
	//Viev
	for (int i = 0; i < 5; i++)
		cout << arr[i] << endl;
}