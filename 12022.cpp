#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

#define FOI(i, A, B) for (i = A; i <= B; i++)
#define FOD(i, A, B) for (i = A; i >= B; i--)
#define PI acos(-1.0)
#define INF 1 << 30
#define EPS 1e-9
#define sqr(x) (x) * (x)

int main()
{
	int64 num[] = {1, 1, 3, 13, 75, 541, 4683, 47293, 545835, 7087261, 102247563, 1622632573};
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		cout << num[N] << endl;
	}
	return 0;
}
