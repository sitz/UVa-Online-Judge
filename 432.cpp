#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define mp make_pair

typedef pair<int, int> pii;

void output(int x1, int y1, int x2, int y2)
{
	printf("(%d,%d)(%d,%d)\n", x1, y1, x2, y2);
}

void reverse_triangle(int basex, int x, int y)
{
	output(basex + x, 0, basex + x - x / 2, y / 2);
	output(basex + x - x / 2, y / 2, basex + x + x / 2, y / 2);
	output(basex + x + x / 2, y / 2, basex + x, 0);
}

pii recleft(int basex, int x, int y, int rem)
{
	pii last;
	if (rem != 0)
	{
		last = recleft(basex, x / 2, y / 2, rem - 1);
	}
	else
	{
		return mp(basex, 0);
	}
	output(last.first, last.second, basex + x, 0);
	reverse_triangle(basex, x, y);
	return mp(basex + x, 0);
}

pii recright(int basex, int x, int y, int rem)
{
	pii last;
	output(basex, 0, basex + x, 0);
	reverse_triangle(basex, x, y);
	if (rem > 1)
	{
		last = recright(basex + x, x / 2, y / 2, rem - 1);
		return last;
	}
	return mp(basex + x, 0);
}

void solve(int r, int l, int x, int y)
{
	pii last;
	if (r == 1 && l == 1)
		;
	else if ((r > 0 && l > 1) || (r > 1 || l > 0))
		;
	else if (r == 0 && l == 0)
	{
		output(x, y, 0, 0);
		output(0, 0, 2 * x, 0);
		output(2 * x, 0, x, y);
		return;
	}
	else
	{
		return;
	}
	output(x, y, 0, 0);
	if (l > 1)
	{
		last = recleft(0, x / 2, y / 2, l - 1);
	}
	else
	{
		last = mp(0, 0);
	}
	output(last.first, last.second, x, 0);
	reverse_triangle(0, x, y);
	last = mp(x, 0);
	if (r > 1)
	{
		last = recright(x, x / 2, y / 2, r - 1);
	}//else
	output(last.first, last.second, 2 * x, 0);
	output(2 * x, 0, x, y);
}

main()
{
	int te;
	cin >> te;
	while (te--)
	{
		int r, l, x, y;
		cin >> l >> r >> x >> y;
		solve(r, l, x, y);
		puts("");
	}
}
