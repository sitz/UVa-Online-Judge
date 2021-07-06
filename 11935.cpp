#include <bits/stdc++.h>

using namespace std;

struct p
{
	p(int a, int b, double c)
	{
		d = a;
		type = b;
		v = c;
	}
	p() {}
	int d;
	int type;
	double v;
} x[100];
bool cmp(p a, p b)
{
	if (a.d == b.d)
	{
		return a.type < b.type;
	}
	return a.d < b.d;
}
string str;
int cnt;
bool judge(double mid)
{
	int leak = 0;
	double now = mid, sp = 0;
	int s = 0;
	for (int i = 0; i < cnt; i++)
	{
		if (x[i].type == 1)
		{
			now -= ((x[i].d - s) * (sp + leak));
			s = x[i].d;
			sp = x[i].v;
			if (now < 0)
			{
				return false;
			}
		}
		else if (x[i].type == 2)
		{
			now -= ((x[i].d - s) * (sp + leak));
			s = x[i].d;
			leak++;
			if (now < 0)
			{
				return false;
			}
		}
		else if (x[i].type == 3)
		{
			now -= ((x[i].d - s) * (sp + leak));
			s = x[i].d;
			if (now < 0)
			{
				return false;
			}
			now = mid;
		}
		else if (x[i].type == 4)
		{
			now -= ((x[i].d - s) * (sp + leak));
			s = x[i].d;
			leak = 0;
			if (now < 0)
			{
				return false;
			}
		}
		else if (x[i].type == 5)
		{
			now -= ((x[i].d - s) * (sp + leak));
			s = x[i].d;
			if (now < 0)
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int d;
	double v;
	while (cin >> d >> str >> str >> v)
	{
		if (v == 0)
		{
			break;
		}
		cnt = 0;
		v /= 100.0;
		x[cnt++] = p(d, 1, v);
		while (cin >> d)
		{
			cin >> str;
			int type;
			if (str == "Fuel")
			{
				cin >> str >> v;
				v = v / 100.0;
				type = 1;
			}
			else if (str == "Leak")
			{
				type = 2;
			}
			else if (str == "Gas")
			{
				cin >> str;
				type = 3;
			}
			else if (str == "Mechanic")
			{
				type = 4;
			}
			else
			{
				type = 5;
			}
			x[cnt++] = p(d, type, v);
			if (type == 5)
			{
				break;
			}
		}
		sort(x, x + cnt, cmp);
		double l = 0, r = 10000000;
		while (r - l >= 0.0001)
		{
			double mid = (l + r) * 0.5;
			int tmp = judge(mid);
			//cout << mid << ' ' << tmp << endl;
			if (tmp == 1)
			{
				r = mid;
			}
			else
			{
				l = mid;
			}
		}
		printf("%.3f\n", l);
	}
	return 0;
}
