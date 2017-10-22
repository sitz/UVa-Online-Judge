#include <bits/stdc++.h>

using namespace std;

#define N 55
#define EPS 1e-9
#define INF 100000000

typedef long long LL;

bool S[N], T[N];
double cost[N][N], lx[N], ly[N], slack[N], slackx[N], prev_[N];
int n, max_match, xy[N], yx[N];
LL lob[N][N], hor[N][N];

void init_lbls()
{
	fill(lx, lx + N, 0);
	fill(ly, ly + N, 0);
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			lx[x] = max(lx[x], cost[x][y]);
		}
	}
}

void update_lbls()
{
	int x, y;
	double delta = INF;
	for (y = 0; y < n; y++)
	{
		if (!T[y])
		{
			delta = min(delta, slack[y]);
		}
	}
	for (x = 0; x < n; x++)
	{
		if (S[x])
		{
			lx[x] -= delta;
		}
	}
	for (y = 0; y < n; y++)
	{
		if (T[y])
		{
			ly[y] += delta;
		}
	}
	for (y = 0; y < n; y++)
	{
		if (!T[y])
		{
			slack[y] -= delta;
		}
	}
}

void add_to_tree(int x, int prev_x)
{
	S[x] = true;
	prev_[x] = prev_x;
	for (int y = 0; y < n; y++)
	{
		if (lx[x] + ly[y] - cost[x][y] + EPS < slack[y])
		{
			slack[y] = lx[x] + ly[y] - cost[x][y];
			slackx[y] = x;
		}
	}
}

void augment()
{
	if (max_match == n)
	{
		return;
	}
	int x, y, root, q[N], wr = 0, rd = 0;
	memset(S, false, sizeof(S));
	memset(T, false, sizeof(T));
	memset(prev_, -1, sizeof(prev_));
	for (x = 0; x < n; x++)
		if (xy[x] == -1)
		{
			q[wr++] = root = x;
			prev_[x] = -2;
			S[x] = true;
			break;
		}
	for (y = 0; y < n; y++)
	{
		slack[y] = lx[root] + ly[y] - cost[root][y];
		slackx[y] = root;
	}
	while (true)
	{
		while (rd < wr)
		{
			x = q[rd++];
			for (y = 0; y < n; y++)
				if (cost[x][y] == lx[x] + ly[y] && !T[y])
				{
					if (yx[y] == -1)
					{
						break;
					}
					T[y] = true;
					q[wr++] = yx[y];
					add_to_tree(yx[y], x);
				}
			if (y < n)
			{
				break;
			}
		}
		if (y < n)
		{
			break;
		}
		update_lbls();
		wr = rd = 0;
		for (y = 0; y < n; y++)
			if (!T[y] && slack[y] == 0)
			{
				if (yx[y] == -1)
				{
					x = slackx[y];
					break;
				}
				else
				{
					T[y] = true;
					if (!S[yx[y]])
					{
						q[wr++] = yx[y];
						add_to_tree(yx[y], slackx[y]);
					}
				}
			}
		if (y < n)
		{
			break;
		}
	}
	if (y < n)
	{
		max_match++;
		for (int cx = x, cy = y, ty; cx != -2; cx = prev_[cx], cy = ty)
		{
			ty = xy[cx];
			yx[cy] = cx;
			xy[cx] = cy;
		}
		augment();
	}
}

int hungarian()
{
	max_match = 0;
	memset(xy, -1, sizeof(xy));
	memset(yx, -1, sizeof(yx));
	init_lbls();
	augment();
	LL u = 1;
	LL v = 1, g;
	for (int x = 0; x < n; x++)
	{
		u = u * lob[x][xy[x]];
		v = v * hor[x][xy[x]];
		g = __gcd(u, v);
		u /= g;
		v /= g;
	}
	u = v - u;
	g = __gcd(u, v);
	u /= g;
	v /= g;
	printf("%lld/%lld\n", u, v);
}

int main()
{
	int T, i, j;
	scanf("%d", &T);
	double z;
	while (T--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d/%d", &lob[i][j], &hor[i][j]);
				lob[i][j] = hor[i][j] - lob[i][j];
				z = (double)(lob[i][j]) / (double)hor[i][j];
				z = z * 10;
				if (z != 0)
				{
					cost[i][j] = (log(z));
				}
				else
				{
					cost[i][j] = 0;
				}
			}
		}
		hungarian();
	}
	return 0;
}
