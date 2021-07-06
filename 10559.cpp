#include <bits/stdc++.h>

using namespace std;

int F[201][201][201];
int len[201], color[201], ptr;
int n, seq[201], t;
inline int sqr(int k)
{
	return k * k;
}
int f(int i, int j, int k)
{
	if (i > j)
	{
		return 0;
	}
	if (F[i][j][k])
	{
		return F[i][j][k];
	}
	F[i][j][k] = f(i, j - 1, 0) + sqr(len[j] + k);
	for (int p = i; p < j; p++)
		if (color[p] == color[j] && f(i, p, len[j] + k) + f(p + 1, j - 1, 0) > F[i][j][k])
		{
			F[i][j][k] = F[i][p][len[j] + k] + F[p + 1][j - 1][0];
		}
	return F[i][j][k];
}
int main()
{
	int i, j;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++)
	{
		scanf("%d", &n);
		ptr = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", seq + i);
		}
		for (i = 1; i <= n; i = j)
		{
			color[++ptr] = seq[i];
			for (j = i + 1; j <= n && seq[i] == seq[j]; j++)
				;
			len[ptr] = j - i;
		}
		memset(F, 0, sizeof(F));
		/*for(int i=1;i<=ptr;i++)   F[i][i-1][0]=0;
		for(int j=0;j<=ptr;j++)
		    for(int i=1;i<=j;i++)
		        for(int k=0;k<=n;k++)
		        {
		            F[i][j][k]=F[i][j-1][0]+sqr(len[j]+k);
		            for(int p=i;p<j;p++)
		                if(color[p]==color[j]&&F[i][p][len[j]+k]+F[p+1][j-1][0]>F[i][j][k])
		                    F[i][j][k]=F[i][p][len[j]+k]+F[p+1][j-1][0];
		        }*/
		printf("Case %d: %d\n", c, f(1, ptr, 0));
	}
	return 0;
}
