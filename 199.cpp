#include <bits/stdc++.h>

using namespace std;

int main()
{
	int m, n, v[3][3], g[3][3], b[4][31], f[31][31], *a = new int[841 * 841];
	for (cin >> m; --m >= 0;)
	{
		cin >> n;
		int r[841] = {0}, nSize = (n - 1) * (n - 1), h2 = n * n;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j<3; cin>> v[i][j++])
				;
		}
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j<3; cin>> g[i][j++])
				;
		}
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j<n + 1; cin>> b[i][j++])
				;
		}
		for (int i = 0; i < n + 1; ++i)
		{
			for (int j = 0; j<n + 1; cin>> f[i][j++])
				;
		}
		for (int i = 1; i < n; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				int id = (i - 1) * (n - 1) + j - 1;
				for (int s = 0; s < 3; ++s)
				{
					for (int t = 0; t < 3; ++t)
					{
						int as = i + s - 1, at = j + t - 1;
						r[id] += f[as][at] * g[s][t];
						if (as == 0)
						{
							r[id] -= b[1][at] * v[s][t] * h2;
						}
						else if (at == 0)
						{
							r[id] -= b[2][n - as] * v[s][t] * h2;
						}
						else if (as == n)
						{
							r[id] -= b[0][at] * v[s][t] * h2;
						}
						else if (at == n)
						{
							r[id] -= b[3][n - as] * v[s][t] * h2;
						}
						else
						{
							int aid = (as - 1) * (n - 1) + at - 1;
							a[id * nSize + aid] = v[s][t] * h2;
						}
					}
				}
			}
		}
		for (int i = 0; i < nSize; ++i)
		{
			for (int j = 0; j < nSize - 1; ++j)
			{
				cout << a[i * nSize + j] << ' ';
			}
			cout << a[i * nSize + nSize - 1] << endl;
		}
		for (int i = 0; i < nSize - 1; ++i)
		{
			cout << r[i] << ' ';
		}
		cout << r[nSize - 1] << endl;
	}
	delete[] a;
	return 0;
}
