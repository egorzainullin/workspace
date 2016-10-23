// resheto_eratosphena.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cout << "please, type n" << endl;
	cin >> n;
	auto arr = new bool[n + 1];
	if (n > 1)
	{
		arr[0] = false;
		arr[1] = false;
	}
	for (int i = 2; i <= n; ++i)
	{
		arr[i] = true;
	}
	for (int i = 2; i <= n; ++i)
	{
		if (arr[i])
		{
			for (int k = 0; i * i + k * i <= n; ++k)
			{
				arr[i * i + i * k] = false;
			}
		}
	}
	for (int i = 2; i <=n; ++i)
	{
		if (arr[i])
		{
			cout << i << " ";
		} 
	}
	cout << endl;
	delete[] arr;
	return 0;
}

