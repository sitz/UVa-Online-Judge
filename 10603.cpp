#include <bits/stdc++.h>

using namespace std;

#define MIN(a, b) (a > b ? b : a)
#define MAXN 1000000// may have to increase

typedef short st;

map<int, int> M;

struct ss
{
	short a, b, c;
	int pour;
} Q[MAXN];
int qh, qt, mindiff, minpour, ca, cb, cc, target;

void Push(st a, st b, st c, int pour)
{
	Q[qh].a = a;
	Q[qh].a = a;
	Q[qh].b = b;
	Q[qh].c = c;
	Q[qh++].pour = pour;
	qh %= MAXN;
}
ss Pop()
{
	ss t;
	t.a = Q[qt].a;
	t.b = Q[qt].b;
	t.c = Q[qt].c;
	t.pour = Q[qt].pour;
	qt++;
	qt %= MAXN;
	return t;
}
void Diff(int a, int b, int c, int np)
{
	int diff;
	diff = target - a;
	if (diff >= 0 && diff <= mindiff)
	{
		if (diff < mindiff)
		{
			mindiff = diff;
			minpour = np;
		}
		else if (diff == mindiff && np < minpour)
			minpour = np;
	}
	diff = target - b;
	if (diff >= 0 && diff <= mindiff)
	{
		if (diff < mindiff)
		{
			mindiff = diff;
			minpour = np;
		}
		else if (diff == mindiff && np < minpour)
			minpour = np;
	}
	diff = target - c;
	if (diff >= 0 && diff <= mindiff)
	{
		if (diff < mindiff)
		{
			mindiff = diff;
			minpour = np;
		}
		else if (diff == mindiff && np < minpour)
			minpour = np;
	}
}
void Pusha(int a, int b, int c, int pour)
{
	int d, ta, tb, tc, val, flag, np;
	if (!a)
		return;
	if (b < cb)//ok
	{
		d = MIN(cb - b, a);
		np = d + pour;
		ta = a - d;
		tb = b + d;
		val = ta * 40401 + 201 * tb + c;
		flag = M[val];
		if (flag)
		{
			if (flag > np)
			{
				Push(ta, tb, c, np);
				M[val] = np;
			}
		}
		else
		{
			Push(ta, tb, c, np);
			M[val] = np;
		}
		Diff(ta, tb, c, np);
	}
	if (c < cc)// ok
	{
		d = MIN(cc - c, a);
		np = d + pour;
		ta = a - d;
		tc = c + d;
		val = ta * 40401 + 201 * b + tc;
		flag = M[val];
		if (flag)
		{
			if (flag > np)
			{
				Push(ta, b, tc, np);
				M[val] = np;
			}
		}
		else
		{
			Push(ta, b, tc, np);
			M[val] = np;
		}
		Diff(ta, b, tc, np);
	}
}
void Pushb(int a, int b, int c, int pour)
{
	int d, ta, tb, tc, val, flag, np;
	if (!b)
		return;
	if (a < ca)//ok
	{
		d = MIN(ca - a, b);
		np = d + pour;
		ta = a + d;
		tb = b - d;
		val = ta * 40401 + 201 * tb + c;
		flag = M[val];
		if (flag)
		{
			if (flag > np)
			{
				Push(ta, tb, c, np);
				M[val] = np;
			}
		}
		else
		{
			Push(ta, tb, c, np);
			M[val] = np;
		}
		Diff(ta, tb, c, np);
	}
	if (c < cc)//ok
	{
		d = MIN(cc - c, b);
		np = d + pour;
		tb = b - d;
		tc = c + d;
		val = a * 40401 + 201 * tb + tc;
		flag = M[val];
		if (flag)
		{
			if (flag > np)
			{
				Push(a, tb, tc, np);
				M[val] = np;
			}
		}
		else
		{
			Push(a, tb, tc, np);
			M[val] = np;
		}
		Diff(a, tb, tc, np);
	}
}
void Pushc(int a, int b, int c, int pour)
{
	int d, ta, tb, tc, val, flag, np;
	if (!c)
		return;
	if (a < ca)//ok
	{
		d = MIN(ca - a, c);
		np = d + pour;
		ta = a + d;
		tc = c - d;
		val = ta * 40401 + 201 * b + tc;
		flag = M[val];
		if (flag)
		{
			if (flag > np)
			{
				Push(ta, b, tc, np);
				M[val] = np;
			}
		}
		else
		{
			Push(ta, b, tc, np);
			M[val] = np;
		}
		Diff(ta, b, tc, np);
	}
	if (b < cb)//ok
	{
		d = MIN(cb - b, c);
		np = d + pour;
		tc = c - d;
		tb = b + d;
		val = a * 40401 + 201 * tb + tc;
		flag = M[val];
		if (flag)
		{
			if (flag > np)
			{
				Push(a, tb, tc, np);
				M[val] = np;
			}
		}
		else
		{
			Push(a, tb, tc, np);
			M[val] = np;
		}
		Diff(a, tb, tc, np);
	}
}
void BFS()
{
	ss p;
	qh = qt = 0;
	Push(0, 0, cc, 0);
	while (qh != qt)
	{
		p = Pop();
		Pusha(p.a, p.b, p.c, p.pour);
		Pushb(p.a, p.b, p.c, p.pour);
		Pushc(p.a, p.b, p.c, p.pour);
	}
}
void Cal()
{
	mindiff = target;
	minpour = 0;
	if (cc <= target)
	{
		printf("%d %d\n", 0, cc);
		return;
	}
	BFS();
	printf("%d %d\n", minpour, target - mindiff);
}

int main()
{
	int kases;
	scanf("%d", &kases);
	while (kases--)
	{
		scanf("%d%d%d%d", &ca, &cb, &cc, &target);
		Cal();
		if (kases)
		{
			M.clear();
		}
	}
	return 0;
}
