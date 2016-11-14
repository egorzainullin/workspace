// degree.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
using namespace std;

int powHalf(int a, int n)
{
	if (n == 1)
	{
		return a;
	}
	int sqrt = powHalf(a, n / 2);
	if (n % 2 == 0)
	{
		return sqrt * sqrt;
	}
	else
	{
		return sqrt * sqrt * a;
	}
}

int powDriveAhead(int a, int n)
{
	int pow = 1;
	for (int i = 1; i <= n; ++i)
	{
		pow = pow * a;
	}
	return pow;
}

int main()
{
	int a = 0;
	cout << "enter number a" << endl;
	cin >> a;
	int n = 0;
	cout << "enter n" << endl;
	cin >> n;
	cout << powHalf(a, n) << endl;
	cout << powDriveAhead(a, n) << endl;
    return 0;
}

