#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)

int mypower(int a, int b)
{
	int result = 1;
	FOR(i, 0, b)
	{
		result *= a;
	}
	return result;
}

int hex_to_int(int n)
{
	int result = 0, counter = 0, tmp;
	while (n > 0)
	{
		tmp = n % 10;
		n /= 10;
		result += tmp * mypower(16, counter);
		counter++;
	}
	return result;
}

static unsigned int n, num;

int main()
{
	scanf("%u", &n);
	while (n--)
	{
		scanf("%u", &num);
		printf("%d %d\n", __builtin_popcount(num), __builtin_popcount(hex_to_int(num)));
	}
	return 0;
}
