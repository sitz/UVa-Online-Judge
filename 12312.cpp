#include <bits/stdc++.h>

using namespace std;

struct node
{
	double lx, ly, lz, rx, ry, rz, mx, my, mz;
	int flag, mid;
	vector<int> iden, idt;
};
node tree[300000];

struct point
{
	double x, y, z;
};
point pt[44444];

double x[44444], y[44444], z[44444], ansx, ansy, ansz, eps = 1e-9, ans_ru;
int tri[3][88888], nx, ny, nz, n, num_tri, num_q, inf = 1000000000, ans_id, vis[44444], ct;
vector<int> adj[44444];

double inter(double fx, double fy, double fz, double tx, double ty, double tz, int id)
{
	double A, B, A1, A2, C1, D1, C2, D2, ru, ix, iy, iz, x1, y1, z1, x2, y2, z2, ru1, ru2;
	x1 = pt[tri[1][id]].x - pt[tri[0][id]].x;
	y1 = pt[tri[1][id]].y - pt[tri[0][id]].y;
	z1 = pt[tri[1][id]].z - pt[tri[0][id]].z;
	x2 = pt[tri[2][id]].x - pt[tri[0][id]].x;
	y2 = pt[tri[2][id]].y - pt[tri[0][id]].y;
	z2 = pt[tri[2][id]].z - pt[tri[0][id]].z;
	A1 = x1 * y2 - x2 * y1;
	C1 = y2 * (tx - fx) - x2 * (ty - fy);
	D1 = (fx - pt[tri[0][id]].x) * y2 - (fy - pt[tri[0][id]].y) * x2;
	A2 = y1 * z2 - y2 * z1;
	C2 = z2 * (ty - fy) - y2 * (tz - fz);
	D2 = (fy - pt[tri[0][id]].y) * z2 - (fz - pt[tri[0][id]].z) * y2;
	A = A1 * C2 - A2 * C1;
	B = -(A1 * D2 - A2 * D1);
	bool ff = true;
	if (fabs(A) < eps)
	{
		ff = false;
		A1 = x1 * y2 - x2 * y1;
		C1 = y2 * (tx - fx) - x2 * (ty - fy);
		D1 = (fx - pt[tri[0][id]].x) * y2 - (fy - pt[tri[0][id]].y) * x2;
		A2 = x1 * z2 - x2 * z1;
		C2 = z2 * (tx - fx) - x2 * (tz - fz);
		D2 = (fx - pt[tri[0][id]].x) * z2 - (fz - pt[tri[0][id]].z) * x2;
		A = A1 * C2 - A2 * C1;
		B = -(A1 * D2 - A2 * D1);
	}
	ru = B / A;
	if (fabs(A1) > eps)
	{
		ru1 = (C1 * ru + D1) / A1;
	}
	else
	{
		ru1 = (C2 * ru + D2) / A2;
	}
	if (fabs(x2) > eps)
	{
		ru2 = (fx + ru * (tx - fx) - pt[tri[0][id]].x - ru1 * x1) / x2;
	}
	else if (ff)
	{
		ru2 = (fy + ru * (ty - fy) - pt[tri[0][id]].y - ru1 * y1) / y2;
	}
	else
	{
		ru2 = (fz + ru * (tz - fz) - pt[tri[0][id]].z - ru1 * z1) / z2;
	}
	if (ru > 0 && ru1 > 0 && ru2 > 0 && (ru1 + ru2) < 1)
	{
		ix = fx + ru * (tx - fx);
		iy = fy + ru * (ty - fy);
		iz = fz + ru * (tz - fz);
		return ru;
	}
	return inf;
}
int inner(double xx, double yy, double zz, double lx, double ly, double lz, double rx, double ry, double rz)
{
	int res = 0;
	if (xx >= lx)
	{
		res |= 1;
	}
	if (xx <= rx)
	{
		res |= 2;
	}
	if (yy >= ly)
	{
		res |= 4;
	}
	if (yy <= ry)
	{
		res |= 8;
	}
	if (zz >= lz)
	{
		res |= 16;
	}
	if (zz <= rz)
	{
		res |= 32;
	}
	return res;
}
void build(double lx, double ly, double lz, double rx, double ry, double rz, int id)
{
	int nx, ny, nz, siz, flag = -1, ip, cx, cy, cz, l = 2 * id + 1, r = 2 * id + 2, i, siz_t;
	double in = -inf, mx, my, mz;
	tree[id].lx = lx;
	tree[id].ly = ly;
	tree[id].lz = lz;
	tree[id].rx = rx;
	tree[id].ry = ry;
	tree[id].rz = rz;
	siz = tree[id].iden.size();
	for (i = 0; i < siz; i++)
	{
		x[i] = pt[tree[id].iden[i]].x;
		y[i] = pt[tree[id].iden[i]].y;
		z[i] = pt[tree[id].iden[i]].z;
	}
	sort(x, x + siz);
	sort(y, y + siz);
	sort(z, z + siz);
	nx = 0;
	for (i = 0; i < siz; i++)
	{
		if (nx == 0 || x[nx - 1] < x[i])
		{
			x[nx++] = x[i];
		}
	}
	ny = 0;
	for (i = 0; i < siz; i++)
	{
		if (ny == 0 || y[ny - 1] < y[i])
		{
			y[ny++] = y[i];
		}
	}
	nz = 0;
	for (i = 0; i < siz; i++)
	{
		if (nz == 0 || z[nz - 1] < z[i])
		{
			z[nz++] = z[i];
		}
	}
	if (in < rx - lx && nx > 1)
	{
		in = rx - lx;
		tree[id].mx = mx = 0.5 * (x[(nx - 1) / 2] + x[(nx + 1) / 2]);
		flag = 0;
	}
	if (in < ry - ly && ny > 1)
	{
		in = ry - ly;
		tree[id].my = my = 0.5 * (y[(ny - 1) / 2] + y[(ny + 1) / 2]);
		flag = 1;
	}
	if (in < rz - lz && nz > 1)
	{
		in = rz - lz;
		tree[id].mz = mz = 0.5 * (z[(nz - 1) / 2] + z[(nz + 1) / 2]);
		flag = 2;
	}
	tree[id].flag = flag;
	if (tree[id].iden.size() <= 1)
	{
		return;
	}
	tree[l].iden.clear();
	tree[r].iden.clear();
	tree[l].idt.clear();
	tree[r].idt.clear();
	siz = tree[id].iden.size();
	siz_t = tree[id].idt.size();
	if (flag == 0)
	{
		for (i = 0; i < siz; i++)
		{
			ip = tree[id].iden[i];
			if (pt[ip].x <= mx)//if(pt[ip].x<=x[mx])
			{
				tree[l].iden.push_back(ip);
			}
			else
			{
				tree[r].iden.push_back(ip);
			}
		}
		for (i = 0; i < siz_t; i++)
		{
			ip = tree[id].idt[i];
			int id1, id2, id3;
			id1 = tri[0][ip];
			id2 = tri[1][ip];
			id3 = tri[2][ip];
			int add = 0;
			add |= inner(pt[id1].x, pt[id1].y, pt[id1].z, lx, ly, lz, mx, ry, rz);
			add |= inner(pt[id2].x, pt[id2].y, pt[id2].z, lx, ly, lz, mx, ry, rz);
			add |= inner(pt[id3].x, pt[id3].y, pt[id3].z, lx, ly, lz, mx, ry, rz);
			if (add == 63)
			{
				tree[l].idt.push_back(ip);
			}
			add = 0;
			add |= inner(pt[id1].x, pt[id1].y, pt[id1].z, mx, ly, lz, rx, ry, rz);
			add |= inner(pt[id2].x, pt[id2].y, pt[id2].z, mx, ly, lz, rx, ry, rz);
			add |= inner(pt[id3].x, pt[id3].y, pt[id3].z, mx, ly, lz, rx, ry, rz);
			if (add == 63)
			{
				tree[r].idt.push_back(ip);
			}
		}
		build(lx, ly, lz, mx, ry, rz, l);
		build(mx, ly, lz, rx, ry, rz, r);
	}
	else if (flag == 1)
	{
		for (i = 0; i < siz; i++)
		{
			ip = tree[id].iden[i];
			if (pt[ip].y <= my)
			{
				tree[l].iden.push_back(ip);
			}
			else
			{
				tree[r].iden.push_back(ip);
			}
		}
		for (i = 0; i < siz_t; i++)
		{
			ip = tree[id].idt[i];
			int id1, id2, id3;
			id1 = tri[0][ip];
			id2 = tri[1][ip];
			id3 = tri[2][ip];
			int add = 0;
			add |= inner(pt[id1].x, pt[id1].y, pt[id1].z, lx, ly, lz, rx, my, rz);
			add |= inner(pt[id2].x, pt[id2].y, pt[id2].z, lx, ly, lz, rx, my, rz);
			add |= inner(pt[id3].x, pt[id3].y, pt[id3].z, lx, ly, lz, rx, my, rz);
			if (add == 63)
			{
				tree[l].idt.push_back(ip);
			}
			add = 0;
			add |= inner(pt[id1].x, pt[id1].y, pt[id1].z, lx, my, lz, rx, ry, rz);
			add |= inner(pt[id2].x, pt[id2].y, pt[id2].z, lx, my, lz, rx, ry, rz);
			add |= inner(pt[id3].x, pt[id3].y, pt[id3].z, lx, my, lz, rx, ry, rz);
			if (add == 63)
			{
				tree[r].idt.push_back(ip);
			}
		}
		build(lx, ly, lz, rx, my, rz, l);
		build(lx, my, lz, rx, ry, rz, r);
	}
	else
	{
		for (i = 0; i < siz; i++)
		{
			ip = tree[id].iden[i];
			if (pt[ip].z <= mz)
			{
				tree[l].iden.push_back(ip);
			}
			else
			{
				tree[r].iden.push_back(ip);
			}
		}
		for (i = 0; i < siz_t; i++)
		{
			ip = tree[id].idt[i];
			int id1, id2, id3;
			id1 = tri[0][ip];
			id2 = tri[1][ip];
			id3 = tri[2][ip];
			int add = 0;
			add |= inner(pt[id1].x, pt[id1].y, pt[id1].z, lx, ly, lz, rx, ry, mz);
			add |= inner(pt[id2].x, pt[id2].y, pt[id2].z, lx, ly, lz, rx, ry, mz);
			add |= inner(pt[id3].x, pt[id3].y, pt[id3].z, lx, ly, lz, rx, ry, mz);
			if (add == 63)
			{
				tree[l].idt.push_back(ip);
			}
			add = 0;
			add |= inner(pt[id1].x, pt[id1].y, pt[id1].z, lx, ly, mz, rx, ry, rz);
			add |= inner(pt[id2].x, pt[id2].y, pt[id2].z, lx, ly, mz, rx, ry, rz);
			add |= inner(pt[id3].x, pt[id3].y, pt[id3].z, lx, ly, mz, rx, ry, rz);
			if (add == 63)
			{
				tree[r].idt.push_back(ip);
			}
		}
		build(lx, ly, lz, rx, ry, mz, l);
		build(lx, ly, mz, rx, ry, rz, r);
	}
}
bool query(double fx, double fy, double fz, double tx, double ty, double tz, int id)
{
	int ip, flag = -1, i, j, s, p, q;
	int l = 2 * id + 1, r = 2 * id + 2;
	double in = inf, ru, ix, iy, iz, lx, ly, lz, rx, ry, rz, mx, my, mz;
	lx = tree[id].lx;
	ly = tree[id].ly;
	lz = tree[id].lz;
	rx = tree[id].rx;
	ry = tree[id].ry;
	rz = tree[id].rz;
	mx = tree[id].mx;
	my = tree[id].my;
	mz = tree[id].mz;
	if (fx != tx)
	{
		ru = (double)(lx - fx) / (double)(tx - fx);
		if (ru > 0 && in > ru)
		{
			ix = fx + ru * (tx - fx);
			iy = fy + ru * (ty - fy);
			iz = fz + ru * (tz - fz);
			if (ix <= rx + eps && ix >= lx - eps && iy <= ry + eps && iy >= ly - eps && iz <= rz + eps && iz >= lz - eps)
			{
				in = ru;
				flag = 0;
			}
		}
		ru = (double)(rx - fx) / (double)(tx - fx);
		if (ru > 0 && in > ru)
		{
			ix = fx + ru * (tx - fx);
			iy = fy + ru * (ty - fy);
			iz = fz + ru * (tz - fz);
			if (ix <= rx + eps && ix >= lx - eps && iy <= ry + eps && iy >= ly - eps && iz <= rz + eps && iz >= lz - eps)
			{
				in = ru;
				flag = 0;
			}
		}
	}
	if (fy != ty)
	{
		ru = (double)(ly - fy) / (double)(ty - fy);
		if (ru > 0 && in > ru)
		{
			ix = fx + ru * (tx - fx);
			iy = fy + ru * (ty - fy);
			iz = fz + ru * (tz - fz);
			if (ix <= rx + eps && ix >= lx - eps && iy <= ry + eps && iy >= ly - eps && iz <= rz + eps && iz >= lz - eps)
			{
				in = ru;
				flag = 0;
			}
		}
		ru = (double)(ry - fy) / (double)(ty - fy);
		if (ru > 0 && in > ru)
		{
			ix = fx + ru * (tx - fx);
			iy = fy + ru * (ty - fy);
			iz = fz + ru * (tz - fz);
			if (ix <= rx + eps && ix >= lx - eps && iy <= ry + eps && iy >= ly - eps && iz <= rz + eps && iz >= lz - eps)
			{
				in = ru;
				flag = 0;
			}
		}
	}
	if (fz != tz)
	{
		ru = (double)(lz - fz) / (double)(tz - fz);
		if (ru > 0 && in > ru)
		{
			ix = fx + ru * (tx - fx);
			iy = fy + ru * (ty - fy);
			iz = fz + ru * (tz - fz);
			if (ix <= rx + eps && ix >= lx - eps && iy <= ry + eps && iy >= ly - eps && iz <= rz + eps && iz >= lz - eps)
			{
				in = ru;
				flag = 0;
			}
		}
		ru = (double)(rz - fz) / (double)(tz - fz);
		if (ru > 0 && in > ru)
		{
			ix = fx + ru * (tx - fx);
			iy = fy + ru * (ty - fy);
			iz = fz + ru * (tz - fz);
			if (ix <= rx + eps && ix >= lx - eps && iy <= ry + eps && iy >= ly - eps && iz <= rz + eps && iz >= lz - eps)
			{
				in = ru;
				flag = 0;
			}
		}
	}
	if (!(fx <= rx + eps && fx >= lx - eps && fy >= ly - eps && fy <= ry + eps && fz >= lz - eps && fz <= rz + eps) && ans_ru < inf && (ans_ru <= in + eps))
	{
		return true;
	}
	if (flag == -1)
	{
		return false;
	}
	ix = fx + in * (tx - fx);
	iy = fy + in * (ty - fy);
	iz = fz + in * (tz - fz);
	if (tree[id].idt.size() <= 1 || tree[id].iden.size() <= 1)
	{
		for (i = 0; i < tree[id].idt.size(); i++)
		{
			ip = tree[id].idt[i];
			ru = inter(fx, fy, fz, tx, ty, tz, ip);
			if (ans_ru > ru)
			{
				ans_ru = ru;
				ans_id = ip;
				ansx = fx + ru * (tx - fx);
				ansy = fy + ru * (ty - fy);
				ansz = fz + ru * (tz - fz);
			}
		}
		if (ans_ru < inf && ansx <= rx + eps && ansx >= lx - eps && ansy <= ry + eps && ansy >= ly - eps && ansz <= rz + eps && ansz >= lz - eps)
		{
			return true;
		}
		return false;
	}
	if (tree[id].flag == 0)
	{
		if (ix <= mx + eps && !(fx <= rx + eps && fx >= mx - eps && fy <= ry + eps && fy >= ly - eps && fz <= rz + eps && fz >= lz - eps))
		{
			if (query(fx, fy, fz, tx, ty, tz, l))
			{
				return true;
			}
			return query(fx, fy, fz, tx, ty, tz, r);
		}
		if (query(fx, fy, fz, tx, ty, tz, r))
		{
			return true;
		}
		return query(fx, fy, fz, tx, ty, tz, l);
	}
	else if (tree[id].flag == 1)
	{
		if (iy <= my + eps && !(fx <= rx + eps && fx >= lx - eps && fy <= ry + eps && fy >= my - eps && fz <= rz + eps && fz >= lz - eps))
		{
			if (query(fx, fy, fz, tx, ty, tz, l))
			{
				return true;
			}
			return query(fx, fy, fz, tx, ty, tz, r);
		}
		if (query(fx, fy, fz, tx, ty, tz, r))
		{
			return true;
		}
		return query(fx, fy, fz, tx, ty, tz, l);
	}
	else
	{
		if (iz <= mz + eps && !(fx <= rx + eps && fx >= lx - eps && fy <= ry + eps && fy >= ly - eps && fz <= rz + eps && fz >= mz - eps))//||(fx<=rx&&fx>=lx&&fy<=ry&&fy>=ly&&fz<=mz&&fz>=lz))
		{
			if (query(fx, fy, fz, tx, ty, tz, l))
			{
				return true;
			}
			return query(fx, fy, fz, tx, ty, tz, r);
		}
		if (query(fx, fy, fz, tx, ty, tz, r))
		{
			return true;
		}
		return query(fx, fy, fz, tx, ty, tz, l);
	}
}

int main()
{
	int i, j, s, p, q;
	double fx, fy, fz, tx, ty, tz, lx, ly, lz, rx, ry, rz;
	while (scanf("%d", &n) && n)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf", &pt[i].x, &pt[i].y, &pt[i].z);
		}
		lx = ly = lz = inf;
		rx = ry = rz = -inf;
		for (i = 0; i < n; i++)
		{
			x[i] = pt[i].x;
			y[i] = pt[i].y;
			z[i] = pt[i].z;
			if (lx > x[i])
			{
				lx = x[i];
			}
			if (ly > y[i])
			{
				ly = y[i];
			}
			if (lz > z[i])
			{
				lz = z[i];
			}
			if (rx < x[i])
			{
				rx = x[i];
			}
			if (ry < y[i])
			{
				ry = y[i];
			}
			if (rz < z[i])
			{
				rz = z[i];
			}
			adj[i].clear();
		}
		scanf("%d", &num_tri);
		for (i = 0; i < num_tri; i++)
		{
			scanf("%d%d%d", &tri[0][i], &tri[1][i], &tri[2][i]);
			adj[tri[0][i]].push_back(i);
			adj[tri[1][i]].push_back(i);
			adj[tri[2][i]].push_back(i);
		}
		tree[0].iden.clear();
		tree[0].idt.clear();
		for (i = 0; i < n; i++)
		{
			tree[0].iden.push_back(i);
		}
		for (i = 0; i < num_tri; i++)
		{
			tree[0].idt.push_back(i);
		}
		build(lx, ly, lz, rx, ry, rz, 0);
		scanf("%d", &num_q);
		for (i = 0; i < num_q; i++)
		{
			scanf("%lf%lf%lf%lf%lf%lf", &fx, &fy, &fz, &tx, &ty, &tz);
			ans_ru = inf;
			if (query(fx, fy, fz, tx, ty, tz, 0))
			{
				printf("%d %.6f %.6f %.6f\n", ans_id, ansx, ansy, ansz);
			}
			else
			{
				printf("-1\n");
			}
		}
	}
	return 0;
}
