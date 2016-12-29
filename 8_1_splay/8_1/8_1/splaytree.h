#pragma once

struct SplayTree;

//create splay array
SplayTree* createSplay();

//delete tree
void deleteTree(SplayTree *&tree);

//insert key or changes value
void insert(SplayTree *tree, const std::string &key, const std::string &value);

//changes value
void changeValue(SplayTree *tree, const std::string &key, const std::string &value);

//gets value by key
std::string getValue(SplayTree *tree, const std::string &key);

//check for existance
bool isHere(SplayTree *tree, const std::string &key);

//removes value by key
void remove(SplayTree *tree, const std::string &key);

//print in preorder form
void preorder(SplayTree *tree);
