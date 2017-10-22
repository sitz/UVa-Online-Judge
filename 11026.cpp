#include <bits/stdc++.h>

using namespace std;

/*
11026
Grouping Problem
*/

#define maxn 1001
typedef long long INT;
INT T[maxn + 1][maxn + 1];
INT A[maxn + 1], M, N, MAXX;
void Gen()
{
	INT i, j, k;
	MAXX = -1;
	T[1][0] = 1;
	T[1][1] = A[1];
	if (N == 1)
	{
		MAXX = A[1] % M;
	}
	for (i = 2; i <= N; i++)
	{
		T[i][0] = 1;
		for (j = 1; j < i; j++)
		{
			k = (T[i - 1][j] + T[i - 1][j - 1] * A[i]) % M;
			if (k > MAXX && i == N)
			{
				MAXX = k;
			}
			T[i][j] = k;
		}
		T[i][i] = (T[i - 1][i - 1] * A[i]) % M;
		if (T[i][i] > MAXX && i == N)
		{
			MAXX = T[i][i];
		}
	}
	cout << MAXX << endl;
	//printf("%I64d\n",MAXX);
}
int main()
{
	while (cin >> N >> M)
	{
		if (!N && !M)
		{
			break;
		}
		for (INT i = 1; i <= N; i++)
		{
			//  scanf("%I64d",&A[i]);
			cin >> A[i];
			A[i] %= M;
		}
		Gen();
	}
	return 0;
}
