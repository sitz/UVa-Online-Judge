#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;
const int MAX_K = 5;
const int MAX_L = 10;

bool is_ok[MAX_N];
char names[MAX_N][MAX_L + 1];
int K, N, cnts[MAX_N], rs[MAX_N][MAX_K];

namespace union_find
{
	const int MAX_UF = MAX_N;

	int pars[MAX_UF];
	int ranks[MAX_UF];

	void init_uf(int n)
	{
		for (int i = 0; i < n; i++)
		{
			pars[i] = i;
			ranks[i] = 0;
		}
	}

	int get_root(int x)
	{
		if (pars[x] == x)
		{
			return x;
		}
		else
		{
			return pars[x] = get_root(pars[x]);
		}
	}

	void merge(int x, int y)
	{
		x = get_root(x);
		y = get_root(y);
		if (x == y)
		{
			return;
		}
		if (ranks[x] < ranks[y])
		{
			pars[x] = y;
		}
		else if (ranks[y] < ranks[x])
		{
			pars[y] = x;
		}
		else
		{
			pars[x] = y;
			ranks[y]++;
		}
	}

	bool is_same_(int x, int y)
	{
		return get_root(x) == get_root(y);
	}
}

using union_find::init_uf;
using union_find::get_root;
using union_find::merge;
using union_find::is_same_;

void init()
{
	memset(is_ok, true, sizeof(is_ok));
	memset(cnts, 0, sizeof(cnts));
	for (int i = 0; i < N; i++)
	{
		scanf(" %s ", names[i]);
		for (int j = 0; j < K; j++)
		{
			scanf("%d ", rs[i] + j);
			rs[i][j]--;
		}
	}
}

void solve()
{
	init_uf(N);
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (!strcmp(names[i], names[j]))
			{
				merge(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			for (int k = j + 1; k < K; k++)
			{
				if (rs[i][j] == rs[i][k])
				{
					is_ok[rs[i][j]] = false;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			if (is_same_(i, rs[i][j]))
			{
				is_ok[rs[i][j]] = false;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			if (!is_same_(i, rs[i][j]))
			{
				cnts[rs[i][j]]++;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (cnts[i] != K)
		{
			is_ok[i] = false;
		}
	}
	int cnt = count(is_ok, is_ok + N, false);
	if (cnt == 1)
	{
		printf("1 PROBLEM FOUND\n");
	}
	else if (cnt > 0)
	{
		printf("%d PROBLEMS FOUND\n", cnt);
	}
	else
	{
		printf("NO PROBLEMS FOUND\n");
	}
}

int main()
{
	while (scanf("%d%d ", &K, &N), N)
	{
		init();
		solve();
	}
	return 0;
}
