#include <bits/stdc++.h>

using namespace std;

const int rmax = 10000;

int main()
{
	int runs;
	scanf("%i", &runs);
	while (runs--)
	{
		int N, F;
		scanf("%i %i", &N, &F);
		vector<int> r(N);
		for (int i = 0; i < N; i++)
		{
			scanf("%i", &r[i]);
		}
		double lo = 0, hi = M_PI * rmax * rmax;
		for (int go = 0; go < 100; go++)
		{
			double x = (lo + hi) / 2;
			int cnt = 0;
			for (int i = 0; i < N; i++)
			{
				cnt += (int)floor(M_PI * r[i] * r[i] / x);
			}
			if (cnt < F + 1)
			{
				hi = x;
			}
			else
			{
				lo = x;
			}
		}
		printf("%.3f\n", lo);
	}
	return 0;
}
