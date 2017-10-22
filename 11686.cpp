#include <bits/stdc++.h>

using namespace std;

#define FOREACH(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)

const int NN = 1000032;

int dep[NN], q[NN], h, t, M, N;
vector<int> adj[NN];

void toposort()
{
	while (h != t)
	{
		int x = q[h++];
		FOREACH(adj[x], itr)
		{
			if (--dep[(*itr)] == 0)
			{
				q[t++] = (*itr);
			}
		}
	}
}

void fastint(register int *n)
{
	register char c;
	*n = 0;
	while (!isdigit(c = getc(stdin)))
		;
	do
	{
		(*n) = (*n) * 10 + (c - '0');
	} while (isdigit(c = getc(stdin)));
}

int main()
{
	int a, b;
	while (scanf("%d%d", &N, &M) == 2 && N)
	{
		h = t = 0;
		for (int i = 0; i < N; ++i)
		{
			adj[i].clear();
			dep[i] = 0;
		}
		for (int i = 0; i < M; ++i)
		{
			fastint(&a);
			fastint(&b);
			adj[--a].push_back(--b);
			dep[b]++;
		}
		for (int i = 0; i < N; ++i)
		{
			if (dep[i] == 0)
			{
				q[t++] = i;
			}
		}
		toposort();
		if (t != N)
		{
			printf("IMPOSSIBLE\n");
		}
		else
		{
			for (int i = 0; i < t; ++i)
			{
				printf("%d\n", q[i] + 1);
			}
		}
	}
	return 0;
}
