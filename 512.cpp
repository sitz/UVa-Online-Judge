#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000;
struct CMD
{
	int A, B[15], t;
	void read()
	{
		char str[5];
		scanf("%s", str);
		if (str[0] != 'E')
		{
			scanf("%d", &A);
		}
		else
		{
			A = 4;
		}
		for (int i = 0; i < A; i++)
		{
			scanf("%d", &B[i]);
		}
		if (str[0] == 'D' && str[1] == 'R')
		{
			t = 0;
		}
		else if (str[0] == 'D' && str[1] == 'C')
		{
			t = 1;
		}
		else if (str[0] == 'I' && str[1] == 'R')
		{
			t = 2;
		}
		else if (str[0] == 'I' && str[1] == 'C')
		{
			t = 3;
		}
		else
		{
			t = 4;
		}
		if (t != 4)
		{
			sort(B, B + A);
			A = unique(B, B + A) - B;
		}
	}
} cmd[maxn];
int R, C, n, totr, totc;

pair<int, int> go(int x, int y)
{
	//printf(">> %d %d\n", x, y);
	for (int i = 0; i < n; i++)
	{
		if (cmd[i].t == 0)
		{
			int tx = x;
			for (int j = 0; j < cmd[i].A; j++)
			{
				if (cmd[i].B[j] < x)
				{
					tx--;
				}
				if (cmd[i].B[j] == x)
				{
					return make_pair(-1, -1);
				}
			}
			x = tx;
		}
		else if (cmd[i].t == 1)
		{
			int ty = y;
			for (int j = 0; j < cmd[i].A; j++)
			{
				if (cmd[i].B[j] < y)
				{
					ty--;
				}
				if (cmd[i].B[j] == y)
				{
					return make_pair(-1, -1);
				}
			}
			y = ty;
		}
		else if (cmd[i].t == 2)
		{
			int tx = x;
			for (int j = 0; j < cmd[i].A; j++)
			{
				if (cmd[i].B[j] <= x)
				{
					tx++;
				}
				else
				{
					break;
				}
			}
			x = tx;
		}
		else if (cmd[i].t == 3)
		{
			int ty = y;
			for (int j = 0; j < cmd[i].A; j++)
			{
				if (cmd[i].B[j] <= y)
				{
					ty++;
				}
				else
				{
					break;
				}
			}
			y = ty;
		}
		else
		{
			int x1 = cmd[i].B[0], y1 = cmd[i].B[1];
			int x2 = cmd[i].B[2], y2 = cmd[i].B[3];
			if (x1 == x && y1 == y)
			{
				x = x2, y = y2;
			}
			else if (x2 == x && y == y2)
			{
				x = x1, y = y1;
			}
		}
		//printf(">> %d %d\n", x, y);
	}
	return make_pair(x, y);
}
int main()
{
	//freopen("test.in", "r", stdin);
	for (int kase = 1; scanf("%d%d", &R, &C) != EOF && R && C; kase++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			cmd[i].read();
		}
		int q;
		scanf("%d", &q);
		if (kase >= 2)
		{
			printf("\n");
		}
		printf("Spreadsheet #%d\n", kase);
		for (int i = 0; i < q; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			pair<int, int> res = go(x, y);
			if (res.first == -1)
			{
				printf("Cell data in (%d,%d) GONE\n", x, y);
			}
			else
			{
				printf("Cell data in (%d,%d) moved to (%d,%d)\n", x, y, res.first, res.second);
			}
		}
	}
	return 0;
}
