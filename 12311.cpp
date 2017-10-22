#include <bits/stdc++.h>

using namespace std;

#define LL long long
const int maxn = 120000 + 10;
struct Point
{
	int x, y;
	void input()
	{
		scanf("%d%d", &x, &y);
	}
} pt[maxn];

struct Qnode
{
	int l, r, id;
	Qnode() {}
	Qnode(int l, int r, int id) : l(l), r(r), id(id) {}
} que[maxn];
int ans[maxn];
int n;

LL dis(const Point &A, const Point &B)
{
	return (LL)(A.x - B.x) * (A.x - B.x) + (LL)(A.y - B.y) * (A.y - B.y);
}
void update(int a, int b)
{
	LL d1 = dis(pt[b], pt[a]), d2 = dis(pt[ans[a]], pt[a]);
	if (d1 > d2 || d1 == d2 && ans[a] > b)
	{
		ans[a] = b;
	}
}
int find1(int x, int w)
{
	int l = que[x].l, r = que[x].r, ow = que[x].id;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (dis(pt[m], pt[w]) > dis(pt[m], pt[ow]))
		{
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}
	return r;
}
int find2(int x, int w)
{
	int l = que[x].r, r = que[x].l, ow = que[x].id;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (dis(pt[m], pt[w]) >= dis(pt[m], pt[ow]))
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	return l;
}

int main()
{
	while (scanf("%d", &n) && n)
	{
		for (int i = 1; i <= n; i++)
		{
			pt[i].input(), ans[i] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			assert(pt[i].x <= 1000000000 && pt[i].x >= -1000000000), assert(pt[i].y <= 1000000000 && pt[i].y >= -1000000000);
		}
		int head = 1, tail = 1;
		que[head] = Qnode(2, n, 1);
		for (int i = 2; i <= n; i++)
		{
			update(i, que[head].id);
			if (i == n)
			{
				continue;
			}
			que[head].l++;
			if (que[head].l > que[head].r)
			{
				++head;
			}
			if (dis(pt[que[tail].r], pt[i]) <= dis(pt[que[tail].r], pt[que[tail].id]))
			{
				continue;
			}
			while (head <= tail && dis(pt[que[tail].l], pt[i]) > dis(pt[que[tail].l], pt[que[tail].id]))
			{
				--tail;
			}
			if (head > tail)
			{
				++tail;
				que[tail] = Qnode(i + 1, n, i);
			}
			else
			{
				int t = find1(tail, i);
				if (t != que[tail].r)
				{
					que[tail].r = t;
				}
				++tail;
				que[tail].l = que[tail - 1].r + 1;
				que[tail].r = n;
				que[tail].id = i;
			}
		}
		head = 1, tail = 1;
		que[head] = Qnode(n - 1, 1, n);
		for (int i = n - 1; i >= 1; i--)
		{
			update(i, que[head].id);
			if (i == 1)
			{
				continue;
			}
			que[head].l--;
			if (que[head].l < que[head].r)
			{
				++head;
			}
			if (dis(pt[que[tail].r], pt[i]) < dis(pt[que[tail].r], pt[que[tail].id]))
			{
				continue;
			}
			while (head <= tail && dis(pt[que[tail].l], pt[i]) >= dis(pt[que[tail].l], pt[que[tail].id]))
			{
				--tail;
			}
			if (head > tail)
			{
				++tail;
				que[tail] = Qnode(i - 1, 1, i);
			}
			else
			{
				int t = find2(tail, i);
				if (t != que[tail].r)
				{
					que[tail].r = t;
				}
				++tail;
				que[tail].l = que[tail - 1].r - 1;
				que[tail].r = 1;
				que[tail].id = i;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
