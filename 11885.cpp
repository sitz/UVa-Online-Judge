#include <bits/stdc++.h>

using namespace std;

#define println(x) cout << #x << " is " << x << endl;

const int N = 2;

typedef long long LL;
LL MOD = 987654321;
struct Mat
{
	LL mat[N][N];
} org, unit;

void setOrg()
{
	org.mat[0][0] = 1;
	org.mat[0][1] = 0;
}

void setUnit()
{
	unit.mat[0][0] = 1;
	unit.mat[0][1] = 1;
	unit.mat[1][0] = 1;
	unit.mat[1][1] = 0;
}

Mat operator*(Mat a, Mat b)
{
	Mat c;
	memset(c.mat, 0, sizeof(c.mat));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				c.mat[i][j] = (c.mat[i][j] + (a.mat[i][k] * b.mat[k][j])) % MOD;
			}
		}
	}
	return c;
}

Mat operator^(Mat a, LL p)
{
	setOrg();
	setUnit();
	for (; p; p = p / 2)
	{
		if (p & 1)
		{
			org = org * unit;
		}
		unit = unit * unit;
	}
	return org;
}

LL solve(LL p)
{
	org = org ^ p;
	return org.mat[0][1] % MOD;
}

int main()
{
	LL idx;
	while (scanf("%lld", &idx))
	{
		if (!idx)
		{
			break;
		}
		if (idx & 1 || idx < 8)
		{
			printf("0\n");
			continue;
		}
		long long ans = solve(idx - 3) - idx / 2 + 1;
		if (ans < 0)
		{
			ans += MOD;
		}
		printf("%lld\n", ans % MOD);
	}
	return 0;
}
