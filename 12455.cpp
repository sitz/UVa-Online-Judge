#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int tar, n;
		scanf("%d%d", &tar, &n);
		int a[20];
		rep(i, n) scanf("%d", a + i);
		bool ok = false;
		rep(S, 1 << n)
		{
			int sum = 0;
			rep(i, n) if (S & 1 << i)
			{
				sum += a[i];
			}
			if (sum == tar)
			{
				ok = true;
				break;
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}
