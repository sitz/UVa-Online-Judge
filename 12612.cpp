#include <bits/stdc++.h>

using namespace std;

#define MAXN 20005

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;

int points[MAXN][3];
int n;
int ax, bx, ay, by, az, bz;

bool inside(int x, int y, int z)
{
	return bx < x && x < ax &&
				 by < y && y < ay &&
				 bz < z && z < az;
}
bool good()
{
	for (int i = 0; i < n; i++)
	{
		if (points[i][0] < bx)
			return false;
		if (points[i][0] > ax)
			return false;
		if (points[i][1] < by)
			return false;
		if (points[i][1] > ay)
			return false;
		if (points[i][2] < bz)
			return false;
		if (points[i][2] > az)
			return false;
		if (inside(points[i][0], points[i][1], points[i][2]))
			return false;
	}
	return true;
}

void solve()
{
	int maxx, maxy, maxz, minx, miny, minz;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &points[i][0], &points[i][1], &points[i][2]);
	}
	maxx = minx = points[0][0];
	maxy = miny = points[0][1];
	maxz = minz = points[0][2];

	for (int i = 1; i < n; i++)
	{
		maxx = max(maxx, points[i][0]);
		minx = min(minx, points[i][0]);
		maxy = max(maxy, points[i][1]);
		miny = min(miny, points[i][1]);
		maxz = max(maxz, points[i][2]);
		minz = min(minz, points[i][2]);
	}

	int maxsize = max(maxx - minx, max(maxy - miny, maxz - minz));

	for (int i = 0; i < 1 << 3; i++)
	{
		ax = maxx, bx = minx, ay = maxy, by = miny, az = maxz, bz = minz;
		if (i & 1)
			ax = bx + maxsize;
		else
			bx = ax - maxsize;
		if (i & 2)
			ay = by + maxsize;
		else
			by = ay - maxsize;
		if (i & 4)
			az = bz + maxsize;
		else
			bz = az - maxsize;
		if (good())
		{
			printf("%d\n", maxsize);
			return;
		}
	}
	printf("-1\n");
}

int main()
{
	int test;
	scanf("%d", &test);
	for (int tt = 1; tt <= test; tt++)
	{
		printf("Case %d: ", tt);
		solve();
	}
	return 0;
}
