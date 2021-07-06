#include <bits/stdc++.h>

using namespace std;

/**
444
***/
#define MAXN 300
char Valid[MAXN];
char Mss[MAXN];
char Temp[MAXN + MAXN];
char p[] = ".!,.:;? ";
void Set()
{
	int i, j;
	for (i = 0; i < MAXN; i++)
	{
		Valid[i] = 0;
	}
	for (i = 0; p[i]; i++)
	{
		j = p[i];
		Valid[j] = 1;
	}
	for (char c = 'A'; c <= 'z'; c++)
	{
		j = c;
		Valid[j] = j;
	}
}
void Decode()
{
	int i, j, k;
	char temp[10];
	Temp[0] = NULL;
	for (i = 0; Mss[i]; i++)
	{
		j = Mss[i];
		sprintf(temp, "%d", j);
		strcat(Temp, temp);
	}
	k = strlen(Temp);
	for (i = k - 1; i >= 0; i--)
	{
		printf("%c", Temp[i]);
	}
	printf("\n");
}
void Encode()
{
	int i, j, l = 0, k;
	char temp[10000];
	k = strlen(Mss);
	for (i = k - 1; i >= 0; i--)
	{
		temp[l++] = Mss[i] - '0';
	}
	for (i = 0; i < l;)
	{
		j = temp[i] * 10 + temp[i + 1];
		if (Valid[j])
		{
			printf("%c", j);
			i += 2;
		}
		else
		{
			j = temp[i] * 100 + temp[i + 1] * 10 + temp[i + 2];
			printf("%c", j);
			i += 3;
		}
	}
	printf("\n");
}
int main()
{
	Set();
	while (gets(Mss))
	{
		if (isdigit(Mss[0]))
		{
			Encode();
		}
		else
		{
			Decode();
		}
	}
	return 0;
}
