#include <bits/stdc++.h>

using namespace std;

/****
10550
****/
#define MAXN 1080
int Close(int a, int b)
{
	int c = 0;
	while (a != b)
	{
		c++;
		a--;
		if (a == -1)
		{
			a = 39;
		}
	}
	return c * 9;
}
int Counter(int a, int b)
{
	int c = 0;
	while (a != b)
	{
		c++;
		a++;
		if (a == 40)
		{
			a = 0;
		}
	}
	return c * 9;
}
int main()
{
	int a, b, c, d;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4)
	{
		if (a == 0 && b == 0 && c == 0 && d == 0)
		{
			break;
		}
		printf("%d\n", Close(a, b) + Counter(b, c) + Close(c, d) + MAXN);
	}
	return 0;
}
