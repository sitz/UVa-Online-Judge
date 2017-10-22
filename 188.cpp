#include <bits/stdc++.h>

using namespace std;

#define MIN(a, b) (a > b ? b : a)

int W[15], tw;
char str[200];

int com(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int Val(char ss[])
{
	int i, j, k = 1, d = 0, l;
	l = strlen(ss);
	for (i = l - 1; i >= 0; i--)
	{
		j = ss[i] - 'a' + 1;
		d += j * k;
		k *= 32;
	}
	return d;
}

void Set()
{
	char *p;
	tw = 0;
	p = strtok(str, " ");
	while (p)
	{
		W[tw++] = Val(p);
		p = strtok(NULL, " ");
	}
}

int Match(int n)
{
	int i, j, x, y;
	for (i = 0; i + 1 < tw; i++)
	{
		for (j = i + 1; j < tw; j++)
		{
			x = n / W[i];
			y = n / W[j];
			x = x % tw;
			y = y % tw;
			if (x == y)
			{
				return 1;
			}
		}
	}
	return 0;
}

int Next(int n)
{
	int i, j, max = -1000000, x, p, q;
	for (i = 0; i + 1 < tw; i++)
		for (j = i + 1; j < tw; j++)
		{
			p = (n / W[i]) % tw;
			q = (n / W[j]) % tw;
			if (q != p)
				continue;
			x = MIN(((n / W[i]) + 1) * W[i], ((n / W[j]) + 1) * W[j]);
			if (x > max)
				max = x;
		}
	return max;
}
void Cal()
{
	int min, ok;
	qsort(W, tw, sizeof(int), com);
	min = W[0];
	ok = Match(min);
	while (ok)
	{
		min = Next(min);
		ok = Match(min);
	}
	printf("%d\n\n", min);
}

int main()
{
	while (gets(str))
	{
		puts(str);
		Set();
		Cal();
	}
	return 0;
}
