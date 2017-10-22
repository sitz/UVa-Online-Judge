#include <bits/stdc++.h>

using namespace std;

struct box
{
	int num, d, dimensions[10];
};

struct res
{
	int len, pos;
};

// tst if box a fits into box b
inline bool box_fits(const box &a, const box &b)
{
	for (int i = 0; i < a.d; i++)
		if (a.dimensions[i] >= b.dimensions[i])
			return false;
	return true;
}

inline bool ordering(const box &a, const box &b)
{
	for (int i = 0; i < a.d; i++)
	{
		if (a.dimensions[i] >= b.dimensions[i])
		{
			if (box_fits(b, a))
			{
				return true;
			}
			else
			{
				return a.num > b.num;
			}
		}
	}
	return false;
}

static int n, k, dp[30];
static box boxes[30];
static res best, tmp;

int main()
{
	while (scanf("%d%d", &n, &k) == 2)
	{
		for (int i = 0; i < 30; i++)
		{
			dp[i] = 1;
		}
		best.pos = 0;
		best.len = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < k; j++)
			{
				scanf("%d", &boxes[i].dimensions[j]);
			}
			boxes[i].d = k;
			boxes[i].num = i + 1;
			sort(boxes[i].dimensions, boxes[i].dimensions + k);
		}
		sort(boxes, boxes + n, ordering);
		for (int i = 0; i < n; i++)
		{
			if (boxes[i].num == 1)
			{
				best.pos = i;
			}
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (box_fits(boxes[i], boxes[j]))
				{
					dp[i] = max(dp[i], dp[j] + 1);
					if (dp[i] > best.len)
					{
						best.len = dp[i];
						best.pos = i;
					}
				}
			}
		}
		printf("%d\n%d", best.len, boxes[best.pos].num);
		best.len--;
		while (best.len)
		{
			printf(" ");
			tmp.len = 2000000;
			tmp.pos = 0;
			for (int i = 0; i < best.pos; i++)
			{
				if (dp[i] == best.len && box_fits(boxes[best.pos], boxes[i]))
				{
					tmp.len = min(tmp.len, boxes[i].num);
					if (tmp.len == boxes[i].num)
						tmp.pos = i;
				}
			}
			printf("%d", boxes[tmp.pos].num);
			best.pos = tmp.pos;
			best.len--;
		}
		printf("\n");
	}
	return 0;
}
