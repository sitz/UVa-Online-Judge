#include <bits/stdc++.h>

using namespace std;

#define M 110
#define eps 1e-8

const double pi = acos(-1.0);

class pnt_type
{
public:
	int x, y;
};

class float_pnt_type
{
public:
	double x, y;
};

float_pnt_type float_pnt1[M], float_pnt2[M];
vector<pair<pnt_type, pnt_type>> tangent;

pnt_type pnt1[M], pnt2[M];
int n1, n2;

void read_data()
{
	int i;
	scanf("%d", &n1);
	for (i = 1; i <= n1; i++)
	{
		scanf("%d%d", &pnt1[i].x, &pnt1[i].y);
	}
	pnt1[n1 + 1] = pnt1[1];
	scanf("%d", &n2);
	for (i = 1; i <= n2; i++)
	{
		scanf("%d%d", &pnt2[i].x, &pnt2[i].y);
	}
	pnt2[n2 + 1] = pnt2[1];
	for (i = 1; i <= n1 + 1; i++)
	{
		float_pnt1[i].x = pnt1[i].x;
		float_pnt1[i].y = pnt1[i].y;
	}
	for (i = 1; i <= n2 + 1; i++)
	{
		float_pnt2[i].x = pnt2[i].x;
		float_pnt2[i].y = pnt2[i].y;
	}
}

inline int area2(pnt_type a, pnt_type b, pnt_type c)
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

inline double area2(float_pnt_type a, float_pnt_type b, float_pnt_type c)
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

inline int sign(int a)
{
	if (a == 0)
	{
		return 0;
	}
	else if (a > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

inline int sign(double a)
{
	if (a == 0)
	{
		return 0;
	}
	else if (a > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
inline bool same_sign(int a, int b)
{
	//int __a = sign(a), __b = sign(b);
	return sign(a) * sign(b) >= 0;
}
bool check(pnt_type a, pnt_type b)
{
	//throw new exception("No implementation exception.");
	int i;
	for (i = 1; i <= n1; i++)
		if (!same_sign(area2(a, b, pnt1[i]), area2(a, b, pnt1[i + 1])))
		{
			return false;
		}
	for (i = 1; i <= n2; i++)
		if (!same_sign(area2(a, b, pnt2[i]), area2(a, b, pnt2[i + 1])))
		{
			return false;
		}
	int tempa, tempb;
	for (i = 1; i <= n1; i++)
		if (area2(a, b, pnt1[i]) != 0)
		{
			tempa = i;
			break;
		}
	for (i = 1; i <= n2; i++)
		if (area2(a, b, pnt2[i]) != 0)
		{
			tempb = i;
			break;
		}
	if (same_sign(area2(a, b, pnt1[tempa]), area2(a, b, pnt2[tempb])))
	{
		return false;
	}
	return true;
}

bool not_appear(pnt_type a, pnt_type b)
{
	int i;
	pnt_type x, y;
	for (i = 0; i < tangent.size(); i++)
	{
		x = tangent[i].first;
		y = tangent[i].second;
		if (area2(a, b, x) == 0 && area2(a, b, y) == 0)
		{
			return false;
		}
	}
	return true;
}

double angle1, angle2;
float_pnt_type cp;

float_pnt_type cross_pnt(pnt_type a, pnt_type b, pnt_type c, pnt_type d)
{
	float_pnt_type res;
	res.x = (area2(a, b, d) * c.x - area2(a, b, c) * d.x + 0.0) / (area2(a, b, d) - area2(a, b, c));
	res.y = (area2(a, b, d) * c.y - area2(a, b, c) * d.y + 0.0) / (area2(a, b, d) - area2(a, b, c));
	return res;
}

float_pnt_type cross_pnt(float_pnt_type a, float_pnt_type b, float_pnt_type c, float_pnt_type d)
{
	float_pnt_type res;
	res.x = (area2(a, b, d) * c.x - area2(a, b, c) * d.x + 0.0) / (area2(a, b, d) - area2(a, b, c));
	res.y = (area2(a, b, d) * c.y - area2(a, b, c) * d.y + 0.0) / (area2(a, b, d) - area2(a, b, c));
	return res;
}

void init()
{
	int i, j;
	//double __slope;
	tangent.clear();
	for (i = 1; i <= n1; i++)
		for (j = 1; j <= n2; j++)
		{
			//printf("%d %d\n",i,j);
			if (check(pnt1[i], pnt2[j]))
			{
				if (not_appear(pnt1[i], pnt2[j]))
				{
					tangent.push_back(make_pair(pnt1[i], pnt2[j]));
				}
			}
		}
	i = i;
	//if (tangent.size() != 2) throw new exception("Does not exist two common tangent!");
	cp = cross_pnt(tangent[0].first, tangent[0].second, tangent[1].first, tangent[1].second);
	angle1 = atan2(tangent[0].second.y - tangent[0].first.y + 0.0, tangent[0].second.x - tangent[0].first.x + 0.0);
	angle2 = atan2(tangent[1].second.y - tangent[1].first.y + 0.0, tangent[1].second.x - tangent[1].first.x + 0.0);
	if (angle1 < 0)
	{
		angle1 += 2 * pi;
	}
	if (angle2 < 0)
	{
		angle2 += 2 * pi;
	}
	if (angle2 - angle1 < 0)
	{
		swap(angle1, angle2);
	}
	if (angle2 - angle1 > pi)
	{
		angle2 -= pi * 2;
		swap(angle2, angle1);
	}
}

double paraK, paraB;

float_pnt_type lf[M], rt[M];
int top_lf, top_rt;

float_pnt_type base;

inline bool cmp(float_pnt_type a, float_pnt_type b)
{
	if (a.x != b.x)
	{
		return a.x < b.x;
	}
	else
	{
		return a.y < b.y;
	}
}

inline bool cmp2(float_pnt_type a, float_pnt_type b)
{
	return area2(base, a, b) > 0;
}

float_pnt_type stk[M];
double calc_area(float_pnt_type *data, int n)
{
	if (n < 3)
	{
		return 0;
	}
	sort(data + 1, data + n + 1, cmp);
	base = data[1];
	sort(data + 2, data + n + 1, cmp2);
	int top = 2;
	stk[1] = base;
	stk[2] = data[2];
	int i;
	for (i = 3; i <= n; i++)
	{
		while (area2(stk[top - 1], stk[top], data[i]) < 0 && top > 2)
		{
			top--;
		}
		stk[++top] = data[i];
	}
	while (area2(stk[top - 1], stk[top], data[1]) < 0 && top > 2)
	{
		top--;
	}
	double res = 0;
	for (i = 3; i <= n; i++)
	{
		res += fabs(area2(data[1], data[i - 1], data[i])) / 2;
	}
	return res;
}
double calc_the_dif(float_pnt_type *float_pnt, int n, double bias, double alpha)
{
	float_pnt_type org, other;
	org.x = cp.x + bias * cos(alpha + pi / 2);
	org.y = cp.y + bias * sin(alpha + pi / 2);
	other.x = org.x + cos(alpha);
	other.y = org.y + sin(alpha);
	top_lf = top_rt = 0;
	int i;
	for (i = 1; i <= n; i++)
	{
		if (area2(org, other, float_pnt[i]) > -eps)
		{
			top_lf++;
			lf[top_lf] = float_pnt[i];
		}
		if (area2(org, other, float_pnt[i]) < eps)
		{
			top_rt++;
			rt[top_rt] = float_pnt[i];
		}
	}
	float_pnt_type temp;
	for (i = 1; i <= n; i++)
		if (sign(area2(org, other, float_pnt[i])) * sign(area2(org, other, float_pnt[i + 1])) < 0)
		{
			temp = cross_pnt(org, other, float_pnt[i], float_pnt[i + 1]);
			top_lf++;
			top_rt++;
			lf[top_lf] = temp;
			rt[top_rt] = temp;
		}
	return calc_area(lf, top_lf) - calc_area(rt, top_rt);
}

double find_the_line(double theta)
{
	double up = 3000, dn = -3000;
	double dif1, dif2;
	dif1 = calc_the_dif(float_pnt1, n1, up, theta);
	dif2 = calc_the_dif(float_pnt1, n1, dn, theta);
	double mid, temp;
	while (up - dn > eps)
	{
		mid = (up + dn) / 2;
		if (mid > -0.5 && mid < 0)
		{
			mid = mid;
		}
		temp = calc_the_dif(float_pnt1, n1, mid, theta);
		if (dif1 > dif2)
		{
			if (temp > 0)
			{
				up = mid;
			}
			else
			{
				dn = mid;
			}
		}
		else
		{
			if (temp > 0)
			{
				dn = mid;
			}
			else
			{
				up = mid;
			}
		}
	}
	return (up + dn) / 2;
}

double temp_p1, temp_theta;

double calc_parameter(double theta)
{
	double p1;
	p1 = find_the_line(theta);
	temp_p1 = p1;
	temp_theta = theta;
	return calc_the_dif(float_pnt2, n2, p1, theta);
}
void work_ans()
{
	double up = angle2, dn = angle1, mid;
	double ref_left = calc_parameter(up);
	double ref_right = calc_parameter(dn);
	double temp;
	while (up - dn > eps)
	{
		mid = (up + dn) / 2;
		temp = calc_parameter(mid);
		if (ref_left > ref_right)
		{
			if (temp > 0)
			{
				up = mid;
			}
			else
			{
				dn = mid;
			}
		}
		else
		{
			if (temp > 0)
			{
				dn = mid;
			}
			else
			{
				up = mid;
			}
		}
	}
	calc_parameter((up + dn) / 2);
}

void show_ans()
{
	paraK = tan(temp_theta);
	double xx, yy;
	xx = cp.x + temp_p1 * cos(temp_theta + pi / 2);
	yy = cp.y + temp_p1 * sin(temp_theta + pi / 2);
	paraB = yy - xx * paraK;
	printf("%.9f %.9f\n", paraK, paraB);
}
int main()
{
	int t, i;
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		read_data();
		init();
		work_ans();
		show_ans();
	}
	return 0;
}
