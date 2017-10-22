#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T, t;
	scanf("%d", &T);
	while (T--)
	{
		int a, b, c;
		double h, l, w, ans;
		scanf("%d%d%d", &a, &b, &c);
		h = c * 1.0f;
		l = (a + h) * 2;
		w = (b + h) * 2;
		ans = hypot(l, w);
		printf("Case %d: %.4lf\n", ++t, ans);
	}
	return 0;
}
