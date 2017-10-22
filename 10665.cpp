#include <bits/stdc++.h>

using namespace std;

struct Count
{
	char c;
	int n;
} w[26], p[26];
bool used[26];
char str[500];
int n;
int compare(const void *a, const void *b)
{
	Count *c = (Count *)a, *d = (Count *)b;
	if (c->n != d->n)
	{
		return d->n - c->n;
	}
	else
	{
		return c->c - d->c;
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			w[i].c = i + 'A';
			w[i].n = 0;
		}
		scanf("%s", str);
		for (int i = 0; str[i] != '#'; i++)
		{
			if (str[i] - 'A' >= n)
			{
				continue;
			}
			w[str[i] - 'A'].n++;
		}
		qsort(w, n, sizeof(Count), compare);
		memset(used, false, sizeof(used));
		int left = 0, right = n - 1;
		for (int i = 0; i < n; i++)
		{
			if (i & 1)
			{
				p[right--] = w[i];
			}
			else
			{
				p[left++] = w[i];
			}
		}
		bool flag;
		do
		{
			flag = false;
			for (int i = 0; i < n / 2; i++)
				if (p[i].c > p[n - 1 - i].c)
				{
					Count x = p[i];
					p[i] = p[n - 1 - i];
					p[n - 1 - i] = x;
					flag = true;
				}
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
					if (p[i].n == p[j].n && p[i].c > p[j].c)
					{
						Count x = p[i];
						p[i] = p[j];
						p[j] = x;
						flag = true;
					}
		} while (flag);
		for (int i = 0; i < n; i++)
		{
			if (i)
			{
				putchar(' ');
			}
			printf("%c", p[i].c);
		}
		puts("");
		for (int i = 0; i < n; i++)
		{
			if (i)
			{
				putchar(' ');
			}
			printf("%d", p[i].n);
		}
		puts("");
	}
}
