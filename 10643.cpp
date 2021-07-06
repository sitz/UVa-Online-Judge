#include <bits/stdc++.h>

using namespace std;

void C(int n, int k)
{
	if (k > n - k)
	{
		k = n - k;
	}
	int temp[400], i, j;
	memset(temp, 0, sizeof(temp));
	temp[0] = 1;
	for (i = n; i > n - k; i--)
	{
		int carry = 0;
		for (j = 0; j < 400; j++)
		{
			int t = temp[j] * i + carry;
			carry = t / 10000;
			temp[j] = t % 10000;
		}
	}
	for (i = 2; i <= k; i++)
	{
		int mod = 0;
		for (j = 399; j >= 0; j--)
		{
			int t = mod * 10000 + temp[j];
			mod = t % i;
			temp[j] = t / i;
		}
	}
	int p;
	for (p = 399; temp[p] == 0; p--)
		;
	printf("%d", temp[p]);
	for (p--; p >= 0; p--)
	{
		printf("%04d", temp[p]);
	}
	printf("\n");
}
int main()
{
	int t, m;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++)
	{
		scanf("%d", &m);
		m /= 2;
		m--;
		printf("Case %d: ", c);
		C(2 * m + 1, m + 1);
	}
}
