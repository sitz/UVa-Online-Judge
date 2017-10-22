#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	char cmd[10];
	for (scanf("%d\n", &t); t--;)
	{
		int fish = 0, bait = 0, get = 0, time = 0;
		while (gets(cmd) && *cmd)
		{
			if (!strcmp(cmd, "bait") && bait < 6)
			{
				++bait;
			}
			else if (!strcmp(cmd, "fish") && bait > 1)
			{
				if (!get || !fish && !time)
				{
					++get, bait -= 2, fish = 3, time = 7;
				}
			}
			if (fish)
			{
				--fish;
			}
			if (time)
			{
				--time;
			}
		}
		printf("%d%s\n", get, t ? "\n" : "");
	}
	return 0;
}
