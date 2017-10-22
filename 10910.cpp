#include <bits/stdc++.h>

using namespace std;

/*
10910
Marks Distrubution
*/

#define maxn 80
typedef long ss;
ss S, T, P;
char Fg[maxn][maxn];
ss D[maxn][maxn];
ss Recur(ss n, ss level)
{
	ss i, d, l = 0;
	if (n == 0)
	{
		return 1;
	}
	if (level == S)
	{
		return 0;
	}
	d = (S - level) * P;
	if (d > n)
	{
		return 0;
	}
	if (Fg[n][level])
	{
		return D[n][level];
	}
	Fg[n][level] = 1;
	for (i = P; i; i++)
	{
		if (d - P > (n - i))
		{
			break;
		}
		l += Recur(n - i, level + 1);
	}
	D[n][level] = l;
	return l;
}
int main()
{
	ss k, i;
	cin >> k;
	while (k--)
	{
		cin >> S >> T >> P;
		cout << Recur(T, 0) << endl;
		for (i = 0; i <= T; i++)
			for (ss j = 0; j <= S; j++)
			{
				Fg[i][j] = 0;
			}
	}
	return 0;
}
