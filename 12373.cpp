#include <bits/stdc++.h>

using namespace std;

struct IN
{
	int xx, yy, zz;
} mat[10000];
long long a;
map<int, int> ync;
int tot = 0;

void solve()
{
	ync.clear();
	for (int i = 1; i <= 1415; i++)
	{
		ync[i * i] = i;
	}
	tot = 0;
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = i; j <= 1000; j++)
		{
			int cnt = i * i + j * j;
			if (ync[cnt])
			{
				mat[tot].xx = i;
				mat[tot].yy = j;
				mat[tot].zz = ync[cnt];
				tot++;
			}
		}
	}
}

int main()
{
	int cas, w, h;
	solve();
	cin >> cas;
	for (int ca = 1; ca <= cas; ca++)
	{
		scanf("%d%d", &w, &h);
		a = 0;
		for (int i = 1; i <= w / 2; i++)
		{
			int ww = min(i, (w - i - i) / 2);
			for (int j = 1; j <= ww; j++)
			{
				int x = 2 * (i + j);
				int y = 2 * max(i, j);
				if (y <= h)
				{
					if (i != j)
					{
						a += 2 * (w - x + 1) * (h - y + 1);
					}
					else
					{
						a += (w - x + 1) * (h - y + 1);
					}
				}
			}
		}
		for (int i = 1; i <= h / 2; i++)
		{
			int hh = min(i, (h - i - i) / 2);
			for (int j = 1; j <= hh; j++)
			{
				int x = 2 * (i + j);
				int y = 2 * max(i, j);
				if (y <= w)
				{
					if (i != j)
					{
						a += 2 * (h - x + 1) * (w - y + 1);
					}
					else
					{
						a += (h - x + 1) * (w - y + 1);
					}
				}
			}
		}
		for (int i = 0; i < tot; i++)
		{
			int x = mat[i].xx + mat[i].zz;
			int y = mat[i].yy + mat[i].zz;
			for (int j = 1; j < mat[i].zz; j++)
			{
				int r = mat[i].zz - j;
				int k1 = max(x, max(2 * r, 2 * j));
				int k2 = max(y, max(2 * r, 2 * j));
				if (k1 <= w && k2 <= h)
				{
					a += 2 * (w + 1 - k1) * (h + 1 - k2);
				}
				if (k2 <= w && k1 <= h)
				{
					a += 2 * (h + 1 - k1) * (w + 1 - k2);
				}
			}
		}
		printf("Case %d: ", ca);
		cout << a << endl;
	}
	return 0;
}
