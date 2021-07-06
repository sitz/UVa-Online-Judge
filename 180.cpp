#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000001;
int f[maxn], g[maxn];
bool safe[maxn];

void init()
{
	for (int i = 1; i <= maxn; i++)
	{
		f[i] = (f[i - 1] + 15) % i, g[i] = (i - f[i]) % i;
	}
}

int main()
{
	init();
	int min, max;
	while (scanf("%d %d", &min, &max) == 2, min + max > 0)
	{
		if (min > max)
		{
			int t = min;
			min = max;
			max = t;
		}
		memset(safe, true, sizeof(safe));
		for (int i = min; i <= max; i++)
		{
			safe[f[i]] = safe[g[i]] = false;
		}
		int p;
		for (p = 1; p <= min / 2; p++)
			if (safe[p])
			{
				printf("%d\n", p);
				break;
			}
		if (p > min / 2)
		{
			puts("Better estimate needed");
		}
	}
}
