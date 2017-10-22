#include <bits/stdc++.h>

using namespace std;

/**
348
Optimal Array multiplication sequence
**/
#define MAXN 15
#define INF 2147483647
typedef long long ss;
ss M[MAXN][MAXN];
int P[MAXN], S[MAXN][MAXN];
int N, K;
char St[30][3];
void Matrix_Chain_Order()
{
	int i, j, k, l;
	ss q;
	for (i = 1; i <= N; i++)
	{
		M[i][i] = 0;
	}
	for (l = 2; l <= N; l++)
	{
		for (i = 1; i <= N - l + 1; i++)
		{
			j = i + l - 1;
			M[i][j] = INF;
			for (k = i; k <= j - 1; k++)
			{
				q = M[i][k] + M[k + 1][j] + P[i - 1] * P[j] * P[k];
				if (q < M[i][j])
				{
					M[i][j] = q;
					S[i][j] = k;
				}
			}
		}
	}
}
/*
void Print_Op_P(int i, int j) {
    if(i == j){
        sprintf(St[K++],"%d",i);
    }
   else {
    strcpy(St[K++],"(");//printf("(");
    Print_Op_P(i,S[i][j]);
    Print_Op_P(S[i][j]+1,j);
    strcpy(St[K++],")");//printf(")");
  }
}
void Print() {
    int i;
    for(i = 0; i<K; i++) {
        if(!strcmp(St[i],"(")) printf("(");
        else if(!strcmp(St[i],")")) {
            if(!strcmp(St[i+1],"("))
                printf(") x ");
            else if(isdigit(St[i+1][0]))
                printf(") x ");
            else printf(")");
        }
        else if(isdigit(St[i][0])) {
            if(isdigit(St[i+1][0]))
                printf("A%d x ",atoi(St[i]));
            else if(!strcmp(St[i+1],"("))
                printf("A%d x ",atoi(St[i]));
            else printf("A%d",atoi(St[i]));
        }
    }
    printf("\n");
}
*/
void Print(int i, int j)
{
	if (i == j)
	{
		printf("A%d", i);
	}
	else
	{
		printf("(");
		Print(i, S[i][j]);
		printf(" x ");
		Print(S[i][j] + 1, j);
		printf(")");
	}
}
int main()
{
	int i, r, c, kase = 1;
	while (1)
	{
		K = 0;
		scanf("%d", &N);
		if (N == 0)
		{
			break;
		}
		for (i = 0; i < N; i++)
		{
			scanf("%d%d", &r, &c);
			P[i] = r;
		}
		P[i] = c;
		Matrix_Chain_Order();
		// Print_Op_P(1,N);
		printf("Case %d: ", kase++);
		Print(1, N);
		putchar('\n');
	}
	return 0;
}
