#include <bits/stdc++.h>

using namespace std;

/*
11064
*/

#define maxn 46342
char sv[maxn];
int P[10000], ind;
void Table()
{
	int i, j;
	for (i = 2; i * i < maxn;)
	{
		for (j = i + i; j < maxn; j += i)
		{
			sv[j] = 1;
		}
		for (++i; sv[i]; i++)
			;
	}
	P[0] = 2;
	ind = 1;
	for (i = 3; i < maxn; i += 2)
	{
		if (!sv[i])
		{
			P[ind++] = i;
		}
	}
}
int Div(int n)
{
	int i, div = 1, k, sum = n, m = n;
	for (i = 0; i < ind && P[i] * P[i] <= n; i++)
	{
		if (n % P[i] == 0)
		{
			k = 0;
			sum -= sum / P[i];
			while (n % P[i] == 0)
			{
				n /= P[i];
				k++;
			}
			div *= (k + 1);
		}
	}
	if (n > 1)
	{
		div *= 2;
		sum -= sum / n;
	}
	div--;
	return m - sum - div;
}
void Cal(int n)
{
	cout << Div(n) << endl;
}
int main()
{
	int n;
	Table();
	while (cin >> n)
	{
		Cal(n);
	}
	return 0;
}
