#include <bits/stdc++.h>

using namespace std;

int fibonacci[5001][1100];

int main()
{
	memset(fibonacci, 0, sizeof(fibonacci));
	fibonacci[0][0] = 1;
	fibonacci[1][0] = 1;
	fibonacci[1][1] = 1;
	int i, j, jinwei, tmp, n;
	for (i = 2; i <= 5000; i++)
	{
		jinwei = 0;
		fibonacci[i][0] = fibonacci[i - 1][0];
		for (j = 1; j <= fibonacci[i - 1][0]; j++)
		{
			tmp = fibonacci[i - 2][j] + fibonacci[i - 1][j] + jinwei;
			if (tmp > 9)
			{
				fibonacci[i][j] = tmp % 10;
				jinwei = 1;
			}
			else
			{
				jinwei = 0;
				fibonacci[i][j] = tmp % 10;
			}
		}
		if (jinwei == 1)
		{
			fibonacci[i][j] = 1;
			fibonacci[i][0]++;
		}
	}
	//begin input cases;
	while (cin >> n)
	{
		cout << "The Fibonacci number for " << n << " is ";
		for (i = fibonacci[n][0]; i > 0; i--)
		{
			cout << fibonacci[n][i];
		}
		cout << endl;
	}
	return 0;
}
