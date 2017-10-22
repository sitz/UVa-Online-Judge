#include <bits/stdc++.h>

using namespace std;

int N, M;
int maxs[11];
int data[5000];
int cnt;

void init()
{
	cnt = 0;
	for (int i = 0; i < maxs[N]; i++)
	{
		data[i] = true;
	}
}

bool func(int now)
{
	if (now * 2 >= maxs[N])
	{
		return data[now];
	}
	bool f1, f2;
	f1 = func(now * 2);
	f2 = func(now * 2 + 1);
	if (f1 && f2)
	{
		return true;
	}
	else if (f1 || f2)
	{
		cnt++;
		return true;
	}
	else
	{
		return false;
	}
}

void solve()
{
	cin >> N >> M;
	init();
	for (int i = 0; i < M; i++)
	{
		int in;
		cin >> in;
		data[maxs[N] - in] = false;
	}
	func(1);
	cout << cnt << endl;
}

int main()
{
	int t;
	maxs[0] = 2;
	for (int i = 1; i <= 11; i++)
	{
		maxs[i] = maxs[i - 1] * 2;
	}
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		solve();
	}
	return 0;
}
