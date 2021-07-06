#include <bits/stdc++.h>

using namespace std;

struct Node
{
	char suffix[2005];
	int len, count;
};
vector<Node> Hash[2001];
queue<Node> Q;
int n;
char words[1000][2000], x[2000], y[2000];
int len[1000];
int compare(char *a, char *b)
{
	int len;
	for (len = 0; *a && *b && (*a++ == *b++); len++)
		;
	return len;
}
int BFS()
{
	int l = compare(x, y), lx = strlen(x), ly = strlen(y);
	Node u, v;
	if (l == 0)
	{
		return -1;
	}
	if (l == lx && l == ly)
	{
		return 0;
	}
	if (l != lx)
	{
		strcpy(u.suffix, x + l);
	}
	if (l != ly)
	{
		strcpy(u.suffix, y + l);
	}
	u.len = strlen(u.suffix);
	u.count = 0;
	Q.push(u);
	while (Q.size() > 0)
	{
		u = Q.front();
		Q.pop();
		for (int i = 0; i < n; i++)
		{
			int s = compare(u.suffix, words[i]);
			if (s != len[i] && s != u.len)
			{
				continue;
			}
			if (s == len[i] && s == u.len)
			{
				return u.count + 1;
			}
			if (u.len > len[i])
			{
				strcpy(v.suffix, u.suffix + s);
				v.len = u.len - s;
			}
			else
			{
				strcpy(v.suffix, words[i] + s);
				v.len = len[i] - s;
			}
			if (v.len == u.len && strcmp(v.suffix, u.suffix) == 0)
			{
				continue;
			}
			bool found = false;
			for (int i = 0; i < Hash[v.len].size() && !found; i++)
				if (strcmp(Hash[v.len][i].suffix, v.suffix) == 0)
				{
					found = true;
				}
			if (found)
			{
				continue;
			}
			Hash[v.len].push_back(v);
			v.count = u.count + 1;
			Q.push(v);
		}
	}
	return -1;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		for (int i = 0; i <= 2000; i++)
		{
			Hash[i].clear();
		}
		scanf("%s %s", x, y);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", words[i]);
			len[i] = strlen(words[i]);
		}
		int ans = BFS();
		printf("%d\n", ans);
	}
}
