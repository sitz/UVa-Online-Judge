#include <bits/stdc++.h>

using namespace std;

struct Time
{
	int m, s, h;
	bool operator<(Time &t)
	{
		if (m < t.m)
		{
			return true;
		}
		if (m > t.m)
		{
			return false;
		}
		if (s < t.s)
		{
			return true;
		}
		if (s > t.s)
		{
			return false;
		}
		if (h < t.h)
		{
			return true;
		}
		if (h > t.h)
		{
			return false;
		}
		return false;
	}
	bool operator==(Time &t)
	{
		return m == t.m && s == t.s && h == t.h;
	}
};
struct Record
{
	int rank;
	Time t;
} comp[1000], sec[8];
int n;
int main()
{
	int T, rank;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; cases++)
	{
		scanf("%d", &n);
		scanf("%d", &rank);
		for (int i = 0; i < n - 1; i++)
		{
			scanf("%d %d:%d:%d", &comp[i].rank, &comp[i].t.m, &comp[i].t.s, &comp[i].t.h);
		}
		Time t;
		int bestX = 0, bestY = 0;
		for (t.m = 0; t.m < 10; t.m++)
			for (t.s = 0; t.s < 60; t.s++)
				for (t.h = 0; t.h < 100; t.h++)
				{
					int X = 0;
					for (int i = 0; i < n - 1 && X <= 7; i++)
						if (comp[i].t < t || (comp[i].t == t && comp[i].rank < rank))
						{
							sec[X++] = comp[i];
						}
					if (X >= 8)
					{
						continue;
					}
					int Y = 0;
					for (int i = 0; i < X; i++)
						if (sec[i].rank < rank)
						{
							Y++;
						}
					if (Y <= 2 && X > bestX)
					{
						bestX = X;
						bestY = Y;
					}
				}
		printf("Case #%d:\n", cases);
		printf("Gustavo should be #%d during the qualification to achieve position #%d in the final.\n", bestX + 1, bestY + 1);
	}
}
