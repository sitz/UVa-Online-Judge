#include <bits/stdc++.h>

using namespace std;

const int N = 205;
int t, s, c, a[N][N];

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &s, &c);
		memset(a, 0, sizeof(a));
		for (int i = 0; i < s; i++)
		{
			scanf("%d", &a[0][i]);
		}
		for (int i = 1; i < s; i++)
		{
			for (int j = 0; j < s - i; j++)
			{
				a[i][j] = a[i - 1][j + 1] - a[i - 1][j];
			}
		}
		for (int i = 0; i < c; i++)
		{
			for (int j = s - 1; j >= 0; j--)
			{
				a[j][s - j + i] = a[j + 1][s - j - 1 + i] + a[j][s - j - 1 + i];
			}
			printf("%d%c", a[0][s + i], (i == c - 1 ? '\n' : ' '));
		}
	}
	return 0;
}
