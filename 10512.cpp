#include <bits/stdc++.h>

using namespace std;

long long int ans[6][2];
int pa;

// binary search
long long int sqrt(long long int k)
{
	long long int left = 0ll, right = 4294967295ll, mid = (left + right) / 2;
	while (left <= right)
	{
		if (mid * mid == k)
		{
			return mid;
		}
		else if (mid * mid < k)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
		mid = (left + right) / 2;
	}
	return -1;
}

long long int a, b, c, d;
int P, Q;

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%d %d", &P, &Q);
		a = 2ll, b = (long long int)-P - P - P - Q, c = (long long int)P * P;
		//printf("%I64d %I64d %I64d\n",a,b,c);
		printf("Case %d:\n", i);
		d = b * b - 4 * a * c;
		d = sqrt(d);
		if (d == -1)
		{
			puts("Impossible.");
		}
		else
		{
			pa = 0;
			long long int t1 = -b + d, t2 = -b - d, x = 65536, y, tx, ty;
			if (t1 % (2 * a) == 0)
			{
				t1 = t1 / (2 * a);
				t1 = sqrt(t1);
				if (t1 != -1)
				{
					if (t1 != 0 && P % t1 == 0)
					{
						tx = P / t1 - t1;
						ty = t1;
						ans[pa][0] = tx;
						ans[pa++][1] = ty;
						ty = -t1;
						tx = P / ty - ty;
						ans[pa][0] = tx;
						ans[pa++][1] = ty;
					}
					else
					{
						tx = sqrt(Q);
						ty = 0;
						if (tx != -1)
						{
							ans[pa][0] = tx;
							ans[pa++][1] = ty;
						}
					}
				}
			}
			if (t2 % (2 * a) == 0)
			{
				t2 = t2 / (2 * a);
				t2 = sqrt(t2);
				if (t2 != 0 && P % t2 == 0)
				{
					tx = P / t2 - t2;
					ty = t2;
					ans[pa][0] = tx;
					ans[pa++][1] = ty;
					ty = -t2;
					tx = P / ty - ty;
					ans[pa][0] = tx;
					ans[pa++][1] = ty;
				}
				else
				{
					tx = sqrt(Q);
					ty = 0;
					if (tx != -1)
					{
						ans[pa][0] = tx;
						ans[pa++][1] = ty;
					}
				}
			}
			long long int ansx = 65536ll, ansy = 65536ll;
			for (int i = 0; i < pa; i++)
				if (ans[i][0] >= ans[i][1] && ans[i][0] < ansx)
				{
					ansx = ans[i][0], ansy = ans[i][1];
				}
			if (ansx == 65536ll)
			{
				puts("Impossible.");
			}
			else
			{
				printf("%lld %lld\n", ansx, ansy);
			}
		}
	}
	return 0;
}
