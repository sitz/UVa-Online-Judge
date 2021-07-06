#include <bits/stdc++.h>

using namespace std;

/**
654
**/
int N, D;
double Res;
void Cal()
{
	int i, j, st;
	double temp, diff, pre;
	Res = (double)N / (double)D;
	diff = fabs(Res - 1);
	st = 1;
	for (i = 2; i; i++)
	{
		temp = fabs(Res - ((double)i / 1));
		if (temp > diff)
		{
			break;
		}
		if (diff > temp)
		{
			st = i;
			diff = temp;
		}
	}
	printf("%d/1\n", st);
	for (i = 2; i; i++)
	{
		for (j = 1; j; j++)
		{
			temp = (double)j / (double)i;
			if (fabs(temp - Res) < .0000001)
			{
				printf("%d/%d\n", j, i);
				return;
			}
			pre = fabs(Res - temp);
			if (pre < diff)
			{
				printf("%d/%d\n", j, i);
				diff = pre;
			}
			else if (temp > Res)
			{
				break;
			}
		}
	}
}
int main()
{
	int c = 0;
	while (scanf("%d%d", &N, &D) == 2)
	{
		if (c++)
		{
			printf("\n");
		}
		Cal();
	}
	return 0;
}
