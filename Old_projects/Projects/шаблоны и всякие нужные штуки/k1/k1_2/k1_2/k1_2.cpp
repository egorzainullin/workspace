// k1_2.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>

using namespace std;

void selectSort(int *arr, int n)
{
	int min = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		min = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		swap(arr[min], arr[i]);
	}
}

bool isSort(int *arr, int n)
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

int main()
{
	const int n = 10;
	int a[n] = {10, 9, 87, 7, 0, 50, 4, 0, 1, 0};
	selectSort(a, n);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << isSort(a, n) << endl;
	return 0;
}

