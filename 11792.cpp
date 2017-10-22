#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/117/11792.html

// @BEGIN_OF_SOURCE_CODE

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 10010
#define LL unsigned long long

int costs[N];
int freq[N];
vector<int> edges[N];
int n;

int bfs(int at)
{
	for (int i = 0; i < N; i++)
	{
		costs[i] = INT_MAX;
	}
	costs[at] = 0;
	queue<int> q;
	q.push(at);
	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		for (size_t i = 0; i < edges[p].size(); i++)
		{
			if (costs[edges[p].at(i)] == INT_MAX)
			{
				costs[edges[p].at(i)] = costs[p] + 1;
				q.push(edges[p].at(i));
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (freq[i] >= 2)
		{
			ret += costs[i];
		}
	}
	return ret;
}

int main()
{
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		memset(freq, 0, sizeof(freq));
		for (int i = 0; i < N; i++)
		{
			edges[i].clear();
		}
		int s;
		scanf("%d %d", &n, &s);
		for (int i = 0; i < s; i++)
		{
			int curr;
			int prev;
			scanf("%d", &curr);
			freq[curr]++;
			prev = curr;
			while (scanf("%d", &curr) && curr)
			{
				freq[curr]++;
				edges[curr].push_back(prev);
				edges[prev].push_back(curr);
				prev = curr;
			}
		}
		int min_cost = INT_MAX;
		int output;
		for (int i = 1; i <= n; i++)
		{
			if (freq[i] >= 2)
			{
				int c = bfs(i);
				if (c < min_cost)
				{
					min_cost = c;
					output = i;
				}
			}
		}
		printf("Krochanska is in: %d\n", output);
	}
	return 0;
}

// @END_OF_SOURCE_CODE
