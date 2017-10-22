#include <bits/stdc++.h>

using namespace std;

struct Char
{
	char c;
	int count;
} c[256];
int m[260];
char str[500000];
int ptr;
int find(char ch)
{
	//if(!isalpha(ch)&&ch!=','&&ch!='.'&&ch!='-'&&ch!='$'&&ch!=' ') return -1;
	for (int i = 0; i < ptr; i++)
		if (c[i].c == ch)
		{
			c[i].count++;
			return i;
		}
	c[ptr].c = ch;
	c[ptr++].count = 1;
	return ptr - 1;
}
int compare(const void *a, const void *b)
{
	return ((Char *)b)->count - ((Char *)a)->count;
}

int main()
{
	int t;
	gets(str);
	sscanf(str, "%d", &t);
	while (t--)
	{
		for (int i = 0; i < 256; i++)
		{
			c[i].c = '\0';
			c[i].count = 0;
		}
		int n;
		ptr = 0;
		gets(str);
		sscanf(str, "%d", &n);
		while (n--)
		{
			gets(str);
			int i;
			for (i = 0; str[i]; i++)
			{
				find(str[i]);
			}
		}
		qsort(c, ptr, sizeof(Char), compare);
		for (int j = ptr; j < 70; j++)
		{
			m[j] = 0;
		}
		for (int i = ptr - 1; i >= 0; i--)
		{
			m[i] = 9999999;
			for (int j = 1, k = 2; j <= 16; j++, k *= 2)
			{
				int p = k - 1;
				int sum = 0, sum1 = 0;
				for (int x = i; x < i + p; x++)
				{
					sum += c[x].count;
				}
				for (int x = i + p; x < ptr; x++)
				{
					sum1 += c[x].count;
				}
				if (i + k == ptr)
				{
					int q = 0;
					for (int x = i; x < ptr; x++)
					{
						q += c[x].count;
					}
					int temp = q * j;
					if (temp < m[i])
					{
						m[i] = temp;
					}
				}
				if (i + p > ptr)
				{
					break;
				}
				if (m[i + p] + sum1 * j + sum * j < m[i])
				{
					m[i] = m[i + p] + sum1 * j + sum * j;
				}
			}
		}
		printf("%d\n", m[0]);
	}
	return 0;
}
