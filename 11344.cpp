#include <bits/stdc++.h>

using namespace std;

int mod[13];
void div(char *s)
{
	int i, j;
	for (i = 0; i < 13; i++)
	{
		mod[i] = 0;
	}
	for (i = 0; s[i]; i++)
		for (j = 1; j < 13; j++)
		{
			mod[j] = ((mod[j] * 10) + (s[i] - '0')) % j;
		}
}
int main()
{
	char inp[10000];
	int d, cur;
	int c = 0;
	scanf("%d", &c);
	getchar();
	while (c--)
	{
		gets(inp);
		div(inp);
		scanf("%d", &d);
		char ok = 1;
		while (d--)
		{
			scanf("%d", &cur);
			ok = ok & !mod[cur];
		}
		getchar();
		if (ok)
		{
			printf("%s - Wonderful.\n", inp);
		}
		else
		{
			printf("%s - Simple.\n", inp);
		}
	}
	return 0;
}
