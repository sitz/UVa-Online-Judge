#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int solve(int n, int k)
{
	int ret = 0;
	while (n != 0)
	{
		//cout << n <<" " << n/k <<" " << n/k/k<<endl;
		int tmp = n / k + 1;
		ret += (n - tmp) + 1;
		n = n / k / k;
	}
	//  ret++;
	return ret;
}

main()
{
	int te;
	cin >> te;
	while (te--)
	{
		int n, k;
		cin >> n >> k;
		cout << solve(n, k) << endl;
	}
	return 0;
}
