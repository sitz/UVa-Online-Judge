#include <bits/stdc++.h>

using namespace std;

char str[100];
struct ss {int Job[30], ind;} com[12];
int F[30], T, Count[30], A[12];

void Reset()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		F[i] = com[i].ind = Count[i] = 0;
	}
	for (i; i < 30; i++)
	{
		F[i] = Count[i] = 0;
	}
}
void Set()
{
	int i, j, k, m;
	k = str[0] - 'A';
	m = str[1] - '0';
	F[k] += m;
	T += m;
	for (i = 3; str[i] != ';'; i++)
	{
		j = str[i] - '0';
		com[j].Job[com[j].ind++] = k;
	}
}
void Print()
{
	int i, j;
	for (i = 1; i < 11; i++)
	{
		j = A[i];
		if (j == 28)
			printf("_");
		else
			printf("%c", j + 'A');
	}
	printf("\n");
}
int BackTrak(int n, int level, int total, int cm)
{
	int i, j, m, k;
	A[level] = cm;
	if (level == 10)
	{
		if (T == total)
		{
			Print();
			return 1;
		}
		return 0;
	}
	Count[cm]++;
	for (i = n + 1; i < 10; i++)
	{
		for (j = 0; j < com[i].ind; j++)
		{
			m = com[i].Job[j];
			k = total;
			if (m != 28)
			{
				k = total + 1;
			}
			if (Count[m] < F[m] || m == 28)
			{
				if (BackTrak(i, level + 1, k, m))
				{
					return 1;
				}
			}
		}
	}
	Count[cm]--;
	return 0;
}
void Cal()
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		com[i].Job[com[i].ind++] = 28;
	}
	if (T > 10)
	{
		printf("!\n");
		return;
	}
	j = BackTrak(-1, 0, 0, 29);
	if (!j)
	{
		printf("!\n");
	}
}

int main()
{
	int i;
	while (gets(str))
	{
		T = 0;
		Set();
		while (gets(str))
		{
			for (i = 0; str[i]; i++)
			{
				if (str[i] == '\n')
				{
					str[i] = '\0';
					break;
				}
			}
			if (strlen(str) == 0)
			{
				break;
			}
			Set();
		}
		Cal();
		Reset();
	}
	return 0;
}
