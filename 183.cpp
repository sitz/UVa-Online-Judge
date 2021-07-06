#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()
#define pb push_back

static string output2;
static char output[10000], in[1000][1000];

inline int calc(int basey, int basex, int r, int c)
{
	bool all1 = true, all0 = true;
	rep(i, r)
	{
		rep(j, c)
		{
			if (in[basey + i][basex + j] == '0')
			{
				all1 = false;
			}
			else if (in[basey + i][basex + j] == '1')
			{
				all0 = false;
			}
		}
	}
	if (all1)
	{
		return 1;
	}
	else if (all0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

inline void enc(int &p, int basey, int basex, int r, int c)
{
	int val = calc(basey, basex, r, c);
	if (val == 0)
	{
		output[p++] = '0';
	}
	else if (val == 1)
	{
		output[p++] = '1';
	}
	else
	{
		output[p++] = 'D';
		enc(p, basey, basex, r / 2 + r % 2, c / 2 + c % 2);
		if (c != 1)
		{
			enc(p, basey, basex + c / 2 + c % 2, r / 2 + r % 2, c / 2);
		}
		if (r != 1)
		{
			enc(p, basey + r / 2 + r % 2, basex, r / 2, c / 2 + c % 2);
		}
		if (c != 1 && r != 1)
		{
			enc(p, basey + r / 2 + r % 2, basex + c / 2 + c % 2, r / 2, c / 2);
		}
	}
}

inline void fillt(int basey, int basex, int r, int c, char t)
{
	rep(i, r)
	{
		rep(j, c)
		{
			in[basey + i][basex + j] = t;
		}
	}
}

inline void dec(int &p, int basey, int basex, int r, int c)
{
	if (output2[p] == 'D')
	{
		p++;
		dec(p, basey, basex, r / 2 + r % 2, c / 2 + c % 2);
		if (c != 1)
		{
			dec(p, basey, basex + c / 2 + c % 2, r / 2 + r % 2, c / 2);
		}
		if (r != 1)
		{
			dec(p, basey + r / 2 + r % 2, basex, r / 2, c / 2 + c % 2);
		}
		if (c != 1 && r != 1)
		{
			dec(p, basey + r / 2 + r % 2, basex + c / 2 + c % 2, r / 2, c / 2);
		}
	}
	else if (output2[p] == '0')
	{
		fillt(basey, basex, r, c, '0');
		p++;
	}
	else if (output2[p] == '1')
	{
		fillt(basey, basex, r, c, '1');
		p++;
	}
}

inline void getdata(int &p, int basey, int basex, int r, int c, int &cnt)
{
	if (p >= (int)output2.size())
	{
		return;
	}
	if (output2[p] == 'D')
	{
		p++;
		getdata(p, basey, basex, r / 2 + r % 2, c / 2 + c % 2, cnt);
		if (c != 1)
		{
			getdata(p, basey, basex + c / 2 + c % 2, r / 2 + r % 2, c / 2, cnt);
		}
		if (r != 1)
		{
			getdata(p, basey + r / 2 + r % 2, basex, r / 2, c / 2 + c % 2, cnt);
		}
		if (c != 1 && r != 1)
		{
			getdata(p, basey + r / 2 + r % 2, basex + c / 2 + c % 2, r / 2, c / 2, cnt);
		}
	}
	else if (output2[p] == '0')
	{
		cnt += r * c;
		p++;
	}
	else if (output2[p] == '1')
	{
		cnt += r * c;
		p++;
	}
}

int main()
{
	char type;
	int r, c;
	while (cin >> type >> r >> c && type != '#')
	{
		int p = 0;
		if (type == 'B')
		{
			rep(i, r) rep(j, c) cin >> in[i][j];
			enc(p, 0, 0, r, c);
			output[p] = '\0';
			printf("D%4d%4d\n", r, c);
			int cnt = 0;
			for (int i = 0; output[i] != '\0'; i++)
			{
				if (cnt == 50)
				{
					cout << endl, cnt = 0;
				}
				cout << output[i];
				cnt++;
			}
			cout << endl;
		}
		else if (type == 'D')
		{
			int p = 0;
			output2 = "";
			while (true)
			{
				string tmp;
				cin >> tmp;
				output2 += tmp;
				int cnt = 0;
				getdata(p, 0, 0, r, c, cnt);
				if (cnt == r * c)
				{
					break;
				}
			}
			p = 0;
			dec(p, 0, 0, r, c);
			printf("B%4d%4d\n", r, c);
			int cnt = 0;
			rep(i, r) rep(j, c)
			{
				if (cnt == 50)
				{
					cout << endl, cnt = 0;
				}
				putchar(in[i][j]);
				cnt++;
			}
			puts("");
		}
	}
	return 0;
}
