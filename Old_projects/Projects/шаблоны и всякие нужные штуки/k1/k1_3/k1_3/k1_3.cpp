// k1_3.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string writeAfter(string str)
{
	int b = false;
	string checkstr = "";
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == ';')
		{
			b = true;
		}
		if (b)
		{
			cout << str[i];
			checkstr = checkstr + str[i];
		}
	}
	cout << endl;
	return checkstr;
}

void test1(string str)
{
	if ((str == ";1233 4444") || (str == "; m1m2m3") || (str == "; movies"))
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
}

int main()
{
	string str = "";
	ifstream file("file.txt");
	if (!file.is_open())
	{
		cout << "error" << endl;
	}
	while (!file.eof())
	{
		if (file.eof())
		{
			break;
		}
		getline(file, str);
		test1(writeAfter(str));
	}
	return 0;
}

