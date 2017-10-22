#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPF(i, a, b) for (int i = (a); i <= (b); ++i)
#define REPD(i, a, b) for (int i = (a); i >= (b); --i)
const int maxint = -1u >> 1;
const double eps = 1e-9;
const double pi = acos(-1.);
typedef long long lint;

int r1, r2, d1, d2;
double s;
int main()
{
	while (scanf("%d%d%d%d%lf", &r1, &r2, &d1, &d2, &s) == 5)
	{
		if (r1 == 0 && r2 == 0 && d1 == 0 && d2 == 0)
		{
			break;
		}
		lint ans = 0;
		REPF(r, r1, r2)
		{
			REPF(d, d1, d2)
			{
				double w = (r + d) * 4;
				double s1 = 2 * (r + d), s2 = 2 * pi * r * r / w;
				ans += max(0, int((s - s2) / (s1 - s2)) * 2);
			}
		}
		printf("%lld", ans);
		cout << endl;
	}
	return 0;
}
