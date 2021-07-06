#include <bits/stdc++.h>

using namespace std;

int mark[30][30], n, prox[30][2], tira[30], ehIgual[30][30], q[30];
int read()
{
	char p[3], p1[3], p2[3], tipo[3];
	if (scanf("%d", &n) == EOF)
	{
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%s%s%s%s", p, p1, p2, tipo);
		prox[p[0] - 'A'][0] = p1[0] - 'A';
		prox[p[0] - 'A'][1] = p2[0] - 'A';
		q[p[0] - 'A'] = tipo[0];
	}
	return 1;
}
int go(int i, int j)
{
	if (ehIgual[i][j] != -1)
	{
		return ehIgual[i][j];
	}
	if (i == j || mark[i][j])
	{
		return 1;
	}
	mark[i][j] = mark[j][i] = 1;
	if (q[i] != q[j])
	{
		return ehIgual[i][j] = ehIgual[j][i] = 0;
	}
	if (go(prox[i][0], prox[j][0]) && go(prox[i][1], prox[j][1]))
	{
		ehIgual[i][j] = ehIgual[j][i] = 1;
	}
	else
	{
		ehIgual[i][j] = ehIgual[j][i] = 0;
	}
	return ehIgual[i][j];
}
void process()
{
	memset(mark, 0, sizeof(mark));
	memset(tira, 0, sizeof(tira));
	memset(ehIgual, -1, sizeof(ehIgual));
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (mark[i][j] == 0)
			{
				go(i, j);
			}
			if (ehIgual[i][j])
			{
				tira[j] = 1;
			}
		}
	for (int i = 0; i < n; i++)
	{
		if (tira[i])
		{
			continue;
		}
		if (i)
		{
			printf(" ");
		}
		printf("%c", 'A' + i);
	}
	printf("\n");
}
int main()
{
	while (read())
	{
		process();
	}
	return 0;
}
