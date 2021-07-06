#include <bits/stdc++.h>

using namespace std;

#define MAX 1 << 29

int s[205][205][4], in[205][205], ans[205][205];

int main()
{
	int N, n, M, m, i, j, dir, len, x, y, nx, ny, dis;
	double stx, sty;
	while (~scanf(" %d %d", &N, &M) && N != -1 && M != -1)
	{
		memset(s, 0, sizeof(s));
		//s : 0-> nothing, 1->wall, 2->door
		//s : 0123 -> up,down,left,right
		//dir : 0->parrelel x, 1->y
		for (n = 0; n < N; n++)
		{
			scanf(" %d %d %d %d", &x, &y, &dir, &len);
			if (dir == 0)
			{
				for (i = 0; i < len; i++, x++)
				{
					s[x][y][1] = 1;
					s[x][y - 1][0] = 1;
				}
			}
			else
			{
				for (i = 0; i < len; i++, y++)
				{
					s[x][y][2] = 1;
					s[x - 1][y][3] = 1;
				}
			}
		}
		for (m = 0; m < M; m++)
		{
			scanf(" %d %d %d", &x, &y, &dir);
			if (dir == 0)
			{
				s[x][y][1] = 2;
				if (y - 1 >= 0)
					s[x][y - 1][0] = 2;
			}
			else
			{
				s[x][y][2] = 2;
				if (x - 1 >= 0)
					s[x - 1][y][3] = 2;
			}
		}
		scanf(" %lf %lf", &stx, &sty);
		x = floor(stx);
		y = floor(sty);
		if (x > 199 || y > 199)
		{
			printf("0\n");
			continue;
		}
		memset(in, 0, sizeof(in));
		for (i = 0; i < 205; i++)
			for (j = 0; j < 205; j++)
				ans[i][j] = MAX;
		queue<int> q;
		q.push(x);
		q.push(y);
		ans[x][y] = 0;
		while (!q.empty())
		{
			x = q.front();
			q.pop();
			y = q.front();
			q.pop();
			dis = ans[x][y];
			in[x][y] = 0;
			for (i = 0; i < 4; i++)
			{
				nx = x;
				ny = y;
				if (i == 0)
					ny++;
				else if (i == 1)
					ny--;
				else if (i == 2)
					nx--;
				else
					nx++;
				if (nx >= 0 && ny >= 0 && nx < 205 && ny < 205)
				{
					if (s[x][y][i] == 0)//empty
					{
						if (dis < ans[nx][ny])
						{
							ans[nx][ny] = dis;
							if (in[nx][ny] == 0)
							{
								in[nx][ny] = 1;
								q.push(nx);
								q.push(ny);
							}
						}
					}
					else if (s[x][y][i] == 2)//door
					{
						if (dis + 1 < ans[nx][ny])
						{
							ans[nx][ny] = dis + 1;
							if (in[nx][ny] == 0)
							{
								in[nx][ny] = 1;
								q.push(nx);
								q.push(ny);
							}
						}
					}
				}
			}
		}
		if (ans[0][0] != MAX)
			printf("%d\n", ans[0][0]);
		else
			printf("-1\n");
	}
	return 0;
}
