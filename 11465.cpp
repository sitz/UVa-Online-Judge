#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 1 << 6;
LL a[N], C[N][N];

LL dfs(const LL &remain, int last, int cnt)
{
	if (cnt == 0)
	{
		return remain < 0;
	}
	if (remain >= a[last] * cnt)
	{
		return 0;
	}
	if (remain < a[0] * cnt)
	{
		return C[last + 1][cnt];
	}
	LL sum = 0;
	for (int i = last; i >= cnt - 1; --i)
	{
		sum += dfs(remain - a[i], i - 1, cnt - 1);
	}
	//cout << remain << ' ' << last << ' ' << cnt << ' ' << sum << endl;
	return sum;
}

LL work(int n, int k)
{
	LL sum = 0;
	for (int i = k - 1; i < n; ++i)
	{
		sum += dfs(a[i], i - 1, k - 1);
		//cout << i << ' ' << sum << endl;
	}
	return sum;
}

int run()
{
	C[0][0] = 1;
	for (int i = 1; i < N; ++i)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j)
		{
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	int _;
	cin >> _;
	for (int cas = 1; cas <= _; ++cas)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		cout << "Case " << cas << ": " << work(n, k) << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	run();
	return 0;
}
