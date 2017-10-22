#include <bits/stdc++.h>

using namespace std;

const int MAX = 2410;
const double pi = acos(-1.0);
struct point
{
	double x, y;
};
point p[MAX];
double a[MAX];
long long C2(int n)
{
	return n * (n - 1ll) / 2;
}
long long C3(int n)
{
	return n * 1ll * (n - 1) * (n - 2) / 6;
}
long long C4(int n)
{
	return n * 1ll * (n - 1) * (n - 2) * (n - 3) / 24;
}
long long solve(int n)
{
	long long ans = C4(n) * 4;
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
			swap(p[0], p[i]);
		for (int k = 1; k < n; k++)
			a[k] = atan2(p[k].y - p[0].y, p[k].x - p[0].x);

		sort(a + 1, a + n);

		for (int k = 1; k < n; k++)
			a[n + k - 1] = a[k] + 2 * pi;
		int t = 1;
		long long tt = 0ll;
		for (int k = 1; k < n; k++)
		{
			while (a[t] < a[k] + pi)
				t++;
			tt += C2(t - k - 1);
		}
		ans -= tt;
	}
	return ans;
}
int main()
{
	// freopen("input.txt","r",stdin);
	int ncases, n;
	int ind = 1;
	while (~scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);

		long long ans = solve(n);

		double p = ans * 1.0 / C3(n);
		printf("City %d: %.2lf\n", ind++, p);
	}
	return 0;
}
