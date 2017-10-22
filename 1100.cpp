#include <bits/stdc++.h>

using namespace std;

struct point3
{
	double x, y, z;
	point3 &operator+=(point3 a)
	{
		x += a.x, y += a.y, z += a.z;
		return *this;
	}
	point3 &operator-=(point3 a)
	{
		x -= a.x, y -= a.y, z -= a.z;
		return *this;
	}
	point3 &operator*=(double a)
	{
		x *= a, y *= a, z *= a;
		return *this;
	}
	point3 &operator/=(double a)
	{
		x /= a, y /= a, z /= a;
		return *this;
	}
};
point3 operator+(point3 a, point3 b)
{
	point3 c;
	c = a, c += b;
	return c;
}
point3 operator-(point3 a, point3 b)
{
	point3 c;
	c = a, c -= b;
	return c;
}
point3 operator*(point3 a, double b)
{
	point3 c;
	c = a, c *= b;
	return c;
}
point3 operator*(double a, point3 b)
{
	point3 c;
	c = b, c *= a;
	return c;
}
point3 operator/(point3 a, double b)
{
	point3 c;
	c = a, c /= b;
	return c;
}
double operator*(point3 a, point3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
point3 operator%(point3 a, point3 b)
{
	point3 c;
	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return c;
}
double dis(point3 a)
{
	return sqrt(a * a);
}
struct line3
{
	point3 a, s;
	line3(point3 _a, point3 _s)
	{
		a = _a, s = _s;
	}
};
struct face3
{
	point3 a, n;
};
double point_line_dis(point3 a, line3 b, point3 *res = NULL)
{
	point3 p;
	p = b.a + ((a - b.a) * b.s) / (b.s * b.s) * b.s;
	if (res != NULL)
	{
		*res = p;
	}
	return dis(a - p);
}
double point_face_dis(point3 a, face3 b, point3 *res = NULL)
{
	point3 p;
	p = ((a - b.a) * b.n) / (b.n * b.n) * b.n;
	if (res != NULL)
	{
		*res = p;
	}
	return dis(p);
}
face3 face_from_point(point3 a, point3 b, point3 c)
{
	face3 f;
	f.a = a, f.n = (b - a) % (c - a);
	return f;
}
double mixed_prod(point3 a, point3 b, point3 c)
{
	return (a % b) * c;
}
point3 x[5], f, g;
void solve()
{
	for (int i = 1; i < 5; i++)
	{
		scanf("%lf%lf%lf", &x[i].x, &x[i].y, &x[i].z);
	}
	scanf("%lf%lf%lf", &f.x, &f.y, &f.z);
	double s1 = fabs(mixed_prod(x[3] - x[0], x[3] - x[1], x[3] - x[2])), s2 = fabs(mixed_prod(x[4] - x[0], x[4] - x[1], x[4] - x[2]));
	g = ((x[0] + x[1] + x[2] + x[3]) / 4 * s1 + (x[0] + x[1] + x[2] + x[4]) / 4 * s2) / (s1 + s2);
	double min = 1e10, max = 0;
	for (int i = 0; i < 5; i++)
		for (int j = i + 1; j < 5; j++)
			for (int k = j + 1; k < 5; k++)
			{
				face3 y = face_from_point(x[i], x[j], x[k]);
				int flag = 0, another = -1;
				for (int t = 0; t < 5; t++)
				{
					double dis = ((x[t] - y.a) * y.n) / (y.n * y.n);
					if (fabs(dis) < 1e-8 && t != i && t != j && t != k)
					{
						another = t;
					}
					if (fabs(dis) > 1e-8)
					{
						int s = (dis > 0 ? 1 : -1);
						if (s == -flag)
						{
							flag = -2;
							break;
						}
						flag = s;
					}
				}
				if (flag == -2)
				{
					continue;
				}
				std::vector<point3> tmp;
				tmp.push_back(x[i]), tmp.push_back(x[j]), tmp.push_back(x[k]);
				if (another > -1)
				{
					tmp.push_back(x[another]);
					for (int i = 0; i < 4; i++)
					{
						double s = 0, t = 0;
						for (int j = 0; j < 4; j++)
							if (i != j)
							{
								int k = (j + 1) % 4;
								if (k == i)
								{
									k = (k + 1) % 4;
								}
								s += fabs(((tmp[i] - tmp[j]) % (tmp[i] - tmp[k])) * y.n);
								t += ((tmp[i] - tmp[j]) % (tmp[i] - tmp[k])) * y.n;
							}
						if (fabs(s - fabs(t)) < 1e-8)
						{
							tmp.erase(tmp.begin() + i);
							break;
						}
					}
					if (tmp.size() == 4)
						for (int i = 1; i < 3; i++)
						{
							int j = i;
							for (; j < 4; j++)
								if (j != i - 2)
								{
									double t = 1;
									for (int k = 0; k < 4; k++)
										if (k != i - 1 && k != j)
										{
											t *= ((tmp[i - 1] - tmp[k]) % (tmp[i - 1] - tmp[j])) * y.n;
										}
									if (t > 1e-8)
									{
										break;
									}
								}
							std::swap(tmp[i], tmp[j]);
						}
				}
				point3 g_ = g - ((g - y.a) * y.n) / (y.n * y.n) * y.n;
				double s = 0, t = 0;
				for (int i = 1; i + 1 < tmp.size(); i++)
				{
					s += dis((tmp[i + 1] - tmp[0]) % (tmp[i] - tmp[0]));
				}
				for (int i = 0; i < tmp.size(); i++)
				{
					t += fabs(dis((g_ - tmp[i]) % (g_ - tmp[(i + 1) % tmp.size()])));
				}
				if (fabs(t - fabs(s)) > 1e-8)
				{
					continue;
				}
				double d = 1e10;
				for (int j = 0; j < tmp.size(); j++)
				{
					d = std::min(d, point_line_dis(g_, line3(tmp[j], tmp[(j + 1) % tmp.size()] - tmp[j])));
				}
				if (d < 0.2)
				{
					continue;
				}
				d = point_face_dis(f, y);
				if (d < min)
				{
					min = d;
				}
				if (d > max)
				{
					max = d;
				}
			}
	printf("%.5lf %.5lf\n", min, max);
}
int main()
{
	int _ = 0;
	while (scanf("%lf%lf%lf", &x[0].x, &x[0].y, &x[0].z) == 3)
	{
		printf("Case %d: ", ++_), solve();
	}
	return 0;
}
