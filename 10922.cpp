#include <bits/stdc++.h>

using namespace std;

/*
10922
*/
#define maxn 1000 * 9 + 2
int A[maxn];
char Fg[maxn];
int Recur(int n)
{
	int i, k = 0, x;
	char ss[1002];
	if (n == 9)
	{
		return 1;
	}
	sprintf(ss, "%d", n);
	for (i = 0; ss[i]; i++)
	{
		k += ss[i] - '0';
	}
	x = Recur(k);
	return x + 1;
}
int Div(char xx[])
{
	int i, c = 0, d, x;
	for (i = 0; xx[i]; i++)
	{
		d = xx[i] - '0';
		x = c * 10 + d;
		c = x % 9;
	}
	if (!c)
	{
		return 0;
	}
	return 1;
}
void Cal(char x[])
{
	int i, d = 0;
	if (Div(x))
	{
		printf("%s is not a multiple of 9.\n", x);
		return;
	}
	for (i = 0; x[i]; i++)
	{
		d += x[i] - '0';
	}
	d = Recur(d);
	printf("%s is a multiple of 9 and has 9-degree %d.\n", x, d);
}
int main()
{
	char x[1002];
	while (gets(x) && strcmp(x, "0"))
	{
		Cal(x);
	}
	return 0;
}
