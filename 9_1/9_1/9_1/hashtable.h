#pragma once

const int dimension = 997;

struct HashTable;

//hashtable constuctor
HashTable* createTable();

//hastable destructor
void deleteTable(HashTable *&hashTable);

//add string str to the table
void add(HashTable *hashTable, const std::string &str);

//get word's count
int getCount(HashTable *hashTable, const std::string &str);

//check for containing
bool isHere(HashTable *hashTable, const std::string &str);

//count of records
int countOfRecords(HashTable *hashTable);

//find max list in table
int findMaxLength(HashTable *hashTable);

//find not null lists in table
int findNotNullLists(HashTable *hashTable);

//print hashtable
void printHashTable(HashTable *hashTable);