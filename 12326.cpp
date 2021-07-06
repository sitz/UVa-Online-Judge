#include <bits/stdc++.h>

using namespace std;

int ans[30];

int main()
{
	ans[1] = 1;
	ans[2] = 1;
	ans[3] = 1;
	ans[4] = 4;
	ans[5] = 6;
	ans[6] = 19;
	ans[7] = 43;
	ans[8] = 120;
	ans[9] = 307;
	ans[10] = 866;
	ans[11] = 2336;
	ans[12] = 6588;
	ans[13] = 18373;
	ans[14] = 52119;
	ans[15] = 147700;
	ans[16] = 422016;
	int ntest, n;
	scanf("%d", &ntest);
	for (int test = 1; test <= ntest; test++)
	{
		scanf("%d", &n);
		printf("Case #%d: %d\n", test, ans[n]);
	}
	return 0;
}
