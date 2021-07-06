#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const int N = 2000001;
bool a[N];
int b[N];
//index = 148933
int generate()
{
	for (int i = 1; i < N; i += 1)
	{
		a[i] = true;
	}
	for (int i = 3; i * i <= N; i += 2)
	{
		for (int j = 2 * i; j < N; j += i)
		{
			a[j] = false;
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

int ansindex = 0;
pair<int, int> ans[N];
void aho(int now, int maxi, int cnt, int index)
{
	if (ans[now].first != -1)
	{
		return;
	}
	ans[now].first = cnt;
	ans[now].second = now;
	for (int i = 0; i < index && now * b[i] <= N; i++)
	{
		aho(now * b[i], maxi, cnt + 1, index);
	}
}

main()
{
	int index = generate();
	rep(i, N) ans[i].first = -1;
	aho(1, 21, 0, index);
	ans[0] = make_pair(10000, 0);
	sort(ans, ans + N);
	int n;
	int tc = 1;
	while (scanf("%d", &n) && n)
	{
		printf("Case %d: %d\n", tc++, ans[n - 1].second);
	}
}
