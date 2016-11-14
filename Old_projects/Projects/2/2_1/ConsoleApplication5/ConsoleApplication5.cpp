// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>

using namespace std;
// будем считать, что нулевое число фибоначчи  -ноль
int fibonacciLin(int n) 
{
	int fPreviousPrevious = 0; 
	int fPrevious = 1; 
	int fCurrent = 1;
	int temporaryVar = 0;
	for (int i = 3; i <= n; ++i)
	{
		temporaryVar = fCurrent + fPrevious;
		fPrevious = fCurrent;
		fPreviousPrevious = fPrevious;
		fCurrent = temporaryVar;
	}
	return fCurrent;
}

int fibonacciRec(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return fibonacciRec(n - 1) + fibonacciRec(n - 2);
}
int main()
{
	cout << fibonacciLin(37) << endl;
	cout << fibonacciRec(37) << endl;
    return 0;
}

