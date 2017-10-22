#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const double eps = 1e-8;
const double offset = 2000;
const double PI = acos(-1.0);
const int MAXN = 505;
const int MAXM = 62;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000009;

int nxt[MAXN][MAXM], cs;
int fail[MAXN], cnt[MAXN];
char str[MAXN];
double d[105][MAXN];
int id[MAXN];
double p[MAXN];
int K, N, L;

void initNode(int id)
{
	cnt[id] = 0, memset(nxt[id], 0, sizeof(nxt[id]));
}

void clear()
{
	initNode(0);
	cs = 1;
}

int getIndex(char ch)
{
	if (ch >= 'a' && ch <= 'z')
	{
		return ch - 'a';
	}
	if (ch >= 'A' && ch <= 'Z')
	{
		return ch - 'A' + 26;
	}
	return ch - '0' + 52;
}

void insert(char *s)
{
	int p = 0;
	for (; *s; ++s)
	{
		int c = getIndex(*s);
		if (!nxt[p][c])
		{
			initNode(cs);
			nxt[p][c] = cs++;
		}
		p = nxt[p][c];
	}
	cnt[p] = 1;
}

void buildAc()
{
	queue<int> Q;
	Q.push(0);
	fail[0] = 0;
	while (!Q.empty())
	{
		int p = Q.front();
		Q.pop();
		for (int i = 0; i < MAXM; ++i)
		{
			if (nxt[p][i])
			{
				if (!p)
				{
					fail[nxt[p][i]] = 0;
				}
				else
				{
					fail[nxt[p][i]] = nxt[fail[p]][i];
				}
				Q.push(nxt[p][i]);
			}
			else
			{
				if (!p)
				{
					nxt[p][i] = 0;
				}
				else
				{
					nxt[p][i] = nxt[fail[p]][i];
				}
			}
			cnt[nxt[p][i]] |= cnt[fail[nxt[p][i]]];
		}
	}
}

void solved(int cas)
{
	printf("Case #%d: ", cas);
	clear();
	scanf("%d", &K);
	while (K--)
	{
		scanf("%s", str);
		insert(str);
	}
	buildAc();
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s %lf", str, &p[i]);
		id[i] = getIndex(str[0]);
	}
	scanf("%d", &L);
	memset(d, 0, sizeof(d));
	d[0][0] = 1;
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < cs; j++)
		{
			if (cnt[j])
			{
				continue;
			}
			for (int k = 0; k < N; k++)
			{
				d[i + 1][nxt[j][id[k]]] += d[i][j] * p[k];
			}
		}
	}
	double ans = 0;
	for (int i = 0; i < cs; i++)
		if (!cnt[i])
		{
			ans += d[L][i];
		}
	printf("%.6lf", ans);
	puts("");
}

int main()
{
	int T = 1;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		solved(i);
	}
	return 0;
}
