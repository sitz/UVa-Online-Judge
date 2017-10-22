#include <bits/stdc++.h>

using namespace std;

int solve(int Z, int I, int M, int L)
{
	int i, cnt = 1, seed;
	bool flag[10000];
	for (i = 0; i < 10000; i++)
	{
		flag[i] = false;
	}
	seed = L;
	flag[L] = true;
	while (flag[(Z * L + I) % M] == false)
	{
		flag[(Z * L + I) % M] = true;
		L = (Z * L + I) % M;
		cnt++;
	}
	if (seed != (Z * L + I) % M)
	{
		cnt--;
	}
	return cnt;
}

int main()
{
	int Z, I, M, L, case_num = 1;
	while (cin >> Z >> I >> M >> L)
	{
		if (Z == 0 && I == 0 && M == 0 && L == 0)
		{
			break;
		}
		cout << "Case " << case_num++ << ": " << solve(Z, I, M, L) << endl;
	}
	return 0;
}
