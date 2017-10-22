#include <bits/stdc++.h>

using namespace std;

#define MAXN 15

char Num1[MAXN], Num2[MAXN], Comm[3][5], Res[MAXN], Val_1[MAXN], Val_2[MAXN];
const char SS[] = "VUCD";
int VV[150];

struct ss
{
	int len;
} Q;
void Set()
{
	int i;
	for (i = 0; SS[i]; i++)
	{
		int k = SS[i];
		VV[k] = i;
	}
}
void GetV()
{
	int i, j;
	int l = strlen(Num1);
	Q.len = 5;
	for (i = l - 1; i >= 0; i--)
	{
		j = Num1[i];
		Val_1[i] = VV[j];
	}
	l = strlen(Num2);
	for (i = l - 1; i >= 0; i--)
	{
		j = Num2[i];
		Val_2[i] = VV[j];
	}
}
void ADD()
{
	char Temp[MAXN];
	char TVal[MAXN];
	int i, j, c = 0;
	int k = 0, s, d;
	s = Q.len;
	d = 4;
	for (i = 0; i < MAXN; i++)
	{
		TVal[i] = 0;
	}
	i = s - 1;
	while (1)
	{
		TVal[i] = Val_1[d--];
		if (d == -1)
		{
			break;
		}
		i--;
	}
	for (i = s - 1; i >= 0; i--)
	{
		j = TVal[i] + Val_2[i] + c;
		Temp[k++] = j % 4;
		c = j / 4;
	}
	if (c)
	{
		Temp[k++] = c;
	}
	c = 0;
	Q.len = k;
	for (i = k - 1; i >= 0; i--)
	{
		Val_2[i] = Temp[c++];
	}
}
void Right()
{
	int i;
	for (i = Q.len - 1; i >= 1; i--)
	{
		Val_2[i] = Val_2[i - 1];
	}
	Val_2[0] = 0;
}
void Left()
{
	int i;
	i = Q.len;
	Val_2[i++] = 0;
	Q.len = i;
}
int GetR()
{
	int i, l = Q.len, d = 8 - l, x = d;
	char RES[MAXN];
	for (i = 0; i < l; i++)
	{
		int j = Val_2[i];
		RES[d++] = SS[j];
	}
	for (i = 0; i < x; i++)
	{
		RES[i] = 'V';
	}
	RES[d] = '\0';
	return !strcmp(RES, Res);
}
void Cal()
{
	int i, j;
	GetV();
	for (i = 0; i < 3; i++)
	{
		if (Comm[i][0] == 'A')
		{
			ADD();
		}
		else if (Comm[i][0] == 'R')
		{
			Right();
		}
		else if (Comm[i][0] == 'L')
		{
			Left();
		}
	}
	j = GetR();
	if (j)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}

int main()
{
	int n, i;
	Set();
	printf("COWCULATIONS OUTPUT\n");
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", Num1);
		scanf("%s", Num2);
		for (i = 0; i < 3; i++)
		{
			scanf("%s", Comm[i]);
		}
		scanf("%s", Res);
		Cal();
	}
	printf("END OF OUTPUT\n");
	return 0;
}
