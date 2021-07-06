#include <bits/stdc++.h>

using namespace std;

#define eps 1e-4

struct Nodes
{
	double x, y, z;
} p[2][4];

double sqr(double x)
{
	return x * x;
}
double dis(Nodes p1, Nodes p2)
{
	return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y) + sqr(p1.z - p2.z));
}
Nodes operator-(Nodes p1, Nodes p2)
{
	Nodes tmp;
	tmp.x = p2.x - p1.x;
	tmp.y = p2.y - p1.y;
	tmp.z = p2.z - p1.z;
	return tmp;
}
double cal_1(Nodes p1, Nodes p2)
{
	return dis(p1, p2);
}
Nodes getP(Nodes u1, Nodes u2, double r)
{
	Nodes now;
	now.x = u1.x + (u2.x - u1.x) * r;
	now.y = u1.y + (u2.y - u1.y) * r;
	now.z = u1.z + (u2.z - u1.z) * r;
	return now;
}
double get_area(Nodes p1, Nodes p2, Nodes p3)
{
	double x1, x2, y1, y2, z1, z2;
	x1 = p2.x - p1.x;
	x2 = p3.x - p1.x;
	y1 = p2.y - p1.y;
	y2 = p3.y - p1.y;
	z1 = p2.z - p1.z;
	z2 = p3.z - p1.z;
	double dx, dy, dz;
	dx = y1 * z2 - z1 * y2;
	dy = -(x1 * z2 - x2 * z1);
	dz = x1 * y2 - y1 * x2;
	return sqrt(sqr(dx) + sqr(dy) + sqr(dz)) / 2.0;
}
double dot(Nodes a, Nodes b, Nodes c)
{
	Nodes p1 = b - a, p2 = c - a;
	return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}
double cal_2(Nodes now, Nodes v1, Nodes v2)
{
	if (dot(v1, now, v2) <= 0)
	{
		return dis(now, v1);
	}
	if (dot(v2, now, v1) <= 0)
	{
		return dis(now, v2);
	}
	double area = get_area(now, v1, v2);
	return area * 2 / dis(v1, v2);
}
double cal_3(Nodes u1, Nodes u2, Nodes v1, Nodes v2)
{
	double L = 0, R = 1;
	double res = 1e100;
	while (L < R)
	{
		double L1 = L + (R - L) / 3;
		double R1 = L + (R - L) * 2 / 3;
		Nodes nowL, nowR;
		nowL = getP(u1, u2, L1);
		nowR = getP(u1, u2, R1);
		double LenL = cal_2(nowL, v1, v2);
		double LenR = cal_2(nowR, v1, v2);
		//puts("yes");
		if (LenL <= LenR)
		{
			if (res > LenL)
			{
				res = LenL;
			}
			R = R1 - eps;
		}
		else
		{
			L = L1 + eps;
			if (res > LenR)
			{
				res = LenR;
			}
		}
	}
	return res;
}

int work(double tmp)
{
	if (fabs(tmp) < eps)
	{
		return 0;
	}
	if (tmp > 0)
	{
		return 1;
	}
	return -1;
}
double cross(Nodes p1, Nodes p2)
{
	return p1.x * p2.y - p1.y * p2.x;
}
bool IsPInPlane(Nodes o, Nodes p1, Nodes p2, Nodes p3)
{
	int sgn1, sgn2, sgn3;
	double tmp = cross(o - p1, o - p2);
	sgn1 = work(tmp);
	tmp = cross(o - p2, o - p3);
	sgn2 = work(tmp);
	tmp = cross(o - p3, o - p1);
	sgn3 = work(tmp);
	if (sgn1 > 0)
	{
		if (sgn2 <= 0 || sgn3 <= 0)
		{
			return false;
		}
		return true;
	}
	if (sgn1 < 0)
	{
		if (sgn2 >= 0 || sgn3 >= 0)
		{
			return false;
		}
		return true;
	}
	return false;
}
double cal_4(Nodes o, Nodes p1, Nodes p2, Nodes p3)
{
	//get the cross vetctor
	double x1, x2, y1, y2, z1, z2;
	x1 = p2.x - p1.x;
	x2 = p3.x - p1.x;
	y1 = p2.y - p1.y;
	y2 = p3.y - p1.y;
	z1 = p2.z - p1.z;
	z2 = p3.z - p1.z;
	double dx, dy, dz, A, B, C, D;
	dx = y1 * z2 - z1 * y2;
	dy = -(x1 * z2 - x2 * z1);
	dz = x1 * y2 - y1 * x2;
	//get the plane
	A = dx;
	B = dy;
	C = dz;
	D = A * p1.x + B * p1.y + C * p1.z;
	double k;
	k = (D - A * o.x - B * o.y - C * o.z) / (A * dx + B * dy + C * dz);
	Nodes s;
	s.x = o.x + dx * k;
	s.y = o.y + dy * k;
	s.z = o.z + dz * k;
	if (IsPInPlane(s, p1, p2, p3))
	{
		return dis(s, o);
	}
	else
	{
		return 1e100;
	}
}
int main()
{
	int i, j, k;
	int t;
	double res = 1e100;
	scanf("%d", &t);
	while (t--)
	{
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 4; j++)
			{
				scanf("%lf%lf%lf", &p[i][j].x, &p[i][j].y, &p[i][j].z);
			}
		}
		res = 1e100;
		//p->p
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				res = min(res, cal_1(p[0][i], p[1][j]));
			}
		}
		//    printf("p->p %.2f\n",res);
		//p->line
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				for (k = 0; k < 4; k++)
				{
					if (j != k)
					{
						res = min(res, cal_2(p[0][i], p[1][j], p[1][k]));
					}
					if (j != k)
					{
						res = min(res, cal_2(p[1][i], p[0][j], p[0][k]));
					}
				}
			}
		}
		//   printf("p->line %.2f\n",res);
		//line->line
		int i1, i2, j1, j2;
		for (i1 = 0; i1 < 4; i1++)
		{
			for (i2 = i1 + 1; i2 < 4; i2++)
			{
				for (j1 = 0; j1 < 4; j1++)
				{
					for (j2 = j1 + 1; j2 < 4; j2++)
					{
						res = min(res, cal_3(p[0][i1], p[0][i2], p[1][j1], p[1][j2]));
					}
				}
			}
		}
		//    printf("line->line %.2f\n",res);
		//p->plane
		for (i = 0; i < 4; i++)
		{
			res = min(res, cal_4(p[0][i], p[1][0], p[1][1], p[1][2]));//3
			res = min(res, cal_4(p[0][i], p[1][0], p[1][1], p[1][3]));//2
			res = min(res, cal_4(p[0][i], p[1][0], p[1][3], p[1][2]));//1
			res = min(res, cal_4(p[0][i], p[1][3], p[1][1], p[1][2]));//0
			//****
			res = min(res, cal_4(p[1][i], p[0][0], p[0][1], p[0][2]));//3
			res = min(res, cal_4(p[1][i], p[0][0], p[0][1], p[0][3]));//2
			res = min(res, cal_4(p[1][i], p[0][0], p[0][3], p[0][2]));//1
			res = min(res, cal_4(p[1][i], p[0][3], p[0][1], p[0][2]));//0
		}
		printf("%.2f\n", res);
	}
	return 0;
}
