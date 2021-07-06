#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const int N = 100000;
int ind[N];

void op(int l, int r)
{
	int cnt = 0;
	REP(i, l, r + 1)
	{
		if (cnt)
		{
			cout << ' ';
		}
		cnt++;
		cout << i + 1;
	}
	cout << endl;
}

main()
{
	int n, c;
	while (scanf("%d%d", &c, &n) && c)
	{
		rep(i, c) ind[i] = -2;
		int sum = 0;
		int l, r;
		ind[0] = -1;
		rep(i, n)
		{
			int tmp;
			scanf("%d", &tmp);
			sum = (sum + tmp) % c;
			//cout << sum<<" ";
			if (ind[sum] != -2)
			{
				l = ind[sum] + 1;
				r = i;
			}
			ind[sum] = i;
		}
		//cout << endl;
		op(l, r);
	}
	return false;
}
