#include <bits/stdc++.h>

using namespace std;

const int N = 10050;
int len;
char s[N];

void solve()
{
	int sum = 1, ans = 0;
	for (int i = 0; i < len; ++i)
	{
		if (s[i] == '0' && sum < 1)
		{
			++sum;
		}
		if (s[i] == '1')
		{
			if (sum >= 1)
			{
				sum = -1;
			}
			else
			{
				--sum;
			}
		}
		if (sum >= 1)
		{
			++ans;
		}
	}
	if (sum < 1)
	{
		ans = 0;
	}
	printf("%d\n", ans);
}

int main()
{
	while (scanf("%s", s) != -1)
	{
		len = strlen(s);
		for (int i = 0; i < len; ++i)
			if (s[i] == '?')
			{
				s[i] = '0';
			}
		solve();
	}
	return 0;
}
