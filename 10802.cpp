#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

bool cango[100][100];
int visited[100];
int path[100];
vector<int> Edge[100];

void make_edge(int n)
{
	rep(k, n)
			rep(i, n)
					rep(j, n) cango[i][j] = (cango[i][j] | (cango[i][k] & cango[k][j]));
}

bool solve(int now, int n, int tar, int p, int prev)
{
	path[p++] = now;
	if (now == tar)
	{
		rep(i, p)
		{
			if (i)
			{
				cout << ' ';
			}
			cout << path[i];
		}
		cout << endl;
		return true;
	}
	//  if ( cango[now][tar] == false)return false;
	visited[now]++;
	rep(i, Edge[now].size())
	{
		int next = Edge[now][i];
		if (next == prev)
		{
			continue;
		}
		if (visited[next] > 0)//if find finite loop
		{
			/*
			if(next > tar){
			if ( visited[i]==2 )continue;
			}
			else {
			puts("No drive.");
			visited[now]--;
			return true;
			}
			*/
			if (visited[i] == 2)
			{
				puts("No drive.");
				visited[now]--;
				return true;
			}
		}
		if (solve(next, n, tar, p, now))
		{
			visited[now]--;
			return true;
		}
	}
	visited[now]--;
	return false;
}

main()
{
	int te, tc = 1;
	cin >> te;
	while (te--)
	{
		int n, m, s;
		cin >> n >> m >> s;
		rep(i, n)
		{
			rep(j, n) cango[i][j] = false;
			cango[i][i] = true;
			Edge[i].clear();
			visited[i] = 0;
		}
		rep(i, m)
		{
			int f, t;
			cin >> f >> t;
			cango[f][t] = cango[t][f] = true;
			Edge[f].push_back(t);
			Edge[t].push_back(f);
		}
		rep(i, n) sort(Edge[i].begin(), Edge[i].end());
		make_edge(n);
		cout << "Case #" << tc++ << ":" << endl;
		rep(i, n)
		{
			if (cango[s][i] == false || solve(s, n, i, 0, -1) == false)
			{
				puts("No drive.");
			}
		}
		puts("");
	}
	return false;
}
