#include <bits/stdc++.h>

using namespace std;

/*
10677
Base Equality
*/
int D[15], ind, B1, B2;
int Con_B2()
{
	int i, k = 1, sum = 0;
	for (i = 0; i < ind; i++)
	{
		sum += D[i] * k;
		k *= B2;
	}
	return sum;
}
void Con_B1(int n)
{
	int k;
	ind = 0;
	while (n)
	{
		k = n % B1;
		D[ind++] = k;
		n /= B1;
	}
}
void Cal(int r1, int r2)
{
	int i, d;
	for (i = r2 - 1; i > r1; i--)
	{
		Con_B1(i);
		d = Con_B2();
		if (d % i == 0)
		{
			printf("%d\n", i);
			return;
		}
	}
	printf("Non-existent.\n");
}
int main()
{
	int kases, r1, r2;
	scanf("%d", &kases);
	while (kases--)
	{
		scanf("%d%d%d%d", &B1, &B2, &r1, &r2);
		Cal(r1, r2);
	}
	return 0;
}
