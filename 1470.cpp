#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300010;
const int MAXSTR = MAXN * 2 + 2;

struct Manacher
{
	int n;
	char s[MAXN];
	int p[MAXSTR];
	Manacher()
	{
		n = 0;
		memset(s, 0, sizeof(s));
		memset(p, 0, sizeof(p));
	}
	Manacher(char *_s)
	{
		n = 0;
		memset(s, 0, sizeof(s));
		if (_s)
		{
			memcpy(s, _s, sizeof(char) * (strlen(_s) + 1));
			n = strlen(s);
		}
		memset(p, 0, sizeof(p));
	}
	void mem(char *_s)
	{
		n = 0;
		memset(s, 0, sizeof(s));
		if (_s)
		{
			memcpy(s, _s, sizeof(char) * (strlen(_s) + 1)), n = strlen(s);
		}
		memset(p, 0, sizeof(p));
	}
	char str[MAXSTR];
	void work()
	{
		str[0] = '*';
		for (int i = 0; i < n; i++)
		{
			str[2 * i + 1] = '_';
			str[2 * i + 2] = s[i];
		}
		str[2 * n + 1] = '_';
		str[2 * n + 2] = '\0';
		n = 2 * n + 2;
		memset(p, 0, sizeof(p));
		int mx = 0, id = 0;
		for (int i = 1; i < n; i++)
		{
			if (i < mx)
			{
				p[i] = min(p[2 * id - i], mx - i);
			}
			while (str[i - p[i]] == str[i + p[i]])
			{
				++p[i];
			}
			if (mx < i + p[i])
			{
				mx = i + p[i];
				id = i;
			}
		}
	}
} S;

char s[MAXN];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		S.mem(s);
		S.work();
		int ans = 0;
		for (int i = 1; i <= S.n - 1; i += 2)
		{
			if (S.p[i] == 1)
			{
				continue;
			}
			for (int l = (S.p[i] - 1) / 4 * 4; l > ans; l -= 4)
			{
				if (S.p[i - l / 2] >= l / 2 && S.p[i + l / 2] >= l / 2)
				{
					ans = max(ans, l);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
