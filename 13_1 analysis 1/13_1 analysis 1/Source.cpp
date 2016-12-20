#include <iostream>  
#include <string>

using namespace std;

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

void case1(int &state, char c)
{
	if (isDigit(c))
	{
		state = 2;
	}
	else
	{
		state = 0;
	}
}

void case2(int &state, char c)
{
	switch (c)
	{
	case '.':
		state = 3;
		break;
	case 'e':
		state = 5;
		break;
	default:
		if (!isDigit(c))
		{
			state = 0;
		}
		break;
	}
}

void case3(int &state, char c)
{
	if (isDigit(c))
	{
		state = 4;
	}
	else
	{
		state = 0;
	}
}

void case4(int &state, char c)
{
	if (isDigit(c))
	{
		state = 4;
	}
	else if (c == 'e')
	{
		state = 5;
	}
	else
	{
		state = 0;
	}
}

void case5(int &state, char c)
{
	{
		if (c == '+' || c == '-')
		{
			state = 7;
		}
		else if (isDigit(c))
		{
			state = 6;
		}
		else
		{
			state = 0;
		}
	}
}

void case6(int &state, char c)
{
	if (isDigit(c))
	{
		state = 6;
	}
	else
	{
		state = 0;
	}
}

void case7(int &state, char c)
{
	if (isDigit(c))
	{
		state = 6;
	}
	else
	{
		state = 0;
	}
}

bool analysis(const string str)
{
	int state = 1;
	int size = str.size();
	for (auto i = 0; i < size; ++i)
	{
		char c = str[i];
		switch (state)
		{
		case 1:
			case1(state, c);
			break;
		case 2:
			case2(state, c);
			break;
		case 3:
			case3(state, c);
			break;
		case 4:
			case4(state, c);
			break;
		case 5:
			case5(state, c);
			break;
		case 6:
			case6(state, c);
			break;
		case 7:
			case7(state, c);
			break;
		default:
			state = 0;
			break;
		}
	}
	return state == 2 || state == 6 || state == 4;
}

bool test1()
{
	string str1 = "56.5e-56";
	string str2 = "567-e12";
	return analysis(str1) && !analysis(str2);
}

int main()
{
	cout << test1() << endl;
	string str = "";
	cin >> str;
	cout << analysis(str) << endl;
	return 0;
}