#include <bits/stdc++.h>

using namespace std;

int main()
{
	int L, W, H, G;
	double leche, area, cateto, tmp = 3.14159265358979 / 180;
	while (scanf("%d %d %d %d", &L, &W, &H, &G) != EOF)
	{
		cateto = L * sin(G * tmp) / sin((90 - G) * tmp);
		if (G == 90)
		{
			printf("0 mL\n");
		}
		else if (cateto <= H)
		{
			cateto = L * sin(G * tmp) / sin((90 - G) * tmp);
			area = L * cateto * W / 2;
			leche = (L * W * H) - area;
			printf("%0.3lf mL\n", leche);
		}
		else if (G)
		{
			cateto = H * sin((90 - G) * tmp) / sin(G * tmp);
			area = H * cateto * W / 2;
			printf("%0.3lf mL\n", area);
		}
		else
		{
			leche = (L * W * H);
			printf("%0.3lf mL\n", leche);
		}
	}
	return 0;
}
