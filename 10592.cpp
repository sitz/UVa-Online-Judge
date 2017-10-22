#include <bits/stdc++.h>

using namespace std;

int dirr[4] = {-1, 0, 1, 0};
int dirc[4] = {0, 1, 0, -1};

bool v[51][51];
char map_[51][51];
int s[51][51], e[501], p[501][2], seq, total, n;

void mark(int r, int c, int id)
{
	s[r][c] = id;
	for (int i = 0; i < 4; i++)
	{
		int tr = r + dirr[i], tc = c + dirc[i];
		if (tr < 0 || tr >= n || tc < 0 || tc >= n || map_[tr][tc] == '.' || s[tr][tc])
		{
			continue;
		}
		mark(tr, tc, id);
	}
}
void mark1(int r, int c, char ch, int id)
{
	v[r][c] = true;
	if (id)
	{
		s[r][c] = id;
	}
	for (int i = 0; i < 4; i++)
	{
		int tr = r + dirr[i], tc = c + dirc[i];
		if (id && tr >= 0 && tr < n && tc >= 0 && tc < n && ch == 'B' && map_[tr][tc] == 'P')
		{
			e[s[r][c]] = 1;
		}
		if (tr < 0 || tr >= n || tc < 0 || tc >= n || map_[tr][tc] != ch || v[tr][tc])
		{
			continue;
		}
		mark1(tr, tc, ch, id);
	}
}

int main()
{
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%s", map_[i]);
		}
		memset(s, 0, sizeof(s));
		memset(p, 0, sizeof(p));
		memset(v, 0, sizeof(v));
		memset(e, 0, sizeof(e));
		seq = total = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map_[i][j] != '.' && s[i][j] == 0)
				{
					mark(i, j, ++seq);
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map_[i][j] == 'B' || map_[i][j] == 'P')
				{
					if (v[i][j])
					{
						continue;
					}
					mark1(i, j, map_[i][j], 0);
					if (map_[i][j] == 'B')
					{
						p[s[i][j]][0]++;
					}
					else
					{
						p[s[i][j]][1]++;
					}
				}
			}
		}
		for (int i = 1; i <= seq; i++)
		{
			printf("Sector #%d: contain %d freedom fighter group(s) & %d enemy group(s)\n", i, p[i][0], p[i][1]);
		}
		memset(s, 0, sizeof(s));
		memset(v, 0, sizeof(v));
		seq = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map_[i][j] == 'B' || map_[i][j] == 'P')
				{
					if (v[i][j])
					{
						continue;
					}
					if (map_[i][j] == 'B')
					{
						seq++;
					}
					mark1(i, j, map_[i][j], seq);
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= seq; i++)
		{
			cnt += e[i];
		}
		printf("Total %d group(s) are in fighting position.\n", cnt * 2);
		printf("\n");
	}
	return 0;
}
