#include <bits/stdc++.h>

using namespace std;

int main()
{
	int P, H, O;
	while (scanf("%d%d%d", &P, &H, &O) == 3)
	{
		if (H > O - P)
		{
			printf("Hunters win!\n");
		}
		else
		{
			printf("Props win!\n");
		}
	}
	return 0;
}
