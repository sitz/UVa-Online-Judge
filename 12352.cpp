#include <bits/stdc++.h>

using namespace std;

struct rect
{
	int x, y, ord, col, row;
} r[10];

struct node
{
	int x, y, i;
} f[125][10];
node no1[10];

bool visit[105][105];
char map_[105][105], st[100];
int s[7][7], p[7];

int main()
{
	int T;
	scanf("%d", &T);
	int t = 0;
	while (T--)
	{
		printf("Case %d: ", ++t);
		int cnt = 0;
		for (int i = 0; i < 20; i++)
		{
			scanf("%s", map_[i]);
		}
		memset(visit, false, sizeof(visit));
		bool fuck = false;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (map_[i][j] == 'x' && !visit[i][j])
				{
					int ii = i, jj = j;
					while (ii < 20 && map_[ii][j] == 'x')
					{
						ii++;
					}
					while (jj < 20 && map_[i][jj] == 'x')
					{
						jj++;
					}
					for (int k = i; k < ii; k++)
						for (int l = j; l < jj; l++)
						{
							visit[k][l] = true;
						}
					r[cnt].x = i;
					r[cnt].y = j;
					r[cnt].row = ii - i;
					r[cnt].col = jj - j;
					r[cnt].ord = cnt;
					if (r[cnt].row > 5 || r[cnt].col > 5)
					{
						fuck = true;
					}
					cnt++;
				}
			}
		}
		if (fuck)
		{
			puts("invalid data");
			continue;
		}
		for (int i = 0; i < cnt; i++)
		{
			p[i] = i;
		}
		int tot = 0;
		do
		{
			memset(s, 0, sizeof(s));
			bool notva = true;
			for (int i = 0; i < cnt; i++)
			{
				rect now = r[p[i]];
				bool flag = true;
				for (int j = 0; j < 5; j++)
				{
					for (int k = 0; k < 5; k++)
						if (!s[j][k])
						{
							if (j + now.row - 1 >= 5 || k + now.col - 1 >= 5)
							{
								notva = false;
							}
							else
							{
								no1[p[i]].x = j;
								no1[p[i]].y = k;
								for (int l = j; l < j + now.row; l++)
									for (int o = k; o < k + now.col; o++)
									{
										s[l][o]++;
									}
							}
							flag = false;
							break;
						}
					if (!flag)
					{
						break;
					}
				}
			}
			if (!notva)
			{
				continue;
			}
			bool f1 = true;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
					if (s[i][j] != 1)
					{
						f1 = false;
						break;
					}
				if (!f1)
				{
					break;
				}
			}
			if (f1)
			{
				for (int j = 0; j < cnt; j++)
				{
					f[tot][j] = no1[j];
				}
				tot++;
			}
		} while (next_permutation(p, p + cnt));
		if (tot == 0)
		{
			puts("invalid data");
			continue;
		}
		int move = 100000000;
		for (int i = 0; i < tot; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				for (int k = 0; k < 20; k++)
				{
					int sum = 0;
					for (int l = 0; l < cnt; l++)
					{
						int nox = j + f[i][l].x;
						int noy = k + f[i][l].y;
						sum += abs(nox - r[l].x) + abs(noy - r[l].y);
					}
					if (sum < move)
					{
						move = sum;
					}
				}
			}
		}
		printf("%d\n", move);
	}
	return 0;
}
