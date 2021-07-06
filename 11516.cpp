#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/115/11516.html
// Runtime : 0.060s
// Tag : binary search

// @BEGIN_OF_SOURCE_CODE

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long

int n, m;
int houseNo[100000 + 10];

bool check(int mid)
{
	int used = 1;
	int wifirange = houseNo[0] + mid;
	for (int i = 0; i < m; i++)
	{
		if (houseNo[i] > wifirange)
		{
			wifirange = houseNo[i] + mid;
			used++;
		}
	}
	return used <= n;
}

int main()
{
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &houseNo[i]);
		}
		if (n >= m)
		{
			printf("0.0\n");
			continue;
		}
		sort(houseNo, houseNo + m);
		int lo = 0;
		int hi = N;
		while (hi - lo > 1)
		{
			int mid = (lo + hi) / 2;
			if (check(mid * 2))
			{
				hi = mid;
			}
			else
			{
				lo = mid;
			}
		}
		lo *= 10;
		hi *= 10;
		for (int i = 0; i < m; i++)
		{
			houseNo[i] *= 10;
		}
		while (hi - lo > 1)
		{
			int mid = (lo + hi) / 2;
			if (check(mid * 2))
			{
				hi = mid;
			}
			else
			{
				lo = mid;
			}
		}
		printf("%d.%d\n", hi / 10, hi % 10);
	}
	return 0;
}

// @END_OF_SOURCE_CODE
