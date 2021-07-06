#include <bits/stdc++.h>

using namespace std;

const int maxn = 24;
int bitcount(int x)
{
	return x == 0 ? 0 : bitcount(x / 2) + (x & 1);
}
map<int, int> table;
int a[maxn], n;
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		char ita[300];
		for (int i = 0; i < n; i++)
		{
			scanf("%s", ita);
			a[i] = 0;
			for (int j = 0; j < strlen(ita); j++)
			{
				a[i] ^= (1 << (ita[j] - 'A'));
			}
		}
		table.clear();
		int n1 = n / 2, n2 = n - n1;
		for (int i = 0; i < (1 << n1); i++)
		{
			int x = 0;
			for (int j = 0; j < n1; j++)
				if (i & (1 << j))
				{
					x ^= a[j];
				}
			if (!table.count(x) || bitcount(table[x]) < bitcount(i))
			{
				table[x] = i;
			}
		}
		int ans = 0;
		for (int i = 0; i < (1 << n2); i++)
		{
			int x = 0;
			for (int j = 0; j < n2; j++)
				if (i & (1 << j))
				{
					x ^= a[n1 + j];
				}
			if (table.count(x) && bitcount(ans) < bitcount(table[x]) + bitcount(i))
			{
				ans = (i << n1) ^ table[x];
			}
		}
		printf("%d\n", bitcount(ans));
		int flag = 0;
		for (int i = 0; i < n; i++)
			if (ans & (1 << i))
			{
				if (!flag)
				{
					printf("%d", i + 1);
					flag = 1;
				}
				else
				{
					printf(" %d", i + 1);
				}
			}
		printf("\n");
	}
	return 0;
}
