#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef signed long long i64;
typedef unsigned long long u64;
typedef pair<int, int> PII;

#define MIN (24 * 60)

VS nam;
int get(string s)
{
	int i;
	for (i = 0; i < nam.size(); i++)
		if (s == nam[i])
		{
			return i;
		}
	nam.push_back(s);
	return i;
}

VI cs, cd, cst, ct;

int main()
{
	int i, j, k, x, y, z, n;
	int h, m, t;
	int ss, es;
	int N, first = 1;
	for (scanf(" %d", &N); N; N--)
	{
		if (!first)
		{
			putchar('\n');
		}
		first = 0;
		nam = VS();
		cs = cd = cst = ct = VI();
		string s;
		cin >> x;
		for (i = 0; i < x; i++)
		{
			cin >> y;
			t = 0;
			for (j = 0; j < y; j++)
			{
				scanf(" %d:%d", &h, &m);
				if (j)
				{
					cst.push_back(t);
				}
				if (j)
				{
					cs.push_back(z);
				}
				if (j)
				{
					ct.push_back(h * 60 + m);
				}
				t = (t + h * 60 + m) % MIN;
				cin >> s;
				z = get(s);
				if (j)
				{
					cd.push_back(z);
				}
			}
		}
		cin >> s;
		ss = get(s);
		cin >> s;
		es = get(s);
		VVI travel(nam.size(), VI(MIN, 1000000000));
		travel[ss] = VI(MIN);
		bool change = true;
		while (change)
		{
			change = false;
			for (i = 0; i < cs.size(); i++)
			{
				x = travel[cs[i]][cst[i]] + ct[i];
				y = (cst[i] + ct[i]) % MIN;
				VI &ar = travel[cd[i]];
				while (ar[y] > x)
				{
					change = true;
					ar[y] = x;
					y = (y + 1) % MIN;
					x++;
				}
			}
		}
		vector<PII> ret;
		for (i = 0; i < MIN; i++)
		{
			ret.push_back(PII(((i - travel[es][i]) % MIN + MIN) % MIN, travel[es][i]));
		}
		sort(ret.begin(), ret.end());
		for (i = 0; i < MIN; i++)
		{
			if (i == 0 || ret[i - 1].first != ret[i].first)
			{
				printf("%02d:%02d ", ret[i].first / 60, ret[i].first % 60);
				printf("%d:%02d\n", ret[i].second / 60, ret[i].second % 60);
			}
		}
	}
	return 0;
}
