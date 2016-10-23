// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
using namespace std;
bool isInside(char s[], char s1[], int first)
{
	int number = strlen(s);
	int number1 = strlen(s1);
	int count = 0;
	for (int i = 0; i < number1; ++i)
	{
	if (s1[i] = s[i + first])
	{
		count++;
	}
	}
	if (count = number1)
	{
		return true;
	}
	return false;
}

int countingHowmuch(char s[], char s1[])
{
	int count = 0;
	int number = strlen(s);
	int number1 = strlen(s1);
	int i = 0;
	while (i <= (number - number1))
	{
		if (isInside(s, s1, i))
		{
			count++;
			i = i + number1;
		}
	}
	return count;
}

void getstring(char str[])
{
	char symbol = ' ';

	while (symbol != 13)
	{
		cin >> symbol;
		cout << symbol;
		str = str + symbol;
	}
}

int main()
{
	char s[] = "";
	char s1[] = "";
	cout << "enter s" << endl;
	getstring(s);
	cout << "enter s1" << endl;
	getstring(s1);
	system("pause");
    return 0;
}

