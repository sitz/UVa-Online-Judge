#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/120/12034.html
// Runtime: 0.016s
// Tag: Dp

// @BEGIN_OF_SOURCE_CODE

#define LL long long

LL res[1000 + 5];

void preCalc()
{
	res[0] = 1;
	res[1] = 1;// when n = 1, res = 1
	res[2] = 3;// when n = 2, res = 3
	res[3] = 13;
	LL numOfZeros[1000 + 5];
	// numOfZeros [5] = number of binary numbers contain 5 zeros in a particular bit
	for (int i = 0; i < 1005; i++)
	{
		numOfZeros[i] = 1;
	}
	numOfZeros[0] = 1;
	numOfZeros[1] = 4;
	numOfZeros[2] = 6;
	numOfZeros[3] = 4;
	for (int i = 4; i <= 1000; i++)
	{
		LL val = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			val += (numOfZeros[j] * res[j]) % 10056;
			val %= 10056;
		}
		res[i] = val;
		for (int j = i; j >= 1; j--)
		{
			numOfZeros[j] += numOfZeros[j - 1];
			numOfZeros[j] %= 10056;
		}
	}
}

int main()
{
	preCalc();
	int testCase;
	scanf("%d", &testCase);
	int cases = 0;
	while (testCase--)
	{
		int n;
		scanf("%d", &n);
		printf("Case %d: %lld\n", ++cases, res[n]);
	}
	return 0;
}

// @END_OF_SOURCE_CODE
