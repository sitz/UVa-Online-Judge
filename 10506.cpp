#include <bits/stdc++.h>

using namespace std;

/*
10506
Ouroboros
*/
#define maxn 65539
char F[maxn];
char R[maxn];
int B, S, Ter;
int Dec(char ss[])
{
	int i, d = 1, sum = 0;
	for (i = S - 1; i >= 0; i--)
	{
		sum += (ss[i] - '0') * d;
		d *= B;
	}
	return sum;
}
void Print(int ind)
{
	int i = 0, j = ind;
	while (1)
	{
		if (R[i] != R[j])
		{
			R[j + 1] = NULL;
			puts(R);
			return;
		}
		i++;
		j--;
	}
}
int Recur(char ss[], int level, int ind)
{
	char temp[50];
	int k, i;
	k = Dec(ss);
	if (F[k])
	{
		return 0;
	}
	R[ind] = ss[S - 1];
	if (level == Ter)
	{
		R[ind + 1] = NULL;
		//puts(R);
		Print(ind);
		return 1;
	}
	F[k] = 1;
	for (i = 1; i < S; i++)
	{
		temp[i - 1] = ss[i];
	}
	for (i = 0; i < B; i++)
	{
		temp[S - 1] = i + '0';
		temp[S] = NULL;
		if (Recur(temp, level + 1, ind + 1))
		{
			F[k] = 0;
			return 1;
		}
	}
	F[k] = 0;
	return 0;
}
void Cal()
{
	int i, j, ind, k;
	char ss[20], temp[20];
	Ter = (int)pow(B, S);
	for (i = 1; i < Ter; i++)
	{
		ind = 0;
		k = i;
		while (k)
		{
			temp[ind++] = k % B + '0';
			k /= B;
		}
		for (j = 0; j < S - ind; j++)
		{
			ss[j] = '0';
		}
		k = ind - 1;
		for (j; j < S; j++)
		{
			ss[j] = temp[k--];
		}
		ss[j] = NULL;
		for (k = 0; k + 1 < S; k++)
		{
			R[k] = ss[k];
		}
		if (Recur(ss, 1, S - 1))
		{
			return;
		}
	}
}
int main()
{
	while (scanf("%d%d", &S, &B) == 2)
	{
		if (B <= 1)
		{
			printf("0\n");
			continue;
		}
		Cal();
	}
	return 0;
}
