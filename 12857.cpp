#include <bits/stdc++.h>

using namespace std;

const int MAX = (int)(1e9);

int n;
string s[200];

template <int N, int M>
struct Trie
{
	int at, nxt[N][M], cnt[N], f[N][201];
	void init()
	{
		memset(f, 0xff, sizeof(f));
		at = -1;
		add();
	}
	int add()
	{
		at++;
		cnt[at] = 0;
		memset(nxt[at], 0xff, sizeof(nxt[at]));
		return at;
	}
	void insert(string &word)
	{
		int u = 0;
		for (int i = 0; i < word.size(); ++i)
		{
			cnt[u]++;
			int &v = nxt[u][word[i] - 'A'];
			if (v == -1)
			{
				v = add();
			}
			u = v;
		}
		cnt[u]++;
	}
	void dfs(int u, int d)
	{
		if (cnt[u] == 1)
		{
			f[u][0] = f[u][1] = 0;
			return;
		}
		for (int i = 0; i < M; ++i)
		{
			int v = nxt[u][i];
			if (v == -1)
			{
				continue;
			}
			dfs(v, d + 1);
		}
		/*
		 * 0: u = 0;
		 * 1: l = 1;
		 * 2: r = 1;
		 * 3: other;
		 * */
		int g[2][201][4], add[4];
		int x = 0, y = 1;
		for (int i = 0; i <= cnt[u]; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				g[x][i][j] = (i == 0 ? 0 : MAX);
			}
		}
		for (int i = 0; i < M; ++i)
		{
			int v = nxt[u][i];
			if (v == -1)
			{
				continue;
			}
			for (int j = 0; j <= cnt[u]; ++j)
			{
				for (int k = 0; k < 4; ++k)
				{
					g[y][j][k] = MAX;
				}
			}
			for (int j = 0; j <= cnt[u]; ++j)
			{
				for (int k = 0; k <= cnt[v] && j + k <= cnt[u]; ++k)
				{
					memset(add, 0x00, sizeof(add));
					if (k == 1)
					{
						if (u == 0)
						{
							add[0] += d;
						}
						add[3] += d;
						if (cnt[u] != 2)
						{
							add[2] += d;
						}
					}
					if (cnt[v] - k == 1)
					{
						if (u == 0)
						{
							add[0] += d;
						}
						add[3] += d;
						if (cnt[u] != 2)
						{
							add[1] += d;
						}
					}
					for (int p = 0; p < 4; ++p)
					{
						g[y][j + k][p] = min(g[y][j + k][p], g[x][j][p] + f[v][k] + add[p]);
					}
				}
			}
			swap(x, y);
		}
		for (int i = 0; i <= cnt[u]; ++i)
		{
			if (u == 0)
			{
				f[u][i] = g[x][i][0];
			}
			else
			{
				if (i == 1)
				{
					f[u][i] = g[x][i][1];
				}
				else if (i == cnt[u] - 1)
				{
					f[u][i] = g[x][i][2];
				}
				else
				{
					f[u][i] = g[x][i][3];
				}
			}
		}
	}
};

Trie<200 * 18 + 1, 26> trie;

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n)
	{
		trie.init();
		for (int i = 0; i < 2 * n; ++i)
		{
			cin >> s[i];
			trie.insert(s[i]);
		}
		trie.dfs(0, 1);
		cout << trie.f[0][n] * n << endl;
	}
	return 0;
}
