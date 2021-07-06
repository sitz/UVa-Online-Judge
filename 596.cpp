#include <bits/stdc++.h>

using namespace std;

struct Pt
{
	long long x, y;

	bool operator<(const Pt &a) const
	{
		if (x != a.x)
		{
			return x < a.x;
		}
		return y < a.y;
	}
};

long long cross(Pt o, Pt a, Pt b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

int monotone(int n, Pt p[], Pt ch[])
{
	sort(p, p + n);
	int i, m = 0, t;
	for (i = 0; i < n; i++)
	{
		while (m >= 2 && cross(ch[m - 2], ch[m - 1], p[i]) < 0)
		{
			m--;
		}
		ch[m++] = p[i];
	}
	for (i = n - 2, t = m + 1; i >= 0; i--)
	{
		while (m >= t && cross(ch[m - 2], ch[m - 1], p[i]) < 0)
		{
			m--;
		}
		ch[m++] = p[i];
	}
	return m - 1;
}

int main()
{
	while (getchar() != ' ')
		;
	char cases[105];
	Pt p[10005], ch[10005];
	int i, j, k;
	while (gets(cases))
	{
		printf("%s convex hull:\n", cases);
		int n = 0, m;
		while (scanf("%s", cases) == 1)
		{
			if (cases[0] != 'P')
			{
				break;
			}
			scanf("%d", &m);
			for (i = 0; i < m; i++, n++)
			{
				scanf("%lld%lld", &p[n].x, &p[n].y);
			}
		}
		sort(p, p + n);
		for (i = 1, j = 0; i < n; i++)
		{
			if (p[j].x != p[i].x || p[j].y != p[i].y)
			{
				p[++j] = p[i];
			}
		}
		n = j + 1;
		m = monotone(n, p, ch);
		int pos = 0;
		for (i = 0; i < m; i++)
		{
			if (ch[i].x > ch[pos].x || (ch[i].x == ch[pos].x && ch[i].y < ch[pos].y))
			{
				pos = i;
			}
		}
		for (i = pos; i < m; i++)
		{
			printf(" (%lld,%lld)", ch[i].x, ch[i].y);
		}
		for (i = 0; i < pos; i++)
		{
			printf(" (%lld,%lld)", ch[i].x, ch[i].y);
		}
		printf("\n");
		if (cases[0] == 'E')
		{
			break;
		}
		while (getchar() != ' ')
			;
	}
	return 0;
}
