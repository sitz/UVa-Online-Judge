#include <bits/stdc++.h>

using namespace std;

typedef struct List
{
	int x, y;
} LIST;
LIST lst[1205], tmp[1205];

int n;

bool cmp(const LIST &p1, const LIST &p2);
int cro(LIST p, LIST q, LIST o);
int inn(LIST p, LIST q, LIST o);

int main()
{
	int N, i, j, c, all, cnt = 1;
	while (scanf(" %d", &N) == 1 && N)
	{
		for (n = c = 0; n < N; n++)
		{
			scanf(" %d %d", &lst[n].x, &lst[n].y);
		}
		all = N * (N - 1) * (N - 2) / 6;
		if (N < 3)
		{
			printf("Scenario %d:\n", cnt++);
			printf("There are 0 sites for making valid tracks\n");
			continue;
		}
		for (n = 0; n < N; n++)
		{
			j = 0;
			for (i = 0; i < N; i++)
			{
				if (i == n)
				{
					continue;
				}
				tmp[j].x = lst[i].x - lst[n].x;
				tmp[j].y = lst[i].y - lst[n].y;
				j++;
			}
			sort(tmp, tmp + N - 1, cmp);
			int st = 0, p = 1, q = 1;
			for (st = 0; st < N - 1; st++)
			{
				int t = 0, k = 0;
				if (p == st)
				{
					p = (p + 1) % (N - 1);
				}
				if (q == st)
				{
					q = (q + 1) % (N - 1);
				}
				while (cro(tmp[st], tmp[p], lst[n]) >= 0 && inn(tmp[st], tmp[p], lst[n]) > 0)
				{
					p = (p + 1) % (N - 1);
					if (p == st)
					{
						break;
					}
					t = 1;
					k++;
				}
				t = 0;
				while (cro(tmp[st], tmp[q], lst[n]) >= 0)
				{
					q = (q + 1) % (N - 1);
					if (q == st)
					{
						break;
					}
					t = 1;
					k++;
				}
				if (q == st || p == st)
				{
					if (p != st && cro(tmp[st], tmp[p], lst[n]) >= 0 && inn(tmp[st], tmp[p], lst[n]) <= 0)
					{
						if (q >= p)
						{
							c += (q - p);
						}
						else
						{
							c += (q + N - 1 - p);
						}
					}
					continue;
				}
				if (cro(tmp[st], tmp[p], lst[n]) >= 0 && inn(tmp[st], tmp[p], lst[n]) <= 0 && cro(tmp[st], tmp[q], lst[n]) < 0)
				{
					if (q >= p)
					{
						c += (q - p);
					}
					else
					{
						c += (q + N - p - 1);
					}
				}
			}
		}
		printf("Scenario %d:\n", cnt++);
		printf("There are %d sites for making valid tracks\n", all - c);
	}
	return 0;
}

bool cmp(const LIST &p1, const LIST &p2)
{
	if (p1.y > 0 && p2.y > 0)
	{
		return p2.x * p1.y < p2.y * p1.x;
	}
	else if (p1.y < 0 && p2.y < 0)
	{
		return p2.x * p1.y < p2.y * p1.x;
	}
	else if (p1.y == 0)
		if (p1.x > 0)
		{
			return true;
		}
		else
		{
			return p2.y < 0;
		}
	else if (p2.y == 0)
		if (p2.x > 0)
		{
			return false;
		}
		else
		{
			return p1.y > 0;
		}
	else
	{
		return p1.y > 0;
	}
}
int cro(LIST p, LIST q, LIST o)
{
	int cross = (p.x) * (q.y) - (q.x) * (p.y);
	return cross;
}
int inn(LIST p, LIST q, LIST o)
{
	int inner = (p.x) * (q.x) + (q.y) * (p.y);
	return inner;
}
