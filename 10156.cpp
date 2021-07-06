#include <bits/stdc++.h>

using namespace std;

#define M 10005

int nx, ny, t, k, mz[65][65];

struct turs
{
	int x, y;
} tur[M];

bool chk(int x, int y)
{
	return !(x >= nx || x < 0 || y >= ny || y < 0 || mz[x][y]);
}

void solve()
{
	char str[100];
	while (k--)
	{
		int id;
		scanf("%d%s", &id, str);
		if (!strcmp(str, "W"))
		{
			int x = tur[id].x - 1, y = tur[id].y;
			if (chk(x, y))
			{
				mz[tur[id].x][tur[id].y] = 0;
				mz[x][y] = 1;
				tur[id].x = x;
				tur[id].y = y;
			}
		}
		else if (!strcmp(str, "E"))
		{
			int x = tur[id].x + 1, y = tur[id].y;
			if (chk(x, y))
			{
				mz[tur[id].x][tur[id].y] = 0;
				mz[x][y] = 1;
				tur[id].x = x;
				tur[id].y = y;
			}
		}
		else if (!strcmp(str, "N"))
		{
			int x = tur[id].x, y = tur[id].y - 1;
			if (chk(x, y))
			{
				mz[tur[id].x][tur[id].y] = 0;
				mz[x][y] = 1;
				tur[id].x = x;
				tur[id].y = y;
			}
		}
		else if (!strcmp(str, "S"))
		{
			int x = tur[id].x, y = tur[id].y + 1;
			if (chk(x, y))
			{
				mz[tur[id].x][tur[id].y] = 0;
				mz[x][y] = 1;
				tur[id].x = x;
				tur[id].y = y;
			}
		}
		else if (!strcmp(str, "NE"))
		{
			int x = tur[id].x + 1, y = tur[id].y - 1;
			if (chk(x, y))
			{
				mz[tur[id].x][tur[id].y] = 0;
				mz[x][y] = 1;
				tur[id].x = x;
				tur[id].y = y;
			}
		}
		else if (!strcmp(str, "NW"))
		{
			int x = tur[id].x - 1, y = tur[id].y - 1;
			if (chk(x, y))
			{
				mz[tur[id].x][tur[id].y] = 0;
				mz[x][y] = 1;
				tur[id].x = x;
				tur[id].y = y;
			}
		}
		else if (!strcmp(str, "SE"))
		{
			int x = tur[id].x + 1, y = tur[id].y + 1;
			if (chk(x, y))
			{
				mz[tur[id].x][tur[id].y] = 0;
				mz[x][y] = 1;
				tur[id].x = x;
				tur[id].y = y;
			}
		}
		else if (!strcmp(str, "SW"))
		{
			int x = tur[id].x - 1, y = tur[id].y + 1;
			if (chk(x, y))
			{
				mz[tur[id].x][tur[id].y] = 0;
				mz[x][y] = 1;
				tur[id].x = x;
				tur[id].y = y;
			}
		}
	}
	for (int i = 0; i < ny; i++)
	{
		int to = -1;
		for (int j = nx - 1; j >= 0; j--)
		{
			if (mz[j][i])
			{
				to = j;
				break;
			}
		}
		for (int j = 0; j <= to; j++)
		{
			printf((mz[j][i]) ? "*" : " ");
		}
		printf("\n");
	}
}

int main()
{
	while (scanf("%d%d%d%d", &ny, &nx, &t, &k) != EOF)
	{
		memset(mz, 0, sizeof(mz));
		for (int i = 0; i < t; i++)
		{
			int id;
			scanf("%d", &id);
			scanf("%d%d", &tur[id].y, &tur[id].x);
			mz[tur[id].x][tur[id].y] = 1;
		}
		solve();
		printf("\n");
	}
	return 0;
}
