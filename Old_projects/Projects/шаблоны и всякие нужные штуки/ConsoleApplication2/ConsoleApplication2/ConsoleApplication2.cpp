// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
using namespace std;

int count0Element(int element)
{
	if (element)
	{
		return 0;
	}
	return 1;
}

int countIt(int* arr, int number)
{
	int result = 0;
	for (int i = 0; i < number; i++)
	{
		result = result + count0Element(arr[i]);
	}
	return result;
}
int arrayIn(int* arr, int number)
{
	for (int i = 0; i < number; i++)
	{
		cout << "please, enter elemets" << endl;
		cin >> arr[i];
	}
	return 0;
}

int main()
{
	int const number = 5;
	int arrayInt[number];
	arrayIn(arrayInt, number);
	cout << countIt(arrayInt, number) << endl;
	system("pause");
	return 0;
}

