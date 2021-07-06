#include <bits/stdc++.h>

using namespace std;

double dp[16 * 16 * 16 * 16 * 5 * 5];
char ss[16 * 16 * 16 * 16 * 5 * 5];
int D[4];
int cas;

double dfs(int mask, int step)
{
	if (ss[mask] == cas)
	{
		return dp[mask];
	}
	int stat[6] = {0}, have[6] = {0};
	ss[mask] = cas;
	double &sum = dp[mask] = 0.0;
	int j1 = mask / 5 % 5, j2 = mask % 5;
	int Mask = mask / 25;
	for (int i = 0; i < 4; ++i)
	{
		have[i] = Mask & 15;
		stat[i] = 13 - have[i];
		Mask >>= 4;
	}
	stat[j1]++, stat[j2]++;
	bool check = false;
	for (int i = 0; i < 4; ++i)
		if (stat[i] < D[i])
		{
			check = true;
			break;
		}
	if (!check)
	{
		return sum = 0.0;
	}
	if (step == 0)
	{
		return sum = 1e100;
	}
	for (int i = 0; i < 4; ++i)
		if (have[i])
		{
			sum += dfs(mask - (1 << (i * 4)) * 25, step - 1) * have[i];
		}
	if (j1 == 4)
	{
		double sun = 1e100;
		for (int i = 0; i < 4; ++i)
		{
			sun = min(sun, dfs(mask - (4 - i) * 5, step - 1));
		}
		sum += sun;
	}
	if (j2 == 4)
	{
		double sun = 1e100;
		for (int i = 0; i < 4; ++i)
		{
			sun = min(sun, dfs(mask - (4 - i), step - 1));
		}
		sum += sun;
	}
	sum = sum / step + 1.0;
	//printf("%d %d %d %d %d %d : %f\n", stat[0], stat[1], stat[2], stat[3], j1, j2, sum);
	return sum;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (cas = 1; cas <= T; ++cas)
	{
		int sum15 = 0, sum14 = 0;
		int idx15 = 0, idx14[2] = {0};
		for (int i = 0; i < 4; ++i)
		{
			scanf("%d", D + i);
			if (D[i] == 15)
			{
				sum15++, idx15 = i;
			}
			if (D[i] == 14)
			{
				idx14[sum14++] = i;
			}
		}
		printf("Case %d: ", cas);
		if (sum15 * 2 + sum14 > 2)
		{
			printf("-1.000\n");
			continue;
		}
		printf("%.3f\n", dfs(1419949, 54));
	}
}
