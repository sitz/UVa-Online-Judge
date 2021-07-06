#include <bits/stdc++.h>

using namespace std;

#define INF 0x7fffffff
#define MAXD 210
long long int f[MAXD];
char b[MAXD];
void solve()
{
	int i, j, k, N;
	long long int v;
	scanf("%s", b);
	N = strlen(b);
	memset(f, 0, sizeof(f));
	for (i = 0; i < N; i++)
	{
		if (b[i] == '0')
		{
			if (f[i] > f[i + 1])
			{
				f[i + 1] = f[i];
			}
		}
		else
		{
			v = 0;
			for (j = i; j < N; j++)
			{
				v = v * 10 + b[j] - '0';
				if (v > INF)
				{
					break;
				}
				if (f[i] + v > f[j + 1])
				{
					f[j + 1] = f[i] + v;
				}
			}
		}
	}
	printf("%lld\n", f[N]);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}
