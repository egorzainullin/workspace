// module_frequent.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <ctime>
#include "heapsort.h"

using namespace std;

int searchForFrequent(int* arr, int n)
{
	heapsort(arr, n);
	int result = 0;
	int maxCount = 0;
	int count = 0;
	int i = 0;
	while (i < n)
	{
		int number = arr[i];
		count = 0;
		while ((arr[i] == number) && (i < n))
		{
			++count;
			++i;
		}
		if (count > maxCount)
		{
			maxCount = count;
			result = number;
		}
	}
	return result;
}

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

