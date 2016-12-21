#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int moveTo(int state, int c, int **arr)
{
	return arr[c][state];
}

int findSymbol(char *arr, int m, char c)
{
	for (auto i = 0; i < m - 1; ++i)
	{
		if (arr[i] == c)
		{
			return i;
		}
	}
	return m - 1;
}

void writecomments()
{
	ifstream readFile("file1.txt");
	int m = 0;
	int n = 0;
	readFile >> m >> n;
	auto symbols = new char[m];
	for (auto i = 0; i < m; ++i)
	{
		readFile >> symbols[i];
	}
	m = m + 1;
	int **arr = new int*[m];
	for (auto i = 0; i < m; ++i)
	{
		arr[i] = new int[n];
	}
	for (auto i = 0; i < m; ++i)
	{
		for (auto j = 0; j < n; ++j)
		{
			readFile >> arr[i][j];
		}
	}
	readFile.close();
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
		auto charNumber = findSymbol(symbols, m, c);
		state = moveTo(state, charNumber, arr);
		if (state != 0)
		{
			str = str + c;
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
	for (auto i = 0; i < m; ++i)
	{
		delete[] arr[i];
	}
	delete[] symbols;
}

bool test1()
{
	ifstream testfile("testfile.txt");
	string str1 = "";
	string str2 = "";
	getline(testfile, str1);
	getline(testfile, str2);
	return str1 == "/*a + b /c */" && str2 == "/*body */";
	testfile.close();
}

int main()
{
	writecomments();
	cout << test1() << endl;
	return 0;
}