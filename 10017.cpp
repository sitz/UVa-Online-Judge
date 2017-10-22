#include <bits/stdc++.h>

using namespace std;

int pillar[3][300], n, times, num[3], i;

void hanoi(int source, int target, int temp, int disk)
{
	if (!disk)
	{
		return;
	}
	hanoi(source, temp, target, disk - 1);
	if (!times)
	{
		return;
	}
	--times;
	pillar[target][num[target]] = pillar[source][--num[source]];
	++num[target];
	if (num[0])
	{
		printf("A=>  ");
		for (i = 0; i < num[0]; ++i)
		{
			printf(" %d", pillar[0][i]);
		}
		putchar('\n');
	}
	else
	{
		puts("A=>");
	}
	if (num[1])
	{
		printf("B=>  ");
		for (i = 0; i < num[1]; ++i)
		{
			printf(" %d", pillar[1][i]);
		}
		putchar('\n');
	}
	else
	{
		puts("B=>");
	}
	if (num[2])
	{
		printf("C=>  ");
		for (i = 0; i < num[2]; ++i)
		{
			printf(" %d", pillar[2][i]);
		}
		putchar('\n');
	}
	else
	{
		puts("C=>");
	}
	putchar('\n');
	hanoi(temp, target, source, disk - 1);
}

int main()
{
	int t = 0;
	while (~scanf("%d %d", &n, &times))
	{
		if (!n && !times)
		{
			break;
		}
		printf("Problem #%d\n\n", ++t);
		for (i = 0; i < n; ++i)
		{
			pillar[0][i] = n - i;
		}
		num[0] = n;
		num[1] = num[2] = 0;
		if (num[0])
		{
			printf("A=>  ");
			for (i = 0; i < num[0]; ++i)
			{
				printf(" %d", pillar[0][i]);
			}
			putchar('\n');
		}
		else
		{
			puts("A=>");
		}
		if (num[1])
		{
			printf("B=>  ");
			for (i = 0; i < num[1]; ++i)
			{
				printf(" %d", pillar[1][i]);
			}
			putchar('\n');
		}
		else
		{
			puts("B=>");
		}
		if (num[2])
		{
			printf("C=>  ");
			for (i = 0; i < num[2]; ++i)
			{
				printf(" %d", pillar[2][i]);
			}
			putchar('\n');
		}
		else
		{
			puts("C=>");
		}
		putchar('\n');
		hanoi(0, 2, 1, n);
	}
	return 0;
}
