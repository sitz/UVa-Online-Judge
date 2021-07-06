#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define N 36

const ll mod = 1000000007;

ll ori[N][N] = {0}, a[N][N], b[N][N], c[N][N];
int d[] = {1, -1};

void matmul(int n, bool flag)
{
	if (flag == true)
		rep(i, n) rep(j, n) b[i][j] = a[i][j];
	else
		rep(i, n) rep(j, n) b[i][j] = ori[i][j];
	rep(i, n)
	{
		rep(j, n)
		{
			c[i][j] = 0;
			rep(k, n)
					c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
		}
	}
	rep(i, n) rep(j, n) a[i][j] = c[i][j];
}

void calc(int n, int p)
{
	if (p == 1)
	{
		matmul(n, false);
		return;
	}
	else if (p == 0)
		return;
	calc(n, p / 2);
	matmul(n, true);
	if (p % 2 == 1)
		matmul(n, false);
}

void print(int val, int a)
{
	if (a == 0)
		return;
	print(val / 2, a - 1);
	if (val % 2 == 1)
		cout << 1 << " ";
	else
		cout << 0 << " ";
}

void move4(int fromstate, int from, int tostate, int *ch, bool *data, map<int, int> &M, int now)
{
	if (now == 4)
	{
		int to;
		if (M.find(tostate) == M.end())
			M[tostate] = M.size();
		to = M[tostate];
		ori[from][to] = 1;
		return;
	}
	rep(i, 2)
	{
		int nex = ch[now] + d[i];
		if (nex < 0 || nex >= 7 || data[nex] == true)
			continue;
		data[nex] = true;
		move4(fromstate, from, (tostate | (1 << nex)), ch, data, M, now + 1);
		data[nex] = false;
	}
}

void choose4(int last, int now, int state, map<int, int> &M, int *ch)
{
	if (now == 4)
	{
		int from;
		bool data[7] = {false};
		if (M.find(state) == M.end())
			M[state] = M.size();
		from = M[state];
		move4(state, from, 0, ch, data, M, 0);
		return;
	}
	REP(i, last, 7)
	{
		ch[now] = i;
		choose4(i + 1, now + 1, (state | (1 << i)), M, ch);
	}
}

int main()
{
	int ch[4];
	map<int, int> M;
	choose4(0, 0, 0, M, ch);
	int te;
	cin >> te;
	while (te--)
	{
		int p;
		cin >> p;
		int state = 0;
		int mul = 0;
		for (int i = 6; i >= 0; i--)
		{
			int tmp;
			cin >> tmp;
			if (tmp != 0)
				state |= (1 << i);
		}
		rep(i, N) rep(j, N) a[i][j] = 0;
		mul = M[state];
		rep(i, N) a[i][i] = 1;
		calc(N, p - 1);
		ll ans = 0;
		rep(i, N) ans = (ans + a[mul][i]) % mod;
		cout << ans << endl;
	}
	return 0;
}
