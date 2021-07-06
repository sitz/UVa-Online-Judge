#include <bits/stdc++.h>

using namespace std;

char np[13][32];
int Up, Lb, N, ind, st[13];

void ReadCase()
{
	char temp[35], ss[100];
	int i, j;
	gets(ss);
	N = 0;
	while (gets(temp))
	{
		for (i = 0; temp[i]; i++)
			if (temp[i] == '\n')
				temp[i] = NULL;
		if (strlen(temp) == 0)
			break;
		strcpy(np[N++], temp);
	}
	if (!strcmp(ss, "*"))
	{
		Up = N;
		Lb = 1;
		return;
	}
	j = sscanf(ss, "%d%d", &Lb, &Up);
	if (j == 2)
		return;
	Lb = Up = Lb;
}
void recur(int n, int level, int Limit)
{
	int i, j;
	st[level] = n;
	if (level == Limit)
	{
		j = st[0];
		printf("%s", np[j]);
		for (j = 1; j <= level; j++)
			printf(", %s", np[st[j]]);
		printf("\n");
		return;
	}
	for (i = n + 1; i < N; i++)
		recur(i, level + 1, Limit);
}
void Cal()
{
	int i, j;
	for (i = Lb; i <= Up; i++)
	{
		printf("Size %d\n", i);
		for (j = 0; j <= N - i; j++)
			recur(j, 0, i - 1);
		printf("\n");
	}
}

int main()
{
	char input[100];
	int kase;
	gets(input);
	sscanf(input, "%d", &kase);
	gets(input);
	while (kase--)
	{
		ReadCase();
		Cal();
		if (kase)
			printf("\n");
	}
	return 0;
}
