#include <bits/stdc++.h>

using namespace std;

int ary[100001], tbl[100001];

int main()
{
	int count, i, j, k, l, n, m, a, b, temp;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &k, &m);
		ary[0] = temp = tbl[1] = k + 2;
		for (i = 2, j = 0, l = 1, n = temp + temp; i < 100001; i++)
		{
			if (i == ary[j])
			{
				tbl[i] = -1;
				n++;
				j++;
			}
			else
			{
				tbl[i] = n;
				ary[l++] = n;
				n += temp;
			}
		}
		while (m--)
		{
			scanf("%d%d", &a, &b);
			if (tbl[a] == b || tbl[b] == a)
			{
				printf("LOSING\n");
			}
			else
			{
				printf("WINNING\n");
			}
		}
		printf("\n");
	}
	return 0;
}
