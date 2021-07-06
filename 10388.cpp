#include <bits/stdc++.h>

using namespace std;

char up[2][100], down[2][100];
int pu[2], pd[2], len[2];

int sim()
{
	int i, j, p;
	for (i = 0; i < 1000; i++)
	{
		if (pu[0] + len[0] == 0)
		{
			return 1;
		}
		if (pu[1] + len[1] == 0)
		{
			return -1;
		}
		up[0][pu[0]++] = down[0][pd[0]++];
		up[1][pu[1]++] = down[1][pd[1]++];
		if (up[0][pu[0] - 1] == up[1][pu[1] - 1])
		{
			p = random() / 141 % 2;
			for (j = 0; j < pu[1 - p]; j++)
			{
				up[p][pu[p]++] = up[1 - p][j];
			}
			pu[1 - p] = 0;
			if (p == 0)
			{
				printf("Snap! for Jane: ");
			}
			else
			{
				printf("Snap! for John: ");
			}
			for (j = pu[p] - 1; j >= 0; j--)
			{
				printf("%c", up[p][j]);
			}
			printf("\n");
		}
		if (pd[0] == len[0])
		{
			len[0] = pu[0];
			pd[0] = pu[0] = 0;
			for (j = 0; j < len[0]; j++)
			{
				down[0][j] = up[0][j];
			}
		}
		if (pd[1] == len[1])
		{
			len[1] = pu[1];
			pd[1] = pu[1] = 0;
			for (j = 0; j < len[1]; j++)
			{
				down[1][j] = up[1][j];
			}
		}
	}
	return 0;
}
int main()
{
	int times, ans;
	scanf("%d", &times);
	for (; times; times--)
	{
		scanf("%s %s", down[0], down[1]);
		len[0] = len[1] = strlen(down[0]);
		pu[0] = pu[1] = pd[0] = pd[1] = 0;
		ans = sim();
		if (ans == 0)
		{
			puts("Keeps going and going ...");
		}
		else if (ans == 1)
		{
			puts("John wins.");
		}
		else
		{
			puts("Jane wins.");
		}
		if (times != 1)
		{
			puts("");
		}
	}
	return 0;
}
