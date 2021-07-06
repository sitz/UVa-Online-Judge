#include <bits/stdc++.h>

using namespace std;

const int MOD = 20071027;
const int MAXN = 500010;

struct Trie {int ch[MAXN][30], val[MAXN], sz;} trie;

char str[MAXN];
int dp[MAXN], start, num;

int GetPos(char c)
{
	return c - 'a';
}
void insert(char *s)
{
	int u = 0, len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		int c = GetPos(s[i]);
		if (!trie.ch[u][c])
		{
			memset(trie.ch[trie.sz], 0, sizeof(trie.ch[trie.sz]));
			trie.val[trie.sz] = 0;
			trie.ch[u][c] = trie.sz++;
		}
		u = trie.ch[u][c];
	}
	trie.val[u] = 1;
}
void find(char *str)
{
	int u = 0;
	for (int i = 0; str[i]; i++)
	{
		int c = GetPos(str[i]);
		if (trie.ch[u][c])
		{
			u = trie.ch[u][c];
			if (trie.val[u])
			{
				num = (num + dp[start + i + 1]) % MOD;
			}
		}
		else
		{
			return;
		}
	}
}

int main()
{
	int t = 1;
	while (scanf("%s", str) != EOF)
	{
		memset(trie.ch[0], 0, sizeof(trie.ch[0]));
		trie.sz = 1;
		int s, ans = 0;
		scanf("%d", &s);
		char ita[3001];
		while (s--)
		{
			scanf("%s", ita);
			insert(ita);
		}
		int len = strlen(str);
		dp[len] = 1;
		for (int i = len - 1; i >= 0; i--)
		{
			num = 0;
			start = i;
			find(&str[i]);
			dp[i] = num;
		}
		printf("Case %d: %d\n", t++, dp[0]);
	}
	return 0;
}
