// 2_4_1.cpp: определяет точку входа для консольного приложения.
// 

#include <iostream>
#include <ctime>

using namespace std;

void apart(int* arr, int n)
{
	int compare = arr[0]; 
	int j = 0;
	cout << compare << "\n\n"; 
	for (int i = 0; i < n; ++i) 
	{
		
		while ((j < n) && (arr[j] <= compare)) 
		{
			
			++j;
		}
		cout << j << "\n";
		if (j < i)
		{
			if (arr[i] < compare) 
			{
				cout << "yes" << "\n";
				swap(arr[i], arr[j]);
			}
		}
		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

}

int main()
{
	srand(time(nullptr));
	int const n = 10;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 10 - 5;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	apart(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
    return 0;
}

