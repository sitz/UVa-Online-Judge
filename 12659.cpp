#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define A first
#define B second

char zz[10];
int tmp[10], ca = 0, n, m;
pair<int, int> ans[5050][5050];
vector<int> cc[2];
map<pair<int, int>, pair<int, int>> lst;

void deal()
{
	map<pair<int, int>, pair<int, int>> use;
	for (map<pair<int, int>, pair<int, int>>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		use[it->B] = it->A;
	}
	memset(ans, -1, sizeof(ans));
	int tcc = 0;
	long long dis = 0;
	for (int i = 0; i < cc[0].size(); i++)
		for (int j = 0; j < cc[1].size(); j++)
		{
			int a = cc[0][i], b = cc[1][j];
			pair<int, int> tmp = mp(a, b);
			if (use.find(tmp) != use.end())
			{
				a = use[tmp].A;
				b = use[tmp].B;
			}
			if (a < n && b < m)
			{
				ans[a][b] = mp(i, j);
				tcc++;
				dis += abs(i - a) + abs(j - b);
			}
		}
	printf("Spreadsheet #%d\n", ++ca);
	printf("There are %d cell(s) kept, total distance = %lld\n", tcc, dis);
}

int solve()
{
	if (scanf("%d%d", &n, &m) == EOF)
	{
		return 0;
	}
	if (n == 0 && m == 0)
	{
		return 0;
	}
	if (ca != 0)
	{
		puts("");
	}
	lst.clear();
	cc[0].resize(n);
	cc[1].resize(m);
	for (int i = 0; i < n; i++)
	{
		cc[0][i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cc[1][i] = i;
	}
	int k;
	scanf("%d", &k);
	int cnt = n + m;
	for (int i = 0; i < k; i++)
	{
		scanf("%s", zz);
		if (zz[0] == 'D')
		{
			int t;
			scanf("%d", &t);
			for (int i = 0; i < t; i++)
			{
				scanf("%d", tmp + i);
			}
			sort(tmp, tmp + t);
			int w = zz[1] == 'C';
			for (int i = t - 1; i >= 0; i--)
			{
				tmp[i]--;
				cc[w].erase(cc[w].begin() + tmp[i]);
			}
		}
		else if (zz[0] == 'I')
		{
			int t;
			scanf("%d", &t);
			for (int i = 0; i < t; i++)
			{
				scanf("%d", tmp + i);
			}
			sort(tmp, tmp + t);
			int w = zz[1] == 'C';
			for (int i = t - 1; i >= 0; i--)
			{
				tmp[i]--;
				cc[w].insert(cc[w].begin() + tmp[i], cnt++);
			}
		}
		else
		{
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			a--;
			b--;
			c--;
			d--;
			a = cc[0][a], b = cc[1][b], c = cc[0][c], d = cc[1][d];
			if (lst.find(mp(a, b)) == lst.end())
			{
				lst[mp(a, b)] = mp(a, b);
			}
			if (lst.find(mp(c, d)) == lst.end())
			{
				lst[mp(c, d)] = mp(c, d);
			}
			pair<int, int> tmp = lst[mp(a, b)];
			lst[mp(a, b)] = lst[mp(c, d)];
			lst[mp(c, d)] = tmp;
		}
	}
	deal();
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		if (ans[a][b].A == -1)
		{
			printf("Cell data in (%d,%d) GONE\n", a + 1, b + 1);
		}
		else
		{
			printf("Cell data in (%d,%d) moved to (%d,%d)\n", a + 1, b + 1, ans[a][b].A + 1, ans[a][b].B + 1);
		}
	}
	return 1;
}

int main()
{
	while (solve())
		;
	return 0;
}
