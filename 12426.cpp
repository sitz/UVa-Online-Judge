#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001
struct point
{
	long long x, y;
	point() {}
	point(long long x0, long long(y0)) : x(x0), y(y0) {}
};
int n, T;
long long max_area;
point a[2 * MAXN];
int edge[MAXN][MAXN][2];
point operator-(const point &A, const point &B)
{
	return point(A.x - B.x, A.y - B.y);
}
long long cross(point A, point B)
{
	return A.x * B.y - A.y * B.x;
}
void rotate()
{
	int i, k;
	int j1, j2;
	for (k = 1; k < n; k++)
	{
		j1 = 1;
		j2 = k + 1;
		for (i = 1; i <= n; i++)
		{
			if (i + k > n)
			{
				break;
			}
			while (abs(cross(a[i] - a[j1 + 1], a[i + k] - a[j1 + 1])) > abs(cross(a[i] - a[j1], a[i + k] - a[j1])))
			{
				j1 = j1 % n + 1;
			}
			edge[i][i + k][0] = j1;
			while (abs(cross(a[i] - a[j2 + 1], a[i + k] - a[j2 + 1])) > abs(cross(a[i] - a[j2], a[i + k] - a[j2])))
			{
				j2 = j2 % n + 1;
			}
			edge[i][i + k][1] = j2;
		}
	}
}
int binary(int i, int k, int j)
{
	long long s;
	int left = i, right;
	int ans = 0;
	if (k < i)
	{
		right = k + n;
	}
	else
	{
		right = k;
	}
	while (left < right)
	{
		int mid = (left + right) / 2;
		s = abs(cross(a[i] - a[mid], a[j] - a[mid]));
		if (max_area < s)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
		if (right - left == 1)
		{
			break;
		}
	}
	ans = left - i;
	left = k;
	if (j < k)
	{
		right = j + n;
	}
	else
	{
		right = j;
	}
	while (left < right)
	{
		int mid = (left + right) / 2;
		s = abs(cross(a[i] - a[mid], a[j] - a[mid]));
		if (max_area < s)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
		if (right - left == 1)
		{
			break;
		}
	}
	ans += (j + n - right) % n;
	return ans;
}
int solve()
{
	int i, j;
	long long ans = 0;
	int k1, k2;
	long long s;
	for (i = 1; i < n; i++)
		for (j = i + 1; j <= n; j++)
		{
			k1 = edge[i][j][0];
			k2 = edge[i][j][1];
			s = abs(cross(a[i] - a[k1], a[j] - a[k1]));
			if (j > i + 1)
			{
				if (max_area >= s)
				{
					ans += j - i - 1;
				}
				else
				{
					ans += binary(i, k1, j);
				}
			}
			if (i + n > j + 1)
			{
				s = abs(cross(a[i] - a[k2], a[j] - a[k2]));
				if (max_area >= s)
				{
					ans += i + n - j - 1;
				}
				else
				{
					ans += binary(j, k2, i);
				}
			}
		}
	return ans / 3;
}
int main()
{
	scanf("%d", &T);
	int i, j;
	for (j = 1; j <= T; j++)
	{
		scanf("%d%lld", &n, &max_area);
		max_area *= 2;
		for (i = 1; i <= n; i++)
		{
			scanf("%lld%lld", &a[i].x, &a[i].y);
			a[n + i] = a[i];
		}
		rotate();
		printf("%d\n", solve());
	}
	return 0;
}
