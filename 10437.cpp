#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
typedef long long ll;
typedef pair<ll, ll> frac;
#define nu first
#define de second//  n/d
bool flag;

ll gcd(ll a, ll b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}

void adjust(frac &a)
{
	if (a.de < 0)
	{
		a.nu *= -1, a.de *= -1;
	}
	int val = a.nu < 0 ? a.nu * -1 : a.nu;
	int g = gcd(val, a.de);
	a.nu /= g;
	a.de /= g;
	if (a.de == 0)
	{
		flag = false;
	}
	return;
}

frac exp(string &t, int &p);

frac num(string &t, int &p)
{
	frac ret(0, 0);
	if (t[p] == '(')
	{
		p++;
		ret = exp(t, p);
		p++;
		adjust(ret);
		return ret;
	}
	while (p < t.size() && isdigit(t[p]))
	{
		ret.nu = ret.nu * 10 + t[p++] - '0';
	}
	if (p < t.size() && t[p] == '|')
	{
		p++;
		while (p < t.size() && isdigit(t[p]))
		{
			ret.de = ret.de * 10 + t[p++] - '0';
		}
	}
	else
	{
		ret.de = 1;
	}
	adjust(ret);
	return ret;
}

frac fact(string &t, int &p)
{
	frac tmp, ret = num(t, p);
	while (p < t.size() && flag)
	{
		if (t[p] == '*')
		{
			p++;
			tmp = num(t, p);
			if (flag == false || tmp.de == 0)
			{
				flag = false;
				return ret;
			}
			ret.nu *= tmp.nu;
			ret.de *= tmp.de;
			adjust(ret);
		}
		else if (t[p] == '/')
		{
			p++;
			tmp = num(t, p);
			if (flag == false || tmp.de == 0)
			{
				flag = false;
				return ret;
			}
			ret.nu *= tmp.de;
			ret.de *= tmp.nu;
			adjust(ret);
		}
		else
		{
			break;
		}
	}
	return ret;
}

frac exp(string &t, int &p)
{
	frac tmp, ret = fact(t, p);
	ll a;
	while (p < t.size())
	{
		if (t[p] == '+')
		{
			p++;
			tmp = fact(t, p);
			if (flag == false || tmp.de == 0)
			{
				flag = false;
				return ret;
			}
			a = ret.nu * tmp.de + ret.de * tmp.nu;
			ret.nu = a;
			ret.de *= tmp.de;
			adjust(ret);
		}
		else if (t[p] == '-')
		{
			p++;
			tmp = fact(t, p);
			if (flag == false || tmp.de == 0)
			{
				flag = false;
				return ret;
			}
			a = ret.nu * tmp.de - ret.de * tmp.nu;
			ret.nu = a;
			ret.de *= tmp.de;
			adjust(ret);
		}
		else
		{
			break;
		}
	}
	return ret;
}

main()
{
	string t, sol;
	int p;
	while (getline(cin, t))
	{
		sol.clear();
		p = 0;
		while (p < t.size())
		{
			if (isdigit(t[p]) || t[p] == '|' ||
					t[p] == '(' || t[p] == ')' ||
					t[p] == '+' || t[p] == '-' ||
					t[p] == '*' || t[p] == '/')
			{
				sol += t[p++];
			}
			else
			{
				p++;
			}
		}
		p = 0;
		flag = true;
		frac ret = exp(sol, p);
		if (flag)
		{
			cout << ret.nu;
			if (ret.nu != 0 && ret.de != 1)
			{
				cout << '|' << ret.de;
			}
			cout << endl;
		}
		else
		{
			puts("INVALID");
		}
	}
}
