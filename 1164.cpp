#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define MOD 1000000007

struct node
{
	int x, y, len;
	int mark;
};
queue<node> q;

bool vis[40005][30];
char s[30], hash_[300];
vector<string> v;
int n, m;
int a[] = {0, 0, 1, -1}, b[] = {1, -1, 0, 0};

int f_max(int x, int y)
{
	return x > y ? x : y;
}
int f_min(int x, int y)
{
	return x < y ? x : y;
}
void f_swap(int &x, int &y)
{
	int t;
	t = x, x = y, y = t;
}
int f_abs(int x)
{
	return x > 0 ? x : -x;
}

int bfs(int x, int y, int tx, int ty)
{
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			for (k = 0; k <= 26; k++)
			{
				vis[i * m + j][k] = false;
			}
	while (!q.empty())
	{
		q.pop();
	}
	node top, next;
	top.x = x;
	top.y = y;
	top.len = 0;
	top.mark = hash_[v[x][y]];
	vis[top.x * m + top.y][top.mark] = true;
	q.push(top);
	while (!q.empty())
	{
		top = q.front();
		q.pop();//printf("%d %d\n",top.x,top.y);
		if (top.x == tx && top.y == ty)
		{
			return top.len;
		}
		next.len = top.len + 1;
		for (i = 0; i < 4; i++)
		{
			x = top.x + a[i];
			y = top.y + b[i];
			if (x < 0 || x >= n || y < 0 || y >= m)
			{
				continue;
			}
			if (v[x][y] == 'x')
			{
				continue;
			}
			else if (v[x][y] == 'o')
			{
				if (vis[x * m + y][top.mark])
				{
					continue;
				}
				vis[x * m + y][top.mark] = true;
				next.x = x;
				next.y = y;
				next.mark = top.mark;
				q.push(next);
			}
			else if (hash_[v[x][y]] <= top.mark)
			{
				continue;
			}
			else
			{
				if (vis[x * m + y][hash_[v[x][y]]])
				{
					continue;
				}
				vis[x * m + y][hash_[v[x][y]]] = true;
				next.x = x;
				next.y = y;
				next.mark = hash_[v[x][y]];
				q.push(next);
			}
		}
	}
	return -1;
}

char chr[2];

int main()
{
	int i, j, k, x, y, tx, ty;
	while (~scanf("%s", s))
	{
		for (i = 0; i < 26; i++)
		{
			hash_[s[i]] = i + 1;
		}
		hash_['o'] = 0;
		scanf("%d%d", &m, &n);
		string str, p;
		v.clear();
		for (i = 0; i < n; i++)
		{
			str = "";
			for (j = 0; j < m; j++)
			{
				scanf("%s", chr);
				str += chr[0];
			}
			v.push_back(str);
		}
		scanf("%d%d%d%d", &y, &x, &ty, &tx);
		int ans = bfs(x, y, tx, ty);
		if (ans != -1)
		{
			printf("%d\n", ans);
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
