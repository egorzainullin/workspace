// ConsoleApplication7.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include <iostream>
#include <fstream>
#include <clocale>
#include <vector>
#include <string>

using namespace std;

void fileToArray(vector <string> &names, vector <string> &phones)
{
	string str = "";
	string number = "";
	ifstream file("file.txt", ios_base::in);
	while (!file.eof())
	{
		file >> str;
		if (file.eof())
		{
			break;
		}
		names.push_back(str);
		file >> number;
		if (file.eof())
		{
			break;
		}
		phones.push_back(number);
	}
	file.close();
}

void arrayOut(vector <string> &names, vector <string> &phones)
{
	int maxIndex = 0;
	maxIndex = (names.size() < phones.size()) ? names.size() : phones.size();
	for (int i = 0; i < maxIndex; ++i)
	{
		cout << names[i] << " " << phones[i] << endl;
	}
}

void saveToFile(vector <string> &names, vector <string> &phones)
{
	int maxIndex = 0;
	maxIndex = (names.size() < phones.size()) ? names.size() : phones.size();
	ofstream file("file.txt");
	for (int i = 0; i < maxIndex; ++i)
	{
		file << names[i] << endl;
		file << phones[i] << endl;
	}
}

void addData(vector <string> &names, vector <string> &phones)
{
	string phone = "";
	string name = "";
	cout << "������� ���" << endl;
	cin >> name;
	cout << " ������� �������" << endl; //??????
	cin >> phone;
	phones.push_back(phone);
	names.push_back(name);
}

int main()
{
	setlocale(LC_ALL, "rus");
	vector <string> phones;
	vector <string> names;
	ifstream file("file.txt", ios_base::in);
	if (!file.is_open())
	{
		file.close();
		ofstream file("file.txt");
	}
	else
	{
		fileToArray(names, phones);
	}
	file.close();
	char c = ' ';
	while (c != '0')
	{
		cout << "�������� �������� �� ������:" << endl;
		cout << " 0, ����� �����" << endl;
		cout << " 1, ����� �������� ������ (��� � �������) " << endl;
		cout << " 2, ����� ����������� ��� ��������� ������" << endl;
		cout << " 3, ����� ����� ������� �� ����� " << endl;
		cout << " 4, ����� ����� ��� �� �������� " << endl;
		cout << " 5, ��������� ������� ������ � ���� " << endl;
		cout << "��������, ������� � ��� ������ ��������� ��� ��������" << endl;
		cin >> c;
		switch (c)
		{
		case '0':
			break;
		case '1':
			addData(names, phones);
			break;
		case '2':
			arrayOut(names, phones);
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			saveToFile(names, phones);
			break;
		default:
			break;
		}
	}
}

