#include <bits/stdc++.h>

using namespace std;

int cmp(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}
int len, ans, d;
long long int tmp;
char s[15], tc;
void perm(int x)
{
	int i;
	if (x == len)
	{
		for (i = 0, tmp = 0LL; i <= len; i++)
		{
			tmp = 10LL * tmp + s[i] - '0';
		}
		if (tmp % d == 0)
		{
			ans++;
		}
		return;
	}
	perm(x + 1);
	for (i = x + 1; i <= len; i++)
	{
		if (s[x] == s[i])
		{
			continue;
		}
		tc = s[x];
		s[x] = s[i];
		s[i] = tc;
		perm(x + 1);
	}
	for (i = len; i > x; i--)
	{
		if (s[x] == s[i])
		{
			continue;
		}
		tc = s[x];
		s[x] = s[i];
		s[i] = tc;
	}
}
int main()
{
	int t, i;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s%d", s, &d);
		len = strlen(s);
		qsort(s, len, sizeof(char), cmp);
		len--;
		ans = 0;
		perm(0);
		printf("%d\n", ans);
	}
	return 0;
}
