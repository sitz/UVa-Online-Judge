#include <bits/stdc++.h>

using namespace std;

struct xx
{
	char *col;
};
struct ss
{
	xx *cc;
};
ss *S;
int R, C;

int Srow(char dummy[])
{
	int i, j, k = 0, m = 1;
	int l = strlen(dummy);
	for (i = l - 1; i >= 0; i--)
	{
		if (dummy[i] == 'a')
			break;
		j = dummy[i] - 'A' + 1;
		k += j * m;
		m *= 26;
	}
	return k;
}
int Recur(int r, int c)
{
	int val = 0, i, j, k, tf = 0, nr, nc;
	char Formula[100][20], *p;
	char dum[10];
	if (S[r].cc[c].col[0] != '=')
		return atoi(S[r].cc[c].col);
	p = strtok(S[r].cc[c].col, "+");
	while (p)
	{
		strcpy(Formula[tf++], p);
		p = strtok(NULL, "+");
	}
	for (i = 0; i < tf; i++)
	{
		Formula[0][0] = 'a';
		for (j = 0; Formula[i][j] && isalpha(Formula[i][j]); j++)
		{
			dum[j] = Formula[i][j];
		}
		dum[j] = '\0';
		nc = Srow(dum);
		k = 0;
		for (j; Formula[i][j] && isdigit(Formula[i][j]); j++)
		{
			dum[k++] = Formula[i][j];
		}
		dum[k] = '\0';
		nr = atoi(dum);
		val += Recur(nr, nc);
	}
	sprintf(S[r].cc[c].col, "%d", val);
	return val;
}
void Cal()
{
	int i, j;
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			if (S[i].cc[j].col[0] != '=')
				printf("%s", S[i].cc[j].col);
			else
				printf("%d", Recur(i, j));
			if (j < C)
				printf(" ");
		}
		printf("\n");
	}
	delete[] S;
}
char ttm[1000005];

int main()
{
	int ks, i, j, l;
	scanf("%d", &ks);
	while (ks--)
	{
		scanf("%d%d", &C, &R);
		S = new ss[R + 1];
		for (i = 1; i <= R; i++)
		{
			S[i].cc = new xx[C + 1];
			for (j = 1; j <= C; j++)
			{
				scanf("%s", ttm);
				l = strlen(ttm);
				S[i].cc[j].col = new char[l + 4];
				strcpy(S[i].cc[j].col, ttm);
			}
		}
		Cal();
	}
	return 0;
}
