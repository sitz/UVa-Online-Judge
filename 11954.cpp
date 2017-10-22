#include <bits/stdc++.h>

using namespace std;

#define SZ(s) s.length()
#define rep(i, n) for (int i = 0; i < n; i++)

string in;
int pos;

string number()
{
	string ret;
	while (pos < SZ(in) && isdigit(in[pos]))
	{
		ret += in[pos++];
	}
	while (SZ(ret) > 1 && ret[0] == '0')
	{
		ret = ret.substr(1);
	}
	return ret;
}

string token()
{
	string ret;
	if (isdigit(in[pos]))
	{
		return number();
	}
	string op = in.substr(pos, 3);
	pos += 3;
	ret = token();
	if (op == "not")
	{
		rep(i, SZ(ret))
		{
			if (ret[i] == '0')
			{
				ret[i] = '1';
			}
			else
			{
				ret[i] = '0';
			}
		}
	}
	else if (op == "shr")
	{
		if (SZ(ret) > 1)
		{
			ret = ret.substr(0, SZ(ret) - 1);
		}
		else
		{
			ret = "0";
		}
	}
	else
	{
		ret += '0';
		while (SZ(ret) > 1 && ret[0] == '0')
		{
			ret = ret.substr(1);
		}
	}
	while (SZ(ret) > 1 && ret[0] == '0')
	{
		ret = ret.substr(1);
	}
	return ret;
}

string expression()
{
	string ret = token();
	string li;
	while (pos < in.size())
	{
		li = ret;
		ret = "";
		string op;
		if (in[pos] != 'o')
		{
			op = in.substr(pos, 3);
			pos += 3;
		}
		else
		{
			op = in.substr(pos, 2);
			pos += 2;
		}
		string ri = token();
		int sz = max(SZ(li), SZ(ri));
		while (SZ(ri) < sz)
		{
			ri = '0' + ri;
		}
		while (SZ(li) < sz)
		{
			li = '0' + li;
		}
		if (op == "or")
		{
			rep(i, SZ(li))
			{
				if (li[i] == '1' || ri[i] == '1')
				{
					ret += '1';
				}
				else
				{
					ret += '0';
				}
			}
		}
		else if (op == "and")
		{
			rep(i, SZ(li))
			{
				if (li[i] == '1' && ri[i] == '1')
				{
					ret += '1';
				}
				else
				{
					ret += '0';
				}
			}
		}
		else
		{
			rep(i, SZ(li))
			{
				if (li[i] + ri[i] - 2 * '0' == 1)
				{
					ret += '1';
				}
				else
				{
					ret += '0';
				}
			}
		}
	}
	while (SZ(ret) > 1 && ret[0] == '0')
	{
		ret = ret.substr(1);
	}
	return ret;
}

int main()
{
	int test;
	cin >> test;
	cin.ignore();
	rep(ca, test)
	{
		cout << "Case " << ca + 1 << ": ";
		string temp;
		getline(cin, temp);
		in = "";
		pos = 0;
		rep(i, SZ(temp)) if (temp[i] != ' ')
		{
			in += temp[i];
		}
		string ans = expression();
		cout << ans << endl;
	}
	return 0;
}
