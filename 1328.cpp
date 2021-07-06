#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;
char str[maxn];
int f[maxn];
void getFail(char *str, int len)
{
	f[0] = f[1] = 0;
	for (int i = 1; i < len; i++)
	{
		int j = f[i];
		while (j && str[i] != str[j])
		{
			j = f[j];
		}
		f[i + 1] = (str[i] == str[j] ? j + 1 : 0);
	}
}
int main()
{
	int n, cas = 1;
	while (scanf("%d", &n) && n)
	{
		scanf("%s", str);
		getFail(str, n);
		printf("Test case #%d\n", cas++);
		for (int i = 1; i <= n; i++)
		{
			if (f[i] > 0 && i % (i - f[i]) == 0)
			{
				printf("%d %d\n", i, i / (i - f[i]));
			}
		}
		printf("\n");
	}
	return 0;
}
