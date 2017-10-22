#include <bits/stdc++.h>

using namespace std;

int compare(const void *a, const void *b)
{
	float c = *(double *)a, d = *(double *)b;
	if (c < d)
	{
		return -1;
	}
	else if (c > d)
	{
		return 1;
	}
	return 0;
}
double neg[10000], pos[10000], t;
int n, lenn, lenp, zero;
int findlower(int left, int right, double value)
{
	if (neg[right] < value)
	{
		return right;
	}
	int mid = (left + right) / 2;
	while (left <= right)
	{
		if (neg[mid] < value && neg[mid + 1] >= value)
		{
			return mid;
		}
		if (neg[mid] > value)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
		mid = (left + right) / 2;
	}
	return -1;
}
int findlowerp(int left, int right, double value)
{
	if (pos[right] < value)
	{
		return right;
	}
	int mid = (left + right) / 2;
	while (left <= right)
	{
		if (pos[mid] < value && pos[mid + 1] >= value)
		{
			return mid;
		}
		if (pos[mid] > value)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
		mid = (left + right) / 2;
	}
	return -1;
}
int findupper(int left, int right, double value)
{
	if (neg[left] > value)
	{
		return left;
	}
	int mid = (left + right) / 2;
	while (left <= right)
	{
		if (neg[mid] > value && neg[mid - 1] <= value)
		{
			return mid;
		}
		if (neg[mid] > value)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
		mid = (left + right) / 2;
	}
	return -1;
}
int main()
{
	int caseno = 1;
	while (scanf("%d", &n), n)
	{
		lenn = lenp = zero = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", &t);
			if (t < 0)
			{
				neg[lenn++] = t;
			}
			else if (t > 0)
			{
				pos[lenp++] = t;
			}
			else
			{
				zero++;
			}
		}
		qsort(neg, lenn, sizeof(double), compare);
		qsort(pos, lenp, sizeof(double), compare);
		int sum = 0;
		for (int i = 1; i < lenn; i++)
		{
			int lower = findlower(0, i - 1, (double)1 / neg[i]);
			sum += lower + 1;
		}
		for (int i = 0; i < lenp; i++)
		{
			sum += zero;
			int s = findupper(0, lenn - 1, -pos[i]);
			if (s != -1)
			{
				sum += lenn - s;
			}
			int t = findlowerp(0, i - 1, (double)1 / pos[i]);
			sum += t + 1;
		}
		printf("Case %d: %d\n", caseno++, sum);
	}
	return 0;
}
