#include  <iostream>
#include <clocale>

using namespace std;

struct Binary
{
	bool digit[8 * sizeof(int)] = {false};
	int size = 8 * sizeof(int);
};

Binary transformToBinary(int a)
{
	int temp = 1;
	Binary binary;
	for (int i = 0; i < 8 * sizeof(int); ++i)
	{
		binary.digit[i] = temp & a;
		temp = temp << 1;
	}
	return binary;
}

Binary binaryPlusSum(Binary a, Binary b)
{
	Binary c;
	int carry = 0;
	for (int i = 0; i < c.size; ++i)
	{
		c.digit[i] = (a.digit[i] + b.digit[i] + carry) % 2;
		carry = (a.digit[i] + b.digit[i] + carry) / 2;
	}
	return c;
}

Binary tranformFromAdditional(Binary binary)
{
	for (int i = 0; i < binary.size; ++i)
	{
		binary.digit[i] = !binary.digit[i];
	}
	binary = binaryPlusSum(binary, transformToBinary(1));
	return binary;
}

int binaryToInt(Binary binary)
{
	int c = 0;
	int sign = 1;
	if (binary.digit[binary.size - 1])
	{
		binary = tranformFromAdditional(binary);
		sign = -1;
	}
	int multiplier = 1;
	for (int i = 0; i < 8 * sizeof(int); ++i)
	{
		c = c + binary.digit[i] * multiplier;
		multiplier = multiplier * 2;
	}
	return c * sign;
}

void printBinary(Binary binary)
{
	for (int i = 8 * sizeof(int) - 1; i >= 0; --i)
	{
		cout << binary.digit[i];
	}
	cout << endl;
}

bool test1()
{
	int a = 2;
	int b = -1;
	auto binaryA = transformToBinary(a);
	auto binaryB = transformToBinary(b);
	return binaryA.digit[0] == 0 && binaryA.digit[1] == 1 && binaryToInt(binaryPlusSum(binaryA, binaryB)) == 1;
}

int main()
{
	cout << test1() << endl;
	setlocale(LC_ALL, "rus");
	int a = 0;
	int b = 0;
	cout << "Введите а" << endl;
	cin >> a;
	auto binaryA = transformToBinary(a);
	cout << "Введите b" << endl;
	cin >> b;
	auto binaryB = transformToBinary(b);
	cout << "В двоичном коде:" << endl;
	printBinary(binaryA);
	printBinary(binaryB);
	cout << "====" << endl;
	auto sum = binaryPlusSum(binaryA, binaryB);
	printBinary(sum);
	cout << binaryToInt(sum) << endl;
	return 0;
}