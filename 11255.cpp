#include <bits/stdc++.h>

using namespace std;

long long cn[41][41];
void init(void)
{
	cn[0][0] = 1;
	for (int i = 1; i <= 40; i++)
		for (int j = 0; j <= i; j++)
		{
			cn[i][j] = cn[i - 1][j - 1] + cn[i - 1][j];
		}
}
long long gcd(long long a, long long b)
{
	while (b)
	{
		b ^= a ^= b ^= a %= b;
	}
	return a;
}
int main(void)
{
	int cas, n, cnt[3];
	init();
	cin >> cas;
	while (cas--)
	{
		cin >> cnt[0] >> cnt[1] >> cnt[2];
		n = cnt[0] + cnt[1] + cnt[2];
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			long long t = n / gcd(i, n);
			if (cnt[0] % t || cnt[1] % t || cnt[2] % t)
			{
				continue;
			}
			ans += cn[n / t][cnt[0] / t] * cn[n / t - cnt[0] / t][cnt[1] / t];
		}
		if (n % 2)
		{
			for (int i = 0; i < 3; cnt[i++]++)
			{
				cnt[i]--;
				if (cnt[i] < 0)
				{
					continue;
				}
				if (cnt[0] % 2 || cnt[1] % 2 || cnt[2] % 2)
				{
					continue;
				}
				ans += n * cn[n / 2][cnt[0] / 2] * cn[n / 2 - cnt[0] / 2][cnt[1] / 2];
			}
		}
		else
		{
			if (!(cnt[0] % 2 || cnt[1] % 2 || cnt[2] % 2))
			{
				ans += n / 2 * cn[n / 2][cnt[0] / 2] * cn[n / 2 - cnt[0] / 2][cnt[1] / 2];
			}
			for (int i = 0; i < 3; cnt[i++]++)
			{
				cnt[i]--;
				if (cnt[i] < 0)
				{
					continue;
				}
				for (int j = 0; j < 3; cnt[j++]++)
				{
					cnt[j]--;
					if (cnt[j] < 0)
					{
						continue;
					}
					if (cnt[0] % 2 || cnt[1] % 2 || cnt[2] % 2)
					{
						continue;
					}
					ans += n / 2 * cn[n / 2 - 1][cnt[0] / 2] * cn[n / 2 - 1 - cnt[0] / 2][cnt[1] / 2];
				}
			}
		}
		ans /= 2 * n;
		cout << ans << endl;
	}
}
