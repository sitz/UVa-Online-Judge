#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000

int Tval, Q[MAXN], QH, QT, MAX;
struct ss
{
	int level;
	char visit;
} V[MAXN];
int Val(int a, int b, int c, int d)
{
	return a * 1000 + b * 100 + c * 10 + d;
}
int Push(int n, int l)
{
	if (V[n].visit == 'r')
	{
		return 0;
	}
	if (n == Tval)
	{
		return 1;
	}
	V[n].visit = 'r';
	V[n].level = l;
	Q[QH++] = n;
	QH %= MAXN;
	return 0;
}
int Pop()
{
	int n;
	n = Q[QT++];
	QT %= MAXN;
	return n;
}
int IsEmpty()
{
	return QH == QT;
}
int PushAll(int a, int b, int c, int d, int lev)
{
	int val, i, j;
	int x[] = {1, -1};
	char temp[100], dummy[100];
	val = Val(a, b, c, d);
	sprintf(temp, "%04d", val);
	strcpy(dummy, temp);
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
		{
			temp[i] = ((dummy[i] - '0' + x[j] + 10) % 10) + '0';
			if (Push(atoi(temp), lev))
			{
				return 1;
			}
		}
		strcpy(temp, dummy);
	}
	return 0;
}
void Ini()
{
	int i;
	for (i = 0; i < MAXN; i++)
	{
		V[i].level = 0;
		V[i].visit = 'w';
	}
}
void DoBfs(int a, int b, int c, int d)
{
	int p, q, r, s, val, lev, n;
	char dummy[100];
	MAX = 21474873;
	if (V[Tval].visit == 'r')
	{
		printf("-1\n");
		return;
	}
	QH = QT = 0;
	val = Val(a, b, c, d);
	V[val].level = 0;
	Push(val, 0);
	while (!IsEmpty())
	{
		n = Pop();
		sprintf(dummy, "%04d", n);
		p = dummy[0] - '0';
		q = dummy[1] - '0';
		r = dummy[2] - '0';
		s = dummy[3] - '0';
		lev = V[n].level + 1;
		if (PushAll(p, q, r, s, lev))
		{
			printf("%d\n", lev);
			return;
		}
	}
	printf("-1\n");
}

int main()
{
	int kase, i, r, f, t;
	int sa, sb, sc, sd;
	int a, b, c, d, v;
	scanf("%d", &kase);
	while (kase--)
	{
		Ini();
		f = 0;
		scanf("%d%d%d%d", &sa, &sb, &sc, &sd);
		scanf("%d%d%d%d", &a, &b, &c, &d);
		Tval = Val(a, b, c, d);
		t = Val(sa, sb, sc, sd);
		scanf("%d", &r);
		for (i = 0; i < r; i++)
		{
			scanf("%d%d%d%d", &a, &b, &c, &d);
			v = Val(a, b, c, d);
			V[v].visit = 'r';
		}
		if (Tval == t && V[t].visit != 'r')
		{
			printf("0\n");
			continue;
		}
		DoBfs(sa, sb, sc, sd);
	}
	return 0;
}
