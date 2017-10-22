#include <bits/stdc++.h>

using namespace std;

/*
 *  Algorithm: Math Problem.
 *      This problem is egyptian number problem.
 *      You can get the conclusion from here:
 *        http://mathworld.wolfram.com/EgyptianNumber.html
 * */

const int not_strict_egyptian_num[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 17,
																			 18, 19, 20, 21, 22, 23, 25, 26, 27, 28, 29, 33, 34, 35, 36, 39, 40, 41, 42, 44, 46, 47,
																			 48, 49, 51, 56, 58, 63, 68, 70, 72, 77};
const int size = 47;

int ans[1000001];
bool egy[1000001];

void init()
{
	int i;
	memset(egy, true, sizeof(egy));
	for (i = 0; i < size; i++)
	{
		egy[not_strict_egyptian_num[i]] = false;
	}
	for (i = 1, ans[0] = 0; i <= 1000000; i++)
	{
		if (egy[i])
		{
			ans[i] = ans[i - 1] + 1;
		}
		else
		{
			ans[i] = ans[i - 1];
		}
	}
}

int main()
{
	init();
	int T, a, b;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &a, &b);
		if (a > b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		printf("%d\n", ans[b] - ans[a - 1]);
	}
	return 0;
}
