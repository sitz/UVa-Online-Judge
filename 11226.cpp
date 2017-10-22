#include <bits/stdc++.h>

using namespace std;

#define N 500001
#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
int a[N];
int b[N];
int table[N];
int val[N];

int generate()
{
	for (int i = 2; i < N; i += 2)
	{
		a[i] = 0;
	}
	for (int j = 1; j < N; j += 2)
	{
		a[j] = 1;
	}
	for (int i = 3; i * i <= N; i += 2)
	{
		if (a[i] == 1)
			for (int j = 2 * i; j < N; j += i)
			{
				a[j] = 0;
			}
	}
	int index = 0;
	b[index++] = 2;
	for (int i = 3; i < N; i += 2)
		if (a[i])
		{
			b[index++] = i;
		}
	return index;
}

void precalc(int *table, int tar, int index)
{
	int n = tar, val = 0;
	for (int i = 0; i < index && b[i] * b[i] <= n; i++)
	{
		if (n % b[i] == 0)
		{
			while (true)
			{
				if (n / b[i] == 0 || n % b[i] != 0)
				{
					break;
				}
				val += b[i];
				n /= b[i];
			}
		}
	}
	if (n != 1)
	{
		val += n;
	}
	table[tar] = val;
	return;
}

void construct(int *table, int index)
{
	REP(i, 2, N)
	{
		precalc(table, i, index);
	}
}

int solve(int *val, int *table, int step, int now)
{
	if (val[now] != -1)
	{
		return val[now];
	}
	int next = table[now];
	if (now == next)
	{
		return val[now] = step;
	}
	val[now] = solve(val, table, step + 1, next) + step;
	return val[now];
}

main()
{
	int index = generate();
	construct(table, index);
	fill(val, val + N, -1);
	REP(i, 2, N)
	{
		if (val[i] != -1)
		{
			continue;
		}
		solve(val, table, 1, i);
	}
	int tc = 1, te;
	cin >> te;
	while (te--)
	{
		int a, b;
		cin >> a >> b;
		if (b < a)
		{
			swap(a, b);
		}
		int ans = 0;
		REP(i, a, b + 1)
		ans = max(ans, val[i]);
		cout << "Case #" << tc++ << ":" << endl
				 << ans << endl;
	}
	return false;
}
