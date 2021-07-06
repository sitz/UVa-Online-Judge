#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define pb push_back

//typedef long long ll;
typedef int ll;
//const int N = 17576001;
const int N = 100000;
vector<int> edge[N];
int deg[N];
ll val[N];
string inp[N];

ll getnum(string &in, int &p)
{
	int sign = 1;
	if (in[p] == '-')
	{
		sign = -1, p++;
	}
	ll ret = 0;
	while (p < (int)in.size() && isdigit(in[p]))
	{
		ret = ret * 10 + in[p++] - '0';
	}
	return ret * sign;
}

//need test??
int convert(string &in)
{
	int ret = 0;
	int mul = 1;
	for (int i = (int)in.size() - 1; i >= 0; i--)
	{
		ret += mul * (in[i] - 'A' + 1);
		mul = mul * 26;
	}
	return ret - 1;
}

int getcell(string &in, int &p, int c)
{
	string ret = "";
	int val = 0;
	if (in[p] == '-')
	{
		p++;
	}
	while (p < (int)in.size() && isalpha(in[p]))
	{
		ret += in[p++];
	}
	val = getnum(in, p);
	return convert(ret) + (val - 1) * c;//column+row*c
}

void readdata(string &in, int now, int c)
{
	if (in[0] == 'e')
	{
		in = in.substr(2, in.size() - 3);
		int p = 0;
		while (p < (int)in.size())
		{
			if (isdigit(in[p]))
			{
				val[now] = getnum(in, p);
			}
			else if (isalpha(in[p]))
			{
				deg[now]++;
				int tmp = getcell(in, p, c);
				edge[tmp].pb(now);
			}
			else
			{
				p++;
			}
		}
	}
	else
	{
		int p = 0;
		val[now] = getnum(in, p);
	}
}

ll exp(string &in, int &p, int c);
ll fact(string &in, int &p, int c);
ll num(string &in, int &P, int c);

ll exp(string &in, int &p, int c)
{
	ll ret = fact(in, p, c);
	while (p < (int)in.size())
	{
		if (in[p] == '+')
		{
			p++;
			ret += fact(in, p, c);
		}
		else if (in[p] == '-')
		{
			p++;
			ret -= fact(in, p, c);
		}
		else
		{
			break;
		}
	}
	return ret;
}

ll fact(string &in, int &p, int c)
{
	ll ret = num(in, p, c);
	while (p < (int)in.size())
	{
		if (in[p] == '*')
		{
			p++;
			ret *= num(in, p, c);
		}
		else if (in[p] == '/')
		{
			p++;
			ret /= num(in, p, c);
		}
		else if (in[p] == '%')
		{
			p++;
			ret %= num(in, p, c);
		}
		else
		{
			break;
		}
	}
	return ret;
}

ll num(string &in, int &p, int c)
{
	ll ret = 0;
	if (in[p] == '(')
	{
		p++;
		ret = exp(in, p, c);
		p++;
	}
	else if (isdigit(in[p]))
	{
		ret = getnum(in, p);
	}
	else if (isalpha(in[p]))
	{
		int tmp = getcell(in, p, c);
		ret = val[tmp];
	}
	else if (p == 0 && in[p] == '-')//必要ないっぽい
	{
		p++;
		ret = num(in, p, c);
	}
	return ret;
}

void solve(int r, int c)
{
	queue<int> Q;
	rep(i, r * c) if (deg[i] == 0)
	{
		Q.push(i);
	}
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		rep(i, (int)edge[now].size())
		{
			int next = edge[now][i];
			deg[next]--;
			if (deg[next] == 0)
			{
				int p = 0;
				val[next] = exp(inp[next], p, c);
				Q.push(next);
			}
		}
	}
}

main()
{
	int te;
	cin >> te;
	while (te--)
	{
		int r, c;
		cin >> r >> c;
		rep(i, r * c) edge[i].clear(), deg[i] = 0, val[i] = 0;
		rep(i, r * c)
		{
			cin >> inp[i];
			bool isexp = inp[i][0] == 'e';
			readdata(inp[i], i, c);
			if (isexp && deg[i] == 0)
			{
				int p = 0;
				val[i] = exp(inp[i], p, c);
			}
		}
		solve(r, c);
		rep(i, r)
		{
			rep(j, c)
			{
				if (j)
				{
					cout << " ";
				}
				//assert(deg[i*c+j] <= 0);//Runtime Error!
				cout << val[i * c + j];
				//cout<< deg[i*c+j];
			}
			cout << endl;
		}
		if (te)
		{
			cout << endl;
		}
	}
	return false;
}
