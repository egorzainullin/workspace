#include <iostream>
#include <fstream>
#include "graphqueue.h"

using namespace std;

void merge(Queue *queue1, Queue *queue2)
{
	while (getHead(queue2))
	{
		addAndSort(queue1, dequeue(queue2));
	}
}

int minTreeAlgorithm(Queue **nodeQueue, bool *used, int n)
{
	merge(nodeQueue[0], nodeQueue[1]);
	used[1] = true;
	int countNumber = n - 1;
	int weightSum = 0;
	printWithPath(nodeQueue[1]);
	while (countNumber > 0)
	{
		if (getHead(nodeQueue[0]))
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
	return  weightSum;
}

int minTree()
{
	ifstream file("file.txt");
	if (!file.is_open())
	{
		cout << "error" << endl;
		return 0;
	}
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
	//launching the main algorithm
	int weightSum = minTreeAlgorithm(nodeQueue, used, n);
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
