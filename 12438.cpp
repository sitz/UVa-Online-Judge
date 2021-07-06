#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
typedef long long ll;
const int N_PHI = 15000;
int phi[N_PHI + 1];
void build_phi()
{
	rep(i, N_PHI + 1) phi[i] = i;
	for (int i = 2; i <= N_PHI; i++)
		if (phi[i] == i)
		{
			for (int j = i; j <= N_PHI; j += i)
			{
				phi[j] = phi[j] / i * (i - 1);
			}
		}
}

int main()
{
	build_phi();
	int len[N_PHI + 1];// len[i] := ( i 次の Farey 数列の長さ )
	len[0] = 2;
	rep(i, N_PHI) len[i + 1] = len[i] + phi[i + 1];
	for (ll I; scanf("%lld", &I), I != -1;)
	{
		if (I == 0)
		{
			puts("1 1");
			continue;
		}
		int n = 1, m;
		for (m = 15000; m >= 2; m--)
			if (2 * (I + m * m - 1) % (m * (m - 1)) == 0)
			{
				ll a = 2 * (I + m * m - 1) / (m * (m - 1));
				while (n <= 15000 && len[n] < a)
				{
					n++;
				}
				if (n > 15000)
				{
					m = 1;
					break;
				}
				if (len[n] == a)
				{
					break;
				}
			}
		if (m == 1)
		{
			puts("NOT FOUND");
		}
		else
		{
			printf("%d %d\n", n, m);
		}
	}
	return 0;
}
