// s1s2.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <string>

using namespace std;

int compare(int i, string s, string s1)
{
	int j = 0;
	while ((s[i] == s1[j]) && (j < s1.length()) && (i < s.length()))
	{
		++i;
		++j;
	}
	cout << j << endl;
	return i;
}

int main()
{
	string s1 = "";
	string s = "";
	cout << "Enter s" << endl;
	cin >> s;
	cout << "Enter s1" << endl;
	cin >> s1;
	int i = 0;
	int k = 0;
	int count = 0;
	while (i < s.length())
	{
		k = i;
		i = compare(i, s, s1);
		if (i - k == s1.length())
		{
			++count;
		}
		if (i == k)
		{
			++i;
		}
	}
	cout << "Answer " << count << endl;
    return 0;
}

