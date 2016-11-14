// k1_1.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
using namespace std;

int numbersOfInt(int a)
{
	int sum = 0;
	a = abs(a);
	int c = 0;
	while (a > 0)
	{
		c = a % 10;
		sum = sum + c;
		a = a / 10;
	}
	return sum;
}

int findMax(int *arr, int n)
{
	int max = 0;
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		k = numbersOfInt(arr[i]);
		if (k > max)
		{
			max = k;
		}
	}
	return max;
}

void getAnswer(int *arr, int n)
{
	int max = findMax(arr, n);
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		k = numbersOfInt(arr[i]);
		if (k == max)
		{
			cout << arr[i] << endl;
		}
	}
}

void test1()
{
	const int n = 5;
	int a[n] = { 111, 222, 999,345, 999 };
	if (findMax(a, n) == 27)
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}
int main()
{
	const int n = 5;
	int a[n] = { 111, 222, 999,345, 999 };
	getAnswer(a, n);
	test1();
	return 0;
}

