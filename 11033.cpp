#include <bits/stdc++.h>

using namespace std;

int N, M, P;
int temp[4][4], sol[2][4][4], sols;
int main()
{
	int caseno = 1;
	while (scanf("%d %d %d", &N, &M, &P) == 3)
	{
		if (!N && !M && !P)
		{
			break;
		}
		printf("Set %d:\n", caseno++);
		sols = 0;
		int mod;
		for (int a = 1; a <= 7; a++)
		{
			temp[0][0] = a;
			for (int b = 1; b <= 7; b++)
			{
				temp[0][1] = b;
				for (int c = 1; c <= 7; c++)
				{
					if (a + b + c >= N || (N - (a + b + c) > 7))
					{
						continue;
					}
					temp[0][2] = c;
					temp[0][3] = N - a - b - c;
					for (int d = 1; d <= 7; d++)
					{
						temp[1][0] = d;
						for (int e = 1; e <= 7; e++)
						{
							temp[1][1] = e;
							for (int f = 1; f <= 7; f++)
							{
								if (d + e + f >= N || (N - (d + e + f) > 7))
								{
									continue;
								}
								temp[1][2] = f;
								temp[1][3] = N - d - e - f;
								for (int g = 1; g <= 7; g++)
								{
									if (a + d + g >= N || (N - (a + d + g) > 7))
									{
										continue;
									}
									temp[2][0] = g;
									temp[3][0] = N - a - d - g;
									if (temp[0][3] + temp[1][2] + temp[3][0] >= N ||
											(N - (temp[0][3] + temp[1][2] + temp[3][0]) > 7))
									{
										continue;
									}
									temp[2][1] = N - (temp[0][3] + temp[1][2] + temp[3][0]);
									if (temp[0][1] + temp[1][1] + temp[2][1] >= N ||
											(N - (temp[0][1] + temp[1][1] + temp[2][1]) > 7))
									{
										continue;
									}
									temp[3][1] = N - (temp[0][1] + temp[1][1] + temp[2][1]);
									int s12 = N - temp[2][0] - temp[2][1], s34 = N - temp[3][0] - temp[3][1];
									int s13 = N - temp[0][2] - temp[1][2], s24 = N - temp[0][3] - temp[1][3];
									int s14 = N - temp[0][0] - temp[1][1];
									int d34 = s13 - s14;
									if ((d34 + s34) & 1)
									{
										continue;
									}
									int x3 = (d34 + s34) >> 1, x4 = s34 - x3;
									int x1 = s14 - x4, x2 = s12 - x1;
									if (x1 < 1 || x1 > 7 || x2 < 1 || x2 > 7 || x3 < 1 || x3 > 7 || x4 < 1 || x4 > 7)
									{
										continue;
									}
									temp[2][2] = x1;
									temp[2][3] = x2;
									temp[3][2] = x3;
									temp[3][3] = x4;
									mod = 1;
									for (int i = 0; i < 4; i++)
										for (int j = 0; j < 4; j++)
										{
											mod = (mod * temp[i][j]) % M;
										}
									if (mod <= P)
									{
										if (sols < 2)
										{
											for (int i = 0; i < 4; i++)
												for (int j = 0; j < 4; j++)
												{
													sol[sols][i][j] = temp[i][j];
												}
										}
										sols++;
									}
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n", sols);
		for (int i = 0; i < sols && i < 2; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					printf("%d", sol[i][j][k]);
				}
				puts("");
			}
			puts("....");
		}
	}
}
