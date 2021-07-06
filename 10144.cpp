#include <bits/stdc++.h>

using namespace std;

void Recursion(int d)
{
	printf("(");
	if (d)
	{
		printf("(A%d|B%d)|(", d, d);
		Recursion(d - 1);
		printf("|((A%d|A%d)|(B%d|B%d)))", d, d, d, d);
	}
	else
	{
		printf("(A0|B0)|(A0|B0)");
	}
	printf(")");
}

int main()
{
	char str[80];
	int times, n;
	gets(str);
	sscanf(str, "%d", &times);
	gets(str);
	for (; times; times--)
	{
		gets(str);
		sscanf(str, "%d", &n);
		Recursion(n - 1);
		printf("\n");
		gets(str);
		if (times != 1)
		{
			puts("");
		}
	}
	return 0;
}
