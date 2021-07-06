#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
char s1[N], s2[N];
int a[N], b[N], c[N], r, dragon, seven, purely, chunkious, sky, royal, tot;

int f(char x, char y)
{
	int r;
	if (y == 'D')
	{
		r = 0;
	}
	if (y == 'B')
	{
		r = 9;
	}
	if (y == 'M')
	{
		r = 18;
	}
	return r + x - '1';
}

char g(int i)
{
	if (i / 9 == 0)
	{
		return 'D';
	}
	if (i / 9 == 1)
	{
		return 'B';
	}
	return 'M';
}

void dfs2(int i)
{
	if (i == 27)
	{
		int x = 0, y = sky, j;
		for (j = 0; j < 27; j++)
		{
			x += a[j];
			if (a[j] != 0 && a[j] != 2)
			{
				break;
			}
			if (a[j] == 2 && j % 9 != 0 && j % 9 != 8)
			{
				sky = 0;
			}
		}
		if (x == 2 && j == 27 && tot == 4)
		{
			r = max(r, 1 + dragon + purely + royal + chunkious + sky);
		}
		sky = y;
		return;
	}
	int x, y;
	if (i % 9 <= 6 && a[i] && a[i + 1] && a[i + 2])
	{
		tot++;
		a[i]--;
		a[i + 1]--;
		a[i + 2]--;
		x = chunkious;
		y = sky;
		chunkious = 0;
		if (i % 9 != 0 && (i + 2) % 9 != 8)
		{
			sky = 0;
		}
		dfs2(i);
		tot--;
		a[i]++;
		a[i + 1]++;
		a[i + 2]++;
		chunkious = x;
		sky = y;
	}
	if (a[i] >= 3)
	{
		tot++;
		a[i] -= 3;
		y = sky;
		if (i % 9 != 0 && i % 9 != 8)
		{
			sky = 0;
		}
		dfs2(i);
		tot--;
		a[i] += 3;
		sky = y;
	}
	dfs2(i + 1);
}

void dfs1(int i)
{
	if (i == 27)
	{
		int j;
		for (j = 0; j < 27; j++)
			if (b[j])
			{
				break;
			}
		if (j == 27)
		{
			dfs2(0);
		}
		return;
	}
	int x, y;
	if (i % 9 <= 6 && b[i] && b[i + 1] && b[i + 2])
	{
		tot++;
		b[i]--;
		b[i + 1]--;
		b[i + 2]--;
		x = chunkious;
		y = sky;
		chunkious = 0;
		if (i % 9 != 0 && (i + 2) % 9 != 8)
		{
			sky = 0;
		}
		dfs1(i);
		tot--;
		b[i]++;
		b[i + 1]++;
		b[i + 2]++;
		chunkious = x;
		sky = y;
	}
	if (b[i] >= 3)
	{
		tot++;
		b[i] -= 3;
		y = sky;
		if (i % 9 != 0 && i % 9 != 8)
		{
			sky = 0;
		}
		dfs1(i);
		tot--;
		b[i] += 3;
		sky = y;
	}
	if (b[i] >= 4)
	{
		tot++;
		b[i] -= 4;
		y = sky;
		if (i % 9 != 0 && i % 9 != 8)
		{
			sky = 0;
		}
		dfs1(i);
		tot--;
		b[i] += 4;
		sky = y;
	}
	dfs1(i + 1);
}

void calc()
{
	int i, x, y, z;
	x = y = z = 0;
	for (i = 0; i < 27; i++)
	{
		if (c[i] == 0)
		{
			continue;
		}
		if (i < 9)
		{
			x++;
		}
		else if (i < 18)
		{
			y++;
		}
		else
		{
			z++;
		}
	}
	if (x && y && z)
	{
		return;
	}
	dragon = purely = royal = 0;
	for (i = 0; i < 27; i++)
		if (c[i] == 4)
		{
			dragon++;
		}
	x = y = z = 0;
	for (i = 0; i < 27; i++)
	{
		if (c[i] == 0)
		{
			continue;
		}
		if (i < 18)
		{
			x++;
		}
		if (i >= 9)
		{
			y++;
		}
		if (i < 9 || i >= 18)
		{
			z++;
		}
	}
	if (x == 0 || y == 0 || z == 0)
	{
		purely = 2;
	}
	for (i = 0; i < 27; i++)
	{
		if (i % 9 == 1 || i % 9 == 4 || i % 9 == 7)
		{
			continue;
		}
		if (c[i])
		{
			break;
		}
	}
	if (i == 27)
	{
		royal = 2;
	}
	x = 0;
	sky = 2;
	for (i = 0; i < 27; i++)
	{
		x += a[i];
		if (a[i] % 2 != 0)
		{
			break;
		}
		if (a[i] && i % 9 != 0 && i % 9 != 8)
		{
			sky = 0;
		}
	}
	if (x == 14 && i == 27)
	{
		r = max(r, 3 + dragon + purely + royal + sky);
	}
	chunkious = 1;
	sky = 2;
	dfs1(0);
}

int main()
{
	int i, t, tt = 1, flag;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s%s", s1, s2);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		for (i = 0; s1[i]; i += 2)
		{
			a[f(s1[i], s1[i + 1])]++;
			c[f(s1[i], s1[i + 1])]++;
		}
		if (strcmp(s2, "NONE") != 0)
		{
			for (i = 0; s2[i]; i += 2)
			{
				b[f(s2[i], s2[i + 1])]++;
				c[f(s2[i], s2[i + 1])]++;
			}
		}
		printf("Case #%d:\n", tt++);
		flag = 0;
		for (i = 0; i < 27; i++)
		{
			if (c[i] == 4)
			{
				continue;
			}
			a[i]++;
			c[i]++;
			r = 0;
			calc();
			if (r)
			{
				flag = 1;
				printf("%d%c: %d\n", i % 9 + 1, g(i), r);
			}
			a[i]--;
			c[i]--;
		}
		if (flag == 0)
		{
			puts("NONE");
		}
	}
	return 0;
}
