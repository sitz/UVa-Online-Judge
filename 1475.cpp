#include <bits/stdc++.h>

using namespace std;

//ç²¾åº¦æ§å¶
const double eps = 1e-10;
int dcmp(double x)
{
	if (fabs(x) < eps)
	{
		return 0;
	}
	return x < 0 ? -1 : 1;
}

//ç¹
struct Point
{
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
};

//åé
typedef Point Vector;

//ç¹-ç¹==åé
Vector operator-(Point A, Point B)
{
	return Vector(A.x - B.x, A.y - B.y);
}

//åé+åé==åé
Vector operator+(Vector A, Vector B)
{
	return Vector(A.x + B.x, A.y + B.y);
}

//åé*å®æ°==åé
Vector operator*(Vector A, double p)
{
	return Vector(A.x * p, A.y * p);
}

//åç§¯
double Cross(Vector A, Vector B)
{
	return A.x * B.y - A.y * B.x;
}

//ææ¹åçç´çº¿
struct Line
{
	Point p;
	Vector v;
	double ang;
	Line() {}
	Line(Point p, Vector v) : p(p), v(v)
	{
		ang = atan2(v.y, v.x);
	}
	bool operator<(const Line &L) const
	{
		return ang < L.ang;
	}
};

//å¤æ­ç¹pæ¯å¦å¨ç´çº¿Lå·¦è¾¹
bool OnLeft(Line L, Point p)
{
	return Cross(L.v, p - L.p) > 0;
}

//å¾å°aä¸bä¸¤ç´çº¿çäº¤ç¹
Point GetIntersection(Line a, Line b)
{
	Vector u = a.p - b.p;
	double t = Cross(b.v, u) / Cross(a.v, b.v);
	return a.p + a.v * t;
}

//è¿ååå¹³é¢äº¤çå¸å¤è¾¹å½¢polyèç¹éå
int HalfplaneIntersection(Line *L, int n, Point *poly)
{
	sort(L, L + n);
	int first = 0, last = 0;
	Point *p = new Point[n];
	Line *q = new Line[n];
	q[0] = L[0];
	for (int i = 1; i < n; i++)
	{
		while (first < last && !OnLeft(L[i], p[last - 1]))
		{
			last--;
		}
		while (first < last && !OnLeft(L[i], p[first]))
		{
			first++;
		}
		q[++last] = L[i];
		if (fabs(Cross(q[last].v, q[last - 1].v)) < eps)
		{
			last--;
			if (OnLeft(q[last], L[i].p))
			{
				q[last] = L[i];
			}
		}
		if (first < last)
		{
			p[last - 1] = GetIntersection(q[last - 1], q[last]);
		}
	}
	while (first < last && !OnLeft(q[first], p[last - 1]))
	{
		last--;
	}
	if (last - first <= 1)
	{
		return 0;
	}
	p[last] = GetIntersection(q[last], q[first]);
	int m = 0;
	for (int i = first; i <= last; i++)
	{
		poly[m++] = p[i];
	}
	return m;
}
/***ä»¥ä¸ä¸ºåæ±ä½³æ¨¡æ¿***/

const int maxn = 50000 + 5;
Point p[maxn], poly[maxn];
Line L[maxn];

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		if (n == 3)//ä¸è§å½¢çè¯,ç´æ¥å é¤ä¸ä¸ªç¹å³å¯
		{
			printf("1\n");
			continue;
		}
		reverse(p, p + n);//å°ææé¡¶ç¹éæ¶éå­æ¾
		//å½ç¸æn-2ä¸ªè¿ç»­çç¹æ¶,åå¹³é¢äº¤è¯å®æ¯ç©º
		int left = 1, right = n - 2;
		while (right > left)
		{
			int mid = left + (right - left) / 2;
			for (int i = 0; i < n; i++)
			{
				L[i] = Line(p[i], p[(i + 1 + mid) % n] - p[i]);
			}
			int m = HalfplaneIntersection(L, n, poly);
			//m>0è¡¨ç¤ºåå¹³é¢äº¤éç©º,é£ä¹éè¦å ç¸å¼¹
			if (m > 0)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		printf("%d\n", left);
	}
	return 0;
}
