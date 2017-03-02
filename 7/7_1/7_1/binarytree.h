#pragma once
//tree
struct Tree;

//tree constructor
Tree* createTree();

//tree destructor
void deleteTree(Tree *&tree);

//print tree
void preorder(Tree *tree);

//print in increasing order
void printInIncreasingOrder(Tree *tree);

//print in decreasing order
void printInDecreasingOrder(Tree *tree);

//check element containing
bool isThere(Tree *tree, int value);

//insert value in tree
void insert(Tree *tree, int value);

//remove from tree
void remove(Tree *tree, int value);