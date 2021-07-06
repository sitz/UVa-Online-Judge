#include <bits/stdc++.h>

using namespace std;

int J[30005], L[30005], E[30005];
int main()
{
	int t, tt, i, j;
	J[1] = 1;
	for (i = 2; i <= 30000; i++)
	{
		if (i & 1)
		{
			J[i] = 2 * J[i >> 1] + 1;
		}
		else
		{
			J[i] = 2 * J[i >> 1] - 1;
		}
	}
	for (i = 1; i <= 30000; i++)
	{
		if (J[i] == i)
		{
			L[i] = 0, E[i] = i;
		}
		else
		{
			L[i] = L[J[i]] + 1, E[i] = E[J[i]];
		}
	}
	scanf("%d", &tt);
	for (t = 1; t <= tt; t++)
	{
		scanf("%d", &i);
		printf("Case %d: %d %d\n", t, L[i], E[i]);
	}
	return 0;
}
