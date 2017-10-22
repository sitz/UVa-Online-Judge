#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010

int a[MAXN], b[MAXN];
int n;

void dvide(int x, int y)
{
	int i, j;
	if (y - x <= 1)
	{
		return;
	}
	for (int i = x; i <= y; i++)
	{
		b[i] = a[i];
	}
	for (i = x, j = x; j <= y; j += 2, i++)
	{
		a[i] = b[j];
	}
	for (j = x + 1; j <= y; j += 2, i++)
	{
		a[i] = b[j];
	}
	dvide((x + y) / 2 + 1, y);
	dvide(x, (x + y) / 2);
}

int main()
{
	while (scanf("%d", &n), n)
	{
		for (int i = 0; i < n; i++)
		{
			a[i] = i;
		}
		dvide(0, n - 1);
		printf("%d:", n);
		for (int i = 0; i < n; i++)
		{
			printf(" %d", a[i]);
		}
		printf("\n");
	}
	return 0;
}
