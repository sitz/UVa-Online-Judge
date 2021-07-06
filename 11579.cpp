#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/115/11579.html
// Runtime: 0.164s
// Tag: triangle, geometry

/*
 * File:   main.cpp
 * Author: shahab
 * Created on March 23, 2011, 12:26 PM
 */

// @BEGIN_OF_SOURCE_CODE

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long

#define For(i, a, b) for (int i = (a); i < (b); i++)
#define Fors(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Set(a, s) memset(a, s, sizeof(a))

double area(double x, double y, double z)
{
	if (x + y < z || x + z < y || y + z < x)
	{
		return 0;
	}
	double area = x + y + z;
	area /= 2;
	return sqrt(area * (area - x) * (area - y) * (area - z));
}

int main(int argc, char **argv)
{
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		int n;
		scanf("%d", &n);
		double s[10000 + 10];
		For(i, 0, n) scanf("%lf", &s[i]);
		sort(s, s + n);
		double ret = 0;
		for (int i = n - 1; i >= 2; i--)
		{
			ret = max(ret, area(s[i], s[i - 1], s[i - 2]));
		}
		printf("%.2lf\n", ret);
	}
	return 0;
}

// @END_OF_SOURCE_CODE
