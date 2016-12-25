#include <iostream>
#include <fstream>

using namespace std;

struct Value
{
	int weight;
	int node1;
	int node2;
};

struct ListElement
{
	Value value;
	ListElement *next;
};

struct Queue
{
	ListElement *head;
	ListElement *tail;
};

Queue* createQueue()
{
	return new Queue{ nullptr, nullptr };
}

Value dequeue(Queue *queue)
{
	if (!queue || !queue->head)
	{
		return{ 0, 0, 0 };
	}
	auto oldElement = queue->head;
	auto oldValue = queue->head->value;
	if (queue->head == queue->tail)
	{
		auto head = queue->head;
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
		auto newElement = new ListElement{ value, nullptr };
		queue->head = newElement;
		queue->tail = newElement;
		return;
	}
	auto newElement = new ListElement{ value, nullptr };
	queue->tail->next = newElement;
	queue->tail = newElement;
}

void addToHead(Queue *queue, Value value)
{
	if (!queue->head)
	{
		auto newElement = new ListElement{ value, nullptr };
		queue->head = newElement;
		queue->tail = newElement;
		return;
	}
	auto newElement = new ListElement{ value, queue->head };
	queue->head = newElement;
}

void addAndSort(Queue *queue, Value value)
{
	addToHead(queue, value);
	auto iterator = queue->head;
	while (iterator->next && iterator->value.weight > iterator->next->value.weight)
	{
		swap(iterator->value, iterator->next->value);
		iterator = iterator->next;
	}
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
		cout << head->value.weight << " ";
		head = head->next;
	}
	cout << endl;
}

void printWithNode(Queue *queue)
{
	auto head = queue->head;
	while (head)
	{
		cout << head->value.node1 << " ";
		head = head->next;
	}
	cout << endl;
}

void printWithPath(Queue *queue)
{
	cout << "===" << endl;
	auto head = queue->head;
	while (head)
	{
		cout << head->value.node1 << " " << head->value.node2 << " (" << head->value.weight << ")";
		cout << endl;
		head = head->next;
	}
	cout << endl;
}

void merge(Queue *queue1, Queue *queue2)
{
	while (queue2->head)
	{
		addAndSort(queue1, dequeue(queue2));
	}
}

int minTree()
{
	ifstream file("file.txt");
	if (!file.is_open())
	{
		cout << "error" << endl;
		return 0;
	}
	int weightSum = 0;
	int n = 0;
	int m = 0;
	file >> n >> m;
	auto used = new bool[n + 1]{ false };
	used[0] = true;
	auto nodeQueue = new Queue*[n + 1]{ nullptr };
	for (int i = 0; i < n + 1; ++i)
	{
		nodeQueue[i] = createQueue();
	}
	auto value = Value{ 0, 0, 0 };
	for (int i = 0; i < m; ++i)
	{
		file >> value.node1;
		file >> value.node2;
		file >> value.weight;
		addAndSort(nodeQueue[value.node2], value);
		swap(value.node1, value.node2);
		addAndSort(nodeQueue[value.node2], value);
	}
	file.close();
	merge(nodeQueue[0], nodeQueue[1]);
	used[1] = true;
	int countNumber = n - 1;
	printWithPath(nodeQueue[1]);
	while (countNumber > 0)
	{
		if (nodeQueue[0]->head)
		{
			auto value1 = dequeue(nodeQueue[0]);
			int i = value1.node1;
			if (!used[i])
			{
				--countNumber;
				weightSum = weightSum + value1.weight;
				addAndSort(nodeQueue[0], value1);
				cout << value1.node1 << " " << value1.node2 << endl;
				used[i] = true;
				merge(nodeQueue[0], nodeQueue[i]);
			}
		}
	}
	//delete something
	delete[] used;
	for (int i = 0; i < n; ++i)
	{
		deleteQueue(nodeQueue[i]);
	}
	return weightSum;
}

bool test1()
{
	return minTree() == 7;
}

int main()
{
	cout << test1() << endl;
	return 0;
}
