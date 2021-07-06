#include <bits/stdc++.h>

using namespace std;

int nseq[20];

string mth_seq(int n, int m)
{
	if (n == 0)
	{
		return "";
	}
	for (int j = 0; j < n; j++)
		if (nseq[n - j - 1] * nseq[j] > m)
		{
			return "E" + mth_seq(n - j - 1, m / nseq[j]) + "S" + mth_seq(j, m % nseq[j]);
		}
		else
		{
			m -= nseq[n - j - 1] * nseq[j];
		}
}

int main()
{
	nseq[0] = 1;
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 0; j < i; j++)
		{
			nseq[i] += nseq[i - j - 1] * nseq[j];
		}
	}
	int N, M;
	while ((cin >> N && N) && (cin >> M && M))
	{
		if (M - 1 >= nseq[N - 1])
		{
			cout << "ERROR" << endl;
		}
		else
		{
			cout << mth_seq(N - 1, M - 1) << endl;
		}
	}
}
