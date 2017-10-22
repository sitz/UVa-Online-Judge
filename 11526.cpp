#include <bits/stdc++.h>

using namespace std;

/*
 *  Algorithm:
 *      There are n/2 1s, n/3 2s, n/4 3s ......
 *      Calculate all the num until only one num remain.
 *      Then sum all this nums.
 * */

typedef long long LL;

LL solve(int n)
{
	if (n < 0)
	{
		return 0;
	}
	int i, j, last = n;
	LL ans = 0;
	for (i = 2;; i++)
	{
		j = n / i;
		ans += (last - j) * (i - 1);
		if (last - j < 2)
		{
			break;
		}
		last = j;
	}
	for (; j >= 1; j--)
	{
		ans += n / j;
	}
	return ans;
}

int main()
{
	int t;
	LL n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}
