#include <bits/stdc++.h>

using namespace std;

char s[1000], t[1000];
int t1, t2;
int read()
{
	if (scanf("%d", &t1) != 1)
	{
		return 0;
	}
	if (t1 > 0)
	{
		scanf("%s", s);
	}
	else
	{
		s[0] = 0;
	}
	scanf("%d", &t2);
	if (t2 > 0)
	{
		scanf("%s", t);
	}
	else
	{
		t[0] = 0;
	}
	return 1;
}
int m[1001][1001];
void process()
{
	int i, j;
	memset(m, 0, sizeof(m));
	for (i = 1; i <= t1; i++)
	{
		m[i][0] = m[i - 1][0] + 1;
	}
	for (i = 1; i <= t2; i++)
	{
		m[0][i] = m[0][i - 1] + 1;
	}
	for (i = 1; i <= t1; i++)
	{
		for (j = 1; j <= t2; j++)
		{
			if (s[i - 1] == t[j - 1])
			{
				m[i][j] = m[i - 1][j - 1];
			}
			else
			{
				m[i][j] = min(m[i - 1][j - 1], min(m[i - 1][j], m[i][j - 1])) + 1;
			}
		}
	}
	printf("%d\n", m[t1][t2]);
}
int main()
{
	while (read())
	{
		process();
	}
	return 0;
}
