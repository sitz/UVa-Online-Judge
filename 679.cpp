#include <bits/stdc++.h>

using namespace std;

/**
679
**/
int D, L, P;
void Cal()
{
	int i;
	P = 1;
	for (i = 0; i < D - 1; i++)
	{
		P = L % 2 != 0 ? 2 * P : 2 * P + 1;
		L = (L + 1) / 2;
	}
	printf("%d\n", P);
}
int main()
{
	int kase;
	while (1)
	{
		scanf("%d", &kase);
		if (kase == -1)
		{
			break;
		}
		while (kase--)
		{
			scanf("%d%d", &D, &L);
			Cal();
		}
	}
	return 0;
}
