#include <bits/stdc++.h>

using namespace std;

struct kid
{
	char name[100];
	char fst;
	char sec;
	int ji;
	int no;
} s[100000], zzl;
int top;
char a[10000000];
int lena;

bool cmp(kid x, kid y)
{
	if (x.ji == y.ji)
	{
		return x.no < y.no;
	}
	else
	{
		return x.ji > y.ji;
	}
}

bool who(char x, char y)
{
	if (x == 'S' && y == 'P')
	{
		return 1;
	}
	if (x == 'P' && y == 'R')
	{
		return 1;
	}
	if (x == 'R' && y == 'S')
	{
		return 1;
	}
	return 0;
}

int main()
{
	int i, j;
	int jj, nn;
	int cas = -1;
	while (gets(a))
	{
		if (cas == 1)
		{
			printf("\n");
		}
		else
		{
			cas = 1;
		}
		lena = strlen(a);
		jj = 0;
		top = 0;
		for (i = 0; i < lena; i++)
		{
			if (a[i] == '[')
			{
				jj++;
			}
			else if (a[i] == ']')
			{
				jj--;
			}
			else if (a[i] == '(')
			{
				for (j = i + 1; a[j] != '-'; j++)
				{
					s[top].name[j - i - 1] = a[j];
				}
				s[top].name[j - i - 1] = '\0';
				s[top].fst = a[j + 1];
				s[top].sec = a[j + 3];
				s[top].ji = jj;
				s[top].no = top;
				top++;
				i = j + 4;
			}
		}
		sort(s, s + top, cmp);
		/*
		        for(i=0;i<top;i++)
		            printf("%s %c %c\n",s[i].name,s[i].fst,s[i].sec);
		*/
		zzl = s[0];
		for (i = 1; i < top; i++)
		{
			if (who(zzl.fst, s[i].fst))
			{
				printf("%s, Weapon: %c VS %s, Weapon: %c\n", zzl.name, zzl.fst, s[i].name, s[i].fst);
				printf("Won: %s\n", zzl.name);
			}
			else if (who(s[i].fst, zzl.fst))
			{
				printf("%s, Weapon: %c VS %s, Weapon: %c\n", zzl.name, zzl.fst, s[i].name, s[i].fst);
				printf("Won: %s\n", s[i].name);
				zzl = s[i];
			}
			else
			{
				if (who(zzl.sec, s[i].sec))
				{
					printf("%s, Weapon: %c VS %s, Weapon: %c\n", zzl.name, zzl.sec, s[i].name, s[i].sec);
					printf("Won: %s\n", zzl.name);
				}
				else
				{
					printf("%s, Weapon: %c VS %s, Weapon: %c\n", zzl.name, zzl.sec, s[i].name, s[i].sec);
					printf("Won: %s\n", s[i].name);
					zzl = s[i];
				}
			}
		}
		printf("Final Winner: (%s-%c-%c)\n", zzl.name, zzl.fst, zzl.sec);
	}
	return 0;
}
