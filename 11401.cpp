#include <bits/stdc++.h>

using namespace std;

/*
  Name: UVA 11401
  Author: zoom
  Date: 28/07/11
*/

#define LLU long long unsigned int
#define LLD long long double
#define FOR(i, N) for (int i = 0; i < (N); i++)
LLU ans[1000001];
int main()
{
	ans[0] = ans[1] = ans[2] = ans[3] = 0;
	LLU inc = 0;
	int N;
	for (int i = 4; i < 1000001; i++)
	{
		inc += (i - 2) / 2;
		ans[i] = ans[i - 1] + inc;
	}
	while (cin >> N and N >= 3)
	{
		cout << ans[N] << endl;
	}
}
