#include <bits/stdc++.h>

using namespace std;

typedef complex<double> Point;

double dot(Point a, Point b)
{
	return a.real() * b.real() + a.imag() * b.imag();
}
double cross(Point a, Point b)
{
	return a.real() * b.imag() - a.imag() * b.real();
}
namespace CCW
{
	enum
	{
		RIGHT = 1,
		LEFT = -1,
		FRONT = 2,
		BACK = 2,
		OTHER = 0
	};
};
int ccw(Point a, Point b, Point c)
{
	b -= a;
	c -= a;
	if (cross(b, c) < 0)
	{
		return CCW::RIGHT;
	}
	if (cross(b, c) > 0)
	{
		return CCW::LEFT;
	}
	if (dot(b, c) < 0)
	{
		return CCW::BACK;
	}
	if (norm(b) < norm(c))
	{
		return CCW::FRONT;
	}
	return CCW::OTHER;
}
bool cmp_real(const Point &a, const Point &b)
{
	if (a.imag() != b.imag())
	{
		return a.imag() < b.imag();
	}
	return a.real() < b.real();
}
vector<Point> andrew(vector<Point> v)
{
	if (v.size() < 3)
	{
		return v;
	}
	sort(v.begin(), v.end(), cmp_real);
	vector<Point> r[2];
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < (int)v.size(); ++j)
		{
			r[i].push_back(v[j]);
			while (2 < r[i].size())
			{
				vector<Point>::iterator itr = r[i].end();
				if (ccw(*(itr - 3), *(itr - 2), *(itr - 1)) == CCW::RIGHT)
				{
					break;
				}
				else
				{
					r[i].erase(itr - 2);
				}
			}
		}
		if (i)
		{
			break;
		}
		for (int j = 0; j < (int)v.size(); ++j)
		{
			v[j] = Point(v[j].real(), v[j].imag()*-1);
		}
	}
	for (int i = r[1].size() - 2; 0 < i; --i)
	{
		r[1][i] = Point(r[1][i].real(), r[1][i].imag()*-1);
		r[0].push_back(r[1][i]);
	}
	return r[0];
}
double dist_pp(const Point &a, const Point &b)
{
	double i = a.imag() - b.imag();
	double r = a.real() - b.real();
	return sqrt(i * i + r * r);
}

int main()
{
	int tree;
	while (scanf("%d", &tree) == 1 && tree)
	{
		vector<Point> v;
		double len[tree], val[tree];
		for (int i = 0; i < tree; ++i)
		{
			double re, im;
			scanf("%lf%lf%lf%lf", &re,&im,&val[i],&len[i]);
			Point p(re,im);
			v.push_back(p);
		}
		int bit = -1;
		double mx = 0;
		for (int i = 1; i < (1 << tree); ++i)
		{
			vector<Point> u;
			double sum_l = 0;
			double sum_v = 0;
			for (int j = 0; j < tree; ++j)
			{
				if (i & (1 << j))
				{
					u.push_back(v[j]);
					sum_v += val[j];
				}
				else
				{
					sum_l += len[j];
				}
			}
			u = andrew(u);
			if (u.size() == 0)
			{
				continue;
			}
			double fance = dist_pp(u[0], u.back());
			for (int j = 0; j + 1 < (int)u.size(); ++j)
			{
				fance += dist_pp(u[j], u[j + 1]);
			}
			if (fance <= sum_l)
			{
				if (mx < sum_v)
				{
					mx = sum_v;
					bit = i;
				}
			}
		}
		double ex = 0;
		vector<Point> u;
		for (int i = 0; i < (int)v.size(); ++i)
		{
			if (bit & (1 << i))
			{
				u.push_back(v[i]);
			}
			else
			{
				ex += len[i];
			}
		}
		u = andrew(u);
		ex -= dist_pp(u[0], u.back());
		for (int i = 0; i + 1 < (int)u.size(); ++i)
		{
			ex -= dist_pp(u[i], u[i + 1]);
		}
		static int cnt = 0;
		if (cnt)
		{
			puts("");
		}
		printf("Forest %d\n", ++cnt);
		printf("Cut these trees:");
		for (int i = 0; i < tree; ++i)
		{
			if (bit & (1 << i))
				;
			else
			{
				printf(" %d", i + 1);
			}
		}
		puts("");
		printf("Extra wood: %.2lf\n", ex);
	}
	return 0;
}
