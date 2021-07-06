#include <bits/stdc++.h>

using namespace std;

typedef std::istringstream ISS;
typedef std::ostringstream OSS;
typedef std::vector<std::string> VS;
typedef long long LL;
typedef int INT;
typedef std::vector<INT> VI;
typedef std::vector<VI> VVI;
typedef std::pair<INT, INT> II;
typedef std::vector<II> VII;

const int SIZE = 1011;
int L, N, X[SIZE], W[SIZE];

inline LL solve()
{
	LL res = 0;
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		if (sum + W[i] > L)
		{
			res += X[i] * 2;
			sum = 0;
		}
		res += X[i];
		sum += W[i];
		if (i - 1 >= 0)
		{
			res -= X[i - 1];
		}
		if (i + 1 < N && sum == L)
		{
			res += X[i] * 2;
			sum = 0;
		}
	}
	res += X[N - 1];
	return res;
}

int main()
{
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; ++i)
	{
		cin >> L >> N;
		for (int i = 0; i < N; ++i)
			cin >> X[i] >> W[i];
		cout << solve() << endl;
	}
	return 0;
}
