#include <bits/stdc++.h>

using namespace std;

bool debug = false;

const int N = 100111;

int dp[N], a[N];

char str[N * 10];

int main()
{
	int data, n = 0;
	while (gets(str) != NULL)
	{
		int len = strlen(str);
		str[len++] = ' ';
		str[len] = 0;
		if (debug)
		{
			cout << str << endl;
		}
		int l = 0, r = 0, n = 1;
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == ' ')
			{
				r = i - 1;
				a[n] = 0;
				bool tag = true;
				for (int j = l; j <= r; j++)
				{
					if (str[j] == '-')
					{
						tag = false;
					}
					else
					{
						a[n] = a[n] * 10 + str[j] - '0';
					}
				}
				l = i + 1;
				if (!tag)
				{
					a[n] = -a[n];
				}
				n++;
			}
		}
		if (debug)
		{
			cout << "debug" << endl;
		}
		if (debug)
		{
			for (int i = 1; i < n; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
		}
		int res = 0;
		dp[0] = 0;
		for (int i = 1; i < n; i++)
		{
			dp[i] = max(a[i], dp[i - 1] + a[i]);
			res = max(res, dp[i]);
		}
		if (debug)
		{
			for (int i = 1; i < n; i++)
			{
				cout << dp[i] << " ";
			}
			cout << endl;
		}
		cout << res << endl;
	}
}
