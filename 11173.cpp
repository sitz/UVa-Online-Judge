#include <bits/stdc++.h>

using namespace std;

int main()
{
	long b, num, bit, t;
	scanf("%ld", &b);
	while (b--)
	{
		scanf("%ld%ld", &bit, &num);
		printf("%ld\n", num ^ (num >> 1));
	}
	return 0;
}
