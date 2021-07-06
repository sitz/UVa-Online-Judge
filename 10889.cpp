#include <bits/stdc++.h>

using namespace std;

int main()
{
	double R, B;
	double b, c, sq;
	double B1, B2;
	char is_valid;
	while (scanf("%lf %lf", &R, &B) == 2)
	{
		if (R == 0 && B == 0)
		{
			break;
		}
		b = 2 * R + 1;
		c = R * R - R;
		sq = sqrt(8 * R + 1);
		if (fmod(sq, 1) == 0)
		{
			B1 = (b - sq) / 2;
			B2 = (b + sq) / 2;
			is_valid = 0;
			if (B1 >= B && B1 * 0.7 <= B)
			{
				printf("%.0lf", B1 - B);
				is_valid = 1;
			}
			if (B2 >= B && B2 * 0.7 <= B)
			{
				if (is_valid == 1)
				{
					printf(" ");
				}
				printf("%.0lf", B2 - B);
				is_valid = 1;
			}
			if (is_valid == 0)
			{
				printf("No. of black balls invalid\n");
			}
			else
			{
				printf("\n");
			}
		}
		else
		{
			printf("No. of red balls invalid\n");
		}
	}
	return 0;
}
