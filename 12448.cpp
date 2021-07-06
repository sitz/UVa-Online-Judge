#include <bits/stdc++.h>

using namespace std;

struct note
{
	long long a, b;
} dp[200][200];

long long gcd(long long a, long long b)
{
	while (b)
	{
		long long t = a % b;
		a = b;
		b = t;
	}
	return a;
}

note add(note a, note b)
{
	note re;
	re.b = a.b * b.b;
	re.a = a.a * b.b + b.a * a.b;
	long long d = gcd(re.a, re.b);
	re.a = re.a / d;
	re.b = re.b / d;
	return re;
}
note mul(note a, note b)
{
	note re;
	re.a = a.a * b.a;
	re.b = a.b * b.b;
	long long d = gcd(re.a, re.b);
	re.a = re.a / d;
	re.b = re.b / d;
	return re;
}
int main()
{
	//cout << gcd(1,0) << " " << gcd(0,1);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		n = 140;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dp[i][j].a = 0;
				dp[i][j].b = 1;
			}
		}
		dp[0][0].a = 1;
		dp[0][0].b = 1;
		cin >> n >> m >> k;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 0; j <= k; j++)
			{
				note no;
				no.a = j;
				no.b = n;
				note yes;
				yes.a = n - j + 1;
				yes.b = n;
				if (j != 0)
				{
					dp[i][j] = add(mul(dp[i - 1][j], no), mul(dp[i - 1][j - 1], yes));
				}
				else
				{
					dp[i][j] = mul(dp[i - 1][j], no);
				}
			}
		}
		if (dp[m][k].a == 0)
		{
			cout << "0\n";
		}
		else if (dp[m][k].b == 1)
		{
			cout << dp[m][k].a << "\n";
		}
		else
		{
			cout << dp[m][k].a << "/" << dp[m][k].b << "\n";
		}
	}
	return 0;
}
