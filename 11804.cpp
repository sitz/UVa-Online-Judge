#include <bits/stdc++.h>

using namespace std;

#define num_play 10

typedef struct
{
	char name[50];
	int attack;
	int defence;
} team;
team player[20], tem;
int main()
{
	int i, j, k, t, test_case;
	while (scanf("%d ", &test_case) == 1)
	{
		for (t = 1; t <= test_case; t++)
		{
			for (i = 0; i < num_play; i++)
			{
				scanf("%s %d %d", &player[i].name, &player[i].attack, &player[i].defence);
			}
			/*sorting for divide in two group*/
			for (i = 0; i < num_play - 1; i++)
			{
				for (k = i + 1; k < num_play; k++)
				{
					if (player[i].attack < player[k].attack)
					{
						tem = player[i];
						player[i] = player[k];
						player[k] = tem;
					}
					else if (player[i].attack == player[k].attack)
					{
						if (player[i].defence > player[k].defence)
						{
							tem = player[i];
							player[i] = player[k];
							player[k] = tem;
						}
						else if (player[i].defence == player[k].defence)
						{
							if (strcmp(player[i].name, player[k].name) > 0)
							{
								tem = player[i];
								player[i] = player[k];
								player[k] = tem;
							}
						}
					}
				}
			}
			/*sorting for lexicography*/
			/*first half attacking*/
			for (i = 0; i < 4; i++)
			{
				for (k = i + 1; k < 5; k++)
				{
					if (strcmp(player[i].name, player[k].name) > 0)
					{
						tem = player[i];
						player[i] = player[k];
						player[k] = tem;
					}
				}
			}
			/*last half defending*/
			for (i = 5; i < 9; i++)
			{
				for (k = i + 1; k < 10; k++)
				{
					if (strcmp(player[i].name, player[k].name) > 0)
					{
						tem = player[i];
						player[i] = player[k];
						player[k] = tem;
					}
				}
			}
			/*printing attack*/
			printf("Case %d:\n", t);
			printf("(");
			for (i = 0; i < 5; i++)
			{
				if (i != 4)
				{
					printf("%s, ", player[i].name);
				}
				else if (i == 4)
				{
					printf("%s)\n", player[i].name);
				}
			}
			/*printing defence*/
			printf("(");
			for (i = 5; i < 10; i++)
			{
				if (i != 9)
				{
					printf("%s, ", player[i].name);
				}
				else if (i == 9)
				{
					printf("%s)\n", player[i].name);
				}
			}
		}
	}
}
