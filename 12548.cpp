#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-9;
int tst = 0, n, MOD = 1000003, head, tail, cnt;
long long hx, hy, now_hx, now_hy, tx, ty, cx, cy, tot, ao, tnt[711][711], tct[711][711], now_tnt, now_tct, now_cont, cont[711][711], ahx[711][711], ahy[711][711], anow_hx[711][711], anow_hy[711][711];

struct point
{
	int x, y, hx, hy;
	double theta;
	int id;
	bool operator<(const point &temp) const
	{
		return theta < temp.theta;
	}
};
point pt[1001], adj[711][711], queue_[111111];

int solve()
{
	int i, j, s, p, q;
	tot = ao = 0;
	cnt = 0;
	for (i = 0; i < n; i++)
	{
		cnt = 0;
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}
			adj[i][cnt] = pt[j];
			adj[i][cnt].id = j;
			adj[i][cnt++].theta = atan2((double)(pt[j].y - pt[i].y), (double)(pt[j].x - pt[i].x));
		}
		sort(adj[i], adj[i] + cnt);
		head = tail = 0;
		now_cont = 0;
		for (j = 0; j < cnt; j++)
		{
			int smin;
			if (head == tail)
			{
				smin = j + 1;
			}
			else
			{
				smin = queue_[tail - 1].id + 1;
			}
			for (int ss = smin; ss < j + cnt; ss++)
			{
				s = ss % cnt;
				while (head < tail)
				{
					if (queue_[head].id <= j)
					{
						head++;
						now_cont--;
					}
					else
					{
						break;
					}
				}
				if (ss <= j)
				{
					continue;
				}
				if (fabs(2 * M_PI * (ss / cnt) + adj[i][s].theta - adj[i][j].theta) < M_PI)
				{
					queue_[tail] = adj[i][s];
					queue_[tail++].id = ss;
					now_cont++;
				}
				else
				{
					break;
				}
			}
			cont[i][j] = now_cont;
		}
		head = tail = 0;
		hx = hy = now_hx = now_hy = now_tnt = 0;
		for (j = 0; j < cnt; j++)
		{
			int smin;
			if (head == tail)
			{
				smin = j + 1;
			}
			else
			{
				smin = queue_[tail - 1].id + 1;
			}
			for (int ss = smin; ss < j + cnt; ss++)
			{
				s = ss % cnt;
				while (head < tail)
				{
					if (queue_[head].id <= j)
					{
						int ig = queue_[head].id % cnt;
						head++;
						now_tnt -= cont[i][ig];
						now_tnt += tail - head;
						hx -= adj[i][ig].x;
						hy -= adj[i][ig].y;
						now_hx -= (tail - head) * adj[i][ig].x % MOD;
						now_hy -= (tail - head) * adj[i][ig].y % MOD;
					}
					else
					{
						break;
					}
				}
				if (ss <= j)
				{
					continue;
				}
				if (fabs(2 * M_PI * (ss / cnt) + adj[i][s].theta - adj[i][j].theta) < M_PI)
				{
					now_hx += hx;
					now_hy += hy;
					hx += adj[i][s].x;
					hy += adj[i][s].y;
					now_tnt += cont[i][s];
					now_tnt -= tail - head;
					queue_[tail] = adj[i][s];
					queue_[tail++].id = ss;
				}
				else
				{
					break;
				}
			}
			ahx[i][j] = hx;
			ahy[i][j] = hy;
			tnt[i][j] = now_tnt;
			anow_hx[i][j] = now_hx;
			anow_hy[i][j] = now_hy;
		}
	}
	tot = ao = 0;
	for (i = 0; i < n; i++)
	{
		head = tail = 0;
		cx = cy = 0;
		for (j = 0; j < cnt; j++)
		{
			int smin;
			long long temp, tey;
			temp = cont[i][j] * adj[i][j].x;
			temp = ((long long)(ahx[i][j] - temp) * (long long)(pt[i].y - adj[i][j].y));
			tey = cont[i][j] * adj[i][j].y % MOD;
			tey = ((long long)(ahy[i][j] - tey) * (long long)(pt[i].x - adj[i][j].x));
			temp = (temp - tey + MOD);
			tot += (long long)(cnt - 1 - cont[i][j]) * (long long)temp % MOD;
			if (head == tail)
			{
				smin = j + 1;
			}
			else
			{
				smin = queue_[tail - 1].id + 1;
			}
			for (int ss = smin; ss < j + cnt; ss++)
			{
				s = ss % cnt;
				while (head < tail)
				{
					if (queue_[head].id <= j)
					{
						int ig = queue_[head].id % cnt;
						cx -= cont[i][ig] * adj[i][ig].x % MOD;
						cy -= cont[i][ig] * adj[i][ig].y % MOD;
						head++;
					}
					else
					{
						break;
					}
				}
				if (ss <= j)
				{
					continue;
				}
				if (fabs(2 * M_PI * (ss / cnt) + adj[i][s].theta - adj[i][j].theta) < M_PI)
				{
					cx += cont[i][s] * adj[i][s].x % MOD;
					cy += cont[i][s] * adj[i][s].y % MOD;
					queue_[tail] = adj[i][s];
					queue_[tail++].id = ss;
				}
				else
				{
					break;
				}
			}
			temp = (cx - anow_hx[i][j]) - (long long)tnt[i][j] * (long long)adj[i][j].x % MOD;
			temp = (long long)temp * (long long)(pt[i].y - adj[i][j].y) % MOD;
			tey = (cy - anow_hy[i][j]) - (int)((long long)tnt[i][j] * (long long)adj[i][j].y % MOD);
			tey = (tey % MOD + MOD) % MOD;
			tey = (int)((long long)tey * (long long)(pt[i].x - adj[i][j].x) % MOD);
			temp = (temp - tey + MOD) % MOD;
			ao = (ao + temp) % MOD;
		}
	}
	ao = (ao * 2) % MOD;
	tot = (tot - ao) % MOD;
	if (tot < 0)
	{
		tot += MOD;
	}
	if (tot % 2)
	{
		tot = (tot + MOD) / 2;
	}
	else
	{
		tot /= 2;
	}
	return ((tot + ao) % MOD + MOD) % MOD;
}

int main()
{
	int t, x, y, i, j, s, p, q;
	scanf("%d", &t);
	while (t--)
	{
		tst++;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			pt[i].x = x;
			pt[i].y = y;
		}
		printf("Case %d: %d\n", tst, solve());
	}
	return 0;
}
