#include <bits/stdc++.h>

using namespace std;

/*排序..水。。
 *
 * WA的话试试以下2租数据
 *    1
 *    2 11 16
 *    2
 *     2 11 16
 *    2 1 3
 *    输出应该是
 *    Workyards 1
 *    Maximum profit is 0.
 *    Number of pruls to buy: 0
 *
 *    Workyards 2
 *    Maximum profit is 16.
 *    Number of pruls to buy: 2
 *    要注意最大利润小于0时的情况，最大利润小于0时，商人是不会买该堆的物品，即此时该堆最大的利润应该是0，而不是所求得的那个负数。
 *
 */

const int MAXW = 50 + 5;
const int MAXB = 20 + 5;

int w, b[MAXW], data[MAXW][MAXB];//输入的数据
int p[MAXW][MAXB], num[MAXW][MAXB], imax[MAXW], k[MAXW];
//p[i][j]:第i组买j个的利润...num[i][j]:第i组等达到利润最大的买的个数。。。imax[i]:第i组的最大利润。。。k[i]:num[i]的上界
int ans_max, ans[10000], t;//ans_max:最大利润。。。ans[]：买的个数。。。。t：ans的上界

void ini()
{
	memset(p, 0, sizeof(p));
	memset(imax, 0, sizeof(imax));
	memset(k, 0, sizeof(k));
	memset(num, 0, sizeof(num));
	t = 0, ans_max = 0;
}

void dfs(int i, int last_v)
{
	if (i == w + 1)
	{
		ans[t++] = last_v;
		return;
	}
	if (imax[i] == 0)
	{
		dfs(i + 1, last_v);
	}
	for (int q = 1; q <= k[i]; q++)
	{
		dfs(i + 1, last_v + num[i][q]);
	}
}

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int tot = 0;
	bool first = true;
	while (scanf("%d", &w))
	{
		if (w == 0)
		{
			return 0;
		}
		if (!first)
		{
			printf("\n");
		}
		tot++;
		ini();
		for (int i = 1; i <= w; i++)
		{
			scanf("%d", &b[i]);
			for (int j = 1; j <= b[i]; j++)
			{
				scanf("%d", &data[i][j]);
				p[i][j] = p[i][j - 1] + 10 - data[i][j];
				if (imax[i] < p[i][j])
				{
					imax[i] = p[i][j];
				}
			}
		}
		for (int i = 1; i <= w; i++)
		{
			for (int j = 1; j <= b[i]; j++)
			{
				if (p[i][j] == imax[i])
				{
					num[i][++k[i]] = j;
				}
			}
			ans_max += imax[i];
		}
		dfs(1, 0);
		qsort(ans, t, sizeof(int), cmp);
		printf("Workyards %d\nMaximum profit is %d.\n", tot, ans_max);
		printf("Number of pruls to buy: ");
		int i = 0, j = 0;
		for (; j < 10 - 1 && i < t - 1; i++)
		{
			if (i == 0 || (i != 0 && ans[i] != ans[i - 1]))
			{
				printf("%d ", ans[i]);
				j++;
			}
		}
		for (; i < t; i++)
		{
			if (i == 0 || (i != 0 && ans[i] != ans[i - 1]))
			{
				printf("%d\n", ans[i]);
				break;
			}
		}
		first = false;
	}
	return 0;
}
