#include <bits/stdc++.h>

using namespace std;

int dx[8], dy[8];
int mark[105][105];
int n, m, odd, even;

void gao(int x, int y)
{
	mark[x][y] = 1;
	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && mark[nx][ny] != -1)
		{
			int has = 0;
			for (int j = 0; j < i; j++)
			{
				int tx = x + dx[j], ty = y + dy[j];
				if (tx == nx && ty == ny)
				{
					has = 1;
					break;
				}
			}
			if (!has)
			{
				cnt++;
			}
			if (mark[nx][ny] == 0)
			{
				gao(nx, ny);
			}
		}
	}
	if (cnt % 2 == 0)
	{
		even++;
	}
	else
	{
		odd++;
	}
}

int main()
{
	int cas, r = 1;
	scanf("%d", &cas);
	while (cas--)
	{
		int x, y;
		scanf("%d%d%d%d", &n, &m, &x, &y);
		dx[0] = x, dx[1] = x, dx[2] = -x, dx[3] = -x, dx[4] = y, dx[5] = y, dx[6] = -y, dx[7] = -y;
		dy[0] = y, dy[1] = -y, dy[2] = y, dy[3] = -y, dy[4] = x, dy[5] = -x, dy[6] = x, dy[7] = -x;
		odd = 0, even = 0;
		memset(mark, 0, sizeof(mark));
		int k;
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
		{
			scanf("%d%d", &x, &y);
			mark[x][y] = -1;
		}
		gao(0, 0);
		printf("Case %d: %d %d\n", r++, even, odd);
	}
}
