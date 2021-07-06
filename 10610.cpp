#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005

typedef long long LL;

struct node
{
	LL dis;
	char color;
} V[MAXN];

struct pt
{
	double x, y;
} P[MAXN];

LL lim, thole, Dis[MAXN][MAXN], Q[MAXN], qh, qt;

double ds(double x1, double y1, double x2, double y2)
{
	double x, y, z;
	x = (x1 - x2);
	x *= x;
	y = (y1 - y2);
	y *= y;
	z = sqrt(x + y);
	return z;
}
void GetDis()
{
	int i, j, s;
	double d;
	for (i = 0; i < thole; i++)
	{
		for (j = i + 1; j < thole; j++)
		{
			d = ds(P[i].x, P[i].y, P[j].x, P[j].y);
			s = (LL)(d * 1000);
			Dis[i + 1][j + 1] = Dis[j + 1][i + 1] = s;
		}
	}
}
int isBlank(char str[])
{
	int i;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
	}
	return strlen(str) == 0;
}
void Ini()
{
	int i;
	for (i = 1; i <= thole; i++)
	{
		V[i].color = 0;
		V[i].dis = 0;
	}
}
void Push(LL n)
{
	Q[qh++] = n;
	qh %= MAXN;
}
LL Pop()
{
	LL n;
	n = Q[qt++];
	qt %= MAXN;
	return n;
}
LL BFS()
{
	LL i, p;
	qh = qt = 0;
	Push(1);
	V[1].color = 1;
	while (qh != qt)
	{
		p = Pop();
		for (i = 1; i <= thole; i++)
		{
			if (V[i].color || Dis[p][i] > lim)
			{
				continue;
			}
			if (i == 2)
			{
				return V[p].dis;
			}
			V[i].color = 1;
			V[i].dis = V[p].dis + 1;
			Push(i);
		}
	}
	return -1;
}
void Cal()
{
	LL n;
	Ini();
	n = BFS();
	if (n >= 0)
	{
		printf("Yes, visiting %lld other holes.\n", n);
	}
	else
	{
		printf("No.\n");
	}
}

int main()
{
	char str[200];
	LL n, m;
	while (gets(str))
	{
		sscanf(str, "%lld%lld", &n, &m);
		if (!n && !m)
		{
			break;
		}
		lim = n * m * 1000 * 60;
		thole = 0;
		gets(str);
		while (!isBlank(str))
		{
			sscanf(str, "%lf%lf", &P[thole].x, &P[thole].y);
			thole++;
			gets(str);
		}
		GetDis();
		Cal();
	}
	return 0;
}
