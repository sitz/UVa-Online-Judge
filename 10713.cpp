#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef complex<double> P;

string opx[2][4] = {"", "east", "east", "east", "", "west", "west", "west"};
string opy[2][4] = {"north", "north", "", "south", "south", "south", "", "north"};
P d[4];

double cross(P a, P b)
{
	return a.real() * b.imag() - a.imag() * b.real();
}

double dot(P a, P b)
{
	return a.real() * b.real() + a.imag() * b.imag();
}

bool isp(P a, P b, P c)
{
	return abs(cross(b - a, c - a)) / abs(b - a) < 1e-10;
}

P intersection_ll(P a1, P a2, P b1, P b2)
{
	P a = a2 - a1, b = b2 - b1;
	return a1 + a * cross(b, b1 - a1) / cross(b, a);
}

void solve(P my, P des, double r)
{
	int indx, indy;
	if (my.real() <= des.real())
	{
		indx = 0;
	}
	else
	{
		indx = 1;
	}
	if (my.imag() <= des.imag())
	{
		indy = 0;
	}
	else
	{
		indy = 1;
	}
	rep(i, 4)
	{
		if (isp(my, my + d[i], des))
		{
			printf("%s%s %.10lf\n",
				opy[i % 2 == 1 ? indx : indy][i].c_str(),
				opx[indx][i].c_str(),
				abs(my - des));
			return;
		}
	}
	P mid;
	double ans = 1e100;
	int indi = -1, indj = -1;
	rep(i, 4)
	{
		rep(j, 4)
		{
			if (i == j)
			{
				continue;
			}
			P tmid = intersection_ll(my, my + d[i], des, des + d[j]);
			if (abs(tmid) > r)
			{
				continue;
			}
			double tmp = abs(tmid - my) + abs(tmid - des);
			if (tmp < ans)
			{
				mid = tmid;
				ans = tmp;
				indi = i;
				indj = j;
			}
		}
	}
	if (indi == -1)
	{
		exit(1);
	}
	printf("%s%s %.10lf\n",
		opy[indi % 2 == 1 ? indx : indy][indi].c_str(),
		opx[indx][indi].c_str(),
		abs(my - mid));
	printf("%s%s %.10lf\n",
		opy[indj % 2 == 1 ? indx : indy][indj].c_str(),
		opx[indx][indj].c_str(),
		abs(des - mid));
}

int main()
{
	d[0] = P(0, 1);
	d[1] = P(1, 1);
	d[2] = P(1, 0);
	d[3] = P(1, -1);
	int tc = 0;
	double r,re1,im1,re2,im2;
	while (scanf("%lf%lf%lf%lf%lf", &r,&re1,&im1,&re2,&im2) && (r >= 0))
	{
		if (tc++)
		{
			puts("");
		}
		solve(P(re1,im1), P(re2,im2), r);
	}
	return 0;
}
