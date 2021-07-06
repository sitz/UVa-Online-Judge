#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ulli;
inline ulli sq(ulli a)
{
	return a * a;
}
int main()
{
	int n = 0;
	ulli p[1000][2];
	ulli d[1000][1000];
	while (std::cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		for (int i = 0; i < n; ++i)
		{
			std::cin >> p[i][0] >> p[i][1];
			for (int j = 0; j <= i; ++j)
			{
				d[i][j] = d[j][i] = sq(p[i][0] - p[j][0]) + sq(p[i][1] - p[j][1]);
			}
		}
		int c = 0;
		for (int i = 0; i < n; ++i)
		{
			std::sort(&d[i][0], &d[i][n]);
		}
		for (int i = 0; i < n; ++i)
		{
			ulli s = d[i][0];
			int k = 0;
			for (int j = 1; j < n; ++j)
			{
				if (d[i][j] != s)
				{
					c += k * (k + 1) / 2;
					s = d[i][j];
					k = -1;
				}
				++k;
			}
			c += k * (k + 1) / 2;
		}
		std::cout << c << std::endl;
	}
	return 0;
}
