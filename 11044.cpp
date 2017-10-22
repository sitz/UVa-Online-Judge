#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, m, k;
	scanf("%lld", &k);
	while (k--)
	{
		scanf("%lld%lld", &n,&m);
		cout << (n / 3) * (m / 3) << endl;
	}
	return 0;
}
