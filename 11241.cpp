#include <bits/stdc++.h>

using namespace std;

int main()
{
	int isH, isT, isD;
	char buf[1000], *token;
	double T, H, D, h, e;
	while (fgets(buf, 1000, stdin))
	{
		if (buf[0] == 'E')
		{
			break;
		}
		isH = isT = isD = 0;
		token = strtok(buf, " ");
		switch (token[0])
		{
		case 'H':
			token = strtok(NULL, " ");
			isH = 1;
			H = atof(token);
			break;
		case 'T':
			token = strtok(NULL, " ");
			isT = 1;
			T = atof(token);
			break;
		case 'D':
			token = strtok(NULL, " ");
			isD = 1;
			D = atof(token);
			break;
		}
		token = strtok(NULL, " ");
		switch (token[0])
		{
		case 'H':
			token = strtok(NULL, " ");
			isH = 1;
			H = atof(token);
			break;
		case 'T':
			token = strtok(NULL, " ");
			isT = 1;
			T = atof(token);
			break;
		case 'D':
			token = strtok(NULL, " ");
			isD = 1;
			D = atof(token);
			break;
		}
		if (isT && isD)
		{
			e = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (D + 273.16))));
			h = 0.5555 * (e - 10);
			H = T + h;
		}
		else if (isH && isD)
		{
			e = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (D + 273.16))));
			h = 0.5555 * (e - 10);
			T = H - h;
		}
		else
		{
			h = H - T;
			e = h / 0.5555 + 10;
			D = 1 / (1 / 273.16 - (log(e / 6.11)) / 5417.7530) - 273.16;
		}
		printf("T %.1f D %.1f H %.1f\n", T, D, H);
	}
	return 0;
}
