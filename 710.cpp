#include <bits/stdc++.h>

using namespace std;

#define maxn 80
#define INF 9999999

char B[maxn], D[maxn][maxn];
char X[] = {0, 1, 0, -1};
char Y[] = {-1, 0, 1, 0};
int Cost[maxn][maxn];
int R, C;

struct ss
{
	int x, y;
	int cost;
	int dir;
};
queue<ss> Q;
int BFS(int u, int v, int y, int z)
{
	ss temp, dump;
	int nx, ny, i, d, min = INF;
	if (u == y && v == z)
		return 0;
	temp.x = u;
	temp.y = v;
	temp.dir = -1;
	temp.cost = 0;
	Q.push(temp);
	while (!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		for (i = 0; i < 4; i++)
		{
			nx = temp.x + X[i];
			ny = temp.y + Y[i];
			if (nx > R + 1 || nx < 0 || ny > C + 1 || ny < 0)
				continue;
			d = 0;
			if (temp.dir != i)
				d = 1;
			if (Cost[nx][ny] <= temp.cost + d)
				continue;
			if (temp.cost + d >= min)
				continue;
			if (nx == y && ny == z)
			{
				min = temp.cost + d;
				continue;
			}
			if (D[nx][ny] == 1)
				continue;
			dump.x = nx;
			dump.y = ny;
			dump.cost = temp.cost + d;
			dump.dir = i;
			Cost[nx][ny] = temp.cost + d;
			Q.push(dump);
		}
	}
	return min;
}
void Ini()
{
	int i, j;
	for (i = 0; i <= R + 1; i++)
		for (j = 0; j <= C + 1; j++)
			Cost[i][j] = INF;
}
void Cal()
{
	int u, v, y, z, d, k = 1;
	while (1)
	{
		gets(B);
		sscanf(B, "%d%d%d%d", &u, &v, &y, &z);
		if (!u && !v && !y && !z)
			break;
		Ini();
		d = BFS(v, u, z, y);
		printf("Pair %d: ", k++);
		if (d == INF)
			printf("impossible.\n");
		else
			printf("%d segments.\n", d);
	}
}
void Free()
{
	int i, j;
	for (i = 0; i <= R; i++)
	{
		for (j = 0; j <= C; j++)
		{
			D[i][j] = 0;
		}
	}
}

int main()
{
	int i, k = 1;
	while (gets(B))
	{
		sscanf(B, "%d%d", &C, &R);
		if (!R && !C)
			break;
		for (i = 1; i <= R; i++)
		{
			gets(B);
			for (int j = 0; B[j]; j++)
			{
				D[i][j + 1] = 0;
				if (B[j] == 'X')
					D[i][j + 1] = 1;
			}
		}
		printf("Board #%d:\n", k++);
		Cal();
		printf("\n");
		Free();
	}
	return 0;
}
