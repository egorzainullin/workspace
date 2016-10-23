// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
using namespace std;

int helpDiv(int dividend, int divisor)
{
	int plusDivisor = abs(divisor);
	int q = 0;
	while (plusDivisor * q <= dividend)
	{
		q++;
	}
	q--;
	return divisor < 0 ? -q : q;
}

int divInt(int dividend, int divisor)
{
	if (dividend > 0)
	{
		return helpDiv(dividend, divisor);
	}
	if (dividend < 0)
	{
		dividend = -dividend;
		int spec = helpDiv(dividend, divisor);
		spec = -spec;
		if (spec * divisor == -dividend)
		{
			return spec;
		}
		else
		{
			return --spec;
		}
	}
	return 0;
}

int main()
{
	int a = 0;
	int b = 0;
	cout << "A/B =?" << endl;
	cout << "enter A" << endl;
	cin >> a;
	cout << "enter B" << endl;
	cin >> b;
	cout << divInt(a, b) << endl;
	return 0;
}

