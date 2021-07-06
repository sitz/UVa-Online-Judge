#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/115/11572.html
// Runtime: 0.416s
// Tag: Adhoc, set Window

/*
 * File:   main.cpp
 * Author: shahab
 * Created on March 16, 2011, 8:17 PM
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

int main(int argc, char **argv)
{
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		int n, ar[N + 10], previous_position[N + 10];
		scanf("%d", &n);
		map<int, int> m;
		int cnt = 0;
		int maxi = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &ar[i]);
			previous_position[i] = m[ar[i]];
			m[ar[i]] = i;
		}
		int curr = 1;
		int previous = 1;
		for (curr = 1; curr <= n; curr++)
		{
			if (previous_position[curr] >= previous)
			{
				maxi = max(maxi, curr - previous);
				previous = previous_position[curr] + 1;
			}
		}
		maxi = max(maxi, curr - previous);
		printf("%d\n", maxi);
	}
	return 0;
}

// @END_OF_SOURCE_CODE
