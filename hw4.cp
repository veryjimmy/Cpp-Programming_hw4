#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;



int binarysearch(int data[], int search, int low, int high, int mid)
{
	mid = (low + high) / 2;
	if (data[mid] == search) 
	{
		return mid;
	}
	else
	{
		if (search < data[mid]) 
		{
			high = mid - 1;
			binarysearch(data, search, low, high, mid);
		}
		else
			if (search > data[mid])
			{
				low = mid + 1;
				binarysearch(data, search, low, high, mid);
			}
	}
}

int main()
{
	while (true)
	{
		int a[10], n, number, ans;
		int low = 0, high = 9;
		int mid = 0;

		cout << "(1)Start" << endl << "(2)End" << endl;
		cin >> n;
		if (n == 2)
			break;
		else
		{
			if (n == 1)
			{
				srand(time(0));

				for (int i = 0; i < 10; i++)
				{
					a[i] = (rand() % 100) + 1;
				}
				for (int i = 0; i < 10; i++)
				{
					sort(a, a + 10);
					cout << a[i] << " ";
				}
				cout << endl;
				cout << "Please input a number that you want to search: ";
				cin >> number;
				if (number != a[0] && number != a[1] && number != a[2] && number != a[3] &&
					number != a[4] && number != a[5] && number != a[6] && number != a[7] &&
					number != a[8] && number != a[9])
				{
					cout << number << " is not in the array!" << endl;
				}
				else
				{
					ans = binarysearch(a, number, low, high, mid);
					cout << number << " is in the array, and the position is " << ans + 1 << endl;
				}
			}
		}
	}
	system("pause");
	return 0;
}