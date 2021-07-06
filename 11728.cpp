#include <bits/stdc++.h>

using namespace std;

int sumOfFactors(int n)
{
	int output = 1;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			output += i;
		}
		if (output > 1000)
		{
			break;
		}
	}
	if (n != 1)
	{
		output += n;
	}
	return output;
}

int main()
{
	int save[1000 + 5];
	memset(save, -1, 1005 * sizeof(int));
	int sof;
	int cases = 0;
	for (int i = 1; i <= 1000; i++)
	{
		sof = sumOfFactors(i);
		if (sof <= 1000)
		{
			save[sof] = i;
		}
	}
	int s;
	while (scanf("%d", &s) && s)
	{
		printf("Case %d: %d\n", ++cases, save[s]);
	}
	return 0;
}
