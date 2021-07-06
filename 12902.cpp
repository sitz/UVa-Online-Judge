#include <bits/stdc++.h>

using namespace std;

int sum[3000100];
int cnt[3000100];

int solve(string s)
{
	int ans = 0;
	int a = 0, b = 0;
	string A = "", B = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'a')
		{
			a++;
		}
		else
		{
			b++;
		}
	}
	if (a - 1 > b)
	{
		for (int i = 0; i < a - 1 - b; i++)
		{
			B += '+';
		}
		ans += a - 1 - b;
	}
	else if (a - 1 < b)
	{
		for (int i = 0; i < b - a + 1; i++)
		{
			A += 'a';
		}
		ans += b - a + 1;
	}
	s = A + s + B;
	if (s[0] == '+')
	{
		s = 'a' + s + '+';
		ans += 2;
	}
	sum[0] = 0;
	int l = s.length();
	for (int i = 1; i < l; i++)
	{
		if (s[i] == 'a')
		{
			sum[i] = sum[i - 1] + 1;
		}
		else
		{
			sum[i] = sum[i - 1] - 1;
		}
		if (sum[i] < 0)
		{
			cnt[-sum[i]]++;
		}
	}
	int d = 0;
	int pv = 1;
	for (int i = 1; i < l; i++)
	{
		if (s[i] == '+' && sum[i] + d < 0)
		{
			if (i + 1 < l && sum[i] + d == -1 && sum[i + 1] + d == 0 && cnt[pv] == 1)
			{
				ans++;
				cnt[pv]--;
			}
			else
			{
				ans += 2;
				d++;
				pv++;
			}
		}
	}
	for (int i = 0; i < l; i++)
		if (sum[i] < 0)
		{
			cnt[-sum[i]] = 0;
		}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++)
	{
		string s;
		cin >> s;
		int ans = solve(s);
		if (s[0] == '+')
		{
			int d = 0;
			for (int i = 1; i < s.length(); i++)
			{
				if (s[i] == 'a')
				{
					d = i;
					break;
				}
			}
			if (d)
			{
				swap(s[0], s[d]);
				ans = min(ans, solve(s) + d);
			}
		}
		cout << "Case " << kase << ": " << ans << endl;
	}
	return 0;
}
