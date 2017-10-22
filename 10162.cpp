#include <bits/stdc++.h>

using namespace std;

#define MAXN 202
int A[MAXN], N;
char DD[MAXN];

void LastD(int n)
{
	int i, j, k;
	k = n % 10;
	if (k == 0 || k == 1 || k == 6 || k == 5)
	{
		N += k;
		N = N % 10;
		return;
	}
	j = 1;
	for (i = 1; i <= n; i++)
	{
		j *= n;
		j %= 10;
	}
	N += j;
	N %= 10;
}
void Gen()
{
	int i;
	N = 0;
	for (i = 1; i <= 100; i++)
	{
		LastD(i);
		A[i] = N;
	}
}
int KEY()
{
	int i, k = 0, c = 1, sum = 0;
	int l = strlen(DD);
	for (i = l - 1; i >= 0; i--)
	{
		sum = (DD[i] - '0') * c;
		k += sum;
		c *= 10;
		if (c == 100)
		{
			break;
		}
	}
	return k;
}

int main()
{
	int i;
	Gen();
	while (1)
	{
		scanf("%s", DD);
		if (!strcmp(DD, "0"))
		{
			break;
		}
		i = KEY();
		printf("%d\n", A[i]);
	}
	return 0;
}
