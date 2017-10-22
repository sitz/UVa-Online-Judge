#include <bits/stdc++.h>

using namespace std;

int a[10000], b[10000], n, k;
bool pos, zero;
int swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
int abs(int v)
{
	return (v > 0) ? v : -v;
}
int compare(const void *a, const void *b)
{
	int c = *(int *)a, d = *(int *)b;
	int cc = abs(c), dd = abs(d);
	if (cc != dd)
	{
		return dd - cc;
	}
	else if (c == d)
	{
		return 0;
	}
	else if (c > d)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
int main()
{
	while (scanf("%d %d", &n, &k) == 2)
	{
		if (!n && !k)
		{
			break;
		}
		pos = zero = false;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
			if (a[i] > 0)
			{
				pos = true;
			}
		}
		if (n == k)
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				sum += a[i];
			}
			printf("%d\n", sum);
			continue;
		}
		qsort(a, n, sizeof(int), compare);
		for (int i = 0; i < k; i++)
			if (a[i] == 0)
			{
				zero = true;
			}
		if (zero)
		{
			int sum = 0;
			for (int i = 0; i < k; i++)
			{
				if (a[i] >= 0)
				{
					sum += a[i];
				}
				else
				{
					int j;
					for (j = k; j < n; j++)
						if (a[j] == 0)
						{
							swap(a[i], a[j]);
							break;
						}
					if (j == n)
					{
						sum += a[i];
					}
				}
			}
			printf("%d\n", sum);
			continue;
		}
		if (!pos)
		{
			int sum = 0;
			if (k & 1)
				for (int i = n - 1, j = 0; j < k; i--, j++)
				{
					sum += a[i];
				}
			else
				for (int i = 0; i < k; i++)
				{
					sum += a[i];
				}
			printf("%d\n", sum);
			continue;
		}
		int neg = 0, sum = 0;
		for (int i = 0; i < k; i++)
			if (a[i] < 0)
			{
				neg++;
			}
		for (int i = 0; i < k; i++)
		{
			sum += a[i];
		}
		if (neg & 1)
		{
			for (int i = 0; i < n; i++)
			{
				b[i] = a[i];
			}
			int p, sum1, sum2, temp;
			int a1, b1, a2, b2;
			char flag1, flag2;
			for (p = k; p < n && a[p] < 0; p++)
				;
			if (p != n)
			{
				if (a[p] == 0)
				{
					sum1 = 0;
					for (int i = 0; i < k; i++)
					{
						if (b[i] < 0)
						{
							for (int j = k; j < n; j++)
								if (b[j] == 0)
								{
									swap(b[i], b[j]);
									break;
								}
						}
						sum1 += b[i];
					}
					flag1 = 0;
				}
				else
				{
					b1 = a[p];
					for (p = k - 1; a[p] >= 0; p--)
						;
					a1 = a[p];
					sum1 = sum - a1 + b1;
					flag1 = 1;
				}
			}
			else
			{
				flag1 = 2;
			}
			for (int i = 0; i < n; i++)
			{
				b[i] = a[i];
			}
			for (p = k - 1; p >= 0 && a[p] < 0; p--)
				;
			if (p < 0)
			{
				flag2 = 0;
			}
			else
			{
				a2 = a[p];
				for (p = k; a[p] >= 0 && p < n; p++)
					;
				if (p >= n)
				{
					flag2 = 0;
				}
				else
				{
					b2 = a[p];
					sum2 = sum - a2 + b2;
					flag2 = 1;
				}
			}
			if (flag1 == 2 && flag2 == 0)
			{
				temp = sum;
			}
			else if (flag1 == 2 && flag2 == 1)
			{
				temp = sum2;
			}
			else if (flag1 == 0 && flag2 == 0)
			{
				temp = sum1;
			}
			else if (flag1 == 0 && flag2 == 1)
			{
				temp = sum2;
			}
			else if (flag1 == 1 && flag2 == 0)
			{
				temp = sum1;
			}
			else
			{
				int t = abs(b1) * abs(a2) - abs(a1) * abs(b2);
				if (t < 0)
				{
					temp = sum2;
				}
				else if (temp > 0)
				{
					temp = sum1;
				}
				else
				{
					temp = (sum1 > sum2) ? sum1 : sum2;
				}
			}
			sum = temp;
		}
	end:
		printf("%d\n", sum);
	}
}
