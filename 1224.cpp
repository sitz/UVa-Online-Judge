#include <bits/stdc++.h>

using namespace std;

#define MAXN 31
int main()
{
	int W1[MAXN], W2[MAXN], i, tc;
	W1[0] = 1;
	W1[1] = 1;
	for (i = 2; i < MAXN; i++)
	{
		W1[i] = 2 * W1[i - 2] + W1[i - 1];
	}
	W2[0] = 1;
	W2[1] = 1;
	W2[2] = 3;
	W2[3] = 1;
	for (i = 4; i < MAXN; i++)
	{
		W2[i] = W2[i - 2] + 2 * W2[i - 4];
	}
	scanf("%d", &tc);
	while (tc-- > 0)
	{
		scanf("%d", &i);
		printf("%d\n", (W1[i] - W2[i]) / 2 + W2[i]);
	}
	return 0;
}
