#include <bits/stdc++.h>

using namespace std;

const char CH[] = {' ', '.', 'x', 'W'};

int main()
{
	int kase, first = 1;
	int dna[10], disk[2][50];
	scanf("%d", &kase);
	while (kase--)
	{
		if (!first)
		{
			printf("\n");
		}
		first = 0;
		for (int i = 0; i < 10; i++)
		{
			scanf("%d", dna + i);
		}
		int now = 0;
		memset(disk, 0, sizeof(disk));
		disk[now][20] = 1;
		for (int i = 0; i < 50; i++)
		{
			for (int j = 1; j <= 40; j++)
			{
				printf("%c", CH[disk[now][j]]);
			}
			printf("\n");
			now = 1 - now;
			for (int j = 1; j <= 40; j++)
			{
				disk[now][j] = dna[disk[1 - now][j] + disk[1 - now][j - 1] + disk[1 - now][j + 1]];
			}
		}
	}
	return 0;
}
