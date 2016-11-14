#include <iostream>

using namespace std;

struct ListElement
{
	int value;
	ListElement *next;
};

void add(ListElement *&head, ListElement *&first, int value)
{
	auto newElement = new ListElement{ value , head };
	head = newElement;
	if (first == nullptr)
	{
		first = head;
	}
	else
	{
		first->next = head;
	}
}

void print(ListElement *head,int n)
{
	cout << "===" << endl;
	int count = 0;
	ListElement *iterator = head;
	while ((iterator != nullptr) && (count < n))
	{
		++count;
		cout << iterator->value << endl;
		iterator = iterator->next;
	}
	cout << "===" << endl;
}

int countingManWhoSurvived(ListElement *&head, int n, int m)
{
	ListElement *first = nullptr;
	if (n == 1)
	{
		return 1;
	}
	for (int i = n; i > 0; --i)
	{
		add(head, first, i);
	}
	int count = 1;
	while ((head != nullptr) && (head->next != nullptr) && (head->next != head))
	{
		++count;
		if (count % m == 0)
		{
			ListElement *old = head->next;
			head->next = head->next->next;
			delete old;
		}
		else
		{
			head = head->next;
		}
	}
	if (head != nullptr)
	{
		return head->value;
	}
	return 0;
}

bool test1()
{
	ListElement *head = nullptr;
	int n = 5;
	int m = 2;
	if (countingManWhoSurvived(head, n, m) != 3)
	{
		print(head, 1);
		delete head;;
		return false;
	}
	n = 5;
	m = 3;
	delete head;
	if (countingManWhoSurvived(head, n, m) != 4)
	{
		print(head, 1);
		delete head;;
		return false;
	}
	delete head;
	return true;
}

int main()
{
	int n = 0;
	cout << "Type n" << endl;
	cin >> n;
	int m = 0;
	cout << "Type m" << endl;
	cin >> m;
	ListElement *head = nullptr;
	cout << "Answer: " << countingManWhoSurvived(head, n, m) << endl;
	delete head;
	cout << "OK: " << test1() << endl;
	return 0;
}