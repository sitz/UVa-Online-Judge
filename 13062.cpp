#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int main()
{
	// [ big ][ small ]
	double pill[N][N] = {{0}}, day[N][N] = {{0}};

	for (int i = 0; i < N; ++i)
		pill[0][i] = i;
	for (int i = 1; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			pill[i][j] = i / double(i + j) * pill[i - 1][j + 1];
			if (j)
				pill[i][j] += j / double(i + j) * pill[i][j - 1];
		}

	for (int i = 1; i < N; ++i)
		day[i][0] = i;
	for (int i = 1; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			day[i][j] = 1 + i / double(i + j) * day[i - 1][j + 1];
			if (j)
				day[i][j] += j / double(i + j) * day[i][j - 1];
		}

	for (int l, s; scanf("%d %d", &l, &s) && l + s;)
		printf("%.12f %.12f\n", pill[l][s], day[l][s]);
}
