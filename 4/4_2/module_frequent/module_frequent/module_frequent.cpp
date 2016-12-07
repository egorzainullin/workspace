// module_frequent.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <ctime>
#include "mostfrequent.h"

using namespace std;

void testFrequent()
{
	int a[5] = { 0, 1, 1, 2, 4 };
	int b[10] = { 0, 2 , 2, 3, 3, 4, 4, 4, 4, 5 };
	searchForFrequent(a, 5) == 1 ? cout << "Ok" : cout << "error";
	cout << endl;
	searchForFrequent(b, 10) == 4 ? cout << "Ok" : cout << "error";
	cout << endl;
}

bool isSorted(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (arr[i] > arr[i + 1])
		{
			return false;
		}
	}
	return true;
}

void randomArr(int *arr, int n)
{
	srand(time(nullptr));
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 10;
	}
}

int main()
{
	int const n = 12;
	int a[n] = { 0 };
	randomArr(a, n);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << searchForFrequent(a, n) << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "is sorted " << isSorted(a, n) << endl;
	testFrequent();
	return 0;
}

