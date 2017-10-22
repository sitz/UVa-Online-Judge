#include <bits/stdc++.h>

using namespace std;

/**
  f(n, k) = # of permutations of n elements, st. exactly k of them
  are in their correct position, eg. f(3, 1) = 3
  which are {1,3,2}, {3,2,1} and {2,1,3}.
  Then ans = sum for every 0≤k≤m of f(n, k).

  D(n) = Numbers of arrangenents of n elements
  for every n we have f(n, 0) = D(n)
  in general, f(n, k) = choose(n, k) * D(n - k)

  The idea behind this is that we fix k elements from the whole
  sequence of n elements in choose(n, k) ways, and for each possibility,
  we rearrange completely the missing n-k elements in D(n-k) ways.

  D(i) is computed using a recursive function, although this could also
  be found using inclusion-exclusion principle.
*/

const int N = 20;

long long choose[N + 1][N + 1], d[N + 1];//d[i] = # of arrangements for i elements

int main()
{
	// Binomial coefficients
	for (int i = 0; i <= N; ++i)
		choose[i][0] = choose[i][i] = 1;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j < i; ++j)
			choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];

	// Arrangements
	d[0] = 1, d[1] = 0;
	for (int i = 2; i <= N; ++i)
		d[i] = (i - 1) * (d[i - 2] + d[i - 1]);

	int n, m;
	while (cin >> n >> m)
	{
		long long ans = 0;
		for (int k = 0; k <= m; ++k)
			ans += choose[n][k] * d[n - k];
		cout << ans << endl;
	}
	return 0;
}
