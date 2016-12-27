#include <iostream>
#include <string>
#include "simplelist.h"
#include "hashtable.h";

using namespace std;

struct HashTable
{
	List* listArray[dimension];
	int countOfRecords;
};

HashTable* createTable()
{
	HashTable *hashTable = new HashTable;
	for (auto i = 0; i < dimension; ++i)
	{
		hashTable->listArray[i] = createList();
	}
	hashTable->countOfRecords = 0;
	return hashTable;
}

void deleteTable(HashTable *&hashTable)
{
	for (auto i = 0; i < dimension; ++i)
	{
		deleteList(hashTable->listArray[i]);
	}
	delete hashTable;
	hashTable = nullptr;
}

int hashFunction(const string &str)
{
	int length = static_cast<int>(str.size());
	int hash = 0;
	for (auto i = 0; i < length; ++i)
	{
		hash = (hash + static_cast<int>(str[i])) % dimension;
	}
	return hash;
}

void add(HashTable *hashTable, const string &str)
{
	int hash = hashFunction(str);
	auto iterator = getHead(hashTable->listArray[hash]);
	while (iterator != nullptr)
	{
		if (getValue(iterator) == str)
		{
			increaseCount(iterator);
			return;
		}
		iterator = next(iterator);
	}
	push(hashTable->listArray[hash], str);
	++hashTable->countOfRecords;
}

int countOfRecords(HashTable *hashTable)
{
	return hashTable->countOfRecords;
}

int findMaxLength(HashTable *hashTable)
{
	int maxLength = 0;
	for (auto i = 0; i < dimension; ++i)
	{
		int length = listLength(hashTable->listArray[i]);
		if (length > maxLength)
		{
			maxLength = length;
		}
	}
	return maxLength;
}

int findNotNullLists(HashTable *hashTable)
{
	int notNullListsCount = 0;
	for (auto i = 0; i < dimension; ++i)
	{
		if (!isEmpty(hashTable->listArray[i]))
		{
			++notNullListsCount;
		}
	}
	return notNullListsCount;
}

bool isHere(HashTable *hashTable, const string &str)
{
	int hash = hashFunction(str);
	auto iterator = getHead(hashTable->listArray[hash]);
	while (iterator != nullptr)
	{
		if (getValue(iterator) == str)
		{
			return true;
		}
	}
	return false;
}

int getCount(HashTable *hashTable, const string &str)
{
	int hash = hashFunction(str);
	auto iterator = getHead(hashTable->listArray[hash]);
	while (iterator != nullptr)
	{
		if (getValue(iterator) == str)
		{
			return getCount(iterator);
		}
	}
	return 0;
}

void printHashTable(HashTable *hashTable)
{
	for (auto i = 0; i < dimension; ++i)
	{
		print(hashTable->listArray[i]);
	}
}