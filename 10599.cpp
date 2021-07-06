#include <bits/stdc++.h>

using namespace std;

#define MAXN 10002

typedef long long LL;

struct ss {int r, c, p;};
ss pt[MAXN];

struct node
{
	int r, c, ad;
	LL count;
};

struct lis
{
	node A[1000];
	int ind;
} L[202];

int total, R, C, max_, chk;

int com(const void *a, const void *b)
{
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	if (x->c != y->c)
	{
		return x->c - y->c;
	}
	return x->r - y->r;
}
void Print(int n)
{
	if (pt[n].p == -1)
	{
		printf("%d", (pt[n].r - 1) * C + pt[n].c);
		chk++;
		return;
	}
	Print(pt[n].p);
	printf(" %d", (pt[n].r - 1) * C + pt[n].c);
	chk++;
}
void Cal()
{
	int i, f, j, l;
	LL times;
	max_ = 0;
	if (total == 1)
	{
		printf("1 1 %d\n", (pt[0].r - 1) * C + pt[0].c);
		return;
	}
	if (total == 0)
	{
		printf("0 0\n");
		return;
	}
	L[0].A[0].r = pt[0].r;
	L[0].A[0].c = pt[0].c;
	L[0].A[0].ad = 0;
	L[0].A[0].count = 1;
	L[0].ind = 1;
	pt[0].p = -1;
	for (i = 1; i < total; i++)
	{
		f = 0;
		times = 0;
		for (j = max_; j >= 0; j--)
		{
			for (int k = L[j].ind - 1; k >= 0; k--)
			{
				if (pt[i].r >= L[j].A[k].r && pt[i].c >= L[j].A[k].c)
				{
					f = 1;
					times += L[j].A[k].count;
					l = L[j].A[k].ad;
				}
			}
			if (f)
			{
				L[j + 1].A[L[j + 1].ind].r = pt[i].r;
				L[j + 1].A[L[j + 1].ind].c = pt[i].c;
				L[j + 1].A[L[j + 1].ind].count = times;
				L[j + 1].A[L[j + 1].ind++].ad = i;
				pt[i].p = l;
				if (j + 1 > max_)
					max_ = j + 1;
				break;
			}
		}
		if (!f)
		{
			L[0].A[L[0].ind].r = pt[i].r;
			L[0].A[L[0].ind].c = pt[i].c;
			L[0].A[L[0].ind].count = 1;
			L[0].A[L[0].ind++].ad = i;
			pt[i].p = -1;
		}
	}
	times = 0;
	for (i = 0; i < L[max_].ind; i++)
		times += L[max_].A[i].count;
	printf("%d %lld ", max_ + 1, times);
	Print(L[max_].A[L[max_].ind - 1].ad);
	printf("\n");
}
void ReSet()
{
	int i;
	for (i = 0; i <= max_ + 1; i++)
		L[i].ind = 0;
}

int main()
{
	int k = 1;
	while (scanf("%d%d", &R, &C) == 2)
	{
		if (R == -1 && C == -1)
			break;
		total = 0;
		while (1)
		{
			scanf("%d%d", &pt[total].r, &pt[total].c);
			if (!pt[total].r && !pt[total].c)
				break;
			total++;
		}
		qsort(pt, total, sizeof(ss), com);
		printf("CASE#%d: ", k++);
		Cal();
		ReSet();
	}
	return 0;
}
