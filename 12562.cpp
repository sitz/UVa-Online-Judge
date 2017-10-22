#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

//int __builtin_popcount (unsigned int x)
//# 1-bits in x
inline int popcount(int x)
{
	x = ((x >> 1) & 0x55555555) + (x & 0x55555555);
	x = ((x >> 2) & 0x33333333) + (x & 0x33333333);
	x = ((x >> 4) + x) & 0x0f0f0f0f;
	x += (x >> 8);
	x += (x >> 16);
	return x & 0x3f;
}

int expr(const char *, int &, int);

int number(const char *s, int &idx)
{
	int n = 0;
	while ('0' <= s[idx] && s[idx] <= '9')
	{
		n = n * 10 + (s[idx++] - '0');
	}
	return n;
}

int primary(const char *s, int &idx, int S)
{
	if (s[idx] == '(')
	{
		idx++;
		int a = expr(s, idx, S);
		idx++;
		return a;
	}
	else
	{
		idx++;
		int n = number(s, idx);
		return S >> (n - 1) & 1;
	}
}

int factor(const char *s, int &idx, int S)
{
	if (s[idx] == '!')
	{
		idx++;
		return !primary(s, idx, S);
	}
	else
	{
		return primary(s, idx, S);
	}
}

int term(const char *s, int &idx, int S)
{
	int a = factor(s, idx, S);
	while (s[idx] == '&')
	{
		idx += 2;
		a &= factor(s, idx, S);
	}
	return a;
}

int expr(const char *s, int &idx, int S)
{
	int a = term(s, idx, S);
	while (s[idx] == '|')
	{
		idx += 2;
		a |= term(s, idx, S);
	}
	return a;
}

int equation(const char *s, int S)
{
	int idx;
	for (idx = 0; s[idx] != '='; idx++)
		;
	idx++;
	return expr(s, idx, S);
}

int x, y, z;
char b[15][512], c[15][512];

int b_ini[15];

int parse(int a_S)
{
	int b_res[15];
	rep(i, y)
			b_res[i] = equation(b[i], a_S);
	rep(i, y) if (b[i][0] == '*' && b_res[i] != b_ini[i])
	{
		return 0;
	}
	int b_S = 0;
	rep(i, y) b_S |= b_res[i] << i;
	int c_res[15];
	rep(i, z) c_res[i] = equation(c[i], b_S);
	int c_S = 0;
	rep(i, z) c_S |= c_res[i] << i;
	return c_S;
}

void solve()
{
	scanf("%d%d%d", &x, &y, &z);
	int a[15];
	rep(i, x) scanf("%d", a + i);
	rep(i, y) scanf("%s", b[i]);
	rep(i, z) scanf("%s", c[i]);
	int S_ini = 0;
	rep(i, x) S_ini |= a[i] << i;
	rep(i, y) b_ini[i] = equation(b[i], S_ini);
	int ini = parse(S_ini);
	int ans = ini, S_ans;
	rep(S, 1 << x)
	{
		int tmp = parse(S_ini ^ S);
		if (popcount(tmp) > popcount(ans) || popcount(tmp) == popcount(ans) && popcount(S) < popcount(S_ans))
		{
			ans = tmp, S_ans = S;
		}
	}
	if (ans == ini)
		puts("Unable to improve future.\n");
	else
	{
		printf("Increased from %d to %d.\n", popcount(ini), popcount(ans));
		int sz = popcount(S_ans);
		rep(i, x) if (S_ans >> i & 1)
		{
			printf("a%d%c", i + 1, sz > 1 ? ' ' : '\n'), sz--;
		}
		puts("");
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		printf("Case %d: ", cas), solve();
	}
	return 0;
}
