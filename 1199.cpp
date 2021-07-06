#include <bits/stdc++.h>

using namespace std;

int f[105];
vector<int> stopFloor;

int chk(int lim, int mx)
{
	int lfloor = lim / 20 + 2;// floor of last person be stopped
	int sfloor = 1;						// now stopping floor
	int scnt = 0;							// stopped times
	vector<int> buf;
	while (lfloor <= mx)
	{
		while (lfloor <= mx && f[lfloor] == 0)
		{
			lfloor++;
		}
		if (scnt * 10 + (lfloor - 1) * 4 > lim)
		{
			return 0;
		}
		int nfloor = (lim - 10 * scnt + 20 * lfloor + 4) / 24;//nxt stopping floor
		lfloor = (lim - 10 * scnt + 16 * nfloor + 4) / 20 + 1;
		sfloor = nfloor;
		buf.push_back(nfloor);
		scnt++;
	}
	stopFloor = buf;
	return 1;
}

int main()
{
	int n, i, j, k, x;
	while (scanf("%d", &n) == 1 && n)
	{
		memset(f, 0, sizeof(f));
		int mx = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &x), f[x] = 1;
			mx = max(mx, x);
		}
		int l = 0, r = mx * (14), mid, ret = 0;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (chk(mid, mx))
			{
				ret = mid, r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		printf("%d\n", ret);
		printf("%d", stopFloor.size());
		for (i = 0; i < stopFloor.size(); i++)
		{
			printf(" %d", stopFloor[i]);
		}
		printf("\n");
	}
	return 0;
}
