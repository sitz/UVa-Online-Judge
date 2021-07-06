#include <bits/stdc++.h>

using namespace std;

int t[15] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};

int n, N, max_, a[16384], s[16384];

int main()
{
	while (scanf("%d", &N) == 1)
	{
		n = t[N];
		max_ = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
			s[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < N; j++)
			{
				s[i] += a[i ^ t[j]];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (s[i] + s[i ^ t[j]] > max_)
				{
					max_ = s[i] + s[i ^ t[j]];
				}
			}
		}
		printf("%d\n", max_);
	}
	return 0;
}
