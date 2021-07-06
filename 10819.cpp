#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) (a > b ? a : b)

struct ss
{
	int cost;
	int fav;
};
struct NewOld
{
	int New, Old;
};
ss List[102];
int T[10300];
char F[10300];
NewOld B[10300];
int D, I, Sum, Max, k;
vector<ss> tmp;
vector<int> V, New;

void Dynamic()
{
	int i, ind, cost, fav;
	int limit = D;
	ss xyz;
	if (D > 1800)
		limit = D + 200;
	Max = 0;
	V.clear();
	for (i = 0; i < I; i++)
	{
		if (List[i].cost > limit)
			continue;
		tmp.clear();
		New.clear();
		for (ind = 0; ind < V.size(); ind++)
		{
			cost = V[ind] + List[i].cost;
			fav = T[V[ind]] + List[i].fav;
			if (cost > limit)
				continue;
			if (F[cost] == 1)
				if (T[cost] >= fav)
					continue;
			if (F[cost] == 0)
			{
				F[cost] = 1;
				New.push_back(cost);
			}
			xyz.cost = cost;
			xyz.fav = fav;
			tmp.push_back(xyz);
			if (cost <= D || cost > 2000)
				if (fav > Max)
					Max = fav;
		}
		if (F[List[i].cost] == 0 || T[List[i].cost] < List[i].fav)
		{
			if (F[List[i].cost] == 0)
			{
				F[List[i].cost] = 1;
				V.push_back(List[i].cost);
			}
			if (List[i].fav > Max && (List[i].cost <= D || List[i].cost > 2000))
				Max = List[i].fav;
			T[List[i].cost] = List[i].fav;
		}
		for (ind = tmp.size() - 1; ind >= 0; ind--)
			T[tmp[ind].cost] = tmp[ind].fav;
		for (ind = New.size() - 1; ind >= 0; ind--)
			V.push_back(New[ind]);
	}
}
void Free()
{
	int i;
	for (i = V.size() - 1; i >= 0; i--)
		F[V[i]] = 0;
}
void Cal()
{
	int i, total = 0;
	if (Sum <= D)
	{
		for (i = 0; i < I; i++)
			total += List[i].fav;
		printf("%d\n", total);
		return;
	}
	Dynamic();
	printf("%d\n", Max);
	Free();
}

int main()
{
	int i;
	while (scanf("%d%d", &D, &I) == 2)
	{
		Sum = 0;
		for (i = 0; i < I; i++)
		{
			scanf("%d%d", &List[i].cost, &List[i].fav);
			Sum += List[i].cost;
		}
		Cal();
	}
	return 0;
}
