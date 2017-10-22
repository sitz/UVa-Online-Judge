#include <bits/stdc++.h>

using namespace std;

const double pg = 9806.65;
const double PI = acos(-1.0);

char str[50];
double W, D, h, SG;
int type;//1--h unknow  2--SG unknow

void Parse(char *p)
{
	if (*p == 'W')
	{
		while (*p != '=')
		{
			p++;
		}
		p++;
		sscanf(p, "%lf", &W);
		W /= 1000.0;
		W *= 9.80665;
	}
	if (*p == 'D')
	{
		while (*p != '=')
		{
			p++;
		}
		p++;
		sscanf(p, "%lf", &D);
		D /= 1000.0;
	}
	if (*p == 'h')
	{
		while (*p != '=')
		{
			p++;
		}
		p++;
		sscanf(p, "%lf", &h);
		h /= 100.0;
		type = 2;
	}
	if (*p == 'S')
	{
		while (*p != '=')
		{
			p++;
		}
		p++;
		sscanf(p, "%lf", &SG);
		type = 1;
	}
}

int main()
{
	while (cin.getline(str, 50))
	{
		Parse(str);
		cin.getline(str, 50);
		Parse(str);
		cin.getline(str, 50);
		Parse(str);
		if (type == 1)
		{
			h = 4.0 * W * (1.0 - 1.0 / SG) / (PI * D * D * pg);
			printf("h=%.2lf\n", h * 100.0);
		}
		else if (type == 2)
		{
			double temp;
			temp = W - pg * h * PI * D * D / 4.0;
			SG = W / temp;
			printf("SG=%.2lf\n", SG);
		}
	}
	return 0;
}
