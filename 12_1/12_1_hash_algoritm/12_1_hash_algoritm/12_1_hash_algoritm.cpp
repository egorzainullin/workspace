// 12_1_hash_algoritm.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>

using namespace std;

int hashFunction(const string &str)
{
	int length = static_cast<int>(str.size());
	int hash = 0;
	for (auto i = 0; i < length; ++i)
	{
		hash += static_cast<int>(str[i]);
	}
	return hash;
}

bool isIdentical(const string &str, int number, const string &comparingString)
{
	int size = comparingString.size();
	for (int i = 0; i < size; ++i)
	{
		if (str[number + i] != comparingString[i])
		{
			return false;
		}
	}
	return true;
}

int searchForString(const string &str, const string &example)
{
	int numberOfMatches = 0;
	int length = str.size();
	int comparingLength = example.size();
	if (length < comparingLength)
	{
		return 0;
	}
	int comparingHash = hashFunction(example);
	string substr = "";
	for (auto i = 0; i < comparingLength; ++i)
	{
		substr += str[i];
	}
	int currentHash = hashFunction(substr);
	if (currentHash == comparingHash)
	{
		if (substr == example)
		{
			++numberOfMatches;
			cout << "0" << endl;
		}
	}
	for (auto i = 1; i < length - comparingLength + 1; ++i)
	{
		currentHash = currentHash - str[i - 1] + str[i + comparingLength - 1];
		if (currentHash == comparingHash)
		{
			if (isIdentical(str, i, example))
			{
				++numberOfMatches;
				cout << i << endl;
			}
		}
	}
	return numberOfMatches;
}

bool test1()
{
	cout << "abcdefgaabaaaab" << " aabii" << endl;
	return searchForString("abcdefgaabaaaab", "aabii") == 3;
}

int main()
{
	cout << "===" << endl << test1() << endl;
    return 0;
}

