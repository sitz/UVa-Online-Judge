#include <bits/stdc++.h>

using namespace std;

/////////////////////////////////
// 11547 - Automatic Answer
/////////////////////////////////
#define pos(a) (a < 0 ? -a : a)
int n, c;
int main()
{
	scanf("%d", &c);
	while (c--)
	{
		scanf("%d", &n);
		printf("%d\n", pos((315 * n + 36962) % 100 / 10));
	}
}
