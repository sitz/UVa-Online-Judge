#include <bits/stdc++.h>

using namespace std;

int l1, l2;
char s1[100], s2[100];
const char *dash = "----------------------------------------------------------------";
const char *zero = "0000000000000000000000000000000000000000000000000000000000000000";

int trans(char *s)
{
	int res;
	for (res = 0; *s; s++)
	{
		res <<= 1;
		res += *s - '0';
	}
	return res;
}

void recurs(long long res, int depth)
{
	int i, f, len, tlen;
	if (res == 0)
	{
		f = !depth;
		tlen = (depth += !depth);
		if (l1 > l2)
		{
			len = l1;
		}
		else
		{
			len = l2;
		}
		if (len > tlen)
		{
			tlen = len;
		}
		printf("%*s\n", tlen, s1);
		printf("%*s\n", tlen, s2);
		printf("%*.*s\n", tlen, len, dash);
		for (i = 0; i < l2; i++)
		{
			printf("%*.*s\n", tlen - i, l1, s2[l2 - i - 1] == '0' ? zero : s1);
		}
		printf("%*.*s\n", tlen, tlen, dash);
		if (f)
		{
			printf("%*.*s\n", tlen, 1, zero);
		}
		return;
	}
	recurs(res >> 1, depth + 1);
	printf("%lld", res % 2);
	if (depth == 0)
	{
		printf("\n");
	}
}

int main()
{
	int t, n1, n2;
	long long res;
	t = 0;
	while (scanf("%s%s", s1, s2) == 2)
	{
		if (strcmp(s1, "0") == 0 && strcmp(s2, "0") == 0)
		{
			break;
		}
		if (t)
		{
			printf("\n");
		}
		t = 1;
		n1 = trans(s1);
		n2 = trans(s2);
		l1 = strlen(s1);
		l2 = strlen(s2);
		res = (long long)n1 * n2;
		recurs(res, 0);
	}
	return 0;
}
