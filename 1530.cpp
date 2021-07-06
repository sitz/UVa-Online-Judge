#include <bits/stdc++.h>

using namespace std;

const double esp = 1e-6;
char str[20];
int i;

int main()
{
	printf("Program 6 by team X\n");
	while (~scanf("%s", str))
	{
		int num1 = 0, flag = 1;
		for (i = 7; i >= 1; i--)
		{
			if (str[i] == '1')
			{
				flag = 0;
			}
			num1 += (str[i] - '0') * (1 << (7 - i));
		}
		double s = pow(2, num1 - 63);
		double num2 = 1;
		for (i = 8; i < 16; i++)
		{
			if (str[i] == '1')
			{
				flag = 0;
			}
			num2 += (str[i] - '0') * (1.0 / (1 << (i - 7)));
		}
		if (flag)
		{
			printf("0.000000e+000\n");
			continue;
		}
		double ans = s * num2;
		int w = 0;
		while (ans - 10 > -esp)
		{
			ans /= 10;
			w++;
		}
		while (ans - 1 < -esp)
		{
			ans *= 10;
			w--;
		}
		if (str[0] == '1')
		{
			printf("-");
		}
		else
		{
			printf(" ");
		}
		printf("%.6lfe", ans);
		if (w >= 0)
		{
			printf("+%03d\n", w);
		}
		else
		{
			printf("-%03d\n", -w);
		}
	}
	printf("End of program 6 by team X\n");
	return 0;
}
