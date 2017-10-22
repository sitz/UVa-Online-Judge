#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(x) (int)x.size()
#define scf scanf
#define ptf printf
#define fst first
#define scd second
#define forp(i, j, k) for (int i = j; i < k; i++)
#define form(i, j, k) for (int i = j; i > k; i--)

typedef long long LL;

unsigned long long pw[100];

void pr()
{
	pw[0] = 1;
	forp(i, 1, 63) pw[i] = pw[i - 1] * 2;
}

int main()
{
	pr();
	int m, e, t0;
	for (scf("%d%d", &m, &e); m || e; scf("%d%d", &m, &e))
	{
		unsigned long long ans = 0;
		if (pw[e] - 1 < 1LL * m + 1)
			t0 = pw[e] - 1;
		else
			t0 = m + 1;
		ans += pw[t0] - 1;
		if (pw[e] - 1 < 1LL * m + 1)
		{
			ptf("%llu\n", ans);
			continue;
		}
		ans += pw[m] * (pw[e] - m - 2);
		ptf("%llu\n", ans);
	}
	return 0;
}
