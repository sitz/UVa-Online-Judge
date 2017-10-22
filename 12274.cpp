#include <bits/stdc++.h>

using namespace std;

const int MAXN = 21;

int dist[1 << MAXN], shoot[1 << MAXN], prev_[1 << MAXN];

int main()
{
	int n, m;
	while (scanf("%i%i\n", &n, &m), n)
	{
		int edge[n];
		fill(&edge[0], &edge[n], 0);
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			scanf("%i%i", &a, &b);
			edge[a] |= 1 << b;
			edge[b] |= 1 << a;
		}
		deque<int> q;
		fill(&dist[0], &dist[1 << n], -1);
		q.push_back((1 << n) - 1);
		dist[(1 << n) - 1] = 0;
		while (dist[0] < 0 && !q.empty())
		{
			int s = q.front(), d = dist[s];
			q.pop_front();
			int prefix[n + 1], suffix[n + 1]; // or[0..i), or[i..n)
			prefix[0] = suffix[n] = 0;
			for (int i = 0; i < n; ++i)
			{
				if (s & (1 << i))
				{
					prefix[i + 1] = prefix[i] | edge[i];
				}
				else
				{
					prefix[i + 1] = prefix[i];
				}
			}
			for (int i = n - 1; i >= 0; --i)
			{
				if (s & (1 << i))
				{
					suffix[i] = suffix[i + 1] | edge[i];
				}
				else
				{
					suffix[i] = suffix[i + 1];
				}
			}
			for (int i = 0; i < n; ++i)
			{
				int t = prefix[i] | suffix[i + 1];
				if (dist[t] < 0)
				{
					dist[t] = d + 1;
					shoot[t] = i;
					prev_[t] = s;
					q.push_back(t);
				}
			}
		}
		if (dist[0] < 0)
		{
			puts("Impossible");
		}
		else
		{
			printf("%i:", dist[0]);
			vector<int> path;
			int s = 0;
			while (s != ((1 << n) - 1))
			{
				path.push_back(shoot[s]);
				s = prev_[s];
			}
			for (int i = path.size() - 1; i >= 0; --i)
			{
				printf(" %i", path[i]);
			}
			puts("");
		}
	}
	return 0;
}
