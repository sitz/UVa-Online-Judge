#include <bits/stdc++.h>

using namespace std;

int fibonacci[55][55];

int main()
{
	memset(fibonacci, 0, sizeof(fibonacci));
	fibonacci[1][0] = 1;
	fibonacci[1][1] = 2;
	fibonacci[2][0] = 1;
	fibonacci[2][1] = 3;
	int i, j, jinwei, tmp;
	for (i = 3; i < 55; i++)
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
	int n, t, kase = 1;
	cin >> n;
	for (t = 0; t < n; t++)
	{
		cout << "Scenario #" << kase++ << ":" << endl;
		cin >> i;
		for (j = fibonacci[i][0]; j > 0; j--)
		{
			cout << fibonacci[i][j];
		}
		cout << '\n'
				 << endl;
	}
	return 0;
}
