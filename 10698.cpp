#include <bits/stdc++.h>

using namespace std;

/*
10698
Football Sort
*/

map<string, int> M;
struct ss
{
	char nam[20];
	char Or[20];
	char avg[20];
	int played;
	int point;
	int goaldiff;
	int goal;
	int aga;
};
ss F[30];
int team, game;
char xx[] = "N/A";
int Com(const void *a, const void *b)
{
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	if (x->played == 0 && y->played == 0)// op
	{
		return strcmp(x->nam, y->nam);// op
	}
	if (x->played && y->played == 0)// op
	{
		return y->played - x->played;// op
	}
	if (x->played == 0 && y->played)//op
	{
		return y->played - x->played;//op
	}
	if (x->point != y->point)
	{
		return y->point - x->point;
	}
	if (x->goaldiff != y->goaldiff)
	{
		return y->goaldiff - x->goaldiff;
	}
	if (x->goal != y->goal)
	{
		return y->goal - x->goal;
	}
	return strcmp(x->nam, y->nam);
}
void ReadCase()
{
	int i, ga, gb, ia, ib;
	char ta[20], tb[20];
	for (i = 0; i < team; i++)
	{
		scanf("%s", F[i].Or);
		M[F[i].Or] = i + 1;
		for (ia = 0; F[i].Or[ia]; ia++)
		{
			F[i].nam[ia] = tolower(F[i].Or[ia]);
		}
	}
	while (game--)
	{
		scanf("%s%d%s%d%s", ta, &ga, tb, &gb, tb);
		ia = M[ta] - 1;
		ib = M[tb] - 1;
		F[ia].goal += ga;
		F[ib].goal += gb;
		F[ia].goaldiff += ga - gb;
		F[ib].goaldiff += gb - ga;
		F[ia].played++;
		F[ib].played++;
		F[ia].aga += gb;
		F[ib].aga += ga;
		if (ga > gb)
		{
			F[ia].point += 3;
		}
		else if (gb > ga)
		{
			F[ib].point += 3;
		}
		else
		{
			F[ia].point++;
			F[ib].point++;
		}
	}
}
int isEqual(int n, int m)
{
	if (F[n].point != F[m].point)
	{
		return 0;
	}
	if (F[n].goaldiff != F[m].goaldiff)
	{
		return 0;
	}
	if (F[n].goal != F[m].goal)
	{
		return 0;
	}
	return 1;
}
void Print()
{
	int i;
	char xyz[] = "   ";
	printf("%2d.%16s%4d%4d%4d%4d%4d%7s\n", 1, F[0].Or, F[0].point, F[0].played,
				 F[0].goal, F[0].aga, F[0].goaldiff, F[0].avg);
	for (i = 1; i < team; i++)
	{
		if (isEqual(i, i - 1))
		{
			printf("%s", xyz);
		}
		else
		{
			printf("%2d.", i + 1);
		}
		printf("%16s%4d%4d%4d%4d%4d%7s\n", F[i].Or, F[i].point, F[i].played,
					 F[i].goal, F[i].aga, F[i].goaldiff, F[i].avg);
	}
}
void Cal()
{
	int i, j;
	double xyz;
	char tt[10];
	for (i = 0; i < team; i++)
	{
		if (F[i].played)
		{
			xyz = (double)F[i].point * 100 / (double)(F[i].played * 3);
			sprintf(tt, "%.2lf", xyz);
			strcpy(F[i].avg, tt);
		}
		else
		{
			strcpy(F[i].avg, xx);
		}
	}
	Print();
}
void ReSet()
{
	int i;
	for (i = 0; i < team; i++)
	{
		F[i].goaldiff = F[i].point = 0;
		F[i].played = 0;
		F[i].aga = 0;
		F[i].goal = 0;
	}
}
int main()
{
	int f = 0;
	while (scanf("%d%d", &team, &game) == 2)
	{
		if (!team && !game)
		{
			break;
		}
		ReSet();
		ReadCase();
		qsort(F, team, sizeof(ss), Com);
		if (f++)
		{
			printf("\n");
			M.empty();
		}
		Cal();
	}
	return 0;
}
