#include <bits/stdc++.h>

using namespace std;

int N, K;
void solve(int m, int n)
{
	int array[20], p;
	if (n < 0)
	{
		puts("0");
	}
	else if (n == 0)
	{
		puts("1");
	}
	else
	{
		memset(array, 0, sizeof(array));
		array[0] = 1;
		for (int i = m; i > m - n; i--)
		{
			int carry = 0;
			for (int j = 0; j < 20; j++)
			{
				int temp = array[j] * i + carry;
				carry = temp / 10000000;
				array[j] = temp % 10000000;
			}
		}
		for (int i = n; i >= 2; i--)
		{
			int mod = 0;
			for (int j = 19; j >= 0; j--)
			{
				int temp = mod * 10000000 + array[j];
				array[j] = temp / i;
				mod = temp % i;
			}
		}
		for (p = 19; array[p] == 0; p--)
			;
		printf("%d", array[p]);
		for (p--; p >= 0; p--)
		{
			printf("%07d", array[p]);
		}
		printf("\n");
	}
}
int main()
{
	int t, d;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &N, &K);
		for (int i = 0; i < K; i++, scanf("%d", &d), N -= d)
			;
		N -= (K - 1);
		solve(K + N, N);
	}
	return 0;
}
