#include <bits/stdc++.h>

using namespace std;

#define For(i, n) for (int i = 0, _m = (n); i < _m; i++)

typedef long long LL;

struct Point
{
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	Point operator-(const Point &p) const
	{
		return Point(x - p.x, y - p.y);
	}
};

LL cross(const Point &a, const Point &b)
{
	return LL(a.x) * b.y - LL(a.y) * b.x;
}

inline bool between(int x, int a, int b)
{
	return a <= x and x <= b;
}
struct Seg
{
	Point p1, p2;
	enum
	{
		UP,
		HOR,
		DOWN
	} type;
	void normalize()
	{
		if (p1.x > p2.x)
		{
			swap(p1, p2);
		}
		if (p1.y < p2.y)
		{
			type = UP;
		}
		else if (p1.y > p2.y)
		{
			type = DOWN;
		}
		else
		{
			type = HOR;
		}
	}
};

struct P2
{
	int id;
	enum
	{
		OPEN,
		CLOSE
	} side;
	int x;
	bool operator<(const P2 &p) const
	{
		return x < p.x;
	}
};

const int N = 100102;
const int M = 1000102;

P2 ps[N * 2];
int fa[N + M], fx[N + M];
int n, m;
int xmin, xmax;
int qx[N];
Seg segs[N];

void getFa(int u, int &v, int &x)
{
	if (fa[u] == u)
	{
		v = u;
		if (fx[u] != -1)
		{
			x = fx[u];
		}
		return;
	}
	x = fx[u];
	getFa(fa[u], v, x);
	fa[u] = v;
	fx[u] = x;
	// printf("getFa(%d) -> (%d, %d)\n", u, v, x);
}

void setFa(int u, int v, int x)
{
	// printf("setFa(%d, %d, %d)\n", u, v, x);
	fa[u] = v;
	fx[u] = x;
}

struct SegCmp
{
	bool lt(const Seg &a, const Seg &b)
	{
		if (between(a.p1.x, b.p1.x, b.p2.x))
		{
			if (cross(a.p1 - b.p1, b.p2 - b.p1) > 0)
			{
				return true;
			}
		}
		if (between(a.p2.x, b.p1.x, b.p2.x))
		{
			if (cross(a.p2 - b.p1, b.p2 - b.p1) > 0)
			{
				return true;
			}
		}
		if (between(b.p1.x, a.p1.x, a.p2.x))
		{
			if (cross(a.p2 - a.p1, b.p1 - a.p1) > 0)
			{
				return true;
			}
		}
		if (between(b.p2.x, a.p1.x, a.p2.x))
		{
			if (cross(a.p2 - a.p1, b.p2 - a.p1) > 0)
			{
				return true;
			}
		}
		return false;
	}
	bool operator()(int i, int j)
	{
		const Seg &a = segs[i];
		const Seg &b = segs[j];
		return lt(a, b);
		// if(lt(a, b)) return true;
		// if(lt(b, a)) return false;
		// else return i < j;
	}
};

void flush(int i)
{
	int v, x;
	getFa(i, v, x);
}

void scan()
{
	int k = 0;
	For(i, n)
	{
		ps[k].id = i;
		ps[k].side = P2::OPEN;
		ps[k].x = segs[i].p1.x;
		k++;
		ps[k].id = i;
		ps[k].side = P2::CLOSE;
		ps[k].x = segs[i].p2.x;
		k++;
	}
	sort(ps, ps + k);
	set<int, SegCmp> h;
	int lastX, curX;
	lastX = 0;
	For(r, k)
	{
		curX = ps[r].x;
		// cout << "x:" << curX << endl;
		if (not h.empty())
		{
			int i = *h.begin();
			while (lastX < curX)
			{
				setFa(n + lastX, i, lastX);
				lastX++;
			}
		}
		else
		{
			lastX = curX;
		}
		int i = ps[r].id;
		if (ps[r].side == P2::OPEN)
		{
			h.insert(i);
			// printf("seg#%d(%d, %d) enter\n", i, segs[i].p1.x, segs[i].p2.x);
			if (segs[i].type == Seg::DOWN)
			{
				if (h.upper_bound(i) != h.end())
				{
					setFa(i, *h.upper_bound(i), curX);
				}
				else
				{
					setFa(i, i, curX);
				}
				// flush(i);
			}
		}
		else
		{
			// printf("seg#%d(%d, %d) leave\n", i, segs[i].p1.x, segs[i].p2.x);
			if (segs[i].type == Seg::UP)
			{
				if (h.upper_bound(i) != h.end())
				{
					setFa(i, *h.upper_bound(i), curX);
				}
				else
				{
					setFa(i, i, curX);
				}
				// flush(i);
			}
			setFa(n + lastX, *h.begin(), lastX);
			lastX++;
			h.erase(i);
		}
		// cout << "hsize: " << h.size() << endl;
	}
	// For(i, n + xmax + 1) {
	//     printf("(%d, %d) ", fa[i], fx[i]);
	// } cout << endl;
}

void init()
{
	xmin = xmax = qx[0];
	For(i, m)
	{
		xmin = min(xmin, qx[i]);
		xmax = max(xmax, qx[i]);
	}
	For(i, n)
	{
		xmin = min(xmin, segs[i].p1.x);
		xmax = max(xmax, segs[i].p2.x);
	}
	For(i, n)
	{
		setFa(i, i, -1);
	}
	For(i, xmax + 1)
	{
		setFa(n + i, n + i, i);
	}
}

int main()
{
	while (cin >> n >> m)
	{
		if (n == -1)
		{
			break;
		}
		For(i, n)
		{
			scanf("%d%d%d%d", &segs[i].p1.x, &segs[i].p1.y, &segs[i].p2.x, &segs[i].p2.y);
			segs[i].normalize();
		}
		For(i, m)
		{
			scanf("%d", &qx[i]);
		}
		init();
		scan();
		For(i, m)
		{
			int u, x;
			getFa(n + qx[i], u, x);
			if (u >= n || segs[u].type != Seg::HOR)
			{
				printf("%d\n", x);
			}
			else
			{
				printf("%d %d\n", x, segs[u].p1.y);
			}
		}
	}
	return 0;
}
