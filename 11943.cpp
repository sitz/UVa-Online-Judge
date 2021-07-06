#include <bits/stdc++.h>

using namespace std;

char ch[120000];
char name[12000];
int age, n, nl;
double w[120000];
int le, st, i, po;
double tt, va, xs;

int main()
{
	bool fi = false;
	while (gets(ch))
	{
		le = strlen(ch);
		nl = 0;
		po = 0;
		n = 0;
		while (ch[po] != '*')
		{
			name[nl++] = ch[po];
			po++;
		}
		po++;
		age = 0;
		while (ch[po] != '*')
		{
			age *= 10;
			age += ch[po] - '0';
			po++;
		}
		po++;
		st = 0;
		va = 0.0;
		tt = 0.1;
		for (i = po; i < le; i++)
		{
			if (ch[i] == ' ')
			{
				continue;
			}
			if (ch[i] == ',')
			{
				w[n++] = va * xs;
				if (ch[i + 1] == '-')
				{
					xs = -1.0;
					i++;
				}
				else
				{
					xs = 1.0;
				}
				va = 0.0;
				st = 0;
			}
			else if (ch[i] == '.')
			{
				st = 1;
				tt = 0.1;
			}
			else if (st == 0)
			{
				va *= 10.0;
				va += (double)(ch[i] - '0');
			}
			else
			{
				va += (double)(ch[i] - '0') * tt;
				tt *= 0.1;
			}
		}
		w[n++] = va * xs;
		if (fi)
		{
			puts("---");
		}
		else
		{
			fi = true;
		}
		for (i = 0; i < nl; i++)
		{
			printf("%c", name[i]);
		}
		puts("");
		printf("%d\n", age);
		int le, ri, id;
		id = -1;
		for (i = 0; i < n; i++)
		{
			if (id == -1 || w[id] < w[i])
			{
				id = i;
			}
		}
		le = id;
		while (le > 0)
		{
			le--;
		}
		while (le > 0)
		{
			le--;
		}
		ri = id;
		while (ri < n - 1)
		{
			ri++;
		}
		while (ri < n - 1)
		{
			ri++;
		}
		if (w[id] <= 35.0 && (ri - le + 2) <= 10 && (ri - le + 2) >= 6)
		{
			puts("Triage PASS");
		}
		else
		{
			puts("Triage NO PASS");
		}
	}
	return 0;
}
