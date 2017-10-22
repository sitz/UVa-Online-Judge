#include <bits/stdc++.h>

using namespace std;

#define pb push_back
const int N = 65537;

queue<int> qu;
bool vis[N];
int pre[N], cnt[N];
char val[N], s[N], str[N];

int n;
int anslen;

bool bfs(int len)
{
	memset(vis, false, sizeof(vis));
	while (!qu.empty())
	{
		qu.pop();
	}
	for (int i = 0; i < len; i++)
		if (s[i] != '0')
		{
			int cur = (s[i] - '0') % n;
			if (!vis[cur])
			{
				qu.push(cur);
				val[cur] = s[i];
				cnt[cur] = 1;
				pre[cur] = -1;
				vis[cur] = true;
			}
		}
	if (vis[0])
	{
		return true;
	}
	while (!qu.empty())
	{
		int cur = qu.front();
		qu.pop();
		if (anslen && cnt[cur] >= anslen)
		{
			return false;
		}
		for (int i = 0; i < len; i++)
		{
			int to = (cur * 10 + s[i] - '0') % n;
			if (!vis[to])
			{
				pre[to] = cur;
				vis[to] = true;
				val[to] = s[i];
				cnt[to] = cnt[cur] + 1;
				if (to == 0)
				{
					return true;
				}
				qu.push(to);
			}
		}
	}
	return false;
}

bool compare()
{
	for (int i = 0; i < anslen; i++)
	{
		if (s[i] < str[i])
		{
			return true;
		}
		if (s[i] > str[i])
		{
			return false;
		}
	}
	return false;
}

void Get()
{
	int cur = 0;
	for (int i = cnt[0] - 1; i >= 0; i--)
	{
		s[i] = val[cur];
		cur = pre[cur];
	}
}

int main()
{
	while (scanf("%d", &n) == 1 && n)
	{
		anslen = 0;
		for (int i = 1; i < 10; i++)
		{
			s[0] = '0' + i;
			if (bfs(1))
			{
				Get();
				if (!anslen || anslen > cnt[0] || (anslen == cnt[0] && compare()))
				{
					anslen = cnt[0];
					strcpy(str, s);
				}
			}
		}
		if (anslen)
		{
			for (int i = 0; i < anslen; i++)
			{
				printf("%c", str[i]);
			}
			puts("");
			continue;
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = i + 1; j < 10; j++)
			{
				s[0] = i + '0';
				s[1] = j + '0';
				if (bfs(2))
				{
					Get();
					if (!anslen || anslen > cnt[0] || (anslen == cnt[0] && compare()))
					{
						anslen = cnt[0];
						strcpy(str, s);
					}
				}
			}
		}
		for (int i = 0; i < anslen; i++)
		{
			printf("%c", str[i]);
		}
		puts("");
	}
	return 0;
}
