#include <bits/stdc++.h>

using namespace std;

const int MAXN = 32767;

class DisjointSet
{
public:
	int parent[MAXN], weight[MAXN];
	int findp(int x)
	{
		return parent[x] == x ? x : parent[x] = findp(parent[x]);
	}
	int joint(int tx, int ty)
	{
		int x = findp(tx), y = findp(ty);
		if (x == y)
			return 0;
		if (weight[x] > weight[y])
			weight[x] += weight[y], parent[y] = x;
		else
			weight[y] += weight[x], parent[x] = y;
		return 1;
	}
	void init(int n)
	{
		for (int i = 0; i <= n; i++)
			parent[i] = i, weight[i] = 1;
	}
} D;

int N, C;
vector<int> AG[MAXN];
int deg[MAXN] = {};
int isValid(int ban)
{
	int valid = 1, one_comp = 1;
	D.init(C);
	for (int i = 0; i < N; i++)
	{
		if (i == ban)
			continue;
		if (AG[i].size() == 2)
			D.joint(AG[i][0], AG[i][1]);
	}
	for (int i = 0; i < N; i++)
	{
		int x, y;
		if (AG[i].size() == 2)
		{
			x = AG[i][0], y = AG[i][1];
		}
		else
		{
			x = AG[i][0], y = AG[i][0];
		}
		if (D.findp(x) != D.findp(AG[0][0]) || D.findp(y) != D.findp(AG[0][0]))
			one_comp = 0;
	}
	if (!one_comp)
	{
		int u = AG[ban][0];
		int v = AG[ban][1];
		if (!(deg[u] == 1 || deg[v] == 1))
			valid = 0;
	}
	return valid;
}
int main()
{
	int line = 0, cases = 0;
	while (scanf("%d %d", &N, &C) == 2)
	{
		line++;
		D.init(C);
		for (int i = 0; i < N; i++)
			AG[i].clear();
		for (int i = 0; i < C; i++)
			deg[i] = 0;

		int x, n;
		for (int i = 0; i < C; i++)
		{
			scanf("%d", &n);
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &x);
				assert(x < N && x >= 0);
				AG[x].push_back(i);
			}
			line++;
		}

		vector<int> G[MAXN];
		for (int i = 0; i < N; i++)
		{
			if (AG[i].size() == 2)
			{
				D.joint(AG[i][0], AG[i][1]);
				deg[AG[i][0]]++;
				deg[AG[i][1]]++;
				G[AG[i][0]].push_back(i);
				G[AG[i][1]].push_back(i);
				//				printf("%d %d --\n", AG[i][0], AG[i][1]);
			}
			else
			{
				assert(AG[i].size() == 1);
				//				printf("%d %d --\n", AG[i][0], AG[i][0]);
				deg[AG[i][0]]++;
				deg[AG[i][0]]++;
				G[AG[i][0]].push_back(i);
			}
		}

		int oddcnt = 0;
		int cand[3] = {INT_MAX, INT_MAX, INT_MAX};
		for (int i = 0; i < C; i++)
		{
			if (deg[i] & 1)
			{
				oddcnt++;
				for (int j = 0; j < G[i].size(); j++)
				{
					x = G[i][j];
					if (x == cand[0] || x == cand[1] || x == cand[2])
						continue;
					if (x < cand[2])
						cand[2] = x;
					if (cand[2] < cand[1])
						swap(cand[2], cand[1]);
					if (cand[1] < cand[0])
						swap(cand[0], cand[1]);
				}
			}
		}

		int valid = 1;
		for (int i = 0; i < N; i++)
		{
			int x, y;
			if (AG[i].size() == 2)
			{
				x = AG[i][0], y = AG[i][1];
			}
			else
			{
				x = AG[i][0], y = AG[i][0];
			}
			if (D.findp(x) != D.findp(AG[0][0]) || D.findp(y) != D.findp(AG[0][0]))
				valid = 0;
		}
		if (valid == 0 || oddcnt > 2)
		{
			puts("-1");
		}
		else if (oddcnt == 0)
		{
			puts("0");
		}
		else
		{
			if (isValid(cand[0]))
				printf("%d\n", cand[0]);
			else if (isValid(cand[1]))
				printf("%d\n", cand[1]);
			else
				printf("%d\n", cand[2]);
		}
	}
	return 0;
}
