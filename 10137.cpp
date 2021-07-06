#include <bits/stdc++.h>

using namespace std;

double ss[1001];

int main()
{
	int n, i, s;
	double sum, av;
	while (scanf("%d", &n) && n)
	{
		sum = s = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%lf", &ss[i]);
			ss[i] *= 100;
			sum += ss[i];
		}
		av = sum / (double)n;
		s = sum = 0;
		for (i = 0; i < n; i++)
		{
			if (av > ss[i])
			{
				s += int(av - ss[i]);
			}
			if (av < ss[i])
			{
				sum += int(ss[i] - av);
			}
		}
		if (sum < s)
		{
			sum = s;
		}
		printf("$%.2lf\n", double(sum) / 100);
	}
	return 0;
}
