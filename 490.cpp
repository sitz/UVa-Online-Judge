#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i = -1, j = -1, k, l, max = 0;
	char ch[200][200], a;
	while (scanf("%c", &a) != EOF)
	{
		i++;
		j = -1;
		while (a != 10)
		{
			if (a != 9)
			{
				j++;
				ch[i][j] = a;
			}
			scanf("%c", &a);
		}
		if (j > max)
		{
			max = j;
		}
	}
	for (l = 0; l <= max; l++)
	{
		for (k = i; k >= 0; k--)
		{
			if (ch[k][l] <= '\0')
			{
				ch[k][l] = ' ';
			}
			printf("%c", ch[k][l]);
		}
		printf("\n");
	}
	return 0;
}
