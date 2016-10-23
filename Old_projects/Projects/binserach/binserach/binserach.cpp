// extrasort3.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

long int superRand()
{
	unsigned long int a = 0;
	for (int i = 0; i < 10; ++i)
	{
		a = 10 * a + (rand() % 10);
	}
	return a;
}

void randomArr(unsigned long int *arr, int n)
{
	srand(time(nullptr));
	for (int i = 0; i < n; ++i)
	{
		arr[i] = superRand();
	}
}

void arrOut(unsigned long int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void afterMove(unsigned long int *arr, int n, int j)
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

bool test1(unsigned long int *arr, int n)
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

void createTree(unsigned long int *arr, int n)
{
	for (int i = n / 2; i > 0; --i)
	{
		afterMove(arr, n, i);
	}
}

void testTree()
{
	const int n = 10;
	unsigned long int arr[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	createTree(arr, n);
	cout << "Tree: " << test1(arr, n) << endl;
}

void sortTree(unsigned long int *arr, int n)
{
	for (int length = n - 1; length > 0; --length)
	{
		swap(arr[0], arr[length]);
		afterMove(arr, length, 1);
	}

}

void heapsort(unsigned long int *arr, int n)
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

bool isSorted(unsigned long int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (arr[i] > arr[i + 1]) return false;
	}
	return true;
}

bool binarySearching(unsigned long int* arr, int request, int left, int right)
{
	if (right - left < 2)
	{
		return ((request == arr[left]) || (request == arr[right])) ? true : false;
	}
	int c = (left + right) / 2;
	if (arr[c] == request)
	{
		return true;
	}
	if (arr[c] < request)
	{
		return binarySearching(arr, request, c + 1, right);
	}
	else
	{
		return binarySearching(arr, request, left, c);
	}
}

bool binarySearchingMain(unsigned long int * arr, int n, int request)
{
	return binarySearching(arr, request, 0, n - 1);
}

void whichElementsIn(unsigned long int *arr, int n, unsigned long int a)
{
	cout << a << endl;
	cout << "In? " << binarySearchingMain(arr, n, a) << endl;
}

bool testAll()
{
	testTree();
	unsigned long int arr[5] = { 2, 1, 3, 5, 6 };
	heapsort(arr, 5);
	return binarySearchingMain(arr, 5, 1) && !binarySearchingMain(arr, 5, 4);
}

int main()
{
	int n = 0;
	int k = 0;
	cout << "Enter n" << endl;
	cin >> n;
	cout << "Enter k" << endl;
	cin >> k;
	unsigned long int* a = new unsigned long int[n];
	randomArr(a, n);
	arrOut(a, n);
	cout << endl;
	heapsort(a, n);
	arrOut(a, n);
	cout << endl;
	cout << "is sorted " << isSorted(a, n) << endl;
	cout << "What do we want to search?" << endl;
	int requestForSearching = 0;
	for (int i = 0; i < k; ++i)
	{
		requestForSearching = superRand();
		whichElementsIn(a, n, requestForSearching);
	}
	delete[] a;
	cout << "is OK ?" << testAll() << endl;
	return 0;
}

