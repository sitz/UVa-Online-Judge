#include <bits/stdc++.h>

using namespace std;

int n;
int m[5][4010];
int vv[2][16000000];
int read()
{
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &m[j][i]);
		}
	}
	return 1;
}
void process()
{
	int i, j, k, l, cont1, cont2;
	cont1 = cont2 = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			vv[0][cont1++] = m[0][i] + m[1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			vv[1][cont2++] = -m[2][i] - m[3][j];
		}
	}
	sort(vv[0], vv[0] + cont1);
	sort(vv[1], vv[1] + cont2);
	int total = 0;
	i = 0;
	j = 0;
	while (i < cont1)
	{
		while (j < cont2 && vv[1][j] < vv[0][i])
		{
			j++;
		}
		if (j == cont2)
		{
			break;
		}
		k = i;
		while (k < cont1 && vv[0][k] == vv[0][i])
		{
			k++;
		}
		l = j;
		while (l < cont2 && vv[1][l] == vv[0][i])
		{
			l++;
		}
		total += (k - i) * (l - j);
		i = k;
		j = l;
	}
	printf("%d\n", total);
}
int main()
{
	int casos;
	scanf("%d", &casos);
	int cc = 0;
	while (casos--)
	{
		if (cc++)
		{
			printf("\n");
		}
		read();
		process();
	}
	return 0;
}
