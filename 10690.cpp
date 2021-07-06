#include <bits/stdc++.h>

using namespace std;

int N, M, a[110];
bool bag[5010][55];
int ll[250006][2], l;

int cmp(const void *a, const void *b)
{
	int *aa = (int *)a;
	int *bb = (int *)b;
	return *bb - *aa;
}

int main()
{
	while (cin >> N >> M)
	{
		if (N > M)
		{
			int t = N;
			N = M;
			M = t;
		}
		int sum = 0, sum2 = 0;
		for (int i = 0; i < N + M; i++)
		{
			cin >> a[i];
			sum += a[i];
			a[i] += 50;
		}
		qsort(a, N + M, sizeof(int), cmp);
		for (int i = 0; i < N; i++)
		{
			sum2 += a[i];
		}
		memset(bag, 0, sizeof(bag));
		bag[0][0] = true;
		l = 0;
		ll[l][0] = 0;
		ll[l++][1] = 0;
		for (int i = 0; i < N + M; i++)
		{
			int tmpl = l;
			for (int j = 0; j < tmpl; j++)
			{
				if (ll[j][0] + a[i] <= sum2 && ll[j][1] + 1 <= N && bag[ll[j][0] + a[i]][ll[j][1] + 1] == false)
				{
					bag[ll[j][0] + a[i]][ll[j][1] + 1] = true;
					ll[l][0] = ll[j][0] + a[i];
					ll[l++][1] = ll[j][1] + 1;
				}
			}
		}
		int mmin = 100000000, mmax = -100000000;
		for (int i = 0; i <= sum2; i++)
		{
			if (bag[i][N])
			{
				int x = i - 50 * N;
				int y = sum - x;
				if (x * y > mmax)
				{
					mmax = x * y;
				}
				if (x * y < mmin)
				{
					mmin = x * y;
				}
			}
		}
		cout << mmax << " " << mmin << endl;
	}
	return 0;
}
