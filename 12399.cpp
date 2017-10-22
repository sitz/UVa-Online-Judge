#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 29;

int dy[] = {0, 0, 0, 1, -1}, dx[] = {0, 1, -1, 0, 0};
int tmp[3][3], ans[3][3], best_ans[3][3];
int board[3][3];
char buf[2000];

bool init()
{
	gets(buf);
	bool f = true;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			f &= (scanf("%d ", board[i] + j) == 1);
		}
	}
	return f;
}

void push(int y, int x)
{
	for (int k = 0; k < 5; k++)
	{
		int ny = y + dy[k], nx = x + dx[k];
		if (0 <= ny && ny < 3 && 0 <= nx && nx < 3)
		{
			tmp[ny][nx]--;
			if (tmp[ny][nx] < 0)
			{
				tmp[ny][nx] += 10;
			}
		}
	}
}

void solve()
{
	int len = INF;
	for (int top = 0; top < 1000; top++)
	{
		memcpy(tmp, board, sizeof(board));
		memset(ans, 0, sizeof(ans));
		ans[0][0] = top / 100;
		ans[0][1] = (top / 10) % 10;
		ans[0][2] = top % 10;
		for (int x = 0; x < 3; x++)
		{
			for (int i = 0; i < ans[0][x]; i++)
			{
				push(0, x);
			}
		}
		for (int y = 1; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				ans[y][x] = tmp[y - 1][x];
				for (int i = 0; i < ans[y][x]; i++)
				{
					push(y, x);
				}
			}
		}
		if (tmp[2][0] == 0 && tmp[2][1] == 0 && tmp[2][2] == 0)
		{
			int cnt = 0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cnt += ans[i][j];
				}
			}
			if (cnt < len)
			{
				len = cnt;
				memcpy(best_ans, ans, sizeof(ans));
			}
		}
	}
	if (len == INF)
	{
		puts("No solution.");
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < best_ans[i][j]; k++)
				{
					putchar('a' + (i * 3 + j));
				}
			}
		}
		puts("");
	}
}

int main()
{
	while (init())
	{
		solve();
	}
	return 0;
}
