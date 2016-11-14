// extrasort3.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void randomArr(int *arr, int n)
{
	srand(time(nullptr));
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 10;
	}
}

void afterMove(int *arr, int n, int j)
{
	if ((n % 2 == 0) && (j == n / 2))
	{
		if (arr[j - 1] < arr[2 * j - 1])
		{
			swap(arr[j - 1], arr[2 * j - 1]);
		}
	}
	else
	{
		if (j <= n / 2)
		{
			if ((arr[2 * j] >= arr[2 * j - 1]) && (arr[2 * j] > arr[j - 1]))
			{
				swap(arr[2 * j], arr[j - 1]);
				afterMove(arr, n, 2 * j + 1);
			}
			else
			{
				if ((arr[2 * j - 1] >= arr[2 * j]) && (arr[2 * j - 1] > arr[j - 1]))
				{
					swap(arr[2 * j - 1], arr[j - 1]);
					afterMove(arr, n, 2 * j);
				}
			}
		}
	}
}

bool test1(int *arr, int n)
{
	for (int i = 1; i < n / 2; ++i)
	{
		if ((arr[i - 1] < arr[2 * i - 1]) || (arr[i - 1] < arr[2 * i]))
		{
			return false;
		}
	}
	return true;
}

void createTree(int *arr, int n)
{
	for (int i = n / 2; i > 0; --i)
	{
		afterMove(arr, n, i);
	}
}

void sortTree(int *arr, int n)
{
	for (int length = n - 1; length > 0; --length)
	{
		swap(arr[0], arr[length]);
		afterMove(arr, length, 1);
	}

}

void testTree()
{
	int const n = 10;
	int arr[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	createTree(arr, n);
	cout << "Tree: " << test1(arr, n) << endl;
}

void heapsort(int *arr, int n)
{
	if (n != 1)
	{
		if (n == 2)
		{
			if (arr[0] > arr[1])
			{
				swap(arr[0], arr[1]);
			}
		}
		else
		{
			createTree(arr, n);
			sortTree(arr, n);
		}
	}

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

int searchForFrequent(int* arr, int n)
{
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
	searchForFrequent(a, 5) == 1 ?  cout << "Ok" : cout << "error";
	cout << endl;
	searchForFrequent(b, 10) == 4 ? cout << "Ok" : cout << "error";
	cout << endl;
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
	heapsort(a, n);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "is sorted " << isSorted(a, n) << endl;
	cout << searchForFrequent(a, n) << endl;
	testTree();
	testFrequent();
	return 0;
}

