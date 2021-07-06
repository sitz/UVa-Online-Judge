#include <bits/stdc++.h>

using namespace std;

int calc(int up, int down, int press)
{
	int D = std::max(0, press * up / (up + down) - (press * up % (up + down) == 0));
	return up * (press - D) - down * D;
}

int main()
{
	for (int press, elevator; scanf("%d %d", &press, &elevator) == 2;)
	{
		int ans = INT_MAX, up, down;
		for (int i = 0; i < elevator; ++i)
		{
			scanf("%d %d", &up, &down);
			ans = std::min(ans, calc(up, down, press));
		}
		printf("%d\n", ans);
	}
}
