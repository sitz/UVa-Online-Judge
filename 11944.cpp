#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int main()
{
	int c, wagers, t, val;
	double sum = 0.00, total = 0.00;
	char num[11111], num1[11111];
	scanf("%d", &c);
	FOR(j, 0, c)
	{
		scanf("%d%d", &wagers, &t);
		total += wagers;
		FOR(i, 0, t)
		{
			scanf("%d", &val);
			if (val < 0.00)
			{
				sprintf(num, "%.3lf", 100.00 / (double)val * (-1));
			}
			else
			{
				sprintf(num, "%.3lf", (double)val / 100.00);
			}
			sprintf(num, "%.3lf", atof(num) * wagers);
			sum = ceil(atof(num));
			wagers += (int)sum;
			total += sum;
			strcmp(num, "");
		}
		sprintf(num1, "%.2lf", total);
		if (total < 1000)
		{
			printf("%d $%.2lf\n", j + 1, total);
		}
		else if (total > 1000000.00)
		{
			printf("%d $1,000,000.00\n", j + 1);
		}
		else
		{
			int len = strlen(num1), pos = 0;
			if (len == 7)
			{
				pos = 0;
			}
			if (len == 8)
			{
				pos = 1;
			}
			if (len == 9)
			{
				pos = 2;
			}
			printf("%d $", j + 1);
			for (int k = 0; k <= pos; k++)
			{
				printf("%c", num1[k]);
			}
			printf(",");
			for (int k = pos + 1; k < (int)strlen(num1); k++)
			{
				printf("%c", num1[k]);
			}
			printf("\n");
			strcmp(num, "");
			strcmp(num1, "");
		}
		total = sum = 0.00;
	}
}
