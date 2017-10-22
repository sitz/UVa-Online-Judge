#include <bits/stdc++.h>

using namespace std;

int arr[105][8];
char ch[8][4] = {"NNN", "NNY", "NYN", "NYY", "YNN", "YNY", "YYN", "YYY"};
int re[8], cmp[8], t[4];

int main()
{
	int ca, n;
	while (scanf("%d", &ca) != EOF)
	{
		while (ca--)
		{
			for (int i = 0; i < 8; i++)
			{
				re[i] = i;
			}
			scanf("%d", &n);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < 8; j++)
				{
					scanf("%d", &arr[i][j]);
				}
			for (int i = n - 1; i >= 0; i--)
			{
				for (int j = 0; j < 8; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						t[k] = re[1 << k ^ j];
					}
					cmp[j] = t[0];
					if (arr[i][cmp[j]] > arr[i][t[1]])
					{
						cmp[j] = t[1];
					}
					if (arr[i][cmp[j]] > arr[i][t[2]])
					{
						cmp[j] = t[2];
					}
				}
				for (int j = 0; j < 8; j++)
				{
					re[j] = cmp[j];
				}
			}
			printf("%s\n", ch[re[0]]);
		}
	}
	return 0;
}
