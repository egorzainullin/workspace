// ConsoleApplication10.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>

using namespace std;


int main()
{
	int sum = 0;
	int arr[28] = { 0 };
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 10; ++k)
			{
				++arr[i + j + k];
			}
		}
	}
	for (int i = 0; i <= 27; ++i)
	{
		sum = sum + arr[i] * arr[i];
	}
	cout << sum << endl;
	return 0;
}
