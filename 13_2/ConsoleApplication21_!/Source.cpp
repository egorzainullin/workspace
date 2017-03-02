#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int moveTo(int state, int c, int **arr)
{
	return arr[c][state];
}

int findSymbol(char *arr, int numberOfSymbols, char symbol)
{
	for (auto i = 0; i < numberOfSymbols - 1; ++i)
	{
		if (arr[i] == symbol)
		{
			return i;
		}
	}
	return numberOfSymbols - 1;
}

void readFileAndFindComments(int **arr, char *symbols, int numberOfSymbols, int numberOfConditions)
{
	ifstream file("file.txt");
	int state = 0;
	string str = "";
	ofstream testfile("testfile.txt");
	while (!file.eof())
	{
		char c = 'a';
		c = file.get();
		if (file.eof())
		{
			break;
		}
		auto charNumber = findSymbol(symbols, numberOfSymbols, c);
		state = moveTo(state, charNumber, arr);
		if (state != 0)
		{
			str = str + c;
			if (state == 1)
			{
				str = "/";
			}
		}
		else
		{
			str = "";
		}
		if (state == 4)
		{
			cout << str << endl;
			testfile << str << endl;
			state = 0;
		}
	}
	testfile.close();
}

void writeComments()
{
	ifstream readFile("lexicinf.txt");
	int numberOfSymbols = 0;
	int numberOfConditions = 0;
	readFile >> numberOfSymbols >> numberOfConditions;
	auto symbols = new char[numberOfSymbols];
	for (auto i = 0; i < numberOfSymbols; ++i)
	{
		readFile >> symbols[i];
	}
	numberOfSymbols = numberOfSymbols + 1;
	int **arr = new int*[numberOfSymbols];
	for (auto i = 0; i < numberOfSymbols; ++i)
	{
		arr[i] = new int[numberOfConditions];
	}
	for (auto i = 0; i < numberOfSymbols; ++i)
	{
		for (auto j = 0; j < numberOfConditions; ++j)
		{
			readFile >> arr[i][j];
		}
	}
	readFile.close();
	readFileAndFindComments(arr, symbols, numberOfSymbols, numberOfConditions);
	for (auto i = 0; i < numberOfSymbols; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;
	delete[] symbols;
}

bool test1()
{
	ifstream testfile("testfile.txt");
	string str1 = "";
	string str2 = "";
	getline(testfile, str1);
	getline(testfile, str2);
	testfile.close();
	return str1 == "/*a + b /c */" && str2 == "/*body */";
}

int main()
{
	writeComments();
	cout << test1() << endl;
	return 0;
}
