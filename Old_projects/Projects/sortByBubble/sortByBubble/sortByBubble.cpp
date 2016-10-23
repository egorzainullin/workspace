// sortByBubble.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>

using namespace std;

int const maxvalue = 5;

void bubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = n - 1; j > i; --j)
		{
			if (arr[j] < arr[i]) 
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}

void extraArraySort(int* arr, int n)
{
	int a[maxvalue] = { 0 };
	for (int i = 0; i < n; ++i)
	{
		int index = arr[i];
		++a[index];
	}
	int j = 0;
	for (int i = 0; i < maxvalue; ++i)
	{
		for (int k = j; k < j + a[i]; ++k)
		{
			arr[k] = i;
		}
		j = j + a[i];
	}
	
}

int main()
{
	int const n = 5;
	int arr[n] = { 3, 9, 4, 5, 7 };
	bubbleSort(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 5;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	extraArraySort(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}

