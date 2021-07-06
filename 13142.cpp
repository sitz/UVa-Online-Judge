#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		LL t, u, s;
		scanf("%lld%lld%lld", &t, &u, &s);
		LL t_t = 24 * 60 * 60;
		LL s_s = 1000000;
		t *= t_t;
		s *= s_s;
		LL v = abs((s / t) - u);
		printf(v - u < 0 ? "Remove " : "Add ");
		LL mass = trunc(abs(abs(v) - u));
		printf("%ld tons\n", mass);
	}
	return 0;
}
