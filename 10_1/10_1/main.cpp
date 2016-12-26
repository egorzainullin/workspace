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

void searchingForCitiesOrderAlgorithm(int n, int k, int *cities, bool *used, Queue **nodeQueue, Queue **citiesQueue)
{
	int countNumber = n - k;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			if (i == cities[j])
			{
				used[i] = true;
			}
		}
	}
	int count = -1;
	while (countNumber > 0)
	{
		++count;
		count = count % k;
		int city = cities[count];
		if (getHead(nodeQueue[city]))
		{
			auto value1 = dequeue(nodeQueue[city]);
			int i = value1.node1;
			if (!used[i])
			{
				--countNumber;
				addAndSort(citiesQueue[count], value1);
				used[i] = true;
				merge(nodeQueue[city], nodeQueue[i]);
			}
		}
	}
}

void ouputCities(Queue **citiesQueue, int k)
{
	ofstream output("out.txt");
	for (int i = 0; i < k; ++i)
	{
		while (getHead(citiesQueue[i]))
		{
			auto node1 = dequeue(citiesQueue[i]).node1;
			output << node1 << " ";
			cout << node1 << " ";
		}
		output << endl;
		cout << endl;
	}
	output.close();
}

void findCountries()
{
	ifstream file("file.txt");
	if (!file.is_open())
	{
		cout << "error" << endl;
		return;
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
	int k = 0;
	file >> k;
	auto cities = new int[k] {0};
	//create cities queue
	auto citiesQueue = new Queue*[k] { nullptr };
	for (int i = 0; i < k; ++i)
	{
		citiesQueue[i] = createQueue();
	}
	for (int i = 0; i < k; ++i)
	{
		int l = 0;
		file >> l;
		cities[i] = l;
	}
	file.close();
	//running algorithm
	searchingForCitiesOrderAlgorithm(n, k, cities, used, nodeQueue, citiesQueue);
	//output in file out.txt
	ouputCities(citiesQueue, k);
	//delete something
	delete[] used;
	delete[] cities;
	for (int i = 0; i < n; ++i)
	{
		deleteQueue(nodeQueue[i]);
	}
	for (int i = 0; i < k; ++i)
	{
		deleteQueue(citiesQueue[i]);
	}
}

bool test1()
{
	ifstream file("out.txt");
	if (!file.is_open())
	{
		return false;
	}
	int a = 0;
	int b = 0;
	int c = 0;
	file >> a >> b >> c;
	return a == 5 && b == 6 && c == 3;
}

int main()
{
	findCountries();
	cout << test1() << endl;
	return 0;
}
