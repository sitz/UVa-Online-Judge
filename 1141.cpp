#include <bits/stdc++.h>

using namespace std;

double eps = 1e-9;
struct point
{
	int x, y;
};
point pt[333333];
struct node
{
	vector<point> pt;
	vector<int> x;
	vector<int> y;
};
node tree[1 << 21];
bool cmp1(point a, point b)
{
	return a.x < b.x;
}
bool cmp2(point a, point b)
{
	return a.y < b.y;
}
int l, h, r, n, ans;
void build(int id)
{
	int sz, l = 2 * id + 1, r = 2 * id + 2, lx, ly, rx, ry, szx, szy, flag, mx, my, mid;
	int i, j, s, p, q;
	if (tree[id].pt.size() <= 1)
	{
		return;
	}
	szx = tree[id].x.size();
	szy = tree[id].y.size();
	lx = tree[id].x[0];
	ly = tree[id].y[0];
	rx = tree[id].x[szx - 1];
	ry = tree[id].y[szy - 1];
	if ((rx - lx > ry - ly))
	{
		flag = 0;
	}
	else
	{
		flag = 1;
	}
	while (l > (1 << 21) || r > (1 << 21))
	{
		puts("no");
	}
	tree[l].pt.clear();
	tree[l].x.clear();
	tree[l].y.clear();
	tree[r].pt.clear();
	tree[r].x.clear();
	tree[r].y.clear();
	sz = tree[id].pt.size();
	if (flag == 0)
	{
		sort(tree[id].pt.begin(), tree[id].pt.end(), cmp1);
		mid = (sz - 1) / 2;
		mx = tree[id].pt[mid].x;
		for (i = 0; i < sz; i++)
		{
			if (i <= mid)//if(tree[id].pt[i].x<=mx)
			{
				tree[l].pt.push_back(tree[id].pt[i]);
				tree[l].x.push_back(tree[id].pt[i].x);
				tree[l].y.push_back(tree[id].pt[i].y);
			}
			else
			{
				tree[r].pt.push_back(tree[id].pt[i]);
				tree[r].x.push_back(tree[id].pt[i].x);
				tree[r].y.push_back(tree[id].pt[i].y);
			}
		}
	}
	else
	{
		sort(tree[id].pt.begin(), tree[id].pt.end(), cmp2);
		mid = (sz - 1) / 2;
		my = tree[id].pt[mid].y;
		for (i = 0; i < sz; i++)
		{
			if (i <= mid)
			{
				tree[l].pt.push_back(tree[id].pt[i]);
				tree[l].x.push_back(tree[id].pt[i].x);
				tree[l].y.push_back(tree[id].pt[i].y);
			}
			else
			{
				tree[r].pt.push_back(tree[id].pt[i]);
				tree[r].x.push_back(tree[id].pt[i].x);
				tree[r].y.push_back(tree[id].pt[i].y);
			}
		}
	}
	sort(tree[l].x.begin(), tree[l].x.end());
	unique(tree[l].x.begin(), tree[l].x.end());
	sort(tree[l].y.begin(), tree[l].y.end());
	unique(tree[l].y.begin(), tree[l].y.end());
	sort(tree[r].x.begin(), tree[r].x.end());
	unique(tree[r].x.begin(), tree[r].x.end());
	sort(tree[r].y.begin(), tree[r].y.end());
	unique(tree[r].y.begin(), tree[r].y.end());
	build(l);
	build(r);
}
bool intersect(int x, int y, int r, int id)
{
	int i, j, s, p, q, lx, ly, rx, ry, szx, szy;
	szx = tree[id].x.size();
	szy = tree[id].y.size();
	lx = tree[id].x[0];
	ly = tree[id].y[0];
	rx = tree[id].x[szx - 1];
	ry = tree[id].y[szy - 1];
	if (x > lx && x < rx && y < ry && y > ly)
	{
		return true;
	}
	if (x >= rx + r || x <= lx - r || y >= ry + r || y <= ly - r)
	{
		return false;
	}
	if ((double)(lx - x) * (double)(lx - x) + (double)(ly - y) * (double)(ly - y) < r * r - eps)
	{
		return true;
	}
	if ((double)(lx - x) * (double)(lx - x) + (double)(ry - y) * (double)(ry - y) < r * r - eps)
	{
		return true;
	}
	if ((double)(rx - x) * (double)(rx - x) + (double)(ly - y) * (double)(ly - y) < r * r - eps)
	{
		return true;
	}
	if ((double)(rx - x) * (double)(rx - x) + (double)(ry - y) * (double)(ry - y) < r * r - eps)
	{
		return true;
	}
	return (x > lx && x < rx) || (y > ly && y < ry);
}
bool inner(int x, int y, int ri, int id)
{
	int i, j, s, p, q, lx, ly, rx, ry, szx, szy;
	szx = tree[id].x.size();
	szy = tree[id].y.size();
	lx = tree[id].x[0];
	ly = tree[id].y[0];
	rx = tree[id].x[szx - 1];
	ry = tree[id].y[szy - 1];
	if ((double)(lx - x) * (double)(lx - x) + (double)(ly - y) * (double)(ly - y) >= r * r - eps)
	{
		return false;
	}
	if ((double)(lx - x) * (double)(lx - x) + (double)(ry - y) * (double)(ry - y) >= r * r - eps)
	{
		return false;
	}
	if ((double)(rx - x) * (double)(rx - x) + (double)(ly - y) * (double)(ly - y) >= r * r - eps)
	{
		return false;
	}
	if ((double)(rx - x) * (double)(rx - x) + (double)(ry - y) * (double)(ry - y) >= r * r - eps)
	{
		return false;
	}
	return true;
}
void query(int id, int x, int y, int ri)
{
	int i, j, s, p, q, l = 2 * id + 1, r = 2 * id + 2;
	if (!intersect(x, y, ri, id))
	{
		return;
	}
	if (inner(x, y, ri, id))
	{
		ans += tree[id].pt.size();
		return;
	}
	if (tree[id].pt.size() <= 1)
	{
		ans++;
		return;
	}
	query(l, x, y, ri);
	query(r, x, y, ri);
}
int main()
{
	int i, j, s, p, q;
	while (scanf("%d%d%d%d", &l, &h, &r, &n) == 4)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &pt[i].x, &pt[i].y);
		}
		tree[0].pt.clear();
		tree[0].x.clear();
		tree[0].y.clear();
		for (i = 0; i < n; i++)
		{
			tree[0].pt.push_back(pt[i]);
			tree[0].x.push_back(pt[i].x);
			tree[0].y.push_back(pt[i].y);
		}
		sort(tree[0].x.begin(), tree[0].x.end());
		unique(tree[0].x.begin(), tree[0].x.end());
		sort(tree[0].y.begin(), tree[0].y.end());
		unique(tree[0].y.begin(), tree[0].y.end());
		build(0);
		ans = 0;
		for (i = 0; i < n; i++)
		{
			query(0, pt[i].x, pt[i].y, r);
		}
		ans -= n;
		while (ans % 2 != 0)
		{
			puts("orz");
		}
		printf("%d\n", ans / 2);
	}
	return 0;
}
