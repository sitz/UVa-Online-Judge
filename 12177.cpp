#include <bits/stdc++.h>

using namespace std;

// method : linear equations, Gaussian elimination for band-limited matrices
// runtime: O(m*n^3)

// move from (i,j) to (i+di[k-1],j+dj[k-1])
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

const int maxn = 64;
const int maxv = maxn * maxn;

// equation system is matrix * unknowns = vec
// band[i][j] is matrix[i][i-n+j]; rest of matrix is 0
double band[maxv][2 * maxn + 1];
double vec[maxv];

int main()
{
	cout.setf(ios::fixed);
	cout.precision(16);
	int m, n;
	while (cin >> m >> n)
	{
		if (m == 0 || n == 0)
		{
			break;
		}
		// matrix := 1; vec := (0,1,...,1)
		for (int i = 0; i < m * n; i++)
			for (int j = 0; j < 2 * n + 1; j++)
			{
				band[i][j] = 0.0;
			}
		for (int i = 0; i < m * n; i++)
		{
			band[i][n] = vec[i] = 1.0;
		}
		vec[0] = 0.0;
		// enter probabilities into matrix
		for (int k = 0; k < 4; k++)
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
				{
					double p;
					cin >> p;
					// moving out of the area?
					if (0 <= i + di[k] && i + di[k] < m &&
							0 <= j + dj[k] && j + dj[k] < n)
					{
						// there are m*m blocks of size n*n
						// index i*n+j is row #j of block #i
						// columns addressed relative to diagonal at index n
						int i1 = (n * m - 1) - (i * n + j);
						int j1 = (n * m - 1) - ((i + di[k]) * n + (j + dj[k]));
						// reverse rows and columns of matrix
						band[i1][j1 + n - i1] = -p;
					}
				}
		// forward elimination
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				// pivot is on the diagonal
				double p = band[i * n + j][n];
				// normalise the current row
				vec[i * n + j] /= p;
				for (int q = 0; q <= n && i * n + j + q < m * n; q++)
				{
					band[i * n + j][n + q] /= p;
				}
				// eliminate first columns of next n rows
				for (int r = 1; r <= n && i * n + j + r < m * n; r++)
					// p = the first entry of row r below the current one
					if ((p = band[i * n + j + r][n - r]) != 0.0)
					{
						// row operation
						vec[i * n + j + r] -= p * vec[i * n + j];
						for (int q = 0; q <= n && i * n + j + q < m * n; q++)
						{
							band[i * n + j + r][n - r + q] -= p * band[i * n + j][n + q];
						}
					}
			}
		// solution is in last row of vec
		cout << vec[m * n - 1] << endl;
	}
	return 0;
}
