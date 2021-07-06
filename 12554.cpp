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

#define F(i, a, b) for (int i = (a); i < (b); i++)
#define Fs(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fe(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define Set(a, s) memset(a, s, sizeof(a))
#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)

char ppl[100 + 5][100 + 5];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", ppl[i]);
	}
	// how many lines would get printed
	int loop;
	if (n % 16)
		loop = n / 16 + 1;
	else
		loop = n / 16;
	loop *= 16;
	char str[5][10] = {"Happy", "birthday", "to", "you", "Rujia"};
	int pplIndex = 0;
	int strIndex = 0;
	// "Rujia" will be printed on every 12th of 16th times
	int cnt = 1;
	for (int i = 0; i < loop; i++)
	{
		printf("%s: ", ppl[pplIndex++]);
		pplIndex %= n;
		if (cnt % 12 == 0)
		{
			// printing "Rujia"
			printf("%s\n", str[4]);
			strIndex = 0;
		}
		else
		{
			printf("%s\n", str[strIndex++]);
			strIndex %= 4;
		}
		cnt++;
		// one full cycle song completed
		if (cnt > 16)
		{
			cnt = 1;
		}
	}
	return 0;
}
