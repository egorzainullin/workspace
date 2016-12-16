// ConsoleApplication7.cpp: определяет точку входа для консольного приложения.
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
	int maxIndex = (names.size() < phones.size()) ? names.size() : phones.size();
	for (int i = 0; i < maxIndex; ++i)
	{
		cout << names[i] << " " << phones[i] << endl;
	}
}

void saveToFile(vector <string> &names, vector <string> &phones)
{
	int maxIndex = (names.size() < phones.size()) ? names.size() : phones.size();
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
	cout << "Введите имя" << endl;
	cin >> name;
	cout << "Введите телефон" << endl; //??????
	cin >> phone;
	phones.push_back(phone);
	names.push_back(name);
}

string findByPhone(vector <string> &names, vector <string> &phones, string request)
{
	int maxIndex = (names.size() < phones.size()) ? names.size() : phones.size();
	for (int i = 0; i < maxIndex; ++i)
	{
		if (phones[i] == request)
		{
			return names[i];
		}
	}
	return "Такого телефона нет в базе данных";
}

string findByName(vector <string> &names, vector <string> &phones, string request)
{
	int maxIndex = (names.size() < phones.size()) ? names.size() : phones.size();
	for (int i = 0; i < maxIndex; ++i)
	{
		if (names[i] == request)
		{
			return phones[i];
		}
	}
	return "Такого имени нет в базе данных";
}

bool testingComponents()
{
	vector <string> phones;
	vector <string> names;
	ofstream file1("testfile.txt");
	file1 << "alex" << endl;
	file1 << "5678" << endl;
	file1 << "man" << endl;
	file1 << "735" << endl;
	file1 << "egor" << endl;
	file1 << "1234" << endl;
	string str = "";
	string number = "";
	file1.close();
	ifstream file("testfile.txt", ios_base::in);
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
	return "egor" == findByPhone(names, phones, "1234") && "1234" == findByName(names, phones, "egor");
}
	
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "result of test: " << testingComponents() << endl;
	vector <string> phones;
	vector <string> names;
	string request = "";
	ifstream file("file.txt", ios_base::in);
	if (!file.is_open())
	{
		file.close();
		file.open("file.txt");
	}
	else
	{
		fileToArray(names, phones);
	}
	file.close();
	char c = ' ';
	while (c != '0')
	{
		cout << "Выберете действие из списка:" << endl;
		cout << " 0, чтобы выйти" << endl;
		cout << " 1, чтобы добавить запись (имя и телефон) " << endl;
		cout << " 2, чтобы распечатать все имеющиеся записи" << endl;
		cout << " 3, чтобы найти телефон по имени " << endl;
		cout << " 4, чтобы найти имя по телефону " << endl;
		cout << " 5, сохранить текущие данные в файл " << endl;
		cout << "Внимание, телефон и имя должны вводиться без пробелов" << endl;
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
			request = "";
			cout << "Введите имя" << endl;
			cin >> request;
			cout << findByName(names, phones, request) << endl;
			break;
		case '4':
			request = "";
			cout << "Введите телефон" << endl;
			cin >> request;
			cout << findByPhone(names, phones, request) << endl;
			break;
		case '5':
			saveToFile(names, phones);
			break;
		default:
			break;
		}
	}
}

