#include <bits/stdc++.h>

using namespace std;

int n, m, digit[10], x;
unsigned long long sum, p10[15], comb[15][15], fact[15];

void init()
{
	int i, j;
	p10[0] = 1;
	fact[0] = 1;
	for (i = 1; i < 15; i++)
	{
		p10[i] = p10[i - 1] * 10;
	}
	for (i = 0; i < 15; i++)
	{
		comb[i][0] = comb[i][i] = 1;
	}
	for (i = 1; i < 15; i++)
		for (j = 1; j <= i; j++)
		{
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	for (i = 1; i < 14; i++)
	{
		fact[i] = fact[i - 1] * i;
	}
}

int main()
{
	init();
	while (cin >> n && n)
	{
		memset(digit, 0, sizeof(digit));
		sum = 0;
		bool f = true;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			digit[x]++;
			if (digit[x] > 1)
			{
				f = false;
			}
		}
		if (f)
		{
			for (int i = 0; i < 10; i++)
			{
				sum += digit[i] * i * fact[n - 1];
			}
		}
		else
		{
			for (int i = 0; i < 10; i++)
			{
				m = n - 1;
				if (digit[i])
				{
					int cnt = 1;
					for (int j = 0; j < 10; j++)
					{
						if (i != j && digit[j])
						{
							cnt *= comb[m][digit[j]];
							m -= digit[j];
						}
					}
					sum += cnt * i;
				}
			}
		}
		unsigned long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += (sum * p10[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
