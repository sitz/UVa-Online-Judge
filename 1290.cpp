#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define REP(i, l, r) for ((i) = (l); (i) <= (r); ++(i))
#define REP2(i, l, r) for ((i) = (l); (i) != (r); ++(i))

typedef long long LL;
typedef double ld;

const int MAX = 100000 + 10;

int n, m;
LL a[MAX], b[MAX], ta[MAX], tb[MAX];

int check(int now)
{
	while (n && m)
	{
		if (now == 1)
		{
			if (a[n] > b[m])
			{
				--m;
			}
			else
			{
				--n;
				a[n] += a[n + 1];
			}
		}
		else
		{
			if (b[m] > a[n])
			{
				--n;
			}
			else
			{
				--m;
				b[m] += b[m + 1];
			}
		}
		now ^= 1;
	}
	if (n)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int Test = 0;
	while (cin >> n >> m)
	{
		int i;
		REP(i, 1, n)
		cin >> a[i];
		sort(a + 1, a + n + 1);
		ta[0] = n;
		REP(i, 1, n)
		ta[i] = a[i];
		REP(i, 1, m)
		cin >> b[i];
		sort(b + 1, b + m + 1);
		tb[0] = m;
		REP(i, 1, m)
		tb[i] = b[i];
		int flag = 0;
		if (a[n] > b[m])
		{
			--m;
			flag |= check(0);
		}
		n = ta[0];
		REP(i, 1, n)
		a[i] = ta[i];
		m = tb[0];
		REP(i, 1, m)
		b[i] = tb[i];
		--n;
		a[n] += a[n + 1];
		flag |= check(0);
		printf("Case %d: ", ++Test);
		if (flag)
		{
			cout << "Takeover Incorporated" << endl;
		}
		else
		{
			cout << "Buyout Limited" << endl;
		}
	}
	return 0;
}
