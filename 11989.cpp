#include <bits/stdc++.h>

using namespace std;

struct point
{
	double x, y, theta;
	bool operator<(const point &temp) const
	{
		return theta < temp.theta;
	}
};
point queue_[1000000], line, oo, l_now, r_now, now, nw, lw;
set<point> hs;
set<point>::iterator it, itt, ht;

bool is;
int n, w, h, head, tail, low, high, mid, vv, vf, l_id;
double now_area, theta, eps = 1e-9;

double cross(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - x2 * y1;
}
point inter(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	double ru1, ru2, A, B;
	point res;
	A = (y2 - y1) * (x4 - x3) - (x2 - x1) * (y4 - y3);
	B = (y3 - y1) * (x4 - x3) - (x3 - x1) * (y4 - y3);
	if (fabs(A) < eps)
	{
		is = false;
		return res;
	}
	ru1 = B / A;
	B = (y3 - y1) * (x2 - x1) - (x3 - x1) * (y2 - y1);
	ru2 = B / A;
	if (ru1 > 1 - eps || ru1 < -eps)
	{
		is = false;
	}
	else
	{
		is = true;
	}
	res.x = x1 + ru1 * (x2 - x1);
	res.y = y1 + ru1 * (y2 - y1);
	return res;
}

int main()
{
	int i, j, s, p, q, id, id1, id2;
	double x1, y1, x2, y2, ru, xx, yy;
	oo.x = 1123;
	oo.y = 1531;
	while (scanf("%d%d%d", &n, &w, &h) == 3)
	{
		head = tail = 500000;
		queue_[tail].x = 0;
		queue_[tail++].y = 0;
		queue_[tail].x = w;
		queue_[tail++].y = 0;
		queue_[tail].x = w;
		queue_[tail++].y = h;
		queue_[tail].x = 0;
		queue_[tail++].y = h;
		hs.clear();
		for (i = head; i < tail; i++)
		{
			id = i + 1;
			if (i == tail - 1)
			{
				id = head;
			}
			queue_[i].theta = atan2(queue_[id].y - queue_[i].y, queue_[id].x - queue_[i].x);
		}
		for (i = head; i < tail; i++)
		{
			hs.insert(queue_[i]);
		}
		now_area = w * h;
		while (n--)
		{
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			if (now_area == 0)
			{
				printf("0\n");
				continue;
			}
			theta = atan2(y2 - y1, x2 - x1);
			now.theta = theta;
			it = hs.upper_bound(now);
			if (it == hs.end())
			{
				it = hs.begin();
			}
			if (cross(x1 - it->x, y1 - it->y, x2 - it->x, y2 - it->y) > -eps)
			{
				printf("%f\n", now_area);
				continue;
			}
			for (itt = it;;)
			{
				ht = itt;
				ht++;
				if (ht == hs.end())
				{
					ht = hs.begin();
				}
				now = inter(itt->x, itt->y, ht->x, ht->y, x1, y1, x2, y2);
				if (is)
				{
					break;
				}
				itt++;
				if (itt == hs.end())
				{
					itt = hs.begin();
				}
				if (itt == it)
				{
					break;
				}
			}
			if (!is)
			{
				now_area = 0;
				printf("0\n");
				continue;
			}
			now.theta = itt->theta;
			tail = 0;
			for (it = itt;;)
			{
				ht = it;
				queue_[tail++] = *it;
				if (ht == hs.begin())
				{
					ht = hs.end();
				}
				ht--;
				nw = inter(ht->x, ht->y, it->x, it->y, x1, y1, x2, y2);
				if (!is)
				{
					nw = *ht;
				}
				now_area -= 0.5 * fabs(cross(nw.x - now.x, nw.y - now.y, it->x - now.x, it->y - now.y));
				it = ht;
				if (is)
				{
					break;
				}
			}
			nw.theta = theta;
			for (i = 0; i < tail; i++)
			{
				hs.erase(queue_[i]);
			}
			hs.insert(now);
			hs.insert(nw);
			printf("%f\n", now_area);
		}
	}
	return 0;
}
