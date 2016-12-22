#include <iostream>
#include <string>

using namespace std;

typedef string Value;

struct TreeElement
{
    string value;
    TreeElement *leftChild;
    TreeElement *rightChild;
};

int toInt(string str)
{
    int length = str.size();
    int sum = 0;
    for (int i = 0; i < length; ++i)
    {
        sum = sum * 10 + static_cast<int>(str[i]) - static_cast<int>('0');
    }
    return sum;
}

TreeElement* createTree(string str)
{
    int length = str.size();
    if (str[0] != '(')
    {
        return new TreeElement{ str, nullptr, nullptr }; // (* (+ 1 1) 2).
    }															   //i
    string op = "";
    op = op + str[1];
    string str1 = "";
    string str2 = "";
    if (str[3] != '(')
    {
        int i = 3;
        while (str[i] != ' ')
        {
            str1 = str1 + str[i];
            ++i;
        }
        for (auto j = i + 1; j < length - 1; ++j)
        {
            str2 = str2 + str[j];
        }
    }
    if (str[3] == '(')
    {
        str1 = "(";
        int i = 4;
        int k = 1;
        int l = 0;
        while (k > l)
        {
            if (str[i] == '(')
            {
                ++k;
            }
            else if (str[i] == ')')
            {
                ++l;
            }
            str1 = str1 + str[i];
            ++i;
        }
        for (auto j = i + 1; j < length - 1; ++j)
        {
            str2 = str2 + str[j];
        }
    }
    return new TreeElement{ op, createTree(str1), createTree(str2) };
}

int calculate(TreeElement *root)
{
    if (root->value == "+")
    {
        return calculate(root->leftChild) + calculate(root->rightChild);
    }
    if (root->value == "-")
    {
        return calculate(root->leftChild) - calculate(root->rightChild);
    }
    if (root->value == "*")
    {
        return calculate(root->leftChild) * calculate(root->rightChild);
    }
    if (root->value == "/")
    {
        return calculate(root->leftChild) / calculate(root->rightChild);
    }
    else return toInt(root->value);
}

void deleteTree(TreeElement *&root)
{
    if (root)
    {
        deleteTree(root->leftChild);
        deleteTree(root->rightChild);
        delete root;
    }
}

void preorder(TreeElement *root)
{
    if (root)
    {
        bool b = root->value == "+" || root->value == "-" || root->value == "*" || root->value == "/";
        if (b)
        {
            cout << "(";
        }
        cout << root->value << " ";
        preorder(root->leftChild);
        preorder(root->rightChild);
        if (b)
        {
            cout << ") ";
        }
    }
}

void print(TreeElement *tree)
{
    preorder(tree);
    cout << endl;
}

bool test1()
{
    auto tree = createTree("(* (+ 1 1) 2)");
    print(tree);
    cout << endl;
    int b = calculate(tree);
    cout << b << endl;
    deleteTree(tree);
    return b == 4;
}

int main()
{
    cout << test1() << endl;
    return 0;
}
