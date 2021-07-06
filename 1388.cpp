#include <bits/stdc++.h>

using namespace std;

int main()
{
	double pos, ans;
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		ans = 0.0f;
		for (int i = 1; i < n; i++)
		{
			pos = (i * 1.0 / n) * (n + m);
			ans += fabs(pos - floor(pos + 0.5f)) / (n + m);
		}
		printf("%.4lf\n", ans * 10000.0f);
	}
	return 0;
}
