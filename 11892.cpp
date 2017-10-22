#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/118/11892.html
// Runtime : 0.064s
// Tag : Nim, Game Theory

// @BEGIN_OF_SOURCE_CODE

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long

int main()
{
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		int n;
		scanf("%d", &n);
		int input;
		int cntOne = 0;
		int cntOthers = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &input);
			if (input == 1)
			{
				cntOne++;
			}
			else
			{
				cntOthers++;
			}
		}
		if (cntOne % 2)
		{
			printf("poopi\n");
		}
		else
		{
			if (cntOthers > 0)
			{
				printf("poopi\n");
			}
			else
			{
				printf("piloop\n");
			}
		}
	}// while loop for testCase
	return 0;
}// end of main ()

// @END_OF_SOURCE_CODE
