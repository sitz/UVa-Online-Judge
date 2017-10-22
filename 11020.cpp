#include <bits/stdc++.h>

using namespace std;

struct point
{
	int x, y;
	bool operator<(const point &t) const
	{
		return x < t.x || (x == t.x && y < t.y);
	}
};
multiset<point> s;
multiset<point>::iterator it;

int main()
{
	int i, j, cas, n;
	scanf("%d", &cas);
	for (int ca = 1; ca <= cas; ca++)
	{
		scanf("%d", &n);
		int x, y;
		s.clear();
		printf("Case #%d:\n", ca);
		while (n--)
		{
			scanf("%d%d", &x, &y);
			point p = (point){
					x, y};
			it = s.lower_bound(p);
			if (it == s.begin() || (--it)->y > y)
			{
				s.insert(p);
				it = s.upper_bound(p);
				while (it != s.end() && it->y >= y)
				{
					s.erase(it++);
				}
			}
			printf("%d\n", s.size());
		}
		if (ca != cas)
		{
			puts("");
		}
	}
	return 0;
}
