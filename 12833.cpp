#include <bits/stdc++.h>

using namespace std;

#define M 200100

char s1[M], s2[M];
int p[M], sum[M][26], all[26][2][M];

void add(int *sum, int i)
{
	for (; i > 0; i -= i & -i)
	{
		sum[i]++;
	}
}

int query(int *sum, int i, int len)
{
	int ans = 0;
	if (i > len || i <= 0)
	{
		return 0;
	}
	return sum[i];
}

int f(int len)
{
	p[1] = 2, p[0] = 1;
	int id = 1, mx = 2;
	for (int i = 2; i < len; ++i)
	{
		int k = min(mx - i, p[id - (i - id)]);
		while (i - k >= 0 && i + k < len && s2[i + k] == s2[i - k])
		{
			++k;
		}
		p[i] = k;
		if (i + k >= mx)
		{
			mx = i + k, id = i;
		}
	}
	for (int i = 1; i < len; ++i)
	{
		memcpy(sum[i], sum[i - 1], sizeof(sum[i - 1]));
		if (s2[i] >= 0 && s2[i] < 26)
		{
			sum[i][s2[i]]++;
		}
	}
	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j <= len; ++j)
		{
			all[i][0][j] = all[i][1][j] = 0;
		}
	}
	for (int i = 1; i < len; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			int s = sum[i + p[i] - 1][j] - sum[i - 1][j];
			int o = 0;
			if (s2[i] == j)
			{
				o = 1;
			}
			all[j][o][s]++;
		}
	}
	return 0;
}

int solve(int c, int x, int len)
{
	int ans;
	if (x > len || x <= 0)
	{
		return 0;
	}
	if (x & 1)
	{
		ans = query(all[c][1], x / 2 + 1, len);
	}
	else
	{
		ans = query(all[c][0], x / 2, len);
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	int j, i, len, cas = 1, x;
	while (T--)
	{
		scanf("%d", &len);
		scanf("%s", s1);
		for (j = i = 0; i < len; ++i)
		{
			s2[j++] = 30, s2[j++] = s1[i] - 'a';
		}
		s2[j++] = 30;
		f(j);
		for (int i = len; i >= 0; --i)
		{
			for (int j = 0; j < 26; ++j)
			{
				for (int k = 0; k < 2; ++k)
				{
					all[j][k][i] += all[j][k][i + 1];
				}
			}
		}
		int m;
		scanf("%d", &m);
		scanf("%s", s1);
		printf("Case %d:\n", cas++);
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &x);
			x = solve(s1[j] - 'a', x, len);
			printf("%d\n", x);
		}
	}
}
