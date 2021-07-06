#include <bits/stdc++.h>

using namespace std;

char tmp[1000];
double sum, r[100];
int i, j, k, m, n, R[100], prev_[20001], who[20001];

int main()
{
	while (1 == scanf("%d", &n) && n)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%lf", &r[i]);
		}
		for (i = sum = 0; i < n; i++)
		{
			sum += r[i];
		}
		for (i = 0; i < n; i++)
		{
			R[i] = r[i] * 20000 / sum;
		}
		memset(who, 0, sizeof(who));
		memset(prev_, 0, sizeof(prev_));
		who[0] = -1;
		for (i = 0; i < n; i++)
		{
			for (j = 10000; j >= 0; j--)
			{
				if (!who[j])
				{
					continue;
				}
				if (who[j + R[i]])
				{
					continue;
				}
				who[j + R[i]] = i + 1;
				prev_[j + R[i]] = j;
			}
		}
		for (i = 10000; !who[i]; i--)
			;
		while (i)
		{
			printf("%d ", who[i]);
			i = prev_[i];
		}
		printf("\n");
	}
	if (n != 0)
	{
		printf("missing end delimiter\n");
	}
	return 0;
}
