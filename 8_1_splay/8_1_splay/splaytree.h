#pragma once

using namespace std;

struct SplayTree;

//create splay array
SplayTree* createSplay();

//delete tree
void deleteTree(SplayTree *&tree);

//insert key or changes value
void insert(SplayTree *tree, int key, string value);

//changes value
void changeValue(SplayTree *tree, int key, string value);

//gets value by key
string getValue(SplayTree *tree, int key);

//check for existance
bool isHere(SplayTree *tree, int key);

//removes value by key
void remove(SplayTree *tree, int key);

//print in preorder form
void preorder(SplayTree *tree);

