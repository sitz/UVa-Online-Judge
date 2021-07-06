#include <bits/stdc++.h>

using namespace std;

int powten[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

long long m, n, cnt;

void solve(long long range, int level)
{
	if (range < 10)
	{
		return;
	}
	long long flor = range / 10 * 10;
	for (long long k = flor + 1; k <= range; k++)
	{
		long long mm = k;
		while (mm)
		{
			if (mm % 10 == 0)
			{
				cnt += powten[level];
			}
			mm /= 10;
		}
	}
	cnt += flor / 10 * powten[level];
	int temp = flor / 10;
	while (temp)
	{
		if (temp % 10 == 0)
		{
			cnt += powten[level];
		}
		temp /= 10;
	}
	solve(flor / 10 - 1, level + 1);
}

int main()
{
	while (cin >> m >> n && m >= 0 && n >= 0)
	{
		long long cntM, cntN;
		if (m == n)
		{
			cnt = 0;
			if (m == 0)
			{
				cnt++;
			}
			while (m)
			{
				if (m % 10 == 0)
				{
					cnt++;
				}
				m /= 10;
			}
			cout << cnt << endl;
		}
		else
		{
			cnt = 0;
			solve(m - 1, 0);
			cntM = cnt;
			cnt = 0;
			solve(n, 0);
			cntN = cnt;
			long long result = cntN - cntM;
			if (m == 0)
			{
				result++;
			}
			cout << result << endl;
		}
	}
	return 0;
}
