#include <bits/stdc++.h>

using namespace std;

int n, m;
int id(int a, int b)
{
	return a * m + b;
}

struct State
{
	int w, step;
	string s, op;
	State(string s = " ", int w = 0, int step = 0)
			: s(s), w(w), step(step)
	{
		op.clear();
	}
	bool operator<(const State &b) const
	{
		return s < b.s || (s == b.s && w < b.w);
	}
};
set<State> dic;

int fall(string &s)
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			int L = id(i, j);
			if (s[L] == '@' || s[L] == 'O')
			{
				int wh = L + m;
				while (wh < m * n && s[wh] == '.')
				{
					wh += m;
				}
				wh -= m;
				if (L != wh)
				{
					// wh might == L; swap is a good way to change
					swap(s[L], s[wh]);
				}
			}
			else if (s[L] == '[')
			{
				for (int k = j + 1; k < m; k++)
				{
					int R = id(i, k);
					if (s[R] == 'X')
					{
						break;
					}
					if (s[R] == ']')// from (i,j) to (i,k)
					{
						int to = 0;
						for (int l = i + 1; l < n; l++)// check if (l,j) to (l,k) is empty
						{
							bool ok = true;
							for (int ii = j; ii <= k; ii++)
							{
								if (s[id(l, ii)] != '.')
								{
									ok = false;
									break;
								}
							}
							if (!ok)
							{
								to = l - 1;
								break;
							}
						}
						if (to != i)
						{
							for (int l = j; l <= k; l++)
							{
								swap(s[id(i, l)], s[id(to, l)]);
							}
						}
						j = k;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '@')
		{
			return i;
		}
	}
	return -1;
}

void lnk_right(char &c)
{
	if (c == ']')
	{
		c = '=';
	}
	else if (c == 'O')
	{
		c = '[';
	}
}

void lnk_left(char &c)
{
	if (c == '[')
	{
		c = '=';
	}
	else if (c == 'O')
	{
		c = ']';
	}
}

bool solve_magic(State &s, int x, int y)
{
	int the = id(x, y);
	if (s.s[the] == 'X')
	{
		return false;
	}
	if (s.s[the] == '.')
	{
		if (s.s[the - 1] != '.' && s.s[the + 1] != '.')
		{
			s.s[the] = '=', lnk_right(s.s[the - 1]), lnk_left(s.s[the + 1]);
		}
		else if (s.s[the - 1] != '.')
		{
			s.s[the] = ']', lnk_right(s.s[the - 1]);
		}
		else if (s.s[the + 1] != '.')
		{
			s.s[the] = '[', lnk_left(s.s[the + 1]);
		}
		else
		{
			s.s[the] = 'O';
		}
	}
	else
	{
		s.s[the] = '.';
		if (s.s[the - 1] == '=')
		{
			s.s[the - 1] = ']';
		}
		if (s.s[the - 1] == '[')
		{
			s.s[the - 1] = 'O';
		}
		if (s.s[the + 1] == '=')
		{
			s.s[the + 1] = '[';
		}
		if (s.s[the + 1] == ']')
		{
			s.s[the + 1] = 'O';
		}
	}
	s.w = fall(s.s);
	return true;
}

bool solve_mv(State &s, int k)
{
	int the = s.w + k;
	if (s.s[the] == '.')
	{
		swap(s.s[s.w], s.s[the]);
	}
	else if (s.s[the] == 'O' && s.s[the + k] == '.')
	{
		int wh = the;
		while (s.s[wh + k] == '.')
		{
			wh += k;
			if (s.s[wh + m] == '.')
			{
				break;
			}
		}
		swap(s.s[the], s.s[wh]);
	}
	else if (s.s[the - m] == '.' && s.s[s.w - m] == '.')
	{
		swap(s.s[s.w], s.s[the - m]);
	}
	else
	{
		return false;
	}
	s.w = fall(s.s);
	return true;
}

int main()
{
	int t = 0;
	while (scanf("%d%d", &n,&m) == 2, n)
	{
		dic.clear();
		string s;
		char line[m];
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", &line);
			s += line;
		}
		int S = 0, T = 0, tx, ty;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '@')
			{
				S = i;
			}
			else if (s[i] == '#')
			{
				T = i, s[i] = '.';
			}
		}
		tx = T / m;
		ty = T % m;
		queue<State> q;
		q.push(State(s, S, 0));
		printf("Case %d: ", ++t);
		while (!q.empty())
		{
			State now = q.front(), ne;
			q.pop();
			if (now.w == T)
			{
				printf("%s", now.op.c_str());
				break;
			}
			int x = now.w / m, y = now.w % m;
			if (abs(y - ty) + now.step > 15)
			{
				continue;
			}
			ne = now;
			if (solve_magic(ne, x + 1, y + 1))
			{
				ne.op.push_back('>');
				ne.step++;
				if (dic.count(ne) == 0)
				{
					dic.insert(ne);
					q.push(ne);
				}
			}
			ne = now;
			if (solve_magic(ne, x + 1, y - 1))
			{
				ne.op.push_back('<');
				ne.step++;
				if (dic.count(ne) == 0)
				{
					dic.insert(ne);
					q.push(ne);
				}
			}
			ne = now;
			if (solve_mv(ne, -1))
			{
				ne.op.push_back('L');
				if (dic.count(ne) == 0)
				{
					dic.insert(ne);
					q.push(ne);
				}
			}
			ne = now;
			if (solve_mv(ne, +1))
			{
				ne.op.push_back('R');
				if (dic.count(ne) == 0)
				{
					dic.insert(ne);
					q.push(ne);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
