#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define MOD 1000000007
#define LL long long

char s[N];

LL cut(LL n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		return n * (n + 1) / 2;
	}
}

int main()
{
	LL n, i, j, k, sum, b, e;
	while (cin >> n)
	{
		scanf("%s", s);
		sum = 0;
		LL l = strlen(s);
		for (i = 1; i <= 9; i++)
		{
			for (j = b = e = 0; j < l; j++)
			{
				if (s[j] - '0' < i)
				{
					sum += cut(e - b);
					b = e = 0;
				}
				else
					e++;
			}
			sum += cut(e - b);
		}
		cout << (sum % MOD) << endl;
	}
	return 0;
}
