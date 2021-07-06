#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define N 2097152

int data[N] = {0};
bool used[N];

inline void construct(int n)
{
	int def = (1 << n);
	int div = (1 << n);
	int now = div - 1;
	fill(used, used + (1 << n), false);
	used[now] = true;
	REP(i, (1 << n) - n, (1 << n))
	{
		data[i] |= def;
		now = (now * 2) % div;
		used[now] = true;
	}
	REP(i, n, (1 << n) - n)
	{
		now = (now * 2) % div;
		if (used[now] == false)//put 0
		{
		}
		else//put 1
		{
			now += 1;
			data[i] |= def;
		}
		used[now] = true;
	}
}

int main()
{
	REP(i, 1, 22)
	{
		construct(i);
	}
	int te;
	cin >> te;
	while (te--)
	{
		int n, k;
		cin >> n >> k;
		int ans = 0;
		int def = (1 << n);
		rep(i, n)
		{
			int now = (k + i) % def;
			ans *= 2;
			if ((data[now] & def) == 0)
				;
			else
			{
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
