#include <bits/stdc++.h>

using namespace std;

long long K, N, S, D;

struct Point
{
	long long x, y;
} p[10010];
long long Where(long long pos, Point A)
{
	long long x = A.x, y = A.y;
	if (D * D - (y - pos) * (y - pos) < 0)
	{
		return -99999999999ll;
	}
	return (long long)(x + sqrt(D * D - (y - pos) * (y - pos)));
}

bool Getdist(long long x, long long y, long long h, long long l)
{
	if ((h - x) * (h - x) + (y - l) * (y - l) <= D * D)
	{
		return true;
	}
	return false;
}
long long pos;
bool cmp(const Point &A, const Point &B)
{
	return Where(pos, A) < Where(pos, B);
}

bool Judge(long long DIST)
{
	pos = K - DIST;
	for (int i = 1; i <= N; i++)
		if (Where(pos, p[i]) == -99999999999ll)
		{
			return false;
		}
	sort(p + 1, p + 1 + N, cmp);
	Point last;
	last.x = Where(pos, p[1]);
	last.y = pos;
	int need = 1;
	for (int i = 2; i <= N; i++)
	{
		if (Getdist(last.x, last.y, p[i].x, p[i].y))
		{
			continue;
		}
		else
		{
			last.x = Where(pos, p[i]);
			need++;
		}
	}
	return (need <= S);
}

int main()
{
	int T;
	scanf("%d", &T);
	int cas = 0;
	while (T--)
	{
		scanf("%lld%lld%lld%lld", &K, &N, &S, &D);
		for (int i = 1; i <= N; i++)
		{
			scanf("%lld%lld", &p[i].x, &p[i].y);
		}
		long long L = 0, R = D, mid;
		if (!Judge(0))
		{
			printf("Case %d: IMPOSSIBLE\n", ++cas);
			continue;
		}
		while (L < R)
		{
			mid = (L + R + 1) / 2;
			if (Judge(mid))
			{
				L = mid;
			}
			else
			{
				R = mid - 1;
			}
		}
		printf("Case %d: %lld\n", ++cas, L);
	}
	return 0;
}
