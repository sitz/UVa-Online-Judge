#include <bits/stdc++.h>

using namespace std;

long long myabs(long long in)
{
	return (in >= 0) ? in : -in;
}

int main()
{
	long long hashmat, enemy;
	while (scanf("%lld %lld ", &hashmat, &enemy) == 2)
	{
		printf("%lld\n", myabs(enemy - hashmat));
	}
	return 0;
}
