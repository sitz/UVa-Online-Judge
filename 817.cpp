#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define pb push_back
#define rep(i, n) REP(i, 0, n)

bool isvalid(int p, string &buf)
{
	int i = 0;
	while (i < p)
	{
		if ((i == 0 && buf[i] == '0') ||
				(i > 0 && !isdigit(buf[i - 1]) && buf[i] == '0'))
		{
			if (i + 1 < p && isdigit(buf[i + 1]))
			{
				return false;
			}
		}
		i++;
	}
	return true;
}

int num(string &in, int &p, int size)
{
	int ret = 0;
	while (p < size && isdigit(in[p]))
	{
		ret = ret * 10 + (in[p++] - '0');
	}
	return ret;
}

int fact(string &in, int &p, int size)
{
	int ret = num(in, p, size);
	while (p < size)
	{
		if (in[p] == '*')
		{
			p++;
			int tmp = num(in, p, size);
			ret *= tmp;
		}
		else
		{
			break;
		}
	}
	return ret;
}

int exp(string &in, int &p, int size)
{
	int ret = fact(in, p, size);
	while (p < size)
	{
		int sign = 1;
		if (in[p] == '+')
		{
			sign = 1;
		}
		else if (in[p] == '-')
		{
			sign = -1;
		}
		else
		{
			break;
		}
		p++;
		int tmp = fact(in, p, size);
		ret += sign * tmp;
	}
	return ret;
}

vector<string> ans;
const string op = "+-*";
void search(int now, int p, string &in, string &buf, bool fg)
{
	if (in[now] == '=')
	{
		if (!fg || !isvalid(p, buf))
		{
			return;
		}
		buf[p] = '=';
		int i = 0;
		int ret = exp(buf, i, p);
		if (ret == 2000)
		{
			ans.pb(buf.substr(0, p + 1));
		}
		return;
	}
	rep(i, 3)
	{
		buf[p] = op[i];
		buf[p + 1] = in[now];
		search(now + 1, p + 2, in, buf, true);
	}
	buf[p] = in[now];
	search(now + 1, p + 1, in, buf, fg);
}

main()
{
	string in;
	int tc = 1;
	while (getline(cin, in) && in != "=")
	{
		cout << "Problem " << tc++ << endl;
		ans.clear();
		string out(100, ' ');
		int p = 0;
		out[p++] = in[0];
		search(1, p, in, out, false);
		if (ans.size() == 0)
		{
			cout << "  IMPOSSIBLE" << endl;
		}
		else
		{
			sort(ans.begin(), ans.end());
			rep(i, ans.size()) cout << "  " << ans[i] << endl;
		}
	}
	return false;
}
