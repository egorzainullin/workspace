// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>

using namespace std;

int formula(int x)
{
	int sqrx = x * x;
	return (1 + x + sqrx) * sqrx + 1 + x;
}

int main()
{
	int x = 0;
	cout << "Enter x" << endl;
	cin >> x;
	cout << "1+x+x^2+x^3+x^4)\n" << formula(x) << endl;
	return 0;
}