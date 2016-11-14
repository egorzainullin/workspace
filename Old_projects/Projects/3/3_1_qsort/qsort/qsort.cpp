// qsort.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <ctime>

using namespace std;

void quicksort(int* arr, int left, int right);

void randomArr(int *arr, int n)
{
	srand(time(nullptr));
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 10;
	}
}

void arrOut(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int chooseElement (int* arr, int left, int right)
{
	int i = left + 1;
	while ((i < right) && (arr[i] == arr[left]))
	{
		++i;
	}
	return (arr[i] > arr[left]) ? i : left;
}

void insertion(int* arr, int left, int right)
{
	for (int i = left; i <= right; ++i)
	{
		for (int j = i; j > left; --j)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
			}
			else
			{
				break;
			}
		}
	}
}

int apart(int* arr, int leftFirst, int rightFirst)
{
	int left = leftFirst;
	int right = rightFirst;
	int elem = arr[chooseElement(arr, left, right)];
	while (left < right)
	{
		while ((arr[left] < elem) && (left < right))
		{
			++left;
		}
		while ((arr[right] >= elem) && (left < right))
		{
			--right;
		}
		if (left < right)
		{
			swap(arr[left], arr[right]);
			++left;
			--right;
		}
	}
	return left;
}

bool checkApart()
{
	int const n = 10;
	int arr[n] = { 5, 1, 2, 5, 3, 4, 10, 11, 12, 13 };
	apart(arr, 0, n - 1);
	for (int i = 0; i < 4; ++i)
	{
		if (arr[i] >= 5)
		{
			return false;
		}
	}
	return true;
}

void quicksort(int* arr, int left, int right)
{
	int newLeft = 0;
	if (left - right < 10)
	{
		insertion(arr, left, right);
	}
	else
	{
		newLeft = apart(arr, left, right);
		quicksort(arr, left, newLeft - 1);
		quicksort(arr, newLeft, right);
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

bool qsortCheck()
{
	int a[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int b[20] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int c[20] = { 0 };
	quicksort(a, 0, 19);
	quicksort(b, 0, 19);
	quicksort(c, 0, 19);
	return isSorted(a, 20) && isSorted(b, 20) && isSorted(c, 20);
}

int main()
{
	int const n = 50;
	int arr[n] = { 0 };
	randomArr(arr, n);
	arrOut(arr, n);
	quicksort(arr, 0, n - 1);
	arrOut(arr, n);
	cout << "Apart ? " << checkApart() << endl;
	cout << "qsort ? " << qsortCheck() << endl;
	cout << "True: " << isSorted(arr, n) << endl;
	return 0;
}
