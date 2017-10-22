#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/113/11377.html
// Runtime: 0.076s
// Tag: BFS, shortest path

#define INF 2147483647
#define N 2000 + 5

bool isAirport[N];
vector<int> matrix[N];
int hop[N];

int main()
{
	int testCase;
	scanf("%d", &testCase);
	int cases = 0;
	while (testCase--)
	{
		memset(isAirport, false, sizeof isAirport);
		for (int i = 0; i < N; i++)
		{
			matrix[i].clear();
		}
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < k; i++)
		{
			int inp;
			scanf("%d", &inp);
			isAirport[inp] = true;
		}
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			matrix[a].push_back(b);
			matrix[b].push_back(a);
		}
		queue<int> q;
		int query;
		scanf("%d", &query);
		printf("Case %d:\n", ++cases);
		while (query--)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			if (a == b)
			{
				printf("0\n");
				continue;
			}
			for (int i = 0; i < N; i++)
			{
				hop[i] = INF;
			}
			q.push(a);
			if (isAirport[a])
			{
				hop[a] = 0;
			}
			else
			{
				hop[a] = 1;
			}
			while (!q.empty())
			{
				int p = q.front();
				q.pop();
				for (size_t i = 0; i < matrix[p].size(); i++)
				{
					int tmp = isAirport[matrix[p][i]] ? hop[p] : hop[p] + 1;
					if (hop[matrix[p][i]] > tmp)
					{
						hop[matrix[p][i]] = tmp;
						q.push(matrix[p][i]);
					}
				}
			}
			if (hop[b] == INF)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", hop[b]);
			}
		}
		printf("\n");
	}
	return 0;
}

/*
 1
 3 1 1
 2
 1 3
 1
 1 3
 *
 Case 1:
 2

 */
