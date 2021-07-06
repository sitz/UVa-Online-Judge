#include <bits/stdc++.h>

using namespace std;

int n;
double t1, t2, t3, t4, p;
int main()
{
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++)
	{
		printf("Case %d: ", c);
		scanf("%d", &n);
		t1 = t2 = p = 0;
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf %lf", &t3, &t4);
			t1 += fabs(t3) * t4;
			if (t3 > 0)
			{
				t2 += t4;
			}
			if (t4 > 1 || t4 < 0)
			{
				flag = false;
			}
			p += t4;
		}
		if (fabs(p - 1) > 1e-6 || fabs(t2) < 1e-6 || !flag)
		{
			printf("God! Save me\n");
		}
		else
		{
			printf("%.2lf\n", t1 / t2);
		}
	}
}
