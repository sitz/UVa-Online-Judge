#include <bits/stdc++.h>

using namespace std;

#define MAXN 105

char M[MAXN][MAXN];
int tt, N;

struct ss
{
	int a, b, c;
};
ss *rec;

void Cal()
{
	int i, j, k;
	rec = new ss[MAXN * MAXN];
	tt = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (i == j)
				continue;
			for (k = 1; k <= N; k++)
			{
				if ((i < j && j < k) || (i > j && j > k))
				{
					if (M[i][j] && M[j][k] && M[k][i])
					{
						rec[tt].a = i;
						rec[tt].b = j;
						rec[tt++].c = k;
					}
					else if (!M[i][j] && !M[j][i] && !M[i][k] && !M[k][i])
					{
						if (!M[k][j] && !M[j][k] && i < j && j < k)
						{
							rec[tt].a = i;
							rec[tt].b = j;
							rec[tt++].c = k;
						}
					}
				}
			}
		}
	}
	printf("%d\n", tt);
	for (i = 0; i < tt; i++)
		printf("%d %d %d\n", rec[i].a, rec[i].b, rec[i].c);
	delete[] rec;
}

int main()
{
	int i, j, x;
	while (scanf("%d", &N) == 1)
	{
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
			{
				scanf("%d", &x);
				M[i][j] = x;
			}
		Cal();
	}
	return 0;
}
