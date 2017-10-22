#include <bits/stdc++.h>

using namespace std;

string tt[4] = {"O", "A", "B", "AB"};
bitset<4> cc(int p1, int p2)
{
	if (p1 > p2)
	{
		return cc(p2, p1);
	}
	try
	{
		switch (p1)
		{
		case 0:
		{
			if (p2 == 0)
			{
				throw "1000";
			}
			if (p2 == 1)
			{
				throw "1100";
			}
			if (p2 == 2)
			{
				throw "1010";
			}
			if (p2 == 3)
			{
				throw "0110";
			}
		}
		case 1:
		{
			if (p2 == 1)
			{
				throw "1100";
			}
			if (p2 == 2)
			{
				throw "1111";
			}
			if (p2 == 3)
			{
				throw "0111";
			}
		}
		case 2:
		{
			if (p2 == 2)
			{
				throw "1010";
			}
			if (p2 == 3)
			{
				throw "0111";
			}
		}
		case 3:
			throw "0111";
		}
	}
	catch (const char *a)
	{
		string s(a);
		reverse(s.begin(), s.end());
		return bitset<4>(s);
	}
}
int abo(string s)
{
	int t = 0;
	if (strchr(s.c_str(), 'A'))
	{
		t |= 1;
	}
	if (strchr(s.c_str(), 'B'))
	{
		t |= 2;
	}
	return t;
}
string dc(string p1, string p2)
{
	bitset<4> a(cc(abo(p1), abo(p2)));
	ostringstream oss;
	for (int i = 0; i < 4; ++i)
		if (a[i])
		{
			oss << tt[i] + "-, ";
		}
	if (*p1.rbegin() == '+' || *p2.rbegin() == '+')
		for (int i = 0; i < 4; ++i)
			if (a[i])
			{
				oss << tt[i] + "+, ";
			}
	string x = oss.str();
	x = x.substr(0, x.length() - 2);
	if (strchr(x.c_str(), ','))
	{
		x = "{" + x + "}";
	}
	return x;
}
string dp(string p, string c)
{
	ostringstream oss;
	for (int i = 0; i < 4; ++i)
		if (cc(abo(p), i)[abo(c)])
		{
			oss << tt[i] + "+, ";
			if (*p.rbegin() != '-' || *c.rbegin() != '+')
			{
				oss << tt[i] + "-, ";
			}
		}
	string x = oss.str();
	if (!x.length())
	{
		return "IMPOSSIBLE";
	}
	x = x.substr(0, x.length() - 2);
	if (strchr(x.c_str(), ','))
	{
		x = "{" + x + "}";
	}
	return x;
}
int main()
{
	string p1, p2, c;
	for (int Tc = 1; cin >> p1 >> p2 >> c; ++Tc)
	{
		if (p1 == "E" && p2 == "N" && c == "D")
		{
			return 0;
		}
		if (c == "?")
		{
			c = dc(p1, p2);
		}
		if (p1 == "?")
		{
			p1 = dp(p2, c);
		}
		if (p2 == "?")
		{
			p2 = dp(p1, c);
		}
		cout << "Case " << Tc << ": " << p1 << " "
				 << p2 << " " << c << endl;
	}
}
