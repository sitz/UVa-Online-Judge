#include <bits/stdc++.h>

using namespace std;

char tbl[6][6][3], ss[6][3];
int rank_[300], A[6];

int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}
void Ini()
{
	char tt[] = "A23456789XJQK";
	int i, j;
	for (i = 0; tt[i]; i++)
	{
		j = tt[i];
		rank_[j] = i;
	}
}
int Fourofkind()
{
	int i, k, j;
	int a[10] = {0};
	for (i = 0; i < 5; i++)
	{
		if (a[i])
		{
			continue;
		}
		k = 1;
		for (j = i + 1; j < 5; j++)
		{
			if (ss[i][0] == ss[j][0])
			{
				k++;
				a[j] = 1;
			}
		}
		if (k == 4)
		{
			return 1;
		}
	}
	return 0;
}
int Fullhouse()
{
	int a[10] = {0}, b[10] = {0}, i, j, c;
	for (i = 0; i < 5; i++)
	{
		if (a[i])
			continue;
		c = 1;
		for (j = i + 1; j < 5; j++)
		{
			if (ss[i][0] == ss[j][0])
			{
				c++;
				a[j] = 1;
			}
		}
		b[c]++;
	}
	return b[3] == 1 && b[2] == 1;
}
int Flush()
{
	int i;
	for (i = 1; i < 5; i++)
	{
		if (ss[i][1] != ss[i - 1][1])
		{
			return 0;
		}
	}
	return 1;
}
int Straight()
{
	int i, j, d = 1, c, k;
	int f[15] = {0};
	for (i = 0; i < 5; i++)
	{
		j = ss[i][0];
		c = rank_[j];
		f[c] = 1;
		k = c;
	}
	c = k + 1;
	c %= 13;
	while (f[c])
	{
		d++;
		c++;
		c %= 13;
	}
	c = k - 1 + 13;
	c %= 13;
	while (f[c])
	{
		d++;
		c--;
		c = (c + 13) % 13;
	}
	return d == 5;
}
int Threeofakind()
{
	int a[6] = {0}, i, c;
	for (i = 0; i < 5; i++)
	{
		if (a[i])
		{
			continue;
		}
		c = 1;
		for (int j = i + 1; j < 5; j++)
		{
			if (ss[i][0] == ss[j][0])
			{
				c++;
				a[j] = 1;
			}
		}
		if (c == 3)
		{
			return 1;
		}
	}
	return 0;
}
int Twopair()
{
	int a[7] = {0}, b[7] = {0}, i, j, c;
	for (i = 0; i < 5; i++)
	{
		if (a[i])
		{
			continue;
		}
		c = 1;
		for (j = i + 1; j < 5; j++)
		{
			if (ss[i][0] == ss[j][0])
			{
				c++;
				a[j] = 1;
			}
		}
		b[c]++;
	}
	return b[2] == 2;
}
int Onepair()
{
	int a[6] = {0}, i, c;
	for (i = 0; i < 5; i++)
	{
		if (a[i])
		{
			continue;
		}
		c = 1;
		for (int j = i + 1; j < 5; j++)
		{
			if (ss[i][0] == ss[j][0])
			{
				c++;
				a[j] = 1;
			}
		}
		if (c == 2)
		{
			return 1;
		}
	}
	return 0;
}
int Decide()
{
	int f, s;
	if (Fourofkind())
	{
		return 8;
	}
	if (Fullhouse())
	{
		return 7;
	}
	f = Flush();
	s = Straight();
	if (s && f)
	{
		return 9;
	}
	if (f)
	{
		return 6;
	}
	if (s)
	{
		return 5;
	}
	if (Threeofakind())
	{
		return 4;
	}
	if (Twopair())
	{
		return 3;
	}
	if (Onepair())
	{
		return 2;
	}
	return 1;
}
void Cal()
{
	int a[10] = {0};
	int i, j, d;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			strcpy(ss[j], tbl[i][j]);
		}
		d = Decide();
		a[d]++;
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			strcpy(ss[j], tbl[j][i]);
		}
		d = Decide();
		a[d]++;
	}
	printf("%d", a[1]);
	for (i = 2; i <= 9; i++)
	{
		printf(", %d", a[i]);
	}
	printf("\n");
}
void ReadCase()
{
	int i, j, k = 0;
	char input[100];
	while (gets(input))
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '\n')
			{
				input[i] = NULL;
			}
		}
		if (strlen(input) == 0)
		{
			break;
		}
		sscanf(input, "%s%s%s%s%s", tbl[k][0], tbl[k][1], tbl[k][2], tbl[k][3], tbl[k][4]);
		k++;
		if (k % 5 == 0)
		{
			Cal();
		}
	}
}

int main()
{
	int kase;
	char in[100];
	gets(in);
	sscanf(in, "%d", &kase);
	gets(in);
	Ini();
	while (kase--)
	{
		ReadCase();
		if (kase)
		{
			printf("\n");
		}
	}
	return 0;
}
