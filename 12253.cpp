#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL p[20];
LL Mul(LL A, LL B, LL C)
{
	LL a1 = A / 1000000;
	LL a2 = A % 1000000;
	LL b1 = B / 1000000;
	LL b2 = B % 1000000;
	LL ret = a2 * b1 * 1000000 % C + b2 * a1 * 1000000 % C + a2 * b2;
	return ret % C;
}
LL pow(LL A, LL B, LL C)
{
	LL ret = 1;
	for (; B; B >>= 1)
	{
		if (B & 1)
			ret = Mul(ret, A, C);
		A = Mul(A, A, C);
	}
	return ret;
}

bool check(LL A, LL B, LL C)
{
	LL phi = C;
	C = C * 10;
	return B == pow(A, B % (4 * phi) + 4 * phi, C) || B == pow(A, (B + 2 * phi) % (4 * phi) + 4 * phi, C);
}
bool dfs(int len, LL now, LL A)
{
	//printf(">>> len = %d now = %lld A = %lld\n", len, now, A);
	if (len == 12)
	{
		LL Mod = p[12];
		if (pow(A, now, Mod) == now)
		{
			printf("%lld\n", now);
			return true;
		}
		return false;
	}
	for (int i = len == 11 ? 1 : 0; i <= 9; i++)
	{
		LL tmp = i * p[len] + now;
		LL Mod = p[len];
		if (check(A, tmp, Mod))
		{
			if (dfs(len + 1, tmp, A))
				return true;
		}
	}
	return false;
}
int main()
{
	p[0] = 1;
	for (int i = 1; i <= 13; i++)
		p[i] = p[i - 1] * 10;
	for (LL n, kase = 1; scanf("%lld", &n) != EOF, n;)
	{
		printf("Case %d: Public Key = %d Private Key = ", kase++, n);
		dfs(0, 0, n);
	}
}
