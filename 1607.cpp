#include <bits/stdc++.h>

using namespace std;

#define MAXM 262144
#define MAXN 131072

int IN1[MAXM], IN2[MAXM], VAL[MAXM], n, m;

int calc(int div)
{
	for (int i = 1; i <= m; i++)
	{
		int a = IN1[i], b = IN2[i], va, vb;
		va = a < 0 ? -a > div : VAL[a];
		vb = b < 0 ? -b > div : VAL[b];
		VAL[i] = !(va & vb);
	}
	return VAL[m];
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &IN1[i], &IN2[i]);
		}
		int v0 = calc(0), v1 = calc(n);
		if (v0 == v1)
		{
			for (int i = 0; i < n; i++)
			{
				printf("0");
			}
			printf("\n");
		}
		else
		{
			int l = 1, r = n + 1, mid, ret = 1;
			while (l <= r)
			{
				mid = (l + r) / 2;
				if (calc(mid) == v1)
				{
					r = mid - 1;
					ret = mid;
				}
				else
				{
					l = mid + 1;
				}
			}
			for (int i = 1; i < ret; i++)
			{
				printf("0");
			}
			printf("x");
			for (int i = ret + 1; i <= n; i++)
			{
				printf("1");
			}
			printf("\n");
		}
	}
	return 0;
}
