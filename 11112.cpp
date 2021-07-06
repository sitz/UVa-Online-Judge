#include <bits/stdc++.h>

using namespace std;

int main()
{
	int ip, bet, fp;
	while (scanf("%d%d%d", &ip, &bet, &fp) == 3)
	{
		if ((ip | bet | fp) == 0)
		{
			break;
		}
		if (ip == fp)
		{
			printf("0\n");
			continue;
		}
		ip = abs(ip - fp);
		if (ip % bet)
		{
			printf("No accounting tablet\n");
			continue;
		}
		printf("%d\n", (ip / bet - 1) / 3 + 1);
	}
	return 0;
}
