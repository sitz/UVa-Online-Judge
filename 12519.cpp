#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
#define pi acos(-1.0)
#define inf 2147483647
#define ll long long int
#define EPS 1e-9
#define mod 100000007
#define sf scanf
#define pf printf
#define pb push_back

struct box
{
	int to;
	int time;
	box(int c, int nm)
	{
		to = c;
		time = nm;
	}
};

vector<box> vec[101];
long vis[101];

bool bfs(int node)
{
	bool flag = 0;
	queue<int> que;
	que.push(node);
	vis[node] = 0;
	while (!que.empty())
	{
		int u = que.front();
		que.pop();
		for (int i = 0; i < vec[u].size(); i++)
		{
			if (vis[vec[u][i].to] == -inf)
			{
				vis[vec[u][i].to] = vis[u] + vec[u][i].time;
				que.push(vec[u][i].to);
			}
			else if (vis[vec[u][i].to] != vis[u] + vec[u][i].time)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			break;
		}
	}
	return flag;
}

int main()
{
	int n, b;
	while (scanf("%d %d", &n, &b) == 2 && (n || b))
	{
		for (int i = 0; i < n; i++)
		{
			vec[i].clear();
		}
		//memset(vis,-1,sizeof(vis));
		for (int i = 0; i < n; i++)
		{
			vis[i] = -inf;
		}
		int c, d, t;
		for (int i = 0; i < b; i++)
		{
			scanf("%d %d %d", &c, &d, &t);
			vec[c - 1].push_back(box(d - 1, t));
			vec[d - 1].push_back(box(c - 1, -t));
		}
		if (bfs(0))
		{
			printf("Y\n");
		}
		else
		{
			printf("N\n");
		}
	}
	return 0;
}
