#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, l[1001];
	short x[1001][220] = {0};
	l[0] = 1;
	l[1] = 1;
	x[0][0] = 1;
	x[1][0] = 2;
	for (int i = 2; i <= 1000; i++)
	{
		for (int j = 0; j < l[i - 1]; j++)
		{
			if (x[i - 1][j] + x[i - 2][j] + x[i][j] >= 10)
			{
				x[i][j + 1] = 1;
			}
			x[i][j] = (x[i][j] + x[i - 1][j] + x[i - 2][j]) % 10;
		}
		if (x[i][l[i - 1]])
		{
			l[i] = l[i - 1] + 1;
		}
		else
		{
			l[i] = l[i - 1];
		}
	}
	while (cin >> n)
	{
		for (int i = l[n] - 1; i >= 0; i--)
		{
			cout << x[n][i];
		}
		cout << endl;
	}
	return 0;
}
