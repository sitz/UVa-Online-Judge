#include <bits/stdc++.h>

using namespace std;

/*
11089
*/

#define maxn 51
int Way[maxn][maxn / 2];
int T[maxn];
void Dynamic()
{
	int i, j, k, n, total = 4, t;
	Way[1][1] = Way[2][1] = Way[3][1] = Way[3][2] = 1;
	T[1] = 1;
	T[2] = 2;
	T[3] = 4;
	for (i = 4; i < maxn; i++)
	{
		Way[i][1] = 1;
		Way[i][2] = i - 2;
		total += i - 1;
		n = (i + 1) / 2;
		t = i - 1;
		for (j = 3; j <= n; j++)
		{
			for (k = i - 2; i >= 1 && Way[k][j - 1]; k--)
			{
				Way[i][j] += Way[k][j - 1];
				total += Way[k][j - 1];
				t += Way[k][j - 1];
				if (total >= 1000000000)
				{
					break;
				}
			}
			if (total >= 1000000000)
			{
				break;
			}
		}
		T[i] = t + T[i - 1];
		if (total >= 1000000000)
		{
			break;
		}
	}
}
int Len(int n)
{
	int i;
	for (i = 1; i < 50 && T[i] < n; i++)
		;
	return i;
}
void Cal(int n)
{
	int len, rem, i, res[50] = {0};
	int l = 3, r, m, p, k;
	len = r = Len(n);
	rem = n - T[len - 1] - 1;
	res[1] = 1;
	m = len - 2;
	for (i = 2; i <= len && rem; i++)
	{
		p = Len(rem);
		rem -= T[p - 1];
		rem--;
		k = p - 1;
		res[len - k] = 1;
		m = len - k + 2;
	}
	for (i = 1; i <= len; i++)
	{
		cout << res[i];
	}
	cout << endl;
}
int main()
{
	int k, n;
	Dynamic();
	cin >> k;
	while (k--)
	{
		cin >> n;
		Cal(n);
	}
	return 0;
}
