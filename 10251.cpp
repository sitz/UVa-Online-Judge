#include <bits/stdc++.h>

using namespace std;

double pi = 2 * acos(0.0f), L, H, D, DX, DY;
char str[100];
int n;

int main()
{
	gets(str);
	sscanf(str, "%d", &n);
	while (n--)
	{
		gets(str);
		if (sscanf(str, "%lf %lf %lf %lf", &L, &H, &DX, &DY) == 4)
		{
			double area;
			if (DX == 0 && DY == 0)
			{
				area = L * L / 2;
			}
			else if (DX == 0)
			{
				area = L * (L / 2 - DY);
			}
			else if (DY == 0)
			{
				area = L * (L / 2 - DX);
			}
			else
			{
				double m = -DX / DY;
				double b = DY - m * DX;
				double x = (L / 2) - (L / 2 - b) / m;
				double y = (L / 2) - (m * L / 2 + b);
				area = 0.5 * x * y;
			}
			printf("%.3lf\n", area * H);
		}
		else if (sscanf(str, "%lf %lf %lf", &L, &H, &D) == 3)
		{
			double theta = acos(D / L);
			double area = L * L * theta - L * D * sin(theta);
			printf("%.3lf\n", area * H);
		}
	}
	return 0;
}
