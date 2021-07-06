#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 29)
#define SET(a) memset(a, -1, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define CLR(a) memset(a, 0, sizeof(a))
#define FILL(a, v) memset(a, v, sizeof(a))
#define PB push_back
#define FOR(i, n) for (int i = 0; i < n; i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a, b) make_pair(a, b)
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define LL long long
#define MX 100000
#define MOD 1000000007

bool isfib[1000 + 10];
int fib[20], n;

int main()
{
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i < 18; i++)
	{
		int x = fib[i] = fib[i - 1] + fib[i - 2];
		isfib[x] = true;
	}
	while (cin >> n && n)
	{
		if (n == 1 || !isfib[n])
			cout << "Alicia" << endl;
		else
			cout << "Roberto" << endl;
	}
	return 0;
}
