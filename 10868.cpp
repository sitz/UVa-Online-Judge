#include <bits/stdc++.h>

using namespace std;

#define dt 0.00005
#define g 9.81

int main()
{
	double k, l, s, w;
	while (scanf("%lf%lf%lf%lf", &k, &l, &s, &w) == 4)
	{
		if (k == 0)
		{
			break;
		}
		assert(0 <= k && 0 <= l && 0 <= s && s < 200 && 0 <= w);
		double d = s < l ? s : l, a, f, F = g * w, t = sqrt(2 * d / g), v = g * t;
		while (1)
		{
			if (d >= s)
			{
				if (v > 10)
				{
					puts("Killed by the impact.");
				}
				if (v < 10)
				{
					puts("James Bond survives.");
				}
				break;
			}
			if (v < 0)
			{
				puts("Stuck in the air.");
				break;
			}
			f = F - k * (d < l ? 0 : d - l);
			a = f / w;
			d += v * dt + dt * dt * a / 2;
			v += dt * a;
		}
	}
}
