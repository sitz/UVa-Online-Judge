#include <bits/stdc++.h>

using namespace std;

int dir[6] = {1, 3, 6, -6, -3, -1};
int dir2[6] = {3, 6, 12, 12, 6, 3};
char t[12][12] = {{0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 3, 4}, {1, 0, 1, 2, 1, 2, 2, 1, 2, 3, 2, 3}, {2, 1, 0, 3, 2, 1, 3, 2, 1, 4, 3, 2}, {1, 2, 3, 0, 1, 2, 2, 3, 4, 1, 2, 3}, {2, 1, 2, 1, 0, 1, 3, 2, 3, 2, 1, 2}, {3, 2, 1, 2, 1, 0, 4, 3, 2, 3, 2, 1}, {1, 2, 3, 2, 3, 4, 0, 1, 2, 1, 2, 3}, {2, 1, 2, 3, 2, 3, 1, 0, 1, 2, 1, 2}, {3, 2, 1, 4, 3, 2, 2, 1, 0, 3, 2, 1}, {2, 3, 4, 1, 2, 3, 1, 2, 3, 0, 1, 2}, {3, 2, 3, 2, 1, 2, 2, 1, 2, 1, 0, 1}, {4, 3, 2, 3, 2, 1, 3, 2, 1, 2, 1, 0}};

char str[15], ans[60], mov[12][12][6];
int lim, nextlim, n;

void init()
{
	mov[0][1][0] = mov[1][2][0] = mov[3][4][0] = mov[4][5][0] = mov[6][7][0] =
	mov[7][8][0] = mov[9][10][0] = mov[10][11][0] = mov[0][3][1] = mov[1][4][1] =
	mov[2][5][1] = mov[6][9][1] = mov[7][10][1] = mov[8][11][1] = mov[0][6][2] =
	mov[1][7][2] = mov[2][8][2] = mov[3][9][2] = mov[4][10][2] = mov[5][11][2] =
	mov[6][0][3] = mov[7][1][3] = mov[8][2][3] = mov[9][3][3] = mov[10][4][3] =
	mov[11][5][3] = mov[3][0][4] = mov[4][1][4] = mov[5][2][4] = mov[9][6][4] =
	mov[10][7][4] = mov[11][8][4] = mov[1][0][5] = mov[2][1][5] = mov[4][3][5] =
	mov[5][4][5] = mov[7][6][5] = mov[8][7][5] = mov[10][9][5] = mov[11][10][5] = 1;
}
int eval()
{
	int sum = 0, i;
	for (i = 0; i < 12; i++)
	{
		if (str[i] == 'L')
		{
			continue;
		}
		sum += t[i][str[i] - 'A'];
	}
	return sum;
}
char IDA_STAR(int depth, int prev, int loc, int ee)
{
	int i;
	if (ee == 0)
	{
		puts(ans);
		return 1;
	}
	else
	{
		int tl, te = ee;
		char ts, xx;
		for (i = 0; i < 6; i++)
		{
			if (i + prev == 5)
			{
				continue;
			}
			tl = loc + dir[i];
			if (tl < 0 || tl >= 12)
			{
				continue;
			}
			if (mov[loc][tl][i] == 0)
			{
				continue;
			}
			xx = str[tl] - 'A';
			ee -= (t[tl][xx] - t[loc][xx]);
			ans[depth] = str[tl];
			ts = str[tl];
			str[tl] = str[loc];
			str[loc] = ts;
			if (depth + 1 + ee <= lim && IDA_STAR(depth + 1, i, tl, ee))
			{
				return 1;
			}
			else if (depth + 1 + ee > lim && depth + 1 + ee < nextlim)
			{
				nextlim = depth + 1 + ee;
			}
			str[loc] = str[tl];
			str[tl] = ts;
			ans[depth] = '\0';
			ee = te;
		}
		return 0;
	}
}

int main()
{
	int caseno = 1, p, ev;
	init();
	scanf("%d", &n);
	while (n--)
	{
		memset(ans, '\0', sizeof(ans));
		scanf("%s", str);
		for (p = 0; p < 12 && str[p] != 'L'; p++)
			;
		printf("Permutation #%d\n", caseno++);
		lim = eval();
		nextlim = 1000;
		ev = lim;
		do
		{
			if (IDA_STAR(0, -1, p, ev))
			{
				break;
			}
			lim = nextlim;
			nextlim = 1000;
		} while (1);
		puts("");
	}
	return 0;
}
