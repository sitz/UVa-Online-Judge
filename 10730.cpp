#include <bits/stdc++.h>

using namespace std;

int V[10005], pos[10005], N;
int Find()
{
	int i, j, k, pa, pb, pc;
	for (i = 0; i < N - 2; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			pa = V[j] - V[i];
			pb = V[j] + pa;
			if (pb < 0)
				continue;
			if (pb >= N)
				continue;
			if (pos[pb] > j)
				return 1;
		}
	}
	return 0;
}

int main()
{
	int i;
	while (scanf("%d:", &N), N)
	{
		for (i = 0; i < N; i++)
		{
			scanf("%d", &V[i]);
			pos[V[i]] = i;
		}
		if (Find())
			puts("no");
		else
			puts("yes");
	}
	return 0;
}
