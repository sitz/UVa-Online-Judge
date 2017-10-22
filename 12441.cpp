#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

struct State
{
	int a, b, c;
	State(int _a, int _b, int _c) : a(_a), b(_b), c(_c)
	{
	}
	State()
	{
	}
};
State prev_[110][110][310], que[110 * 110 * 310], st;

int La, Lb, Lc, mark[110][110][310] = {}, cmark, dist[110][110][310], way[110][110][310], qh, qt, nxt[310][256];
string A, B, C;

void visit(int a, int b, int c, int d, int w)
{
	if (c > Lc)
	{
		return;
	}
	if (mark[a][b][c] != cmark)
	{
		mark[a][b][c] = cmark;
		dist[a][b][c] = d;
		way[a][b][c] = w;
		prev_[a][b][c] = st;
		que[qt++] = State(a, b, c);
	}
	else if (dist[a][b][c] == d)
	{
		int &ref = way[a][b][c];
		ref += w;
		if (ref >= MOD)
		{
			ref -= MOD;
		}
	}
}

void work()
{
	cin >> A >> B >> C;
	La = A.size(), Lb = B.size(), Lc = C.size();
	fill(nxt[Lc], nxt[Lc] + 256, Lc);
	for (int i = Lc - 1; i >= 0; --i)
	{
		memcpy(nxt[i], nxt[i + 1], sizeof nxt[i]);
		nxt[i][C[i]] = i;
	}
	++cmark;
	dist[0][0][0] = 0;
	way[0][0][0] = 1;
	mark[0][0][0] = cmark;
	qh = qt = 0;
	que[qt++] = State(0, 0, 0);
	int ret = -1;
	State last;
	while (qh < qt)
	{
		st = que[qh++];
		int a = st.a, b = st.b, c = st.c;
		int d = dist[a][b][c], w = way[a][b][c];
		if (ret != -1 && d > ret)
		{
			break;
		}
		if (a == La && b == Lb)
		{
			if (ret == -1)
			{
				last = st;
				ret = d;
			}
			continue;
		}
		if (a == La)
		{
			visit(a, b + 1, nxt[c][B[b]] + 1, d + 1, w);
			continue;
		}
		if (b == Lb)
		{
			visit(a + 1, b, nxt[c][A[a]] + 1, d + 1, w);
			continue;
		}
		if (A[a] != B[b])
		{
			if (A[a] < B[b])
			{
				visit(a + 1, b, nxt[c][A[a]] + 1, d + 1, w);
				visit(a, b + 1, nxt[c][B[b]] + 1, d + 1, w);
			}
			else
			{
				visit(a, b + 1, nxt[c][B[b]] + 1, d + 1, w);
				visit(a + 1, b, nxt[c][A[a]] + 1, d + 1, w);
			}
			continue;
		}
		visit(a + 1, b + 1, nxt[c][A[a]] + 1, d + 1, w);
	}
	if (ret == -1)
	{
		cout << 0 << endl;
		cout << "NOT FOUND" << endl;
		return;
	}
	// calc ans
	int ans = 0;
	for (int i = 0; i <= Lc; ++i)
	{
		if (mark[La][Lb][i] == cmark && dist[La][Lb][i] == ret)
		{
			ans += way[La][Lb][i];
			ans %= MOD;
		}
	}
	cout << ans << endl;
	string s = "";
	while (last.c != 0)
	{
		s += C[last.c - 1];
		last = prev_[last.a][last.b][last.c];
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		printf("Case %d: ", i);
		work();
	}
	return 0;
}
