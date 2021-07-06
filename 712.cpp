#include <bits/stdc++.h>

using namespace std;

/**
712
**/
int N[20];
int tn;
char Val[130];
char VVA[10];
struct ss
{
	char val;
} node[10];
int Cal()
{
	int i, lo, up = 1, k;
	int diff;
	lo = 1;
	for (i = 0; i < tn; i++)
	{
		up *= 2;
	}
	for (i = 0; VVA[i]; i++)
	{
		node[i + 1].val = VVA[i] - '0';
	}
	for (i = 0; i < tn; i++)
	{
		k = N[i];
		diff = up - lo + 1;
		if (node[k].val == 0)
		{
			up = lo + (diff / 2) - 1;
		}
		else
		{
			lo = (lo + diff / 2);
		}
	}
	if (node[k].val == 1)
	{
		printf("%c", Val[up]);
	}
	else
	{
		printf("%c", Val[lo]);
	}
	return 0;
}
int main()
{
	int i, kase, t = 1;
	char input[100];
	while (scanf("%d", &tn) == 1)
	{
		if (!tn)
		{
			break;
		}
		for (i = 0; i < tn; i++)
		{
			scanf("%s", input);
			input[0] = '0';
			sscanf(input, "%d", &N[i]);
		}
		scanf("%s", Val + 1);
		scanf("%d", &kase);
		printf("S-Tree #%d:\n", t++);
		while (kase--)
		{
			scanf("%s", VVA);
			Cal();
		}
		printf("\n\n");
	}
	return 0;
}
