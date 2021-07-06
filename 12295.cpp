#include <bits/stdc++.h>

using namespace std;

#define MAXN 110
#define MAXD 10010
#define INF 1000000000
#define MOD 1000000009

int N, M, a[MAXN][MAXN];
long long int f[MAXD];
int q[MAXD], inq[MAXD], d[MAXD], vis[MAXD], min_, tree[4 * MAXD];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int init()
{
	int i, j;
	scanf("%d", &N);
	if (!N)
	{
		return 0;
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - i - 1; j++)
		{
			a[i][j] += a[N - 1 - j][N - 1 - i];
		}
	}
	return 1;
}

void SPFA()
{
	int i, j, k, z, newz, x, y, newx, newy, front, rear;
	for (i = 0; i < MAXD; i++)
	{
		d[i] = INF;
	}
	d[1] = a[0][0];
	memset(inq, 0, sizeof(inq));
	front = rear = 0;
	q[rear++] = 1;
	while (front != rear)
	{
		z = q[front++];
		if (front > N * N)
		{
			front = 0;
		}
		inq[z] = 0;
		x = (z - 1) / N;
		y = (z - 1) % N;
		if (x + y == N - 1)
		{
			continue;
		}
		for (i = 0; i < 4; i++)
		{
			newx = x + dx[i];
			newy = y + dy[i];
			if (newx >= 0 && newx < N && newy >= 0 && newy < N)
			{
				newz = newx * N + newy + 1;
				if (d[z] + a[newx][newy] < d[newz])
				{
					d[newz] = d[z] + a[newx][newy];
					if (!inq[newz])
					{
						q[rear++] = newz;
						if (rear > N * N)
						{
							rear = 0;
						}
						inq[newz] = 1;
					}
				}
			}
		}
	}
}

long long int DP(int cur)
{
	int i, x, y, newx, newy, newz;
	if (f[cur] != -1)
	{
		return f[cur];
	}
	x = (cur - 1) / N;
	y = (cur - 1) % N;
	if (x + y == N - 1)
	{
		f[cur] = d[cur] == min_ ? 1 : 0;
		return f[cur];
	}
	f[cur] = 0;
	for (i = 0; i < 4; i++)
	{
		newx = x + dx[i];
		newy = y + dy[i];
		if (newx >= 0 && newx < N && newy >= 0 && newy < N)
		{
			newz = newx * N + newy + 1;
			if (d[cur] + a[newx][newy] == d[newz])
			{
				f[cur] += DP(newz);
			}
		}
	}
	return f[cur];
}

void solve()
{
	int i, j, k;
	long long int ans;
	SPFA();
	min_ = INF;
	for (i = 0; i < N; i++)
	{
		if (d[i * N + N - i] < min_)
		{
			min_ = d[i * N + N - i];
		}
	}
	memset(f, -1, sizeof(f));
	ans = DP(1);
	printf("%lld\n", ans);
}

int main()
{
	while (init())
	{
		solve();
	}
	return 0;
}
