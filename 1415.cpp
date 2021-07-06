#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 10005
bool f[N], fac[N];
int n, m;
vector<int> prime;
void init()
{
	f[1] = f[0] = 1;
	for (int i = 2; i * i <= 10000; ++i)
		if (!f[i])
			for (int j = i * i; j <= 10000; j += i)
			{
				f[j] = 1;
			}
	for (int i = 2; i <= 10000; ++i)
		if (!f[i])
		{
			prime.push_back(i);
		}
	for (int i = 0; i * i <= 10000; ++i)
		for (int j = 0; i * i + j * j * 2 <= 10000; ++j)
		{
			fac[i * i + j * j * 2] = 1;
		}
}
int main()
{
	init();
	int _;
	scanf("%d", &_);
	while (_--)
	{
		scanf("%d%d", &n, &m);
		if (n == 0)
		{
			if (!f[m] && !fac[m])
			{
				puts("Yes");
			}
			else
			{
				puts("No");
			}
		}
		else
		{
			int i, x = n * n + m * m * 2;
			for (i = 2; i * i <= x; ++i)
				if (x % i == 0)
				{
					break;
				}
			printf("%s\n", i * i <= x ? "No" : "Yes");
		}
	}
	return 0;
}
