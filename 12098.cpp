#include <bits/stdc++.h>

using namespace std;

/**
	Brute-force
	Try all ways of partitioning 4 train lines together
	then compute cost of a min steiner tree on the partition

	to do so, on a set of k nodes:
	- select up to k-2 of remaining nodes
	- compute MST on up to 2k-2 nodes
	- ~(n-k choose k-2) ways of choosing k-2 nodes ≤ 22 C 6 ~= 75k
*/

const int inf = 1 << 26;

int msts, n, dist[40][40], cityset[40], inset[40];
pair<int, int> routes[4];

// Prim MST
int mst(int cities)
{
	++msts;
	int dst[40], used[40], res = 0;
	for (int i = 0; i < cities; ++i)
	{
		dst[i] = inf, used[i] = false;
	}
	dst[0] = 0;
	for (int i = 0; i < cities; ++i)
	{
		int bj = -1;
		for (int j = 0; j < cities; ++j)
			if (!used[j] && (bj == -1 || dst[j] < dst[bj]))
			{
				bj = j;
			}
		used[bj] = true;
		res += dst[bj];
		for (int j = 0; j < cities; ++j)
		{
			dst[j] = min(dst[j], dist[cityset[bj]][cityset[j]]);
		}
	}
	return res;
}

// recursively choose internal nodes in the steiner tree
int steinertree(int internal, int from, int *out)
{
	if (internal <= 0)
	{
		return mst(out - cityset);
	}
	int res = mst(out - cityset);
	for (int i = from; i < n; ++i)
	{
		if (inset[i])
		{
			continue;
		}
		*out = i;
		res = min(res, steinertree(internal - 1, i + 1, out + 1));
	}
	return res;
}

// Compute a steiner tree on the set of routes
// indicated by the four lowest bits of left
int steinerforest(int left)
{
	if (!left)
	{
		return 0;
	}
	int m = 0x10, res = 1 << 28;
	while (!(left & m))
	{
		m >>= 1;
	}
	assert(m < 0x10);
	for (int s = 0; s < m; ++s)
	{
		if ((left | s) == left)
		{
			int size = 0;
			memset(inset, false, sizeof(inset));
			for (int i = 0; i < 4; ++i)
				if ((m | s) & (1 << i))
				{
					if (!inset[routes[i].first])
					{
						inset[cityset[size++] = routes[i].first] = true;
					}
					if (!inset[routes[i].second])
					{
						inset[cityset[size++] = routes[i].second] = true;
					}
				}
			int cost = steinertree(size - 2, 0, cityset + size);
			res = min(res, cost + steinerforest(left & ~(m | s)));
		}
	}
	return res;
}

int main()
{
	int m;
	while (scanf("%d%d", &n, &m) == 2 && n)
	{
		map<string, int> id;
		char name1[50], name2[50];
		memset(dist, 0x1f, sizeof(dist));
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", name1);
			id[name1] = i;
			dist[i][i] = 0;
		}
		for (int i = 0; i < m; ++i)
		{
			int d;
			scanf("%s%s%d", name1, name2, &d);
			int a = id[name1], b = id[name2];
			dist[a][b] = min(dist[a][b], d);
			dist[b][a] = min(dist[b][a], d);
		}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
		for (int i = 0; i < 4; ++i)
		{
			scanf("%s%s", name1, name2);
			routes[i].first = id[name1];
			routes[i].second = id[name2];
		}
		//		fprintf(stderr, "go %d %d\n", n, m);
		int res = steinerforest(0xF);
		printf("%d\n", res);
		//		fprintf(stderr, "%d msts needed to be computed\n", msts);
		msts = 0;
	}
	return 0;
}
