#include <bits/stdc++.h>

using namespace std;

int in[10001], out[10001], N, K, S, p;
void solve()
{
	int moves = 0, free;
	for (int i = 1; i <= p; i++)
	{
		if (in[i] == 0)
		{
			int j = i;
			while (out[j])
			{
				printf("%d %d\n", out[j], j);
				int t = out[j];
				out[j] = 0;
				j = t;
				moves++;
			}
		}
	}
	for (free = N; free > 0 && out[free] != 0; free--)
		;
	for (int i = 1; i <= p; i++)
		if (out[i] != 0 && in[i] != i)
		{
			printf("%d %d\n", i, free);
			moves++;
			out[in[i]] = free;
			out[free] = 0;
			int j = i;
			while (out[j])
			{
				printf("%d %d\n", out[j], j);
				int t = out[j];
				out[j] = 0;
				j = t;
			}
		}
	if (moves == 0)
	{
		puts("No optimization needed");
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int c = 0; c < t; c++)
	{
		if (c)
		{
			puts("");
		}
		p = 1;
		scanf("%d %d", &N, &K);
		for (int i = 1; i <= N; i++)
		{
			in[i] = out[i] = 0;
		}
		for (int i = 0; i < K; i++)
		{
			scanf("%d", &S);
			for (int j = 0; j < S; j++, p++)
			{
				int t;
				scanf("%d", &t);
				in[t] = p;
				out[p] = t;
			}
		}
		solve();
	}
	return 0;
}
