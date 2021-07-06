#include <bits/stdc++.h>

using namespace std;

// Recursive, Dp, bitmask

#define INF 2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long

#define For(i, a, b) for (int i = (a); i < (b); i++)
#define Fors(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fore(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define Set(a, s) memset(a, s, sizeof(a))

int l, s, sPos[10 + 2], c, maxFlow[10 + 2], bitMaskFilled[10 + 2][10 + 2], maxFilled;

int minimum(int p, int q)
{
	if (p < q)
		return p;
	return q;
}

void recur(int at, int cLeft, int filled)
{
	if (at == s || !cLeft)
	{
		int cnt = 0;
		for (int i = 0; i <= l; i++)
			if (filled & (1 << i))
				cnt++;
		if (cnt > maxFilled)
			maxFilled = cnt;
		return;
	}
	for (int i = 0; i <= minimum(maxFlow[at], cLeft); i++)
		recur(at + 1, cLeft - i, filled | bitMaskFilled[at][i]);
}

int main()
{
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		scanf("%d %d", &l, &s);
		for (int i = 0; i < s; i++)
			scanf("%d", &sPos[i]);
		scanf("%d", &c);
		for (int i = 0; i < s; i++)
			scanf("%d", &maxFlow[i]);
		Set(bitMaskFilled, 0);
		int tmp;
		for (int i = 0; i < s; i++)
		{
			for (int j = 1; j <= maxFlow[i]; j++)
			{
				tmp = bitMaskFilled[i][j - 1];
				tmp |= (1 << sPos[i]);
				tmp |= (1 << (sPos[i] + j));
				tmp |= (1 << (sPos[i] - j));
				bitMaskFilled[i][j] = tmp;
			}
		}
		maxFilled = 0;
		recur(0, c, 0);
		printf("%d\n", maxFilled);
	}
	return 0;
}
