#include <iostream>
#include <string>
#include <fstream>
#include "hashtable.h"

using namespace std;

void createHashTableFromFile(HashTable *hashTable)
{
	ifstream file("file.txt");
	if (!file.is_open())
	{
		cout << "error" << endl;
		return;
	}
	string str = "";
	while (!file.eof())
	{
		file >> str;
		add(hashTable, str);
	}
	file.close();
	printHashTable(hashTable);
	cout << "===" << endl;
	double k = countOfRecords(hashTable) / 1.0 / dimension;
	double averageCount = countOfRecords(hashTable) / 1.0 / findNotNullLists(hashTable);
	cout << "k " << k << endl;
	cout << "MaxLength " << findMaxLength(hashTable) << endl;
	cout << "Medium " << averageCount << endl;
}

bool test1(HashTable *hashTable)
{
	return isHere(hashTable, "nyan") && getCount(hashTable, "hacking") == 2;
}

int main()
{
	auto hashTable = createTable();
	createHashTableFromFile(hashTable);
	cout << test1(hashTable) << endl;
	deleteTable(hashTable);
	return 0;
}

