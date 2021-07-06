#include <bits/stdc++.h>

using namespace std;

double a[1001], left_, right_;
int n;

int main()
{
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		scanf("%lf %lf", &left_, &right_);
		for (int i = 1; i <= n; i++)
		{
			a[i] = 99999999;
			for (int j = 0; j < i; j++)
				if (a[j] + a[i - 1 - j] + (1 + left_ * a[j] + right_ * a[i - 1 - j]) / (1 - left_ - right_) < a[i])
				{
					a[i] = a[j] + a[i - 1 - j] + (1 + left_ * a[j] + right_ * a[i - 1 - j]) / (1 - left_ - right_);
				}
		}
		printf("%.2lf\n", a[n]);
	}
	return 0;
}
