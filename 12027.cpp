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
	while (true)
	{
		string str;
		int i, j;
		cin >> str;
		if (str == "0")
			break;
		int L = str.length();
		int N = (int)(str[0] - '0');
		if (L % 2 == 0)
		{
			N *= 10;
			N += (str[1] - '0');
		}
		cout << (int)sqrt(N);
		FOI(i, 1, ceil(L / 2.0) - 1)
		cout << "0";
		cout << endl;
	}
	return 0;
}
