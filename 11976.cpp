#include <bits/stdc++.h>

using namespace std;

const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, leap[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void incre(int &y, int &m, int &d)
{
	d = (d == (y % 4 == 0 ? leap[m] : days[m]) ? 1 : d + 1);
	if (d == 1)
		++m;
	if (m == 13)
	{
		m = 1;
		++y;
	}
}

int main()
{
	int t, except, y, m, d, by, bm, bd, ey, em, ed;
	char type;
	scanf("%d", &t);

	for (int i = 1; i <= t; ++i)
	{
		bool holiday[2026][13][32];
		int work = 0, week = 3;
		scanf("%d", &except);
		for (int Y = 1975; Y <= 2025; ++Y)
			for (int M = 1; M <= 12; ++M)
				for (int D = 1; D <= (Y % 4 ? days[M] : leap[M]); ++D)
				{
					holiday[Y][M][D] = week <= 5 && week >= 1 ? false : true;
					week = (week + 1) % 7;
				}
		for (int i = 0; i < except; ++i)
		{
			scanf("%d-%d-%d %c\n", &y, &m, &d, &type);
			holiday[y][m][d] = type == 'H' ? true : false;
		}
		scanf("%d-%d-%d %d-%d-%d", &by, &bm, &bd, &ey, &em, &ed);
		for (y = by, m = bm, d = bd; y != ey || m != em || d != ed; incre(y, m, d))
			if (!holiday[y][m][d])
				++work;
		if (!holiday[ey][em][ed])
			++work;
		printf("Case %d: %d\n", i, work);
	}

	return 0;
}
