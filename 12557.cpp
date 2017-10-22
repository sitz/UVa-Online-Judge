#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int solve()
{
	static char s[1000001], t[1000001];
	gets(s);
	gets(t);
	int m = strlen(s), n = strlen(t);
	int last1[128], last2[128];
	char f[128];
	rep(c, 128) last1[c] = last2[c] = -1;
	int ans = 0;
	rep(i, m - n + 1)
	{
		bool ok = true;
		rep(j, n)
		{
			if ('A' <= s[i + j] && s[i + j] <= 'Z')
			{
				if (t[j] != s[i + j])
				{
					ok = false;
					break;
				}
			}
			else
			{
				if ('A' <= t[j] && t[j] <= 'Z')
				{
					ok = false;
					break;
				}
				else if (last1[t[j]] != i)
				{
					if (last2[s[i + j]] == i)
					{
						ok = false;
						break;
					}
					else
					{
						f[t[j]] = s[i + j];
						last1[t[j]] = i;
						last2[s[i + j]] = i;
					}
				}
				else if (f[t[j]] != s[i + j])
				{
					ok = false;
					break;
				}
			}
		}
		if (ok)
		{
			ans++;
		}
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d ", &T);
	for (int cas = 1; cas <= T; cas++)
		printf("Case %d: %d\n", cas, solve());
	return 0;
}
