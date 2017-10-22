#include <bits/stdc++.h>

using namespace std;

/**
 * 371 Ackermann function (AC)
 * Author: chchwy
 * Last Modified: 2010.03.18
 */

int getLength(long long n)
{
	int length = 0;
	do
	{
		length++;
		if (n % 2 == 0)
		{
			n = n >> 1;// div 2
		}
		else
		{
			n = n * 3 + 1;
		}
	} while (n != 1);
	return length;
}

int main()
{
	int L, H;
	while (scanf("%d %d", &L, &H))
	{
		if (L == 0 && H == 0)
		{
			break;
		}
		if (L > H)
		{
			std::swap(L, H);//L may be greater than H
		}
		int maxLen = 1, max = L;
		for (int i = L; i <= H; ++i)
		{
			int curLen = getLength(i);
			if (curLen > maxLen)
			{
				max = i;
				maxLen = curLen;
			}
		}
		printf("Between %d and %d, %d generates the longest sequence of %d values.\n", L, H, max, maxLen);
	}
	return 0;
}
