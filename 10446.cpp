#include <bits/stdc++.h>

using namespace std;

int n, back;
unsigned long long f[100][100];

void init()
{
	int i, j, k;
	for (i = 0; i < 61; i++)
	{
		f[0][i] = 1;
		f[1][i] = 1;
	}
	for (i = 2; i < 61; i++)
		for (j = 0; j < 61; j++)
		{
			f[i][j] = 1;
			for (k = 1; k <= j; k++)
			{
				if (i - k < 0)
				{
					f[i][j] += f[0][j];
				}
				else
				{
					f[i][j] += f[i - k][j];
				}
			}
		}
}

int main()
{
	init();
	int kase = 1;
	while (cin >> n >> back)
	{
		if (n > 60)
		{
			break;
		}
		if (n < 0)
		{
			n = 0;
		}
		cout << "Case " << kase++ << ": " << f[n][back] << endl;
	}
	return 0;
}
