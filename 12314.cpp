#include <bits/stdc++.h>

using namespace std;

bool no, there, vis[111][111], mat[111][111];
double r, inf = 1e9, eps2 = 1e-6, eps = 1e-6, oox = -13573.123479, ooy = -31736.3543217, pr, now, ans, lx, ly, rx, ry;
int n, cnt_po, ps[2][1111], nt, cnt_x[111], tn, pos[111], cnt_cir, num[1111], nxt[1111], tnum[1111], pnum[1111];

struct point
{
	double x, y, px, py, qx, qy, theta;
	int kind, id1, id2, id, at;
	bool operator<(const point &temp) const
	{
		if (fabs(x - temp.x) < eps)
		{
			return y < temp.y - eps;
		}
		return x < temp.x;
	}
	bool operator==(const point &temp) const
	{
		return fabs(x - temp.x) < eps && fabs(y - temp.y) < eps;
	}
};

bool cmp(point a, point b)
{
	return a.theta < b.theta - eps;
}

point pt[111], cir[10000], adj[1111][1111], tadj[1111][1111], padj[1111][1111], poly[1111], lst[111], xl[111][111];

bool inter(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	int i, j, s, p, q;
	double ru1, ru2, A, B;
	A = (x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1);
	B = (x3 - x1) * (y4 - y3) - (x4 - x3) * (y3 - y1);
	if (fabs(A) < eps)
	{
		pr = inf;
		return false;
	}
	ru1 = B / A;
	A = -A;
	B = (x1 - x3) * (y2 - y1) - (y1 - y3) * (x2 - x1);
	ru2 = B / A;
	pr = ru1;
	return ru1 < 1 + eps && ru1 > -eps && ru2 < 1 + eps && ru2 > -eps;
}

bool inner(double cx, double cy)
{
	int res = 0, i, j, s, p, q;
	double x1, y1, x2, y2;
	for (i = 0; i < n; i++)
	{
		x1 = pt[i].x;
		y1 = pt[i].y;
		x2 = pt[(i + 1) % n].x;
		y2 = pt[(i + 1) % n].y;
		res ^= inter(x1, y1, x2, y2, oox, ooy, cx, cy);
	}
	return res;
}

bool check(double cx, double cy)
{
	int i, j, s, p, q;
	double nowx, nowy, dist, x1, y1, x2, y2, ru, A, B, C, delta, theta, th, xp, yp;
	for (i = 0; i < n; i++)
	{
		x1 = pt[i].x;
		y1 = pt[i].y;
		x2 = pt[(i + 1) % n].x;
		y2 = pt[(i + 1) % n].y;
		dist = sqrt((pt[i].x - cx) * (pt[i].x - cx) + (pt[i].y - cy) * (pt[i].y - cy));
		if (dist < r - 1e-5)
		{
			return false;
		}
		nowx = 0.5 * (pt[i].x + pt[(i + 1) % n].x);
		nowy = 0.5 * (pt[i].y + pt[(i + 1) % n].y);
		dist = sqrt((nowx - cx) * (nowx - cx) + (nowy - cy) * (nowy - cy));
		if (dist < r - eps2)
		{
			return false;
		}
		theta = atan2(y2 - y1, x2 - x1);
		if ((cy - y1) * (x2 - x1) - (cx - x1) * (y2 - y1) < 0)
		{
			theta += M_PI / 2;
		}
		else
		{
			theta -= M_PI / 2;
		}
		double ds = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		ds = fabs(cx * (y2 - y1) - cy * (x2 - x1) + x2 * y1 - x1 * y2) / ds;
		if (ds - r > -eps2)
		{
			continue;
		}
		th = theta + acos(ds / r);
		xp = cx + r * cos(th);
		yp = cy + r * sin(th);
		if (fabs(x1 - x2) < eps)
		{
			ru = (yp - y1) / (y2 - y1);
		}
		else
		{
			ru = (xp - x1) / (x2 - x1);
		}
		if (ru < 1 - eps2 && ru > eps2)
		{
			return false;
		}
		th = theta - acos(ds / r);
		xp = cx + r * cos(th);
		yp = cy + r * sin(th);
		if (fabs(x1 - x2) < eps)
		{
			ru = (yp - y1) / (y2 - y1);
		}
		else
		{
			ru = (xp - x1) / (x2 - x1);
		}
		if (ru < 1 - eps2 && ru > eps2)
		{
			return false;
		}
	}
	return !inner(cx, cy);
}

bool get_P_to_P(int id1, int id2)
{
	int i, j, s, p, q;
	bool res = false;
	double cx, cy, th, theta, alpha, dist = sqrt((pt[id1].x - pt[id2].x) * (pt[id1].x - pt[id2].x) + (pt[id1].y - pt[id2].y) * (pt[id1].y - pt[id2].y));
	dist /= 2.0;
	if (r < dist - eps)
	{
		return false;
	}
	if (r < dist)
	{
		dist = r;
	}
	theta = acos(dist / r);
	alpha = atan2(pt[id2].y - pt[id1].y, pt[id2].x - pt[id1].x);
	th = alpha + theta;
	cir[cnt_cir].id1 = id1;
	cir[cnt_cir].id2 = id2;
	cir[cnt_cir].kind = 0;
	cir[cnt_cir].x = cx = pt[id1].x + r * cos(th);
	cir[cnt_cir].y = cy = pt[id1].y + r * sin(th);
	cir[cnt_cir].px = pt[id1].x;
	cir[cnt_cir].py = pt[id1].y;
	cir[cnt_cir].qx = pt[id2].x;
	cir[cnt_cir].qy = pt[id2].y;
	if (check(cx, cy))
	{
		cnt_cir++;
		i = id1;
		j = id2;
		padj[i][pnum[i]] = cir[cnt_cir - 1];
		padj[i][pnum[i]].theta = atan2(cir[cnt_cir - 1].y - pt[i].y, cir[cnt_cir - 1].x - pt[i].x);
		padj[i][pnum[i]++].id = cnt_cir - 1;
		padj[j][pnum[j]] = cir[cnt_cir - 1];
		padj[j][pnum[j]].theta = atan2(cir[cnt_cir - 1].y - pt[j].y, cir[cnt_cir - 1].x - pt[j].x);
		padj[j][pnum[j]++].id = cnt_cir - 1;
	}
	th = alpha - theta;
	if (fabs(theta) < eps)
	{
		return false;
	}
	cir[cnt_cir].x = cx = pt[id1].x + r * cos(th);
	cir[cnt_cir].y = cy = pt[id1].y + r * sin(th);
	cir[cnt_cir].px = pt[id1].x;
	cir[cnt_cir].py = pt[id1].y;
	cir[cnt_cir].qx = pt[id2].x;
	cir[cnt_cir].qy = pt[id2].y;
	if (check(cx, cy))
	{
		cir[cnt_cir].id1 = id1;
		cir[cnt_cir].id2 = id2;
		cir[cnt_cir].kind = 0;
		cnt_cir++;
		i = id1;
		j = id2;
		padj[i][pnum[i]] = cir[cnt_cir - 1];
		padj[i][pnum[i]].theta = atan2(cir[cnt_cir - 1].y - pt[i].y, cir[cnt_cir - 1].x - pt[i].x);
		padj[i][pnum[i]++].id = cnt_cir - 1;
		padj[j][pnum[j]] = cir[cnt_cir - 1];
		padj[j][pnum[j]].theta = atan2(cir[cnt_cir - 1].y - pt[j].y, cir[cnt_cir - 1].x - pt[j].x);
		padj[j][pnum[j]++].id = cnt_cir - 1;
	}
}

bool get_P_to_L(int id1, int id2)
{
	int i, j, s, p, q;
	double ds, nx, ny, th, xx, yy, cc, theta, alpha, dist, A, B, C, x1, y1, x2, y2, dd;
	x1 = pt[id1].x;
	y1 = pt[id1].y;
	x2 = pt[(id1 + 1) % n].x;
	y2 = pt[(id1 + 1) % n].y;
	A = y2 - y1;
	B = x1 - x2;
	C = y1 * x2 - x1 * y2;
	dd = sqrt(A * A + B * B);
	double tc = C;
	for (q = 0; q < 2; q++)
	{
		if (q == 1 && A * pt[id2].x + B * pt[id2].y + tc > eps)
		{
			continue;
		}
		if (q == 0 && A * pt[id2].x + B * pt[id2].y + tc < -eps)
		{
			continue;
		}
		if (q == 0)
		{
			C = tc - r * dd;
		}
		else
		{
			C = tc + r * dd;
		}
		dist = fabs(A * pt[id2].x + B * pt[id2].y + C) / dd;
		if (dist > r + eps)
		{
			return false;
		}
		if (dist > r)
		{
			dist = r;
		}
		cc = A * pt[id2].y - B * pt[id2].x;
		xx = (-C * A - cc * B) / (A * A + B * B);
		yy = (cc * A - C * B) / (A * A + B * B);
		theta = acos(dist / r);
		alpha = atan2(yy - pt[id2].y, xx - pt[id2].x);
		xx = pt[id2].x + r * cos(theta + alpha);
		yy = pt[id2].y + r * sin(theta + alpha);
		cir[cnt_cir].id1 = id1;
		cir[cnt_cir].id2 = id2;
		cir[cnt_cir].kind = 1;
		cir[cnt_cir].x = xx;
		cir[cnt_cir].y = yy;
		dist = sqrt((xx - pt[id1].x) * (xx - pt[id1].x) + (yy - pt[id1].y) * (yy - pt[id1].y) - r * r);
		th = atan2(pt[(id1 + 1) % n].y - pt[id1].y, pt[(id1 + 1) % n].x - pt[id1].x);
		cir[cnt_cir].px = nx = xx + r * cos(th + M_PI / 2);
		cir[cnt_cir].py = ny = yy + r * sin(th + M_PI / 2);
		ds = fabs(A * nx + B * ny - x1 * y2 + x2 * y1);
		if (ds > eps)
		{
			cir[cnt_cir].px = nx = xx + r * cos(th - M_PI / 2);
			cir[cnt_cir].py = ny = yy + r * sin(th - M_PI / 2);
		}
		cir[cnt_cir].qx = pt[id2].x;
		cir[cnt_cir].qy = pt[id2].y;
		if (nx < max(x1, x2) + eps && nx > min(x1, x2) - eps && ny < max(y1, y2) + eps && ny > min(y1, y2) - eps && check(xx, yy))
		{
			cnt_cir++;
			i = id1;
			j = id2;
			adj[i][num[i]] = cir[cnt_cir - 1];
			adj[i][num[i]++].id = cnt_cir - 1;
			padj[j][pnum[j]] = cir[cnt_cir - 1];
			padj[j][pnum[j]].theta = atan2(cir[cnt_cir - 1].y - pt[j].y, cir[cnt_cir - 1].x - pt[j].x);
			padj[j][pnum[j]++].id = cnt_cir - 1;
		}
		if (fabs(theta) < eps)
		{
			continue;
		}
		xx = pt[id2].x + r * cos(alpha - theta);
		yy = pt[id2].y + r * sin(alpha - theta);
		cir[cnt_cir].id1 = id1;
		cir[cnt_cir].id2 = id2;
		cir[cnt_cir].kind = 1;
		cir[cnt_cir].x = xx;
		cir[cnt_cir].y = yy;
		dist = sqrt((xx - pt[id1].x) * (xx - pt[id1].x) + (yy - pt[id1].y) * (yy - pt[id1].y) - r * r);
		th = atan2(pt[(id1 + 1) % n].y - pt[id1].y, pt[(id1 + 1) % n].x - pt[id1].x);
		cir[cnt_cir].px = nx = xx + r * cos(th + M_PI / 2);
		cir[cnt_cir].py = ny = yy + r * sin(th + M_PI / 2);
		ds = fabs(A * nx + B * ny - x1 * y2 + x2 * y1);
		if (ds > eps)
		{
			cir[cnt_cir].px = nx = xx + r * cos(th - M_PI / 2);
			cir[cnt_cir].py = ny = yy + r * sin(th - M_PI / 2);
		}
		cir[cnt_cir].qx = pt[id2].x;
		cir[cnt_cir].qy = pt[id2].y;
		if (nx < max(x1, x2) + eps && nx > min(x1, x2) - eps && ny < max(y1, y2) + eps && ny > min(y1, y2) - eps && check(xx, yy))
		{
			cnt_cir++;
			i = id1;
			j = id2;
			adj[i][num[i]] = cir[cnt_cir - 1];
			adj[i][num[i]++].id = cnt_cir - 1;
			padj[j][pnum[j]] = cir[cnt_cir - 1];
			padj[j][pnum[j]].theta = atan2(cir[cnt_cir - 1].y - pt[j].y, cir[cnt_cir - 1].x - pt[j].x);
			padj[j][pnum[j]++].id = cnt_cir - 1;
		}
	}
}

bool get_L_to_L(int id1, int id2)
{
	int i, j, s, p, q;
	point pp, qq, gg, ff, tk;
	double xx, yy, fx, fy, gx, gy, px, py, qx, qy, dist, dr, alpha, cx, cy, tx, ty, theta, x1, y1, x2, y2, x3, y3, x4, y4;
	inter(pt[id1].x, pt[id1].y, pt[(id1 + 1) % n].x, pt[(id1 + 1) % n].y, pt[id2].x, pt[id2].y, pt[(id2 + 1) % n].x, pt[(id2 + 1) % n].y);
	if (fabs(pr - inf) < eps)
	{
		return false;
	}
	tx = pt[id1].x + pr * (pt[(id1 + 1) % n].x - pt[id1].x);
	ty = pt[id1].y + pr * (pt[(id1 + 1) % n].y - pt[id1].y);
	x1 = pt[id1].x;
	y1 = pt[id1].y;
	x2 = pt[(id1 + 1) % n].x;
	y2 = pt[(id1 + 1) % n].y;
	x3 = pt[id2].x;
	y3 = pt[id2].y;
	x4 = pt[(id2 + 1) % n].x;
	y4 = pt[(id2 + 1) % n].y;
	tk.x = tx;
	tk.y = ty;
	for (q = 0; q < 2; q++)
	{
		if (fabs(y2 - ty) < eps && fabs(x2 - tx) < eps)
		{
			ff.x = fx = x1;
			ff.y = fy = y1;
			gg.x = gx = x2;
			gg.y = gy = y2;
		}
		else
		{
			ff.x = fx = x2;
			ff.y = fy = y2;
			gg.x = gx = x1;
			gg.y = gy = y1;
		}
		if (fabs(y4 - ty) < eps && fabs(x4 - tx) < eps)
		{
			pp.x = px = x3;
			pp.y = py = y3;
			qq.x = qx = x4;
			qq.y = qy = y4;
		}
		else
		{
			pp.x = px = x4;
			pp.y = py = y4;
			qq.x = qx = x3;
			qq.y = qy = y3;
		}
		if (q == 1)
		{
			if ((pp < tk && tk < qq) || (qq < tk && tk < pp))
			{
				swap(pp, qq);
				swap(px, qx);
				swap(py, qy);
			}
			else if ((ff < tk && tk < gg) || (gg < tk && tk < ff))
			{
				swap(ff, gg);
				swap(fx, gx);
				swap(fy, gy);
			}
			else
			{
				break;
			}
		}
		double f1, f2;
		f1 = atan2(fy - ty, fx - tx);
		f2 = atan2(py - ty, px - tx);
		while (f1 - f2 > M_PI)
		{
			f1 -= 2 * M_PI;
		}
		while (f1 - f2 < -M_PI)
		{
			f1 += 2 * M_PI;
		}
		theta = 0.5 * (f1 + f2);
		alpha = 0.5 * fabs(f1 - f2);
		if (fabs(alpha) < eps)
		{
			return false;
		}
		dr = r / sin(alpha);
		cir[cnt_cir].id1 = id1;
		cir[cnt_cir].id2 = id2;
		cir[cnt_cir].kind = 2;
		cir[cnt_cir].x = cx = tx + dr * cos(theta);
		cir[cnt_cir].y = cy = ty + dr * sin(theta);
		dist = r * cos(alpha) / sin(alpha);
		cir[cnt_cir].px = xx = tx + dist * cos(atan2(fy - ty, fx - tx));
		cir[cnt_cir].py = yy = ty + dist * sin(atan2(fy - ty, fx - tx));
		if (xx < max(x1, x2) + eps && xx > min(x1, x2) - eps && yy < max(y1, y2) + eps && yy > min(y1, y2) - eps)
		{
			cir[cnt_cir].qx = xx = tx + dist * cos(atan2(py - ty, px - tx));
			cir[cnt_cir].qy = yy = ty + dist * sin(atan2(py - ty, px - tx));
			if (xx < max(x3, x4) + eps && xx > min(x3, x4) - eps && yy < max(y3, y4) + eps && yy > min(y3, y4) - eps)
			{
				if (check(cx, cy))
				{
					cnt_cir++;
					i = id1;
					j = id2;
					adj[i][num[i]] = cir[cnt_cir - 1];
					adj[i][num[i]++].id = cnt_cir - 1;
					adj[j][num[j]] = cir[cnt_cir - 1];
					adj[j][num[j]++].id = cnt_cir - 1;
				}
			}
		}
	}
}

double cmp1(double cx, double cy, point a, point b)
{
	int i, j, s, p, q;
	double theta;
	theta = atan2(a.y - cy, a.x - cx) - atan2(b.y - cy, b.x - cx);
	while (theta < -M_PI + eps)
	{
		theta += 2 * M_PI;
	}
	while (theta > M_PI - eps)
	{
		theta -= 2 * M_PI;
	}
	theta = fabs(theta);
	return 0.5 * (theta - sin(theta)) * r * r;
}

bool at(int kind, double cx, double cy, point a, point b)
{
	double jk;
	if (kind == 0)
	{
		return fabs(a.x - b.x) < eps && fabs(a.y - b.y) < eps;
	}
	jk = (cx - a.x) * (a.x - b.x) + (cy - a.y) * (a.y - b.y);
	if (fabs(jk) < eps)
	{
		for (int i = 0; i < n; i++)
		{
			double c1, c2, ru1, ru2, x1, y1, x2, y2;
			x1 = pt[i].x;
			y1 = pt[i].y;
			x2 = pt[(i + 1) % n].x;
			y2 = pt[(i + 1) % n].y;
			c1 = fabs((a.x - x1) * (y2 - y1) - (a.y - y1) * (x2 - x1));
			c2 = fabs((b.x - x1) * (y2 - y1) - (b.y - y1) * (x2 - x1));
			if (c1 < eps && c2 < eps)
			{
				if (x1 == x2)
				{
					ru1 = (a.y - y1) / (y2 - y1);
					ru2 = (b.y - y1) / (y2 - y1);
				}
				else
				{
					ru1 = (a.x - x1) / (x2 - x1);
					ru2 = (b.x - x1) / (x2 - x1);
				}
				if (ru1 < 1 + eps && ru1 > -eps && ru2 < 1 + eps && ru2 > -eps)
				{
					return true;
				}
			}
		}
	}
	return false;
}

void dfs(int id1, int id2, int pre1, int pre2)
{
	int i, j, s, p, q, id;
	double theta, parea = 0;
	if (lst[id1].x < lx - eps || lst[id1].x > rx + eps || lst[id1].y < ly - eps || lst[id1].y > ry + eps)
	{
		no = true;
	}
	if (vis[id1][id2])
	{
		if (!no)
		{
			for (i = 1; i < cnt_po - 1; i++)
			{
				double x1, y1, x2, y2;
				x1 = poly[i].x - poly[0].x;
				y1 = poly[i].y - poly[0].y;
				x2 = poly[i + 1].x - poly[0].x;
				y2 = poly[i + 1].y - poly[0].y;
				parea += 0.5 * (x1 * y2 - x2 * y1);
			}
			now += fabs(parea);
			if (ans < now)
			{
				ans = now;
			}
		}
		return;
	}
	vis[id1][id2] = true;
	poly[cnt_po++] = xl[id1][id2];
	for (i = 0; i < tnum[id1]; i++)
	{
		id = tadj[id1][i].id;
		for (j = 0; j < cnt_x[id]; j++)
		{
			if (at(tadj[id1][i].kind, lst[id1].x, lst[id1].y, xl[id1][id2], xl[id][j]) && !(id == pre1 && j == pre2))
			{
				break;
			}
		}
		if (j < cnt_x[id])
		{
			if (tadj[id1][i].kind == 0)
			{
				now += cmp1(lst[id1].x, lst[id1].y, xl[id1][id2], xl[id][j]);
			}
			dfs(id, j, id1, id2);
			break;
		}
	}
	if (i >= tnum[id1])
	{
		id = id1;
		j = (id2 + 1) % cnt_x[id1];
		theta = -(atan2(xl[id1][id2].y - lst[id1].y, xl[id1][id2].x - lst[id1].x) - atan2(xl[id1][j].y - lst[id1].y, xl[id1][j].x - lst[id1].x));
		if (j == 0)
		{
			theta += 2 * M_PI;
		}
		if (theta > M_PI - eps || (j == pre2 && id1 == pre1))
		{
			j = (id2 - 1 + cnt_x[id1]) % cnt_x[id1];
		}
		now += cmp1(lst[id1].x, lst[id1].y, xl[id1][id2], xl[id1][j]);
		dfs(id1, j, id1, id2);
	}
}

int main()
{
	double ru, cx, cy, theta;
	int i, j, s, p, q, id1, id2, id;
	while (scanf("%d%lf", &n, &r) == 2 && (n || r))
	{
		ly = lx = 1.0 / eps;
		ry = rx = -1.0 / eps;
		for (i = 0; i < n; i++)
		{
			scanf("%lf%lf", &pt[i].x, &pt[i].y);
			lx = min(lx, pt[i].x);
			ly = min(ly, pt[i].y);
			rx = max(rx, pt[i].x);
			ry = max(ry, pt[i].y);
		}
		memset(vis, false, sizeof(vis));
		cnt_cir = 0;
		memset(num, 0, sizeof(num));
		memset(tnum, 0, sizeof(tnum));
		memset(pnum, 0, sizeof(pnum));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (i < j)
				{
					cir[cnt_cir].id1 = i;
					cir[cnt_cir].id2 = j;
					cir[cnt_cir].kind = 0;
					get_P_to_P(i, j);
				}
				cir[cnt_cir].id1 = i;
				cir[cnt_cir].id2 = j;
				cir[cnt_cir].kind = 1;
				get_P_to_L(i, j);
				if (i < j)
				{
					cir[cnt_cir].id1 = i;
					cir[cnt_cir].id2 = j;
					cir[cnt_cir].kind = 2;
					get_L_to_L(i, j);
				}
			}
		}
		nt = 0;
		for (i = 0; i < cnt_cir; i++)
		{
			lst[nt++] = cir[i];
		}
		sort(lst, lst + nt);
		tn = 0;
		memset(cnt_x, 0, sizeof(cnt_x));
		for (i = 0; i < nt; i++)
		{
			if (tn == 0 || lst[tn - 1] < lst[i])
			{
				lst[tn++] = lst[i];
			}
			xl[tn - 1][cnt_x[tn - 1]].x = lst[i].px;
			xl[tn - 1][cnt_x[tn - 1]].theta = atan2(lst[i].py - lst[i].y, lst[i].px - lst[i].x);
			xl[tn - 1][cnt_x[tn - 1]++].y = lst[i].py;
			xl[tn - 1][cnt_x[tn - 1]].x = lst[i].qx;
			xl[tn - 1][cnt_x[tn - 1]].theta = atan2(lst[i].qy - lst[i].y, lst[i].qx - lst[i].x);
			xl[tn - 1][cnt_x[tn - 1]++].y = lst[i].qy;
		}
		nt = tn;
		for (i = 0; i < cnt_cir; i++)
		{
			for (j = 0; j < nt; j++)
			{
				if (cir[i] == lst[j])
				{
					pos[i] = j;
					break;
				}
			}
		}
		for (i = 0; i < nt; i++)
		{
			sort(xl[i], xl[i] + cnt_x[i], cmp);
			tn = 0;
			for (j = 0; j < cnt_x[i]; j++)
			{
				if (tn == 0 || !(xl[i][tn - 1] == xl[i][j]))
				{
					xl[i][tn++] = xl[i][j];
				}
			}
			if (tn != 1 && xl[i][tn - 1] == xl[i][0])
			{
				tn--;
			}
			cnt_x[i] = tn;
		}
		memset(mat, false, sizeof(mat));
		for (i = 0; i < n; i++)
		{
			sort(adj[i], adj[i] + num[i]);
			for (j = 0; j < num[i] - 1; j++)
			{
				id1 = adj[i][j].id;
				id2 = adj[i][j + 1].id;
				for (s = j + 1; s < num[i]; s++)
				{
					id2 = adj[i][s].id;
					if (!inter(cir[id1].x, cir[id1].y, cir[id2].x, cir[id2].y, pt[i].x, pt[i].y, pt[(i + 1) % n].x, pt[(i + 1) % n].y))
					{
						break;
					}
				}
				if (s >= num[i])
				{
					continue;
				}
				id2 = adj[i][s].id;
				cx = 0.5 * (cir[id1].x + cir[id2].x);
				cy = 0.5 * (cir[id1].y + cir[id2].y);
				if (pos[id1] != pos[id2] && !mat[pos[id1]][pos[id2]] && check(cx, cy))
				{
					id1 = pos[id1];
					id2 = pos[id2];
					mat[id1][id2] = true;
					tadj[id1][tnum[id1]].kind = 1;
					tadj[id1][tnum[id1]++].id = id2;
					tadj[id2][tnum[id2]].kind = 1;
					tadj[id2][tnum[id2]++].id = id1;
				}
			}
			sort(padj[i], padj[i] + pnum[i], cmp);
			for (j = 0; j < pnum[i]; j++)
			{
				double theta1 = padj[i][j].theta, theta2 = padj[i][(j + 1) % pnum[i]].theta;
				if (j == pnum[i] - 1)
				{
					theta1 -= 2 * M_PI;
				}
				id1 = padj[i][j].id;
				id2 = padj[i][(j + 1) % pnum[i]].id;
				theta = 0.5 * (theta1 + theta2);
				cx = pt[i].x + r * cos(theta);
				cy = pt[i].y + r * sin(theta);
				if (pos[id1] != pos[id2] && !mat[pos[id1]][pos[id2]] && check(cx, cy))
				{
					id1 = pos[id1];
					id2 = pos[id2];
					mat[id1][id2] = true;
					tadj[id1][tnum[id1]].kind = 0;
					tadj[id1][tnum[id1]++].id = id2;
					tadj[id2][tnum[id2]].kind = 0;
					tadj[id2][tnum[id2]++].id = id1;
				}
			}
		}
		memset(vis, false, sizeof(vis));
		ans = -1;
		for (i = 0; i < nt; i++)
		{
			for (j = 0; j < cnt_x[i]; j++)
			{
				if (vis[i][j])
				{
					continue;
				}
				cnt_po = no = 0;
				now = 0.0;
				dfs(i, j, -1, -1);
			}
		}
		if (ans < 0)
		{
			printf("Impossible\n");
		}
		else
		{
			printf("%.2f\n", ans);
		}
	}
	return 0;
}
