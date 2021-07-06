#include <bits/stdc++.h>

using namespace std;

/*
10635
Prince and Princess
*/

#define maxn 62505
int Add[maxn];
int C[maxn], B[maxn];
int N, P, Q, lcs;
void Set()
{
	int n, aj;
	while (Q--)
	{
		cin >> n;
		aj = Add[n];
		if (aj)
		{
			C[1] = aj;
			lcs = 1;
			return;
		}
	}
}
void Cal()
{
	int i, aj, n;
	lcs = 0;
	Q++;
	Set();
	if (Q < 0)
	{
		Q = 0;
	}
	while (Q--)
	{
		cin >> n;
		aj = Add[n];
		if (!aj)
		{
			continue;
		}
		for (i = lcs; i >= 0; i--)
		{
			if (C[i] < aj)
			{
				if (i + 1 > lcs || C[i + 1] > aj)
				{
					C[i + 1] = aj;
				}
				if (i + 1 > lcs)
				{
					lcs = i + 1;
				}
				break;
			}
		}
	}
	cout << lcs << endl;
}
void Free()
{
	int i;
	for (i = 1; i <= P + 1; i++)
	{
		Add[B[i]] = 0;
	}
}
int main()
{
	int ks, n, i, k = 1;
	cin >> ks;
	while (ks--)
	{
		cin >> N >> P >> Q;
		for (i = 1; i <= P + 1; i++)
		{
			cin >> n;
			B[i] = n;
			Add[n] = i;
		}
		cout << "Case " << k++ << ": ";
		Cal();
		if (ks)
		{
			Free();
		}
	}
	return 0;
}
