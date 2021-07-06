#include <bits/stdc++.h>

using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")

#define ll long long
#define ull unsigned long long
#define eps 1e-8
#define NMAX 201000
#define MOD 1000000007
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define PI acos(-1)
template <class T>
inline void scan_d(T &ret)
{
	char c;
	int flag = 0;
	ret = 0;
	while (((c = getchar()) < '0' || c > '9') && c != '-')
		;
	if (c == '-')
	{
		flag = 1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		ret = ret * 10 + (c - '0'), c = getchar();
	}
	if (flag)
	{
		ret = -ret;
	}
}
int comp[17][2][17][2], len[17];
char s[17][2][105];
bool can[17];
int dp[(1 << 16) + 10][17][2], n;

int find_overlap(char *a, char *b, int len1, int len2)
{
	int p;
	if (len1 > len2)
	{
		p = len1 - len2 + 1;
	}
	else
	{
		p = 1;
	}
	for (int i = p; i < len1; i++)
	{
		if (strncmp(a + i, b, len1 - i) == 0)
		{
			return len1 - i;
		}
	}
	return 0;
}

void init()
{
	char tmp[17][2][105];
	int tlen[17];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", tmp[i][0]);
		int m = strlen(tmp[i][0]);
		strcpy(tmp[i][1], tmp[i][0]);
		reverse(tmp[i][1], tmp[i][1] + m);
		//        reverse_copy(tmp[i][0],tmp[i][0]+m,tmp[i][1]);
		//        cout<<tmp[i][1]<<endl;
		tlen[i] = m;
	}
	memset(can, 0, sizeof(can));
	for (int i = 0; i < n; i++)//remove strings
	{
		for (int j = 0; j < n; j++)
			if (j != i)
			{
				if (tlen[j] < tlen[i])
				{
					continue;
				}
				bool ok = 0;
				for (int k = 0; k <= tlen[j] - tlen[i]; k++)
				{
					if (strncmp(tmp[i][0], tmp[j][0] + k, tlen[i]) == 0)
					{
						ok = 1;
						if (k == 0 && tlen[i] == tlen[j] && i > j)
						{
							ok = 0;
						}
						break;
					}
					if (strncmp(tmp[i][0], tmp[j][1] + k, tlen[i]) == 0)
					{
						ok = 1;
						if (k == 0 && tlen[i] == tlen[j] && i > j)
						{
							ok = 0;
						}
						break;
					}
				}
				if (ok)
				{
					can[i] = 1;
					break;
				}
			}
	}
	int nct = 0;
	for (int i = 0; i < n; i++)
		if (!can[i])
		{
			memcpy(s[nct], tmp[i], sizeof(tmp[i]));
			len[nct++] = tlen[i];
		}
	n = nct;
	for (int i = 0; i < n; i++)
		for (int x = 0; x < 2; x++)
			for (int j = 0; j < n; j++)
				for (int y = 0; y < 2; y++)
				{
					comp[i][x][j][y] = find_overlap(s[i][x], s[j][y], len[i], len[j]);
				}
}

int main()
{
#ifdef GLQ
	freopen("input.txt", "r", stdin);
//    freopen("o3.txt","w",stdout);
#endif
	while (~scanf("%d", &n) && n)
	{
		init();
		memset(dp, -1, sizeof(dp));
		dp[1][0][0] = len[0];
		for (int s = 1; s < (1 << n); s++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < 2; j++)
					if (dp[s][i][j] != -1)
						for (int k = 0; k < n; k++)
							if (!((1 << k) & s))
							{
								int &d = dp[s | (1 << k)][k][0], &d2 = dp[s | (1 << k)][k][1];
								if (d == -1 || d > dp[s][i][j] + len[k] - comp[i][j][k][0])
								{
									d = dp[s][i][j] + len[k] - comp[i][j][k][0];
								}
								if (d2 == -1 || d2 > dp[s][i][j] + len[k] - comp[i][j][k][1])
								{
									d2 = dp[s][i][j] + len[k] - comp[i][j][k][1];
								}
							}
		int ans = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 2; j++)
				if (dp[(1 << n) - 1][i][j] > 0)
				{
					if (ans == -1 || ans > dp[(1 << n) - 1][i][j] - comp[i][j][0][0])
					{
						ans = dp[(1 << n) - 1][i][j] - comp[i][j][0][0];
					}
				}
		if (ans < 2)
		{
			ans = 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}
