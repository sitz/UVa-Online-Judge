#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-6;

struct point
{
	double x, y;
	int num;
	bool operator<(const point &temp) const
	{
		if (fabs(x - temp.x) < EPS)
		{
			return y < temp.y - EPS;
		}
		return x < temp.x;
	}
	bool operator==(const point &temp) const
	{
		return !(*this < temp) && !(temp < *this);
	}
};
point poly[222], pt[1000000];
set<point> ps;

int cnt_p, num;

struct segment
{
	point l, r;
	bool operator<(const segment &temp) const
	{
		if (fabs((r.y - l.y) * (temp.r.x - temp.l.x) - (r.x - l.x) * (temp.r.y - temp.l.y)) < EPS)
		{
			if (fabs((r.x * l.y - l.x * r.y) * (temp.r.x - temp.l.x) - (r.x - l.x) * (temp.r.x * temp.l.y - temp.l.x * temp.r.y)) < EPS)
			{
				if (l == temp.l)
				{
					return r < temp.r;
				}
				return l < temp.l;
			}
			return (r.x * l.y - l.x * r.y) * (temp.r.x - temp.l.x) - (r.x - l.x) * (temp.r.x * temp.l.y - temp.l.x * temp.r.y) < 0;
		}
		return (r.y - l.y) * (temp.r.x - temp.l.x) - (r.x - l.x) * (temp.r.y - temp.l.y) < 0;
	}
};
bool cmp(segment a, segment b)
{
	if (a.l == b.l)
	{
		return a.r < b.r;
	}
	return a.l < b.l;
}
set<segment> hs;
set<segment>::iterator it, itt;
set<point>::iterator pit;

segment lst[1000000], add[1000000];
int n, len, shu[500], cnt_shu, cnt_lst, cnt_add;
char fs[100], str[1111111];

bool inter(segment a, segment b, double &x, double &y)
{
	double ru1, ru2, A, B;
	A = (a.r.x - a.l.x) * (b.r.y - b.l.y) - (a.r.y - a.l.y) * (b.r.x - b.l.x);
	B = (b.l.x - a.l.x) * (b.r.y - b.l.y) - (b.l.y - a.l.y) * (b.r.x - b.l.x);
	if (fabs(A) < EPS)
	{
		return false;
	}
	ru1 = B / A;
	A = -A;
	B = (a.l.x - b.l.x) * (a.r.y - a.l.y) - (a.l.y - b.l.y) * (a.r.x - a.l.x);
	ru2 = B / A;
	if (ru1 < 1 + EPS && ru1 > -EPS && ru2 < 1 + EPS && ru2 > -EPS)
	{
		x = a.l.x + ru1 * (a.r.x - a.l.x);
		y = a.l.y + ru1 * (a.r.y - a.l.y);
		return true;
	}
	return false;
}
bool same_line(segment a, segment b)
{
	double ju1, ju2;
	ju1 = (a.r.y - a.l.y) * (b.r.x - b.l.x) - (a.r.x - a.l.x) * (b.r.y - b.l.y);
	ju2 = (a.r.x * a.l.y - a.l.x * a.r.y) * (b.r.x - b.l.x) - (a.r.x - a.l.x) * (b.r.x * b.l.y - b.l.x * b.r.y);
	return fabs(ju1) < EPS && fabs(ju2) < EPS;
}
void insert(segment now)
{
	int i, j, s, p, q;
	point rp;
	segment nw;
	double x, y;
	cnt_lst = 0;
	for (it = hs.begin(); it != hs.end(); it++)
	{
		if (same_line(now, *it))
		{
			if (!(it->r < now.l) && !(now.r < it->l))
			{
				lst[cnt_lst++] = *it;
			}
		}
		else if (inter(now, *it, x, y))
		{
			lst[cnt_lst++] = *it;
		}
	}
	for (i = 0; i < cnt_lst; i++)
	{
		hs.erase(lst[i]);
	}
	num = 0;
	for (i = 0; i < cnt_lst; i++)
	{
		if (same_line(now, lst[i]))
		{
			if (lst[i].l < now.l)
			{
				now.l = lst[i].l;
			}
			if (now.r < lst[i].r)
			{
				now.r = lst[i].r;
			}
		}
	}
	for (i = 0; i < cnt_lst; i++)
	{
		if (!same_line(now, lst[i]))
		{
			bool test = inter(now, lst[i], rp.x, rp.y);
			if (lst[i].l < rp)
			{
				nw.l = lst[i].l;
				nw.r = rp;
				hs.insert(nw);
			}
			if (rp < lst[i].r)
			{
				nw.l = rp;
				nw.r = lst[i].r;
				hs.insert(nw);
			}
			pt[num++] = rp;
		}
	}
	pt[num++] = now.l;
	pt[num++] = now.r;
	sort(pt, pt + num);
	int nc = 0;
	for (i = 0; i < num; i++)
	{
		if (nc == 0 || pt[nc - 1] < pt[i])
		{
			pt[nc++] = pt[i];
		}
	}
	num = nc;
	for (i = 0; i < num - 1; i++)
	{
		now.l = pt[i];
		now.r = pt[i + 1];
		hs.insert(now);
	}
}
void del(double x, double y, double d)
{
	int i, j, s, p, q;
	double dis, dt, dis1, dis2;
	point rp;
	segment now, nw;
	cnt_lst = 0;
	for (it = hs.begin(); it != hs.end(); it++)
	{
		now = *it;
		dt = sqrt((now.l.x - now.r.x) * (now.l.x - now.r.x) + (now.l.y - now.r.y) * (now.l.y - now.r.y));
		dis = fabs((now.r.y - now.l.y) * x - (now.r.x - now.l.x) * y + now.r.x * now.l.y - now.l.x * now.r.y);
		dis /= dt;
		dis1 = sqrt((now.l.x - x) * (now.l.x - x) + (now.l.y - y) * (now.l.y - y) - dis * dis);
		dis2 = sqrt((now.r.x - x) * (now.r.x - x) + (now.r.y - y) * (now.r.y - y) - dis * dis);
		if (dis < d + EPS)
		{
			if (fabs(dis1 + dis2 - dt) < EPS)
			{
				lst[cnt_lst++] = *it;
			}
			else
			{
				dis1 = sqrt((now.l.x - x) * (now.l.x - x) + (now.l.y - y) * (now.l.y - y));
				dis2 = sqrt((now.r.x - x) * (now.r.x - x) + (now.r.y - y) * (now.r.y - y));
				if (dis1 < d + EPS || dis2 < d + EPS)
				{
					lst[cnt_lst++] = *it;
				}
			}
		}
	}
	for (i = 0; i < cnt_lst; i++)
	{
		hs.erase(lst[i]);
	}
	ps.clear();
	for (it = hs.begin(); it != hs.end(); it++)
	{
		now = *it;
		pit = ps.find(now.l);
		rp = now.l;
		if (pit != ps.end())
		{
			rp = *pit;
			ps.erase(rp);
			rp.num++;
		}
		else
		{
			rp.num = 1;
		}
		ps.insert(rp);
		pit = ps.find(rp);
		rp = now.r;
		pit = ps.find(now.r);
		if (pit != ps.end())
		{
			rp = *pit;
			ps.erase(rp);
			rp.num++;
		}
		else
		{
			rp.num = 1;
		}
		ps.insert(rp);
	}
	cnt_lst = cnt_add = 0;
	for (it = hs.begin(); it != hs.end(); it++)
	{
		if (it == hs.begin() || !same_line(add[cnt_add - 1], *it) || !(add[cnt_add - 1].r == it->l))
		{
			add[cnt_add++] = *it;
		}
		else
		{
			rp = add[cnt_add - 1].r;
			pit = ps.find(rp);
			if (pit == ps.end() || pit->num > 2)
			{
				add[cnt_add++] = *it;
			}
			else
			{
				add[cnt_add - 1].r = it->r;
			}
		}
	}
	hs.clear();
	for (i = 0; i < cnt_add; i++)
	{
		hs.insert(add[i]);
	}
}

int main()
{
	int i, j, s, p, q;
	double x, y, d;
	segment now;
	while (scanf("%d", &n) && n)
	{
		getchar();
		hs.clear();
		for (i = 0; i <= n; i++)
		{
			j = 0;
			gets(str);
			len = strlen(str);
			cnt_shu = 0;
			shu[0] = 0;
			int flag = 1;
			for (j = 0; j < len; j++)
			{
				if (str[j] == '-')
				{
					flag = -1;
				}
				else if (str[j] <= '9' && str[j] >= '0')
				{
					shu[cnt_shu] = 10 * shu[cnt_shu] + str[j] - '0';
				}
				else if (j && str[j - 1] >= '0' && str[j - 1] <= '9' && str[j] == ' ')
				{
					shu[cnt_shu] *= flag;
					cnt_shu++;
					shu[cnt_shu] = 0;
					flag = 1;
				}
			}
			shu[cnt_shu] *= flag;
			cnt_shu++;
			if (str[0] == 'D')
			{
				cnt_p = 0;
				for (j = 0; j < cnt_shu; j++)
				{
					if (j % 2 == 0)
					{
						poly[cnt_p].x = shu[j];
					}
					else
					{
						poly[cnt_p++].y = shu[j];
					}
				}
				poly[cnt_p] = poly[0];
				for (j = 0; j < cnt_p - 1; j++)
				{
					segment now;
					now.l = poly[j];
					now.r = poly[j + 1];
					if (now.l == now.r)
					{
						continue;
					}
					if (now.r < now.l)
					{
						swap(now.l, now.r);
					}
					insert(now);
				}
			}
			else if (str[0] != 'E')
			{
				x = shu[0];
				y = shu[1];
				d = shu[2];
				del(x, y, d);
			}
		}
		num = 0;
		for (it = hs.begin(); it != hs.end(); it++)
		{
			now = *it;
			pt[num++] = now.l;
			pt[num++] = now.r;
		}
		sort(pt, pt + num);
		int nc = 0;
		for (i = 0; i < num; i++)
		{
			if (nc == 0 || pt[nc - 1] < pt[i])
			{
				pt[nc++] = pt[i];
			}
		}
		num = nc;
		printf("%d\n", num);
		for (i = 0; i < num; i++)
		{
			printf("%.2f %.2f\n", pt[i].x + EPS, pt[i].y + EPS);
		}
		printf("%d\n", hs.size());
		cnt_lst = 0;
		for (it = hs.begin(); it != hs.end(); it++)
		{
			lst[cnt_lst++] = *it;
		}
		sort(lst, lst + cnt_lst, cmp);
		for (i = 0; i < cnt_lst; i++)
		{
			now = lst[i];
			int id1 = -1, id2 = -1;
			for (j = 0; j < num; j++)
			{
				if (now.l == pt[j])
				{
					id1 = j + 1;
				}
				if (now.r == pt[j])
				{
					id2 = j + 1;
				}
			}
			printf("%d %d\n", id1, id2);
		}
	}
	return 0;
}
