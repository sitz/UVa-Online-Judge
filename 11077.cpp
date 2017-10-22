#include <bits/stdc++.h>

using namespace std;

unsigned long long f[22][22];

int main()
{
	int i, j;
	for (i = 0; i < 22; i++)
	{
		f[0][i] = 0;
	}
	for (i = 1; i < 22; i++)
	{
		f[i][0] = 1;
		for (j = 1; j <= i; j++)
		{
			f[i][j] = f[i - 1][j] + f[i - 1][j - 1] * (i - 1);
		}
	}
	int n, k;
	while (cin >> n >> k && n)
	{
		cout << f[n][k] << endl;
	}
	return 0;
}
