#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned int n, m;
	while (scanf("%u%u", &n, &m) == 2)
	{
		printf("%u\n", n ^ m);
	}
	return 0;
}
