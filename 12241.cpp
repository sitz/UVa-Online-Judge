#include <bits/stdc++.h>

using namespace std;

int c[2][10], pow10_[10];

void cnt_f(int x, bool up)
{
	int *cnt = c[up], d, dcnt = 0, r = 0, rem0 = 0, v;
	while (x)
	{
		d = x % 10;
		x /= 10;
		if (dcnt)
		{
			v = d * pow10_[dcnt - 1] * dcnt;
			for (int i = 0; i < 10; ++i)
			{
				cnt[i] += v;
			}
			if (!d)
			{
				rem0 += (pow10_[dcnt] - 1) - r;
			}
		}
		v = pow10_[dcnt];
		for (int i = 1; i < d; ++i)
		{
			cnt[i] += v;
		}
		if (d)
		{
			cnt[d] += r + 1;
		}
		r = pow10_[dcnt++] * d + r;
	}
	cnt[0] -= rem0;
}

int main()
{
	pow10_[0] = 1;
	for (int i = 1; i < 10; ++i)
	{
		pow10_[i] = 10 * pow10_[i - 1];
	}
	for (int a, b; scanf("%d %d", &a, &b) == 2 && (a || b);)
	{
		for (int i = 0; i < 10; ++i)
		{
			c[0][i] = c[1][i] = 0;
		}
		cnt_f(b, 1);
		cnt_f(a - 1, 0);
		for (int i = 0; i < 10; ++i)
		{
			if (i)
			{
				putc(32, stdout);
			}
			printf("%d", c[1][i] - c[0][i]);
		}
		putc(10, stdout);
	}
	return 0;
}
