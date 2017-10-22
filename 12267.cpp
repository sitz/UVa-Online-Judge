#include <bits/stdc++.h>

using namespace std;

/* ***********************************************
Author        :kuangbin
Created Time  :2014/6/14 10:49:42
File Name     :E:\2014ACM\åºåèµç»ä¹ \2010\2010NWERC\I.cpp
************************************************ */

pair<int, int> p[100010];
int Index[100010];
int tmpIndex[100010];
int ans[100010];
vector<int> vec[100010];
int color[100010];
bool dfs(int u, int col)
{
	color[u] = col;
	int sz = vec[u].size();
	for (int i = 0; i < sz; i++)
	{
		int v = vec[u][i];
		if (color[v] != -1)
		{
			if (color[v] == col)
			{
				return false;
			}
			continue;
		}
		if (!dfs(v, !col))
		{
			return false;
		}
	}
	return true;
}

struct Node
{
	int val;
	int id;
} node[100010];
bool cmp(Node a, Node b)
{
	return a.val < b.val;
}
void solve(int n, int l, int r)
{
	if (n == 0)
	{
		return;
	}
	if (l >= r)
	{
		return;
	}
	for (int i = l; i < r; i++)
	{
		vec[i].clear();
	}
	int cnt = 0;
	for (int i = l; i < r; i++)
	{
		node[cnt].val = (p[Index[i]].first & ((1 << (n - 1)) - 1));
		node[cnt].id = i;
		cnt++;
	}
	sort(node, node + cnt, cmp);
	for (int i = 1; i < cnt; i++)
		if (node[i - 1].val == node[i].val)
		{
			vec[node[i - 1].id].push_back(node[i].id);
			vec[node[i].id].push_back(node[i - 1].id);
		}
	cnt = 0;
	for (int i = l; i < r; i++)
	{
		node[cnt].val = (p[Index[i]].second & ((1 << (n - 1)) - 1));
		node[cnt].id = i;
		cnt++;
	}
	sort(node, node + cnt, cmp);
	for (int i = 1; i < cnt; i++)
		if (node[i - 1].val == node[i].val)
		{
			vec[node[i - 1].id].push_back(node[i].id);
			vec[node[i].id].push_back(node[i - 1].id);
		}
	for (int i = l; i < r; i++)
	{
		color[i] = -1;
	}
	for (int i = l; i < r; i++)
		if (color[i] == -1)
		{
			dfs(i, 0);
		}
	int cnt1 = l;
	for (int i = l; i < r; i++)
		if (color[i] == 0)
		{
			tmpIndex[cnt1++] = Index[i];
		}
	int cnt2 = cnt1;
	for (int i = l; i < r; i++)
		if (color[i] == 1)
		{
			tmpIndex[cnt2++] = Index[i];
			ans[Index[i]] += (1 << (n - 1));
		}
	for (int i = l; i < r; i++)
	{
		Index[i] = tmpIndex[i];
	}
	solve(n - 1, l, cnt1);
	solve(n - 1, cnt1, r);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n, m;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
		{
			Index[i] = i;
			scanf("%d%d", &p[i].first, &p[i].second);
		}
		memset(ans, 0, sizeof(ans));
		solve(n, 0, m);
		for (int i = 0; i < m; i++)
		{
			printf("%d", ans[i]);
			if (i < m - 1)
			{
				printf(" ");
			}
			else
			{
				printf("\n");
			}
		}
	}
	return 0;
}
