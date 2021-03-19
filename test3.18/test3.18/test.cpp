#include <iostream>
using namespace std;

int main()
{
	int arr[6][6] = { {0} };
	int b = 10;
	for (int i = 0; i < 6; ++i)
	{
		int a = (i + 1);

		for (int j = 0; j < 6; ++j)
		{
			int c = j + a;
			if (i == 0)
			{
				arr[i][j] = a++;
			}
			else
			{
				arr[i][j] = arr[i - 1][j] * b + c;
			}
		}
	}
	int n = 6;
	for (int i = 0; i < 6; ++i)
	{

		for (int j = 0; j < n; ++j)
		{
			printf("%-5d ", arr[i][j]);
		}
		cout << endl;
		--n;
	}

	return 0;
}