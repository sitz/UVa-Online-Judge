#include <bits/stdc++.h>

using namespace std;

char s[10][15], ss[105];
int N, ans, len[10];

void dfs(int use, int level, int st)
{
	int i, j, k, t;
	if (level == N)
	{
		if (st < ans)
		{
			ans = st;
		}
		return;
	}
	for (i = 0; i < N; i++)
	{
		if (use & (1 << i))
		{
			continue;
		}
		if (level == 0)
		{
			for (j = st, k = 0; k < len[i]; j++, k++)
			{
				ss[j] = s[i][k];
			}
			dfs(use | (1 << i), level + 1, j);
		}
		else
		{
			int re = 0;
			for (j = st - len[i]; j < st; j++)
			{
				t = j;
				k = 0;
				if (s[i][0] == ss[j])
				{
					for (k = 0, t = j; k < len[i] && t < st; k++, t++)
					{
						if (s[i][k] != ss[t])
						{
							break;
						}
					}
				}
				if (t == st)
				{
					re = 1;
					break;
				}
			}
			if (re == 1)
			{
				for (k = 0; k < len[i]; j++, k++)
				{
					ss[j] = s[i][k];
				}
				dfs(use | (1 << i), level + 1, j);
			}
			else if (re == 0)
			{
				for (j = st, k = 0; k < len[i]; j++, k++)
				{
					ss[j] = s[i][k];
				}
				dfs(use | (1 << i), level + 1, j);
			}
		}
	}
}

int main()
{
	int T, t, n, i, j;
	scanf(" %d", &T);
	for (t = 0; t < T; t++)
	{
		scanf(" %d", &N);
		gets(s[0]);
		for (n = 0; n < N; n++)
		{
			gets(s[n]);
			len[n] = strlen(s[n]);
		}
		ans = 99999999;
		dfs(0, 0, 0);
		printf("Case %d: %d\n", t + 1, ans);
	}
	return 0;
}
