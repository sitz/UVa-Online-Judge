#include <bits/stdc++.h>

using namespace std;

typedef long long int Integer;

Integer f(Integer n)
{
	return n * (n + 1) / 2;
}

#define MAX 1000001
int main()
{
	int n;
	Integer *F = new Integer[MAX];
	Integer dpn;
	Integer *DP = new Integer[MAX];
	F[1] = 1;
	dpn = 0;
	DP[0] = 0;
	for (n = 1; n < MAX; ++n)
	{
		dpn = f(n) - dpn;
		DP[n] = DP[n - 1] + dpn;
		if (n > 1)
		{
			F[n] = F[n - 1] + f(n);
		}
	}
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		Integer X, Y;
		Integer tX;
		cin >> X >> Y;
		if (Y < X)
		{
			swap(X, Y);
		}
		--X;
		tX = 2 * X + 1;
		if (tX >= Y)
		{
			tX = Y;
			X = Y - (1 + X);
		}
		Integer ans = F[X + 1] + (DP[Y] - DP[tX]) - f(X) * (Y - tX);
		cout << ans << endl;
	}
	delete[] F;
	delete[] DP;
	return 0;
}
