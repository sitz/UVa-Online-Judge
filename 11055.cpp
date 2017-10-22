#include <bits/stdc++.h>

using namespace std;

/*
11055
*/
#define maxn 1002
int A[maxn][maxn], N;
int isHom()
{
	int i, j;
	for (i = 0; i + 1 < N; i++)
	{
		for (j = 0; j + 1 < N; j++)
		{
			if (A[i][j] + A[i + 1][j + 1] != A[i][j + 1] + A[i + 1][j])
			{
				return 0;
			}
		}
	}
	return 1;
}
int main()
{
	int i, d;
	while (cin >> N && N)
	{
		for (i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> A[i][j];
			}
		}
		d = isHom();
		if (d)
		{
			cout << "homogeneous\n";
		}
		else
		{
			cout << "not homogeneous\n";
		}
	}
	return 0;
}
