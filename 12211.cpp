#include <bits/stdc++.h>

using namespace std;

struct List {char s[5][5];};
struct List nxt;

void vanish(int x, int y, char ch)
{
	int op[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, i, j, nx, ny;
	nxt.s[x][y] = '-';
	for (i = 0; i < 4; i++)
	{
		nx = x + op[i][0];
		ny = y + op[i][1];
		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && nxt.s[nx][ny] == ch)
		{
			vanish(nx, ny, ch);
		}
	}
}
void fall()
{
	int i, j, k;
	for (j = 0; j < 4; j++)
	{
		for (i = 3; i >= 0; i--)
		{
			if (nxt.s[i][j] != '-')
			{
				for (k = i + 1; k < 4; k++)
				{
					if (nxt.s[k][j] == '-')
					{
						nxt.s[k][j] = nxt.s[k - 1][j];
						nxt.s[k - 1][j] = '-';
					}
				}
			}
		}
	}
}
int AB(struct List now, int lv, int A, int B)
{
	int i, j, re = 0;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (now.s[i][j] != '-')
			{
				re = 1;
			}
	if (re == 0)
	{
		if (lv % 2 == 0)
		{
			return -lv;
		}
		return lv;
	}
	if (lv % 2 == 0)
	{
		int stop = 0;
		for (i = 3; i >= 0 && stop == 0; i--)
		{
			for (j = 0; j < 4 && stop == 0; j++)
			{
				if (now.s[i][j] != '-')
				{
					nxt = now;
					vanish(i, j, now.s[i][j]);
					fall();
					A = max(A, AB(nxt, lv - 1, A, B));
					if (B <= A)
					{
						stop = 1;
					}
				}
			}
		}
		return A;
	}
	else
	{
		int stop = 0;
		for (i = 3; i >= 0 && stop == 0; i--)
		{
			for (j = 0; j < 4 && stop == 0; j++)
			{
				if (now.s[i][j] != '-')
				{
					nxt = now;
					vanish(i, j, now.s[i][j]);
					fall();
					B = min(B, AB(nxt, lv - 1, A, B));
					if (B <= A)
					{
						stop = 1;
					}
				}
			}
		}
		return B;
	}
}

int main()
{
	int T, t, i, j;
	struct List now;
	scanf(" %d", &T);
	for (t = 0; t < T; t++)
	{
		gets(now.s[0]);
		for (i = 0; i < 4; i++)
		{
			gets(now.s[i]);
		}
		int tmp = AB(now, 16, -1e9, 1e9);
		if (tmp >= 0)
		{
			printf("Case %d: win %d\n", t + 1, 16 - tmp);
		}
		else
		{
			printf("Case %d: loss %d\n", t + 1, 16 + tmp);
		}
	}
	return 0;
}
