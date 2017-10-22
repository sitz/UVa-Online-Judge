#include <bits/stdc++.h>

using namespace std;

int i, v, x, l, c;
void single(int n)
{
	switch (n)
	{
	case 0:
		break;
	case 1:
		i++;
		break;
	case 2:
		i += 2;
		break;
	case 3:
		i += 3;
		break;
	case 4:
		i++;
		v++;
		break;
	case 5:
		v++;
		break;
	case 6:
		v++;
		i++;
		break;
	case 7:
		i += 2;
		v++;
		break;
	case 8:
		i += 3;
		v++;
		break;
	case 9:
		i++;
		x++;
		break;
	}
}
void dou(int n)
{
	switch (n)
	{
	case 0:
		break;
	case 1:
		x++;
		break;
	case 2:
		x += 2;
		break;
	case 3:
		x += 3;
		break;
	case 4:
		x++;
		l++;
		break;
	case 5:
		l++;
		break;
	case 6:
		x++;
		l++;
		break;
	case 7:
		x += 2;
		l++;
		break;
	case 8:
		x += 3;
		l++;
		break;
	case 9:
		x += 1;
		c++;
		break;
	case 10:
		c++;
		break;
	}
}
main()
{
	int n, j;
	while (1)
	{
		i = v = x = l = c = 0;
		scanf("%d", &n);
		if (!n)
		{
			break;
		}
		for (j = 1; j <= n; j++)
		{
			single(j % 10);
			dou(j / 10);
		}
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, i, v, x, l, c);
	}
	return 0;
}
