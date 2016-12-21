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

struct AriphmeticTree
{
	int value;
	TreeElement *root;
};

struct StackElement
{
	Value value;
	StackElement *next;
};

struct Queue
{
	StackElement *head;
	StackElement *tail;
};

Queue* createQueue()
{
	return new Queue{ nullptr, nullptr };
}

Value dequeue(Queue *queue)
{
	if (!queue || !queue->head)
	{
		return " ";
	}
	auto oldElement = queue->head;
	auto oldValue = queue->head->value;
	if (queue->head == queue->tail)
	{
		auto head = queue->head;
		auto tail = queue->tail;
		delete head;
		queue->head = nullptr;
		queue->tail = nullptr;
		return oldValue;
	}
	queue->head = queue->head->next;
	delete oldElement;
	return oldValue;
}

void enequeue(Queue *queue, Value value)
{
	if (!queue->head)
	{
		auto newElement = new StackElement{ value, nullptr };
		queue->head = newElement;
		queue->tail = newElement;
		return;
	}
	auto newElement = new StackElement{ value, nullptr };
	queue->tail->next = newElement;
	queue->tail = newElement;
}

void deleteQueue(Queue *&queue)
{
	while (queue->head)
	{
		dequeue(queue);
	}
	delete queue;
	queue = nullptr;
}

void print(Queue *queue)
{
	auto head = queue->head;
	while (head)
	{
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}


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
	op = "" + str[1];
	cout << op << endl;
	string str1 = "";
	string str2 = "";
	//str[3] != '(';
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
	cout << str << endl;
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
		cout << root->value << endl;
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}

int main()
{
	auto queue = createQueue();
	deleteQueue(queue);
	cout << toInt("123") << endl;
	auto tree = createTree("(* (+ 1 1) 2)");
	preorder(tree);
	deleteTree(tree);
	return 0;
}