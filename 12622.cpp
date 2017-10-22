#include <bits/stdc++.h>

using namespace std;

#define fr(a, b, c) for (int a = b; a < c; a++)
#define rp(a, b) fr(a, 0, b)

typedef long long ll;

int go(int n, int b)
{
	int ret = 0;
	while (n)
	{
		if (n % b == 4)
			ret++;
		n /= b;
	}
	return ret;
}

int main()
{
	int T, P;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &P);
		int C = P;
		if (P < 0)
			P = -P;
		int fou = 0, temp, res;
		int q = max(1000, (int)sqrt(P)) + 10;
		fr(i, 5, q)
		{
			temp = go(P, i);
			if (temp > fou)
			{
				fou = temp;
				res = i;
			}
		}
		if (P <= 1000 || fou > 1)
		{
			if (!fou)
				printf("%d is infuriable.\n", C);
			else
				printf("%d %d %d\n", C, fou, res);
		}
		else
		{
			if (P % 4 == 0)
				printf("%d 2 %d\n", C, (P - 4) / 4);
			else if (fou == 1)
				printf("%d %d %d\n", C, fou, res);
		}
	}
	return 0;
}
