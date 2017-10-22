#include <bits/stdc++.h>

using namespace std;

const int maxn = 145;

int n, pos;
double sum, pri[maxn];

struct player
{
	char name[25];
	double prize;
	bool amateur, t;
	int sc[4], pre, tot, dq, rk;
} p[maxn];

bool cmp1(const player &a, const player &b)
{
	if (a.dq > -3 && b.dq > -3)
	{
		return a.pre < b.pre;
	}
	return a.dq > b.dq;
}

bool cmp2(const player &a, const player &b)
{
	if (a.dq != b.dq)
	{
		return a.dq > b.dq;
	}
	if (a.tot != b.tot)
	{
		return a.tot < b.tot;
	}
	return strcmp(a.name, b.name) < 0;
}

void init()
{
	memset(p, 0, sizeof(p));
	scanf("%lf", &sum);
	for (int i = 0; i < 70; ++i)
	{
		scanf("%lf", &pri[i]);
		pri[i] = pri[i] / 100.0 * sum;
	}
	scanf("%d\n", &n);
	char s[40];
	for (int i = 0; i < n; ++i)
	{
		fgets(p[i].name, 20, stdin);
		if (strchr(p[i].name, '*'))
		{
			p[i].amateur = true;
		}
		for (int j = 0; j < 4; ++j)
		{
			if (!scanf("%d", &p[i].sc[j]))
			{
				p[i].dq = j - 4;
				break;
			}
			if (j < 2)
			{
				p[i].pre += p[i].sc[j];
			}
			p[i].tot += p[i].sc[j];
		}
		fgets(s, 40, stdin);
	}
	return;
}

void solve()
{
	sort(p, p + n, cmp1);
	pos = 0;
	while (pos < min(n, 70) && p[pos].dq > -3)
	{
		++pos;
	}
	while (p[pos].dq > -3 && p[pos].pre == p[pos - 1].pre)
	{
		++pos;
	}
	sort(p, p + pos, cmp2);
	int k = 0, rk = 0, prk = 0;
	while (k < pos)
	{
		if (p[k].dq)
		{
			break;
		}
		int sta = k, prerk = rk + 1, cnt = 0;
		bool x = false;
		double sum = 0;
		while (!p[sta].dq && p[k].tot == p[sta].tot)
		{
			if (!p[sta].amateur)
			{
				sum += pri[prk + cnt++], x = true;
			}
			++rk, ++sta;
		}
		sum /= cnt;
		for (int i = k; i <= sta; ++i)
		{
			p[i].rk = prerk;
			if (prk > 69)
			{
				p[i].amateur = true, p[i].t = false;
			}
			if (!p[i].amateur)
			{
				p[i].prize = sum, p[i].t = cnt > 1;
			}
		}
		k = sta - 1, k++;
		prk += cnt;
	}
}

void disp()
{
	printf("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n");
	printf("-----------------------------------------------------------------------\n");
	for (int i = 0; i < pos; ++i)
	{
		printf("%-21s", p[i].name);
		if (p[i].dq)
			printf("          ");
		else
		{
			char t[5];
			sprintf(t, "%d%c", p[i].rk, p[i].t ? 'T' : ' ');
			printf("%-10s", t);
		}
		for (int j = -4; j < p[i].dq; ++j)
			printf("%-5d", p[i].sc[4 + j]);
		for (int j = p[i].dq; j < 0; ++j)
			printf("     ");
		if (p[i].dq)
			printf("%s", "DQ");
		else if (!p[i].amateur)
			printf("%-10d", p[i].tot);
		else
			printf("%d", p[i].tot);
		if (p[i].dq || p[i].amateur)
		{
			printf("\n");
			continue;
		}
		printf("$%9.2lf\n", p[i].prize);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		init();
		solve();
		disp();
		if (t)
		{
			printf("\n");
		}
	}
	return 0;
}
