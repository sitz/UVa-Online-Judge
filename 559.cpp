#include <bits/stdc++.h>

using namespace std;

int board[1000][1000], size[1000][1000];
int w, h, m, maxr, maxc, maxs;
int min(int a, int b)
{
	return (a < b) ? a : b;
}
void fill(int r, int c)
{
	int tr, tc;
	for (int delta = 1;; delta++)
	{
		tr = r - delta;
		tc = c + delta;
		if (tr < 0 || tc >= w)
		{
			return;
		}
		for (int i = c; i <= tc; i++)
			if (!board[tr][i])
			{
				return;
			}
		for (int i = tr; i <= r; i++)
			if (!board[i][tc])
			{
				return;
			}
		for (int i = c; i <= tc; i++)
		{
			board[tr][i] = 0;
		}
		for (int i = tr; i <= r; i++)
		{
			board[i][tc] = 0;
		}
	}
}
int main()
{
	int times;
	scanf("%d", &times);
	for (; times; times--)
	{
		maxs = 0;
		scanf("%d %d %d", &h, &w, &m);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				board[i][j] = 1;
			}
		for (int i = 0; i < m; i++)
		{
			int baser, basec;
			scanf("%d %d", &baser, &basec);
			baser = h - baser;
			basec--;
			board[baser][basec] = 0;
			fill(baser, basec);
		}
		/*      for(int i=0;i<h;i++)
		        {
		            for(int j=0;j<w;j++) printf("%d ",board[i][j]);
		            printf("\n");
		        }*/
		for (int i = w - 1; i >= 0; i--)
		{
			size[0][i] = board[0][i];
			if (size[0][i] >= maxs)
			{
				maxs = size[0][i];
				maxr = 0;
				maxc = i;
			}
		}
		for (int i = 1; i < h; i++)
		{
			size[i][w - 1] = board[i][w - 1];
			if (size[i][w - 1] >= maxs)
			{
				maxs = size[i][w - 1];
				maxr = i;
				maxc = w - 1;
			}
			for (int j = w - 2; j >= 0; j--)
			{
				if (!board[i][j])
				{
					size[i][j] = 0;
				}
				else
				{
					int m = min(size[i - 1][j], size[i][j + 1]);
					m = min(m, size[i - 1][j + 1]);
					size[i][j] = m + 1;
					if (size[i][j] >= maxs)
					{
						maxs = size[i][j];
						maxr = i;
						maxc = j;
					}
				}
			}
		}
		if (maxs == 0)
		{
			puts("game over");
		}
		else
		{
			printf("%d %d %d\n", h - maxr, maxc + 1, maxs);
		}
	}
	return 0;
}
