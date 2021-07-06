#include <bits/stdc++.h>

using namespace std;

#define REP(i, e) for (int i = 0; i < (int)(e); i++)
#define FOR(i, b, e) for (int i = (int)(b); i < (int)(e); i++)

template <class T>
void ls(T &a, T b)
{
	if (b < a)
	{
		a = b;
	}
}

const int N = 512;

char v[N][N];
int l[N][N];
int r[N][N];
int u[N][N];
int d[N][N];

int square(int n)
{
	int ans = 0;
	int k, t;
	REP(i, n)
	REP(j, n)
	{
		for (k = 1, t = r[i][j]; t >= k; t = min(t, r[i + k][j]), k++)
		{
		}
		if (k >= 2)
		{
			ans += k - 2;
		}
	}
	return ans;
}

int diamond(int n)
{
	int ans = 0;
	REP(i, n)
	REP(j, n)
	{
		int t = min(min(l[i][j], r[i][j]), min(u[i][j], d[i][j])), k;
		for (k = 1; 0 <= i - k && i + k < n && 0 <= j - k && j + k < n && t > 1; k++)
			t = min(t, k - 1 + min(min(min(l[i - k][j], r[i - k][j]), min(l[i + k][j], r[i + k][j])),
														 min(min(u[i][j - k], d[i][j - k]), min(u[i][j + k], d[i][j + k]))));
		if (k >= 2)
		{
			ans += min(t, k - 1);
		}
	}
	return ans;
}

int brute_force(int n)
{
	if (n == 500)
	{
		return 0;
	}
	int a = 0, b = 0;
	REP(i, n)
	REP(j, n) FOR(k, 2, n + 1)
	{
		int cnt = 0;
		FOR(ii, i, i + k)
		FOR(jj, j, j + k) if (v[ii][jj] == 'x')
		{
			cnt++;
		}
		if (cnt == k * k)
		{
			a++;
		}
	}
	REP(i, n)
	REP(j, n) FOR(k, 1, n + 1)
	{
		FOR(ii, i - k, i + k + 1)
		FOR(jj, j - k, j + k + 1)
		{
			if (!(0 <= ii && ii < n && 0 <= jj && jj < n))
			{
				goto bad;
			}
			if (abs(ii - i) + abs(jj - j) <= k && v[ii][jj] != 'x')
			{
				goto bad;
			}
		}
		b++;
	bad:;
	}
	return a + b;
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		memset(v, '.', sizeof v);
		REP(i, n)
		scanf("%s", v[i]);
		memset(l, 0, sizeof l);
		memset(r, 0, sizeof r);
		memset(u, 0, sizeof u);
		memset(d, 0, sizeof d);
		REP(i, n)
		{
			int cnt;
			cnt = 0;
			for (int j = n - 1; j >= 0; j--)
			{
				cnt = (v[i][j] == 'x' ? cnt + 1 : 0);
				r[i][j] = cnt;
			}
			cnt = 0;
			for (int j = n - 1; j >= 0; j--)
			{
				cnt = (v[j][i] == 'x' ? cnt + 1 : 0);
				d[j][i] = cnt;
			}
			cnt = 0;
			REP(j, n)
			{
				cnt = (v[i][j] == 'x' ? cnt + 1 : 0);
				l[i][j] = cnt;
			}
			cnt = 0;
			REP(j, n)
			{
				cnt = (v[j][i] == 'x' ? cnt + 1 : 0);
				u[j][i] = cnt;
			}
		}
		cout << square(n) + diamond(n) << endl;
	}
}
