#include <bits/stdc++.h>

using namespace std;

char c1[1000011], c2[1000011];
int nxt[1000011];

int kmp()
{
	int k = strlen(c1), i, j, y = -1;
	memset(nxt, 0, sizeof(nxt));
	nxt[0] = -1;
	for (i = 1; i < k; i++)
	{
		while (y > -1 && c1[i] != c1[y + 1])
		{
			y = nxt[y];
		}
		if (c1[y + 1] == c1[i])
		{
			y++;
		}
		nxt[i] = y;
	}
	int max = -1;
	y = -1;
	for (i = 0; i < k; i++)
	{
		while (y > -1 && c2[i] != c1[y + 1])
		{
			y = nxt[y];
		}
		if (c1[y + 1] == c2[i])
		{
			y++;
			if (max < y)
			{
				max = y;
			}
		}
	}
	return max;
}

int main()
{
	int t, n, m, i, j, k;
	scanf("%d%*c", &t);
	while (t--)
	{
		gets(c1);
		k = strlen(c1);
		for (i = 0; i <= k - 1; i++)
		{
			c2[i] = c1[k - i - 1];
		}
		n = kmp();
		for (i = n; i >= 0; i--)
		{
			printf("%c", c1[i]);
		}
		puts("");
	}
	return 0;
}
