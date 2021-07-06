#include <bits/stdc++.h>

using namespace std;

// O(n^2) randomized solution to 'Comparing answers' (Freivalds' algorithm).
// David Garcia Soriano.

const int maxn = 1000;
int mat[2][maxn][maxn];

int n;

vector<int> mult(int mi, vector<int> &x)
{
	vector<int> ret(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			ret[i] += mat[mi][i][j] * x[j];
		}
	return ret;
}

int main()
{
	while (scanf("%i", &n), n)
	{
		for (int nm = 0; nm < 2; ++nm)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
				{
					scanf("%i", &mat[nm][i][j]);
				}
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			v[i] = rand();
		}
		vector<int> Av = mult(0, v), A2v = mult(0, Av),
								Bv = mult(1, v);
		bool equal = true;
		for (int i = 0; i < n; ++i)
			if (A2v[i] != Bv[i])
			{
				equal = false;
				break;
			}
		puts(equal ? "YES" : "NO");
	}
	return 0;
}
