#include <bits/stdc++.h>

using namespace std;

int seg[405][1205], mat[405][1205];

void init(int *arr, int *mat, int now, int l, int r)
{
	int c;
	arr[now] = 0;
	mat[now] = 0;
	if (l != r)
	{
		c = (l + r) / 2;
		init(arr, mat, now << 1, l, c);
		init(arr, mat, (now << 1) + 1, c + 1, r);
	}
}

int chk(int *arr, int *mat, int now, int l, int r, int tl, int tr)
{
	int c, res;
	if (arr[now])
	{
		return 1;
	}
	if (tl <= l && tr >= r)
	{
		return arr[now] + mat[now];
	}
	res = 0;
	c = (l + r) / 2;
	if (c >= tl && tr >= l)
	{
		res |= chk(arr, mat, now << 1, l, c, tl, tr);
	}
	if (r >= tl && tr >= c + 1)
	{
		res |= chk(arr, mat, (now << 1) + 1, c + 1, r, tl, tr);
	}
	return res;
}

int insert(int *arr, int *mat, int now, int l, int r, int tl, int tr)
{
	int c;
	if (tl <= l && tr >= r)
	{
		arr[now] = 1;
		return 1;
	}
	c = (l + r) / 2;
	if (c >= tl && tr >= l)
	{
		mat[now] |= insert(arr, mat, now << 1, l, c, tl, tr);
	}
	if (r >= tl && tr >= c + 1)
	{
		mat[now] |= insert(arr, mat, (now << 1) + 1, c + 1, r, tl, tr);
	}
	return arr[now] | mat[now];
}

int main()
{
	int count, cas, n, i, j, x1, x2, y1, y2, ans;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i = 0; i <= 200; i++)
		{
			init(seg[i], mat[i], 1, 0, 200);
		}
		for (i = 0, ans = 0; i < n; i++)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for (j = x1; j < x2; j++)
			{
				if (chk(seg[j + 100], mat[j + 100], 1, 0, 200, y1 + 100, y2 + 100 - 1))
				{
					break;
				}
			}
			if (j >= x2)
			{
				for (j = x1; j < x2; j++)
				{
					insert(seg[j + 100], mat[j + 100], 1, 0, 200, y1 + 100, y2 + 100 - 1);
				}
				ans += (x2 - x1) * (y2 - y1);
			}
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
