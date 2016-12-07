#include "mostfrequent.h"
#include <iostream>

using namespace std;

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


