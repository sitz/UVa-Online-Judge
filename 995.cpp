#include <bits/stdc++.h>

using namespace std;

int U[16], A[60], S[60], len, b;
void find(int lv)
{
	int i, j, n;
	for (n = 0, i = 1; i < lv; i++)
	{
		n = (n * b + S[i]) % lv;
	}
	n = n * b % lv;
	for (i = ((lv == 1) ? 1 : 0); i < b; i++)
	{
		if (!U[i] || (n + i) % lv)
		{
			continue;
		}
		S[lv] = i;
		find(lv + 1);
		if (lv >= len)
		{
			len = lv;
			for (j = 1; j <= lv; j++)
			{
				A[j] = S[j];
			}
		}
	}
}
int main()
{
	int i, j;
	char s[16];
	while (scanf("%d%s", &b, s) == 2)
	{
		for (i = 0; i < b; i++)
		{
			U[i] = 0;
		}
		for (i = 0; s[i]; i++)
		{
			U[s[i] - '0'] = 1;
		}
		len = 0;
		find(1);
		for (i = 1; i <= len; i++)
		{
			printf("%d", A[i]);
		}
		printf("\n");
	}
	return 0;
}
