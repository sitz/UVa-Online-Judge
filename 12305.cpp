#include <bits/stdc++.h>

using namespace std;

struct halfplane
{
	double a, b, c, d;
	int id[1111];
};
halfplane half[111];

struct point
{
	double x, y, z;
	double ax, bx, ay, by, az, bz;
};
point to, rr;

struct polygon
{
	vector<point> pt;
	int flag, ip;
};
polygon up, down, lt[111][1111], lst[111111], up_t, down_t[1111], now_t, now, nw, var[1111], temp[1111];

int d_cnt[1111], n, m, cnt_up, cnt_down, cnt, num_z[1111];

struct zz
{
	double v;
	bool del;
	bool operator<(const zz &temp) const
	{
		return v < temp.v;
	}
};
zz z[1111][201];

double h, eps = 1e-9, surf[211], volume[211], now_a, now_b, now_c;

int inter(point l, point r, double a, double b, double c, double d)
{
	double ru, x1 = l.x, y1 = l.y, z1 = l.z, x2 = r.x, y2 = r.y, z2 = r.z, v, ru_a, ru_b;
	v = a * (x2 - x1) + b * (y2 - y1) + c * (z2 - z1);
	if (fabs(v) < eps)
	{
		return 0;
	}
	ru = -(a * x1 + b * y1 + c * z1 + d) / v;
	ru_a = -c / v;
	ru_b = -(a * x1 + b * y1 + d) / v;
	rr.ax = ru_a * (x2 - x1);
	rr.bx = x1 + ru_b * (x2 - x1);
	rr.x = x1 + ru * (x2 - x1);
	rr.ay = ru_a * (y2 - y1);
	rr.by = y1 + ru_b * (y2 - y1);
	rr.az = 1;
	rr.bz = 0;
	rr.y = y1 + ru * (y2 - y1);
	rr.z = z1 + ru * (z2 - z1);
	if (ru < 1 + eps && ru > -eps)
	{
		return 2;
	}
	return 0;
}
void deal(polygon &lp, double a, double b, double c, double d)
{
	int i, j, s, p, q, p_ip = lp.ip;
	if (lp.pt.size() == 0)
	{
		return;
	}
	now.pt.clear();
	now.flag = lp.flag;
	for (i = 0; i < lp.pt.size(); i++)
	{
		if (a * lp.pt[i].x + b * lp.pt[i].y + c * lp.pt[i].z + d < eps)
		{
			to = lp.pt[i];
			now.pt.push_back(to);
		}
		if (inter(lp.pt[i], lp.pt[(i + 1) % lp.pt.size()], a, b, c, d) > 0)
		{
			now.pt.push_back(rr);
		}
	}
	lp = now;
	lp.ip = p_ip;
}
void ins(polygon &lp, int ip)
{
	deal(lp, half[ip].a, half[ip].b, half[ip].c, half[ip].d);
}
void insert(int id, int ip)
{
	int i, j, s, p, q;
	double a, b, c, d;
	if (id == ip)
	{
		for (i = 1; i < n - 1; i++)
		{
			a = half[ip].a;
			b = half[ip].b;
			c = 0;
			d = half[ip].d;
			if (half[ip].c < 0)
			{
				a = -a;
				b = -b;
				d = -d;
			}
			deal(lt[id][i], a, b, c, d);
			a = half[ip].a;
			b = half[ip].b;
			c = 0;
			d = half[ip].c * h + half[ip].d;
			if (half[ip].c < 0)
			{
				a = -a;
				b = -b;
				d = -d;
			}
			deal(lt[id][i], -a, -b, -c, -d);
			if (half[ip].c == 0)
			{
				now.pt.clear();
				to = rr = lt[id][i].pt[0];
				for (j = 1; j < lt[id][i].pt.size(); j++)
				{
					if (fabs(lt[id][i].pt[j].x - to.x) > eps || fabs(lt[id][i].pt[j].y - to.y) > eps)
					{
						rr = lt[id][i].pt[j];
						break;
					}
				}
				to.z = 0;
				now.pt.push_back(to);
				to.z = h;
				now.pt.push_back(to);
				to = rr;
				to.z = h;
				now.pt.push_back(to);
				to.z = 0;
				now.pt.push_back(to);
				now.ip = 0;
				lst[cnt] = now;
				lst[cnt++].flag = down_t[i].flag;
				half[id].id[i] = cnt - 1;
				lt[id][i].pt.clear();
			}
		}
	}
	a = half[id].a;
	b = half[id].b;
	c = half[id].c;
	d = half[id].d;
	if (c < 0)
	{
		a = -a;
		b = -b;
		c = -c;
		d = -d;
	}
	for (i = 1; i < n - 1; i++)
	{
		if (half[id].c != 0)
		{
			deal(lt[id][i], half[ip].a * c - half[ip].c * a, half[ip].b * c - half[ip].c * b, 0, half[ip].d * c - half[ip].c * d);
		}
		else
		{
			deal(lst[half[id].id[i]], half[ip].a, half[ip].b, half[ip].c, half[ip].d);
		}
	}
}
double get_angle(double a, double b, double c)
{
	return atan2(sqrt(a * a + b * b), fabs(c));
}
double get_area(point a, point b, point c)
{
	double dx1 = (a.x - c.x), dy1 = (a.y - c.y), dz1 = (a.z - c.z), dx2 = (b.x - c.x), dy2 = (b.y - c.y), dz2 = (b.z - c.z);
	double dax1, dbx1, day1, dby1, daz1, dbz1, dax2, dbx2, day2, dby2, daz2, dbz2;
	double f1 = dx1 * dy2 - dx2 * dy1, f2 = dx1 * dz2 - dz1 * dx2, f3 = dy1 * dz2 - dz1 * dy2;
	dax1 = a.ax - c.ax;
	dbx1 = a.bx - c.bx;
	day1 = a.ay - c.ay;
	dby1 = a.by - c.by;
	dax2 = b.ax - c.ax;
	dbx2 = b.bx - c.bx;
	day2 = b.ay - c.ay;
	dby2 = b.by - c.by;
	now_a = 0.5 * (dax1 * day2 - dax2 * day1);
	now_b = 0.5 * (dax1 * dby2 + dbx1 * day2 - dax2 * dby1 - dbx2 * day1);
	now_c = 0.5 * (dbx1 * dby2 - dbx2 * dby1);
	return 0.5 * sqrt(f1 * f1 + f2 * f2 + f3 * f3);
}
double solve_surf(int id)
{
	int i, j, s, p, q, neg = 0, posi = 0;
	double res = 0, now, theta;
	for (i = 0; i < cnt; i++)
	{
		if (lst[i].pt.size() > 0 && lst[i].ip > 0)
		{
			posi = 1;
		}
		if (lst[i].pt.size() > 0 && lst[i].ip < 0)
		{
			neg = 1;
		}
	}
	for (i = 0; i < n - 2; i++)
	{
		num_z[i] = 0;
		if (neg > 0)
		{
			z[i][num_z[i]++].v = 0;
		}
		if (posi > 0)
		{
			z[i][num_z[i]++].v = h;
		}
	}
	for (i = 0; i < cnt; i++)
	{
		now = 0;
		for (j = 1; j < (int)(lst[i].pt.size()) - 1; j++)
		{
			now += lst[i].flag * get_area(lst[i].pt[0], lst[i].pt[j], lst[i].pt[j + 1]);
		}
		res += now;
	}
	for (i = 0; i < id; i++)
		for (j = 1; j < n - 1; j++)
		{
			double test = 0;
			for (s = 1; s < (int)(lt[i][j].pt.size()) - 1; s++)
			{
				now = lt[i][j].flag * get_area(lt[i][j].pt[0], lt[i][j].pt[s], lt[i][j].pt[s + 1]);
				theta = get_angle(half[i].a, half[i].b, half[i].c);
				now /= cos(theta);
				res += now;
				test += now;
			}
			for (s = 0; s < lt[i][j].pt.size(); s++)
			{
				double xx = lt[i][j].pt[s].x, yy = lt[i][j].pt[s].y;
				z[j - 1][num_z[j - 1]++].v = -(half[i].a * xx + half[i].b * yy + half[i].d) / half[i].c;
			}
		}
	return res;
}
double solve_volume(int id)
{
	int i, j, s, p, q, siz;
	bool del;
	double S1, S2, h1, h2, res = 0, now, rc;
	for (j = 1; j < n - 1; j++)
		for (i = 0; i < num_z[j - 1] - 1; i++)
		{
			if (z[j - 1][i].v == z[j - 1][i + 1].v)
			{
				continue;
			}
			temp[j] = var[j] = down_t[j];
			siz = var[j].pt.size();
			for (s = 0; s < siz; s++)
			{
				var[j].pt[s].z = 0.5 * (z[j - 1][i].v + z[j - 1][i + 1].v);
				temp[j].pt[s].z = z[j - 1][i].v + 0.25 * (z[j - 1][i + 1].v - z[j - 1][i].v);
				var[j].pt[s].ax = 0;
				var[j].pt[s].bx = var[j].pt[s].x;
				var[j].pt[s].ay = 0;
				var[j].pt[s].by = var[j].pt[s].y;
				var[j].pt[s].az = 1;
				var[j].pt[s].bz = 0;
			}
			for (s = 0; s <= id; s++)
			{
				ins(var[j], s);
				ins(temp[j], s);
				if (var[j].pt.size() < 3)
				{
					break;
				}
			}
			if (s <= id)
			{
				continue;
			}
			siz = var[j].pt.size();
			for (s = 0; s < siz; s++)
			{
				double ru_a = 1.0 / (var[j].pt[s].z - temp[j].pt[s].z);
				double ru_b = -temp[j].pt[s].z / (var[j].pt[s].z - temp[j].pt[s].z);
				double x1 = temp[j].pt[s].x, y1 = temp[j].pt[s].y, x2 = var[j].pt[s].x, y2 = var[j].pt[s].y;
				var[j].pt[s].ax = ru_a * (x2 - x1);
				var[j].pt[s].bx = x1 + ru_b * (x2 - x1);
				var[j].pt[s].ay = ru_a * (y2 - y1);
				var[j].pt[s].by = y1 + ru_b * (y2 - y1);
			}
			rc = 0;
			for (s = 1; s < siz - 1; s++)
			{
				get_area(var[j].pt[0], var[j].pt[s], var[j].pt[s + 1]);
				now = now_a * (z[j - 1][i + 1].v * z[j - 1][i + 1].v * z[j - 1][i + 1].v - z[j - 1][i].v * z[j - 1][i].v * z[j - 1][i].v) / 3.0;
				now += now_b * (z[j - 1][i + 1].v * z[j - 1][i + 1].v - z[j - 1][i].v * z[j - 1][i].v) / 2.0;
				now += now_c * (z[j - 1][i + 1].v - z[j - 1][i].v);
				res += var[j].flag * fabs(now);
				rc += var[j].flag * fabs(now);
			}
		}
	return res;
}

int main()
{
	int i, j, s, p, q;
	while (scanf("%d%lf%d", &n, &h, &m) && (n + h + m))
	{
		up.pt.clear();
		down.pt.clear();
		for (i = 0; i < n; i++)
		{
			scanf("%lf%lf", &to.x, &to.y);
			to.z = 0;
			down.pt.push_back(to);
			to.z = h;
			up.pt.push_back(to);
		}
		cnt = 0;
		memset(d_cnt, 0, sizeof(d_cnt));
		for (i = 1; i < n - 1; i++)
		{
			up_t.pt.clear();
			up_t.pt.push_back(up.pt[0]);
			up_t.pt.push_back(up.pt[i]);
			up_t.pt.push_back(up.pt[i + 1]);
			up_t.ip = 1;
			down_t[i].pt.clear();
			down_t[i].pt.push_back(down.pt[0]);
			down_t[i].pt.push_back(down.pt[i]);
			down_t[i].pt.push_back(down.pt[i + 1]);
			down_t[i].ip = -1;
			if ((up.pt[i + 1].y - up.pt[0].y) * (up.pt[i].x - up.pt[0].x) > (up.pt[i + 1].x - up.pt[0].x) * (up.pt[i].y - up.pt[0].y))
			{
				down_t[i].flag = up_t.flag = 1;
			}
			else
			{
				down_t[i].flag = up_t.flag = -1;
			}
			lst[cnt++] = up_t;
			lst[cnt++] = down_t[i];
			now.pt.clear();
			now.pt.push_back(down.pt[0]);
			now.pt.push_back(down.pt[i]);
			now.pt.push_back(up.pt[i]);
			now.pt.push_back(up.pt[0]);
			now.pt.clear();
			now.pt.push_back(down.pt[i]);
			now.pt.push_back(down.pt[i + 1]);
			now.pt.push_back(up.pt[i + 1]);
			now.pt.push_back(up.pt[i]);
			now.pt.push_back(down.pt[0]);
			now.pt.push_back(down.pt[i + 1]);
			now.pt.push_back(up.pt[i + 1]);
			now.pt.push_back(up.pt[0]);
			for (j = 0; j < m; j++)
			{
				lt[j][i] = down_t[i];
			}
		}
		for (i = 0; i < n; i++)
		{
			now_t.pt.clear();
			now_t.pt.push_back(up.pt[i]);
			now_t.pt.push_back(up.pt[(i + 1) % n]);
			now_t.pt.push_back(down.pt[(i + 1) % n]);
			now_t.pt.push_back(down.pt[i]);
			now_t.flag = 1;
			now_t.ip = 0;
			lst[cnt++] = now_t;
		}
		for (i = 0; i <= m; i++)
		{
			if (i > 0)
			{
				scanf("%lf%lf%lf%lf", &half[i - 1].a, &half[i - 1].b, &half[i - 1].c, &half[i - 1].d);
				for (j = 0; j < i - 1; j++)
				{
					insert(j, i - 1);
				}
				for (j = i - 1; j >= 0; j--)
				{
					insert(i - 1, j);
				}
				for (j = 0; j < cnt; j++)
				{
					if (lst[j].pt.size() == 0)
					{
						continue;
					}
					ins(lst[j], i - 1);
				}
			}
			surf[i] = solve_surf(i);
			for (j = 0; j < n - 2; j++)
			{
				sort(z[j], z[j] + num_z[j]);
			}
			volume[i] = solve_volume(i - 1);
		}
		for (i = 0; i <= m; i++)
		{
			printf("%f %f\n", volume[i], surf[i]);
		}
	}
	return 0;
}
