#include <bits/stdc++.h>

using namespace std;

int main()
{
	for (int n; scanf("%d", &n) == 1 && n; puts(n & (n + 1) ? "Alice" : "Bob"))
		;
	return 0;
}
