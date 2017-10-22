#include <bits/stdc++.h>

using namespace std;

#define maxn 102

char G[maxn][maxn];
int R, C;

struct ss
{
	int x, y;
	int dur, dir;
	int cov;
};
ss K[1001];

void Cover(int x, int y, int cover, int dir)
{
	int i;
	if (dir == 0)
		for (i = x; i >= x - cover && i > 0; i--)
			G[i][y] = 1;
	else if (dir == 1)
		for (i = y; i <= y + cover && i <= C; i++)
			G[x][i] = 1;
	else if (dir == 2)
		for (i = x; i <= x + cover && i <= R; i++)
			G[i][y] = 1;
	else
		for (i = y; i >= y - cover && i > 0; i--)
			G[x][i] = 1;
}

void Fill(int x, int y, int st, int dur, int lim1, int lim2, int diff, int dir, int cov)
{
	int d, k, p, q, end;
	end = st + dur - 1;
	if (st > lim2)
		return;
	if (st >= lim1 && st <= lim2)
	{
		Cover(x, y, cov, dir);
		return;
	}
	d = lim1 - st;
	k = d % diff;
	p = d - k + st;
	q = p + dur - 1;
	if (q >= lim1)
	{
		Cover(x, y, cov, dir);
		return;
	}
	else
	{
		p += diff;
		if (p <= lim2)
		{
			Cover(x, y, cov, dir);
			return;
		}
	}
}

void Process(int x, int y, int dur, int cover, int direct, int st, int endt)
{
	int diff, p;
	diff = (dur + 1) * 4;
	Fill(x, y, 0, dur, st, endt, diff, direct, cover);
	p = dur + 1;
	Fill(x, y, p, dur, st, endt, diff, (direct + 1) % 4, cover);
	p += 1 + dur;
	Fill(x, y, p, dur, st, endt, diff, (direct + 2) % 4, cover);
	p += 1 + dur;
	Fill(x, y, p, dur, st, endt, diff, (direct + 3) % 4, cover);
}

void Cal(int k)
{
	int i = 0, st, end, c = 0;
	char dir;
	while (i++ < k)
	{
		cin >> K[i].x >> K[i].y >> K[i].dur >> K[i].cov >> dir;
		if (dir == 'N')
			dir = 0;
		else if (dir == 'E')
			dir = 1;
		else if (dir == 'S')
			dir = 2;
		else
			dir = 3;
		K[i].dir = dir;
		G[K[i].x][K[i].y] = 1;
	}
	cin >> st >> end;
	i = 0;
	while (i++ < k)
		Process(K[i].x, K[i].y, K[i].dur, K[i].cov, K[i].dir, st, end);
	for (i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (G[i][j] == 0)
				c++;
	cout << c << endl;
}

void Free()
{
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			G[i][j] = 0;
}

int main()
{
	int k;
	while (cin >> R >> C >> k)
	{
		if (!R && !C && !k)
			break;
		Cal(k);
		Free();
	}
	return 0;
}
