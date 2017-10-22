#include <bits/stdc++.h>

using namespace std;

long sumofDigit(long n, long ditInd, long poss)
{
	if (n == 0)
	{
		return 0;
	}
	long m = n % 10;
	return n / 10 * 45 * ditInd + m * poss + m * (m - 1) / 2 * ditInd + sumofDigit(n / 10, ditInd * 10, poss + m * ditInd);
}
int main()
{
	long x, y;
	while (1)
	{
		scanf("%ld %ld", &x, &y);
		if (x == 0 && y == 0)
		{
			break;
		}
		printf("%ld\n", sumofDigit(y, 1, 1) - sumofDigit(x - 1, 1, 1));
	}
	return 0;
}
