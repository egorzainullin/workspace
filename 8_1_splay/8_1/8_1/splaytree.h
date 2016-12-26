#pragma once

using namespace std;

struct SplayTree;

//create splay array
SplayTree* createSplay();

//delete tree
void deleteTree(SplayTree *&tree);

//insert key or changes value
void insert(SplayTree *tree, const string &key, const string &value);

//changes value
void changeValue(SplayTree *tree, const string &key, const string &value);

//gets value by key
string getValue(SplayTree *tree, const string &key);

//check for existance
bool isHere(SplayTree *tree, const string &key);

//removes value by key
void remove(SplayTree *tree, const string &key);

//print in preorder form
void preorder(SplayTree *tree);
