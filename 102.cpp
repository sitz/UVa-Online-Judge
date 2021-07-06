#include <bits/stdc++.h>

using namespace std;

enum
{
	B = 0,
	C = 1,
	G = 2
};

int main()
{
	int binColor[][3] = {{B, C, G}, {B, G, C}, {C, B, G}, {C, G, B}, {G, B, C}, {G, C, B}};
	char s[][4] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
	int bin[3][3];
	while (scanf("%d%d%d%d%d%d%d%d%d",
							 &bin[0][B], &bin[0][G], &bin[0][C],
							 &bin[1][B], &bin[1][G], &bin[1][C],
							 &bin[2][B], &bin[2][G], &bin[2][C]) != EOF)
	{
		int currMv = 0, totalGlasses = 0;
		for (int i = 0; i < 3; i++)
		{
			totalGlasses += (bin[i][B] + bin[i][G] + bin[i][C]);
		}
		int minMv = totalGlasses, minNo = 0;
		for (int i = 0; i < 6; i++)
		{
			currMv = totalGlasses - bin[0][binColor[i][0]] - bin[1][binColor[i][1]] - bin[2][binColor[i][2]];
			if (currMv < minMv)
			{
				minMv = currMv;
				minNo = i;
			}
		}
		printf("%s %d\n", s[minNo], minMv);
	}
	return 0;
}
