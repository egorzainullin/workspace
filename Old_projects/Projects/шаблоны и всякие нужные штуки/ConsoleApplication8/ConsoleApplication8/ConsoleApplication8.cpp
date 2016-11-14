// ConsoleApplication8.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
using namespace std;
template <typename T>
void merge(T a[], int i, int j)
{
	if (i < j)
	{
		merge(a, i, (i + j) / 2);
		merge(a, (i + j) / 2 + 1, j);
	}
	T* arr1 = new T[(i + j) / 2 + 1];
	T* arr2 = new T[(i + j) /2 + (i + j) % 2 + 1];
	for (int i1 = 0; i1 < (i + j) / 2; ++i1)
	{
		arr1[i1] = a[i1];
	}
	arr1[(i + j) / 2] = 10000;
	arr2[(i + j) / 2 + (i + j) % 2] = 10000;
	int k = (i + j) / 2;
	for (int i2 = 0; i2 < (i + j) / 2 + (i + j) % 2; ++i2)
	{
		arr2[i2] = a[k + i2];
	}
	int i1 = 0;
	int i2 = 0;
	for (int index = i; index <= j; ++index)
	{
		if (arr1[i1] < arr2[i2])
		{
			a[i] = arr1[i1];
			++i1;
		}
		else
		{
			a[i] = arr2[i2];
			++i2;
		}
	}
	delete[] arr1;
	delete[] arr2;


}

void main()
{
	int number = 0;
	int * array = new int[number];
	for (int index = 0; index < number; ++index)
	{
		cin >> array[index];
	}
	merge(array, 0, number - 1);
	cout << endl;
	for (int index = 0; index < number; ++index)
	{
		cout << array[index]<<" ";
	}
	delete[] array;
}

