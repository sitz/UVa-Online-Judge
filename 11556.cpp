#include <bits/stdc++.h>

using namespace std;

/////////////////////////////////
// 11556 - Best Compression Ever
/////////////////////////////////
unsigned long long int a, b;
const char *y = "yes", *n = "no";
int main()
{
	while (scanf("%llu %llu", &a, &b) != EOF)
		if (a < 1LLU << (b + 1))
		{
			puts(y);
		}
		else
		{
			puts(n);
		}
	return 0;
}
