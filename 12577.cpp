#include <bits/stdc++.h>

using namespace std;

#define Inf 2147483647
#define Pi acos(-1.0)
#define N 1000000
#define LL long long

inline LL Power(int b, int p)
{
	LL ret = 1;
	for (int i = 1; i <= p; i++)
	{
		ret *= b;
	}
	return ret;
}
const int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

#define F(i, a, b) for (int i = (a); i < (b); i++)
#define Fs(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fe(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define Set(a, s) memset(a, s, sizeof(a))
#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)

int main()
{
	char input[50];
	int cases = 0;
	while (scanf("%s", input) && strcmp(input, "*"))
	{
		if (strcmp(input, "Hajj") == 0)
			printf("Case %d: Hajj-e-Akbar\n", ++cases);
		else
			printf("Case %d: Hajj-e-Asghar\n", ++cases);
	}
	return 0;
}
