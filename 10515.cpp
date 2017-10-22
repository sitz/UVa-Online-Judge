#include <bits/stdc++.h>

using namespace std;

int main()
{
	char ca[102], cb[102];
	int a, b, c;
	for (;;)
	{
		scanf("%s%s", &ca, &cb);
		if (ca[0] == '0' && ca[1] == '\0' && cb[0] == '0' && cb[1] == '\0')
		{
			break;
		}
		if (cb[0] == '0' && cb[1] == '\0')
		{
			printf("1\n");
			continue;
		}
		for (c = 0; ca[c] != '\0'; c++)
			;
		a = (int)(ca[c - 1] - '0');
		for (c = 0; cb[c] != '\0'; c++)
			;
		if (c >= 2)
		{
			b = (int)(cb[c - 2] - '0') * 10 + (int)(cb[c - 1] - '0');
		}
		else
		{
			b = (int)(cb[c - 1] - '0');
		}
		c = 1;
		for (int i = 0; i < (b + 3) % 4 + 1; i++)
		{
			c = c * a % 10;
		}
		printf("%d\n", c);
	}
	return 0;
}
