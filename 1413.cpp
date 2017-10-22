#include <bits/stdc++.h>

using namespace std;

const int L = 0, R = 1;
int n, k;
double p[55], pn[55][55][2][2], px[55][55][2];

int main()
{
	while (scanf("%d%d", &n, &k) != EOF)
	{
		for (int i = 0; i < n - 1; i++)
		{
			scanf("%lf", &p[i]);
		}

		for (int i = 0; i < 55; i++)
		{
			for (int j = 0; j < 55; j++)
			{
				pn[i][j][L][L] = pn[i][j][R][L] = pn[i][j][R][R] = pn[i][j][L][R] = px[i][j][L] = px[i][j][R] = 0;
			}
		}

		for (int i = 0; i < n - 1; i++)
		{
			pn[i][i][L][L] = 1.0f - p[i];
			pn[i][i][R][L] = 1.0f - p[i];
			pn[i][i][R][R] = p[i];
			pn[i][i][L][R] = p[i];
		}

		for (int d = 2; d < n; d++)
		{
			for (int i = 0; i + d < n; i++)
			{
				int j = i + d - 1;
				pn[i][j][L][L] = (1.0f - p[i]) / ((1.0f - p[i]) + p[i] * pn[i + 1][j][L][R]);
				pn[i][j][R][L] = (1.0f - p[j]) * pn[i][j - 1][R][L] / ((1.0f - p[j]) * pn[i][j - 1][R][L] + p[j]);
				pn[i][j][R][R] = p[j] / (p[j] + (1.0f - p[j]) * pn[i][j - 1][R][L]);
				pn[i][j][L][R] = p[i] * pn[i + 1][j][L][R] / (1.0f - p[i] + p[i] * pn[i + 1][j][L][R]);
			}
		}

		px[k - 1][k - 1][L] = 1.0f;

		for (int d = 2; d < n; d++)
		{
			for (int i = 0; i + d < n; i++)
			{
				int j = i + d - 1;
				px[i][j][L] = px[i + 1][j][L] * pn[i + 1][j][L][L] + px[i + 1][j][R] * pn[i + 1][j][R][L];
				px[i][j][R] = px[i][j - 1][L] * pn[i][j - 1][L][R] + px[i][j - 1][R] * pn[i][j - 1][R][R];
			}
		}

		printf("%.10lf\n", px[0][n - 2][L] + px[0][n - 2][R]);
	}
	return 0;
}
