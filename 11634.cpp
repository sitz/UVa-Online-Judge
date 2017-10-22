#include <bits/stdc++.h>

using namespace std;

int map_[10001];

int main()
{
	int a;
	int cnt = 0;
	while (scanf("%d", &a) != EOF)
	{
		memset(map_, 0, sizeof(map_));
		if (!a)
		{
			break;
		}
		cnt = 0;
		while (1)
		{
			map_[a]++;
			if (map_[a] > 1)
			{
				break;
			}
			a *= a;
			a /= 100;
			a %= 10000;
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
