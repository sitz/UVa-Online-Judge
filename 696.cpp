#include <bits/stdc++.h>

using namespace std;

/**
696
**/
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)
int M, N;
void Knight()
{
	int d, x, max = 0;
	if (M == 0 || N == 0)
	{
		goto done;
	}
	if (M == 1 || N == 1)
	{
		max = MAX(M, N);
	}
	else if (M == 2 || N == 2)
	{
		d = MAX(M, N);
		int temp1 = d / 4;
		int temp = d - 3;
		if (temp < 0)
		{
			x = 0;
		}
		else
		{
			x = (temp / 4) + 1;
		}
		max = (d - temp1 - x) * 2;
	}
	else
	{
		d = M * N;
		max = d / 2;
		if (d % 2)
		{
			max += 1;
		}
	}
done:;
	printf("%d knights may be placed on a %d row %d column board.\n", max, M, N);
}
int main()
{
	while (scanf("%d%d", &M, &N) == 2)
	{
		if (M == 0 && N == 0)
		{
			break;
		}
		Knight();
	}
	return 0;
}
