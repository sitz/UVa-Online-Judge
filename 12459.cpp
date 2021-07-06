#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main()
{
	ll f[81] = {0}, m[81] = {1};
	rep(i, 80)
	{
		f[i + 1] = f[i] + m[i];
		m[i + 1] = f[i];
	}
	for (int n; scanf("%d", &n), n;)
	{
		printf("%lld\n", f[n] + m[n]);
	}
	return 0;
}
