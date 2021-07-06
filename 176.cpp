#include <bits/stdc++.h>

using namespace std;

long vzdal[51][51][4];
struct _s {int neex1, neex2;};
struct _s smerx[49][50];
struct _s smery[50][49];
int fronta[16000], vefronte;
char vstup[100];
int i, j, k, l, m, n, start, konec, navic;
long vysl;

void zarad(int p)
{
	int x, y, z;
	long v;
	v = vzdal[(fronta[n] >> 8) & 63][(fronta[n] >> 2) & 63][fronta[n] & 3];

	if (p == konec)
	{
		vysl = v;
		return;
	}

	x = (p >> 8) & 63;
	y = (p >> 2) & 63;
	z = p & 3;

	switch (z)
	{
	case 2:
		if (x == 0)
		{
			return;
		}
		if (smerx[x - 1][y].neex1 == -1)
		{
			v += 50;
			x--;
		}
		else
		{
			if (smerx[x - 1][y].neex2 == 49)
			{
				return;
			}
			v += 98 - 2 * smerx[x - 1][y].neex2;
			z = 0;
		}
		break;

	case 0:
		if (x == 49)
		{
			return;
		}
		if (smerx[x][y].neex1 == -1)
		{
			v += 50;
			x++;
		}
		else
		{
			if (smerx[x][y].neex1 == 0)
			{
				return;
			}
			v += 2 * smerx[x][y].neex1;
			z = 2;
		}
		break;

	case 3:
		if (y == 0)
		{
			return;
		}
		if (smery[x][y - 1].neex1 == -1)
		{
			v += 50;
			y--;
		}
		else
		{
			if (smery[x][y - 1].neex2 == 49)
			{
				return;
			}
			v += 98 - 2 * smery[x][y - 1].neex2;
			z = 1;
		}
		break;

	case 1:
		if (y == 49)
		{
			return;
		}
		if (smery[x][y].neex1 == -1)
		{
			v += 50;
			y++;
		}
		else
		{
			if (smery[x][y].neex1 == 0)
			{
				return;
			}
			v += 2 * smery[x][y].neex1;
			z = 3;
		}
		break;
	}

	if (vzdal[x][y][z] != -1)
	{
		return;
	}

	vzdal[x][y][z] = v;

	if ((fronta[vefronte++] = (x << 8) + (y << 2) + z) == konec)
	{
		vysl = v;
	}
}

int main()
{
	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 49; j++)
		{
			smery[i][j].neex1 = smerx[j][i].neex1 = -1;
		}
	}

	gets(vstup);

	while (vstup[0] != '#')
	{
		sscanf(vstup + 1, "%d", &i);
		sscanf(vstup + 4, "%d", &j);
		sscanf(vstup + 9, "%d", &k);

		if (vstup[0] == 'A')
		{
			for (l = j / 100; l <= k / 100; l++)
			{
				smery[i][l].neex1 = (l == j / 100) ? j % 100 / 2 : 0;
				smery[i][l].neex2 = (l == k / 100) ? (k % 100) / 2 : 49;
			}
		}
		else
		{
			for (l = j / 100; l <= k / 100; l++)
			{
				smerx[l][i].neex1 = (l == j / 100) ? j % 100 / 2 : 0;
				smerx[l][i].neex2 = (l == k / 100) ? (k % 100) / 2 : 49;
			}
		}
		gets(vstup);
	}

	gets(vstup);

	while (vstup[0] != '#')
	{
		for (i = 0; i < 51; i++)
		{
			for (j = 0; j < 51; j++)
			{
				for (k = 0; k < 4; k++)
				{
					vzdal[i][j][k] = -1;
				}
			}
		}

		navic = 0;
		vysl = -1;
		sscanf(vstup + 1, "%d", &i);
		sscanf(vstup + 4, "%d", &j);

		if (vstup[0] == 'A')
		{
			if (j & 1)
			{
				if ((smery[i][j / 100].neex1 == -1) || ((j >> 1) % 50 > smery[i][j / 100].neex2))
				{
					start = (i << 8) + ((j / 100 + 1) << 2) + 1;
					navic += 49 - (j >> 1) % 50;
				}
				else
				{
					start = (i << 8) + ((j / 100) << 2) + 3;
					navic += 2 * smery[i][j / 100].neex1 - (j >> 1) % 50 - 1;
				}
			}
			else if ((smery[i][j / 100].neex1 == -1) || ((j >> 1) % 50 < smery[i][j / 100].neex1))
			{
				start = (i << 8) + ((j / 100) << 2) + 3;
				navic += (j >> 1) % 50;
			}
			else
			{
				start = (i << 8) + ((j / 100 + 1) << 2) + 1;
				navic += 48 + (j >> 1) % 50 - 2 * smery[i][j / 100].neex2;
			}
		}
		else if (j & 1)
		{
			if ((smerx[j / 100][i].neex1 == -1) || ((j >> 1) % 50 > smerx[j / 100][i].neex2))
			{
				start = (i << 2) + ((j / 100 + 1) << 8) + 0;
				navic += 49 - (j >> 1) % 50;
			}
			else
			{
				start = (i << 2) + ((j / 100) << 8) + 2;
				navic += 2 * smerx[j / 100][i].neex1 - (j >> 1) % 50 - 1;
			}
		}
		else if ((smerx[j / 100][i].neex1 == -1) || ((j >> 1) % 50 < smerx[j / 100][i].neex1))
		{
			start = (i << 2) + ((j / 100) << 8) + 2;
			navic += (j >> 1) % 50;
		}
		else
		{
			start = (i << 2) + ((j / 100 + 1) << 8) + 0;
			navic += 48 + (j >> 1) % 50 - 2 * smerx[j / 100][i].neex2;
		}

		m = i;
		n = j;
		sscanf(vstup + 10, "%d", &i);
		sscanf(vstup + 13, "%d", &j);

		if (vstup[9] == 'A')
		{
			if (j & 1)
			{
				if ((smery[i][j / 100].neex1 == -1) || ((j >> 1) % 50 < smery[i][j / 100].neex1))
				{
					konec = (i << 8) + ((j / 100) << 2) + 1;
					navic += (j >> 1) % 50;
					if ((vstup[0] == 'A') && (n / 100 == j / 100) && (m == i) && (n & 1) && ((n >> 1) % 50 <= (j >> 1) % 50))
					{
						vysl = (j - n) >> 1;
					}
				}
				else
				{
					konec = (i << 8) + ((j / 100 + 1) << 2) + 3;
					navic += 48 + (j >> 1) % 50 - 2 * smery[i][j / 100].neex2;
					if ((vstup[0] == 'A') && (start + 4 - 2 == konec) && ((n >> 1) % 50 > smery[i][j / 100].neex2))
					{
						if (!(n & 1))
						{
							vysl = -1 + (n >> 1) % 50 + (j >> 1) % 50 - 2 * smery[i][j / 100].neex2;
						}
						else if (n <= j)
						{
							vysl = (j - n) >> 1;
						}
					}
				}
			}
			else if ((smery[i][j / 100].neex1 == -1) || ((j >> 1) % 50 > smery[i][j / 100].neex2))
			{
				konec = (i << 8) + ((j / 100 + 1) << 2) + 3;
				navic += 49 - (j >> 1) % 50;
				if ((vstup[0] == 'A') && (n / 100 == j / 100) && (m == i) && (!(n & 1)) && ((j >> 1) % 50 <= (n >> 1) % 50))
				{
					vysl = (n - j) >> 1;
				}
			}
			else
			{
				konec = (i << 8) + ((j / 100) << 2) + 1;
				navic += 2 * smery[i][j / 100].neex1 - (j >> 1) % 50 - 1;
				if ((vstup[0] == 'A') && (start - 4 + 2 == konec) && ((n >> 1) % 50 < smery[i][j / 100].neex1))
				{
					if (n & 1)
					{
						vysl = 2 * smery[i][j / 100].neex1 - (n >> 1) % 50 - (j >> 1) % 50 - 1;
					}
					else if (j <= n)
					{
						vysl = (n - j) >> 1;
					}
				}
			}
		}
		else if (j & 1)
		{
			if ((smerx[j / 100][i].neex1 == -1) || ((j >> 1) % 50 < smerx[j / 100][i].neex1))
			{
				konec = (i << 2) + ((j / 100) << 8) + 0;
				navic += (j >> 1) % 50;

				if ((vstup[0] == 'S') && (n / 100 == j / 100) && (m == i) && (n & 1) && ((n >> 1) % 50 <= (j >> 1) % 50))
					vysl = (j - n) >> 1;
			}
			else
			{
				konec = (i << 2) + ((j / 100 + 1) << 8) + 2;
				navic += 48 + (j >> 1) % 50 - 2 * smerx[j / 100][i].neex2;

				if ((vstup[0] == 'S') && (start == konec - 2) && ((n >> 1) % 50 > smerx[j / 100][i].neex2))
				{
					if (!(n & 1))
						vysl = -1 + (n >> 1) % 50 + (j >> 1) % 50 - 2 * smerx[j / 100][i].neex2;
					else if (n <= j)
						vysl = (j - n) >> 1;
				}
			}
		}
		else if ((smerx[j / 100][i].neex1 == -1) || ((j >> 1) % 50 > smerx[j / 100][i].neex2))
		{
			konec = (i << 2) + ((j / 100 + 1) << 8) + 2;
			navic += 49 - (j >> 1) % 50;
			if ((vstup[0] == 'S') && (n / 100 == j / 100) && (m == i) && (!(n & 1)) && ((j >> 1) % 50 <= (n >> 1) % 50))
			{
				vysl = (n - j) >> 1;
			}
		}
		else
		{
			konec = (i << 2) + ((j / 100) << 8) + 0;
			navic += 2 * smerx[j / 100][i].neex1 - (j >> 1) % 50 - 1;
			if ((vstup[0] == 'S') && (start == konec + 2) && ((n >> 1) % 50 < smerx[j / 100][i].neex1))
			{
				if (n & 1)
				{
					vysl = 2 * smerx[j / 100][i].neex1 - (n >> 1) % 50 - (j >> 1) % 50 - 1;
				}
				else if (j <= n)
				{
					vysl = (n - j) >> 1;
				}
			}
		}

		if (vysl >= 0)
		{
			printf("%ld\n", --vysl);
		}
		else
		{
			fronta[0] = start;
			vzdal[(start >> 8) & 63][(start >> 2) & 63][start & 3] = 0;
			n = 0;
			vefronte = 1;
			while (vysl < 0)
			{
				if ((vysl < 0) && ((fronta[n] & 3) != 0))
				{
					zarad((fronta[n] & 0xfffc) | 2);
				}
				if ((vysl < 0) && ((fronta[n] & 3) != 1))
				{
					zarad((fronta[n] & 0xfffc) | 3);
				}
				if ((vysl < 0) && ((fronta[n] & 3) != 2))
				{
					zarad((fronta[n] & 0xfffc) | 0);
				}
				if ((vysl < 0) && ((fronta[n] & 3) != 3))
				{
					zarad((fronta[n] & 0xfffc) | 1);
				}
				n++;
			}
			printf("%ld\n", vysl + navic);
		}
		gets(vstup);
	}
	return 0;
}
