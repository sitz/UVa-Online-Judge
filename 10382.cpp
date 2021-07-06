#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 10000

struct Sprinkler
{
	double L, R;
	bool operator<(const Sprinkler &s) const
	{
		return L < s.L;
	}
} sprinklers[MAX_SIZE + 1];

int main()
{
	double w;
	int n, l;
	while (scanf("%d%d%lf", &n, &l, &w) == 3)
	{
		w /= 2.0;
		int m = 0;
		for (int i = 0; i < n; ++i)
		{
			int p, r;
			scanf("%d%d", &p, &r);
			if (r > w)
			{
				double half_len = sqrt((double)r * r - w * w);
				sprinklers[m].L = (double)p - half_len;
				sprinklers[m++].R = (double)p + half_len;
			}
		}
		sort(sprinklers, sprinklers + m);

		double rightmost = 0.0f;
		int cnt = 0;
		int i, j;
		for (i = 0; i < m; i = j)
		{
			if (sprinklers[i].L > rightmost)
			{
				break;
			}
			for (j = i + 1; j < m && sprinklers[j].L <= rightmost; ++j)
			{
				if (sprinklers[j].R > sprinklers[i].R)
				{
					i = j;
				}
			}
			++cnt;
			rightmost = sprinklers[i].R;
			if (rightmost >= l)
			{
				break;
			}
		}

		if (rightmost >= l)
		{
			printf("%d\n", cnt);
		}
		else
		{
			printf("-1\n", cnt);
		}
	}
	return 0;
}
