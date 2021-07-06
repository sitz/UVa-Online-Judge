#include <bits/stdc++.h>

using namespace std;

#define i64 long long
int tes, n;
i64 k, bas[7][7], tmp[7][7], res[7][7];
const i64 inf = 34830;
void mul(i64 a[][7], i64 b[][7])
{
	memset(tmp, 0, sizeof(tmp));
	for (int h = 0; h < 7; ++h)
		for (int i = 0; i < 7; ++i)
			for (int j = 0; j < 7; ++j)
			{
				tmp[i][j] += a[i][h] * b[h][j];
			}
	for (int i = 0; i < 7; ++i)
		for (int j = 0; j < 7; ++j)
		{
			a[i][j] = tmp[i][j] % inf;
		}
}
i64 cal(int m)
{
	memset(bas, 0, sizeof(bas));
	memset(res, 0, sizeof(res));
	bas[0][0] = (k - 4) % inf;
	bas[0][1] = bas[0][2] = (k - 3) % inf;
	bas[1][3] = (k - 3) % inf;
	bas[1][6] = (k - 2) % inf;
	bas[2][4] = (k - 3) % inf;
	bas[2][5] = (k - 2) % inf;
	bas[3][0] = bas[3][2] = 1;
	bas[4][0] = bas[4][1] = 1;
	bas[5][3] = 1;
	bas[6][4] = 1;
	for (int i = 0; i < 7; ++i)
	{
		res[i][i] = 1;
	}
	while (m)
	{
		if (m & 1)
		{
			mul(res, bas);
		}
		m >>= 1;
		mul(bas, bas);
	}
	return res[5][5] * k % inf * (k - 1) % inf;
}
i64 init()
{
	if (n == 1)
	{
		return k % inf;
	}
	if (n == 2)
	{
		return k * (k - 1) % inf;
	}
	if (k < 3)
	{
		return 0;
	}
	//if(k==3)    return k*(k-1)%inf;
	return cal(n);
}
int main()
{
	scanf("%d", &tes);
	for (int h = 1; h <= tes; ++h)
	{
		scanf("%d %lld", &n, &k);
		printf("Case %d: %lld\n", h, init());
	}
	return 0;
}
