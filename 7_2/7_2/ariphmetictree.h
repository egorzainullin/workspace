#pragma once
#include <string>

//tree node
struct TreeElement;

//struct tree
struct Tree;

//constuct tree
Tree* createTree();

//destruct tree
void deleteTree(Tree *&tree);

//construct treeElement
TreeElement* createTreeElement();

//construct treeElement and initialise it with str
TreeElement* createTreeElement(const std::string &str);

//gets root
TreeElement* getRoot(Tree *tree);

//gets value
std::string getValue(TreeElement *root);

//set tree root
void setRoot(Tree *tree, TreeElement *root);

//change element's value
void setValue(TreeElement *element, std::string value);

//gets left child
TreeElement* getLeftChild(TreeElement *node);

//gets right child
TreeElement* getRightChild(TreeElement *node);

//seting child as parent's leftchild
void setLeftChild(TreeElement *parent, TreeElement *child);

//seting child as parent's rightchild
void setRightChild(TreeElement *parent, TreeElement *child);