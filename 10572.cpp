#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define mp make_pair
#define rep(i, n) for (int i = 0; i < n; ++i)

struct myHash
{
	const static int deep = 65;
	const static int mod = 4001;
	const static int size = 125000;
	int head[deep][mod], nxt[size], cs;
	int s1[size], s2[size], cnt[size];
	int getHash(int x1, int x2)
	{
		return abs(x1 * x2 + x1 + x2) % mod;
	}
	void clear()
	{
		cs = 0, memset(head, -1, sizeof(head));
	}
	int find(int x1, int x2, int f)
	{
		int u = getHash(x1, x2);
		for (int i = head[f][u]; i != -1; i = nxt[i])
			if (s1[i] == x1 && s2[i] == x2)
			{
				return i;
			}
		return -1;
	}
	void insert(int x1, int x2, int f)
	{
		int u = getHash(x1, x2);
		s1[cs] = x1, s2[cs] = x2, cnt[cs] = 0;
		nxt[cs] = head[f][u], head[f][u] = cs++;
	}
	int push(int x1, int x2, int f, int c)
	{
		int t = find(x1, x2, f);
		if (t == -1)
		{
			insert(x1, x2, f);
			t = cs - 1;
		}
		cnt[t] += c;
		return t;
	}
};

const char *base = "o#.";
const int maxn = 10;
int n, m, sg[maxn][maxn];
char g[maxn][maxn];
int state[maxn], st, ed;
PII pre[125000];
int ynn[2][maxn][maxn];
int result, flag, tool[maxn];
myHash dp;

inline int get(int s, int p)
{
	return (s >> p) & 1;
}

void expand(int s)
{
	for (int i = 0; i < m; ++i)
	{
		state[i] = s & 7;
		s >>= 3;
	}
}
int encode()
{
	int s = 0;
	for (int i = m - 1; i >= 0; --i)
	{
		s = (s << 3) | state[i];
	}
	return s;
}

void preWork()
{
	dp.clear();
	int tot = 1 << m, j, k;
	for (int s = 0; s < tot; ++s)
	{
		for (j = 0; j < m; ++j)
		{
			if (sg[0][j] != 2 && sg[0][j] != ((s >> j) & 1))
			{
				break;
			}
		}
		if (j < m)
		{
			continue;
		}
		for (k = 1, j = state[0] = 0; k < m; ++k)
		{
			if (((s >> k) & 1) != ((s >> (k - 1)) & 1))
			{
				++j;
			}
			state[k] = j;
		}
		int t = dp.push(s, encode(), 0, 1);
		pre[t] = mp(-1, -1);
	}
}

bool checkl(int s, int x)
{
	expand(s);
	for (int i = 0; i < m; ++i)
	{
		if (i != x && state[i] == state[x])
		{
			return false;
		}
	}
	return true;
}

void weihu()
{
	memset(tool, -1, sizeof(tool));
	for (int i = 0, j = 0; i < m; ++i)
	{
		if (tool[state[i]] == -1)
		{
			tool[state[i]] = j++;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		state[i] = tool[state[i]];
	}
}

void un(int s, int a, int b)
{
	expand(s);
	b = state[b], a = state[a];
	for (int i = 0; i < m; ++i)
	{
		if (state[i] == b)
		{
			state[i] = a;
		}
	}
}

void create(int s, int a)
{
	expand(s);
	int j = -1;
	for (int i = 0; i < m; ++i)
	{
		if (i != a && state[i] > j)
		{
			j = state[i];
		}
	}
	state[a] = j + 1;
}

bool checkc(int s, int x)
{
	for (int i = 0; i < m; ++i)
	{
		if (i != x && get(s, i) == get(s, x))
		{
			return true;
		}
	}
	return false;
}
int ans[maxn * maxn];
void dfs(int u, int p)
{
	int s1 = dp.s1[p], s2 = dp.s2[p], c = pre[p].second;
	if (c == -1)
	{
		for (int i = 0; i < m; ++i)
		{
			ans[i] = (s1 >> i) & 1;
		}
	}
	else
	{
		ans[u + m - 1] = c;
		dfs(u - 1, pre[p].first);
	}
}

void output(int u, int p, int c)
{
	for (int i = u + 1; i < n * m; ++i)
	{
		ans[i] = c;
	}
	dfs(u, p);
}

int bfs()
{
	preWork();
	int u = 0;
	st = 0, ed = dp.cs;
	for (int i = 0; i < n; ++i)
	{
		for (int j = ((!i) ? (m - 1) : (0)); j < m; ++j)
		{
			if (i == n - 1 && j == m - 1)
			{
				return u;
			}
			for (; st < ed; ++st)
			{
				for (int c = 0; c < 2; ++c)
				{
					int x = i, y = j, s1 = dp.s1[st], s2 = dp.s2[st];
					int x1 = get(s1, j), x2 = get(s1, j + 1), x3 = get(s1, m);
					if (j == m - 1)
					{
						s1 ^= x3 << m;
						x1 = x3 = -1, x2 = get(s1, 0);
						++x, y = -1;
					}
					if (sg[x][y + 1] != 2 && sg[x][y + 1] != c)
					{
						continue;
					}
					if (x == n - 1 && y + 1 == m - 1 && x1 != c && x2 != c && x3 == c)
					{
						continue;
					}
					if (x1 == c && x2 == c && x3 == c)
					{
						continue;
					}
					if (x2 != c && checkl(s2, y + 1))
					{
						if (checkc(s1, y + 1) || ynn[!c][x][y + 1])
						{
							continue;
						}
						if (x < n - 1 || (y + 1) < m - 2)
						{
							continue;
						}
						result += dp.cnt[st];
						if (!flag)
						{
							flag = 1;
							output(u, st, c);
						}
						continue;
					}
					if (x3 != -1)
					{
						s1 ^= (x3 << m);
					}
					s1 ^= (x2 << (y + 1));
					s1 |= (x2 << m) | (c << (y + 1));
					if (x1 == c && x2 == c)
					{
						un(s2, y, y + 1);
					}
					else if (x1 != c && x2 != c)
					{
						create(s2, y + 1);
					}
					else if (x1 == c && x2 != c)
					{
						expand(s2);
						state[y + 1] = state[y];
					}
					else if (x1 != c && x2 == c)
					{
						expand(s2);
					}
					weihu();
					int t = dp.push(s1, encode(), u + 1, dp.cnt[st]);
					pre[t] = mp(st, c);
				}
			}
			++u, ed = dp.cs;
		}
	}
	return -1;
}

void calc(int u)
{
	memset(tool, -1, sizeof(tool));
	for (; st < dp.cs; ++st)
	{
		expand(dp.s2[st]);
		int c = 0;
		for (int i = 0; i < m; ++i)
		{
			if (tool[state[i]] != -st)
			{
				tool[state[i]] = -st, ++c;
			}
		}
		if (c <= 2)
		{
			result += dp.cnt[st];
			if (!flag)
			{
				flag = 1;
				output(u, st, pre[st].second);
			}
		}
	}
}

void solved(int nT)
{
	scanf("%d %d", &n, &m);
	rep(i, n)
	{
		scanf("%s", g[i]);
		rep(j, m) sg[i][j] = find(base, base + 3, g[i][j]) - base;
	}
	int t[2] = {0, 0};
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = m - 1; j >= 0; --j)
		{
			for (int u = 0; u <= 1; ++u)
			{
				ynn[u][i][j] = sg[i][j] == u || t[u];
				t[u] = ynn[u][i][j];
			}
		}
	}
	result = flag = 0;
	calc(bfs());
	printf("%d\n", result);
	if (flag)
	{
		for (int i = 0, c = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j, ++c)
			{
				putchar(ans[c] ? '#' : 'o');
			}
			puts("");
		}
	}
	puts("");
}

int main()
{
	int T = 1;
	scanf("%d", &T);
	for (int nT = 1; nT <= T; ++nT)
	{
		solved(nT);
	}
	return 0;
}
