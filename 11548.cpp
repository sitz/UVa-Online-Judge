#include <bits/stdc++.h>

using namespace std;

char str[80][80];
int mat[80][80];
int n;
int read()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		str[i][0] = ' ';
		scanf("%s", str[i] + 1);
	}
}
int match(int a, int b)
{
	for (int i = 0; str[a][i]; i++)
	{
		mat[i][0] = 0;
	}
	for (int i = 0; str[b][i]; i++)
	{
		mat[0][i] = 0;
	}
	for (int i = 1; str[a][i]; i++)
	{
		for (int j = 1; str[b][j]; j++)
		{
			mat[i][j] = mat[i - 1][j - 1];
			if (str[a][i] == str[b][j])
			{
				mat[i][j]++;
			}
		}
	}
	int max = 0;
	int la = strlen(str[a] + 1);
	int lb = strlen(str[b] + 1);
	for (int i = 1; str[a][i]; i++)
	{
		if (mat[i][lb] > max)
		{
			max = mat[i][lb];
		}
	}
	for (int i = 1; str[b][i]; i++)
	{
		if (mat[la][i] > max)
		{
			max = mat[la][i];
		}
	}
	return max;
}
void process()
{
	int best = 0, ret;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			ret = match(i, j);
			if (ret > best)
			{
				best = ret;
			}
		}
	}
	printf("%d\n", best);
}
int main()
{
	int casos;
	scanf("%d", &casos);
	while (casos--)
	{
		read();
		process();
	}
	return 0;
}
