#include <bits/stdc++.h>

using namespace std;

#define Inf 2147483647
#define Pi acos(-1.0)
#define N 1000000
#define M 100000
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

#define F(i, a, b) for (int i = (a); i < (b); i++)
#define Fs(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fe(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define Set(a, s) memset(a, s, sizeof(a))
#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)

bool mark[M + 100];
map<string, bool> stringMap;

void sieve()
{
	Set(mark, true);
	mark[0] = mark[1] = false;
	for (int i = 4; i < M; i += 2)
	{
		mark[i] = false;
	}
	for (int i = 3; i * i <= M; i += 2)
		if (mark[i])
			for (int j = i * i; j < M; j += 2 * i)
			{
				mark[j] = false;
			}
}

void generateStringMap()
{
	stringMap["2"] = true;
	char str[10];
	for (int i = 3; i < M; i += 2)
		if (mark[i])
		{
			sprintf(str, "%d", i);
			stringMap[str] = true;
		}
}

int main()
{
	sieve();
	generateStringMap();
	string input;
	while (cin >> input && input != "0")
	{
		int len = input.size();
		int ret = -1;
		for (int digit = 5; digit >= 1; digit--)
			for (int i = 0; i + digit - 1 < len; i++)
				if (stringMap[input.substr(i, digit)])
					ret = max(ret, atoi(input.substr(i, digit).c_str()));
		printf("%d\n", ret);
	}
	return 0;
}
