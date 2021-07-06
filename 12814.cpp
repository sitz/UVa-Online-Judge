#include <bits/stdc++.h>

using namespace std;

#define p1 0.6
#define p2 0.4

double day[7];

int main()
{
	int i, r = 1, c;
	double sum;
	while (r)
	{
		for (i = 0; i < 7; i++)
		{
			day[i] = 0;
		}
		for (i = r = 0; i < 7; i++)
		{
			r += scanf("%d", &c);
			day[(i + 1) % 7] += c ? p1 : 0;
			day[(i + 2) % 7] += c ? p2 : 0;
		}
		if (r != 7)
		{
			break;
		}
		for (i = sum = 0; i < 7; i++)
		{
			sum += day[i];
		}
		for (i = 0; i < 7; i++)
		{
			if (i)
			{
				printf(" ");
			}
			if (sum)
			{
				printf("%.5lf", day[i] / sum);
			}
			else
			{
				printf("%.5lf", 0.0);
			}
		}
		printf("\n");
	}
	return 0;
}
