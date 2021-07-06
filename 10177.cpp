#include <bits/stdc++.h>

using namespace std;

#define MAXN 101

long long Store[3][MAXN], RStore[3][MAXN];

void Gen_Sq()
{
	int i, j, k = 1;
	long long Sum;
	for (i = 0; i < 3; i++)
	{
		Sum = 0;
		k++;
		for (j = 1; j <= 100; j++)
		{
			Sum += pow(j, k);
			Store[i][j] = Sum;
		}
	}
}
void Gen_Rec()
{
	int i, j, k;
	int p, q, n = 1;
	for (i = 0; i < 3; i++)
	{
		n++;
		for (j = 2; j <= 100; j++)
		{
			k = j - 1;
			p = k + 1;
			q = k + 2;
			if (p % 2 == 0)
			{
				p /= 2;
			}
			else
			{
				q /= 2;
			}
			RStore[i][j] = pow((p * q), n) - Store[i][j];
		}
	}
}

int main()
{
	int n;
	Gen_Sq();
	Gen_Rec();
	while (scanf("%d", &n) == 1)
	{
		printf("%lld %lld %lld %lld %lld %lld\n", Store[0][n], RStore[0][n],
			Store[1][n], RStore[1][n], Store[2][n], RStore[2][n]);
	}
	return 0;
}
