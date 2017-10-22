#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 30;

bool graph[MAXSIZE][MAXSIZE];
bool visit[MAXSIZE];
int n;

void input()
{
	memset(graph, 0, sizeof(graph));
	memset(visit, 0, sizeof(visit));
	char c1, c2, str[5];
	cin >> c1;
	cin.get();
	n = c1 - 'A' + 1;
	while (cin.getline(str, 5) && strcmp(str, "\0"))
	{
		c1 = str[0];
		c2 = str[1];
		int a = c1 - 'A';
		int b = c2 - 'A';
		graph[a][b] = graph[b][a] = true;
	}
}

void dfs(int node)
{
	if (visit[node])
	{
		return;
	}
	visit[node] = true;
	for (int i = 0; i < n; i++)
		if (!visit[i] && graph[node][i])
		{
			dfs(i);
		}
}

void solve()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (!visit[i])
		{
			cnt++;
			dfs(i);
		}
	cout << cnt << endl;
}

int main()
{
	int numOfCase;
	cin >> numOfCase;
	cin.get();
	for (int kase = 1; kase <= numOfCase; kase++)
	{
		input();
		solve();
		if (kase != numOfCase)
		{
			cout << endl;
		}
	}
	return 0;
}
