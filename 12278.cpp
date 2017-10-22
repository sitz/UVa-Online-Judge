#include <bits/stdc++.h>

using namespace std;

// O(1)

typedef long long ll;

struct point
{
	ll x, y;
	point(ll a = 0, ll b = 0) : x(a), y(b) {}
};

// Returns twice the signed area of triangle abc.
// Its sign is positive if c is to the left of ab.
ll area2(point a, point b, point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main()
{
	point p[4];
	for (;;)
	{
		for (int i = 0; i < 4; ++i)
		{
			ll z;
			scanf("%lli%lli%lli", &p[i].x, &p[i].y, &z);
			if (p[i].x + p[i].y + z == 0)
			{
				return 0;
			}
		}
		ll triang = area2(p[0], p[1], p[2]);
		if (triang < 0)
		{
			swap(p[0], p[1]);
		}
		bool inside;
		if (triang == 0)// degenerate triangle
		{
			ll a = min(p[0].x, min(p[1].x, p[2].x)),
				 b = max(p[0].x, max(p[1].x, p[2].x)),
				 c = min(p[0].y, min(p[1].y, p[2].y)),
				 d = max(p[0].y, max(p[1].y, p[2].y));
			inside = ((a < p[3].x && p[3].x < b) || (c < p[3].y && p[3].y < d)) && (area2(p[0], p[1], p[3]) == 0);
		}
		else
			inside =
					(area2(p[0], p[1], p[3]) > 0) &&
					(area2(p[1], p[2], p[3]) > 0) &&
					(area2(p[2], p[0], p[3]) > 0);
		puts(inside ? "YES" : "NO");
	}
	return 0;
}
