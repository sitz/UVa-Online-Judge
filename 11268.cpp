#include <bits/stdc++.h>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define iter(a) typeof((a).begin())
#define Tr(a, b) for (iter(b) a = (b).begin(); a != (b).end(); ++a)
#define Fr(a, b, c) for (int a = b; a < c; ++a)
#define rF(a, b, c) for (int a = c - 1; a >= b; --a)
#define Rp(a, b) Fr(a, 0, b)
#define fr Fr
#define rp Rp
#define cl(a, b) memset(a, b, sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, pair<int, int>> pdi;
typedef vector<pair<int, int>> vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define MAXN 1000
#define MAXM 120000
#define MOD 200003

int gcd(int a, int b)
{
	return (!b) ? a : gcd(b, a % b);
}

int T, n, m, mm;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		mm = 0;
		if (m & 1)
			printf("%d\n", n * ((m + 1) >> 1));
		else
			printf("%d\n", n * (m >> 1) + ((n + 1) >> 1));
		fr(i, 1, n)
		{
			fr(j, 1, n + 1) printf("%d %d\n", j, (j + i - 1) % n + 1);
			mm += 2;
			if (mm >= m)
				break;
		}
		if (m % 2 == 0)
		{
			fr(j, 1, ((n + 1) >> 1) + 1) printf("%d %d\n", j, (j + n / 2 - 1) % n + 1);
		}
		puts("");
	}
	return 0;
}