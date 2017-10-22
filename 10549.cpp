#include <bits/stdc++.h>

using namespace std;

/*
10549
Russina Doll
*/

#define maxn 202
struct ss
{
	int d, h, w;
} D[maxn];
ss A[maxn], B[maxn];
int N;
int com(const void *a, const void *b)
{
	ss *x;
	ss *y;
	x = (ss *)a;
	y = (ss *)b;
	if (x->h != y->h)
	{
		return y->h - x->h;
	}
	if (x->d != y->d)
	{
		return y->d - x->d;
	}
	return x->w - y->w;
}
int Hold(int n, int m)
{
	if (A[n].h - A[n].w * 2 < D[m].h)
	{
		return 0;
	}
	if (A[n].d - A[n].w * 2 < D[m].d)
	{
		return 0;
	}
	return 1;
}
int HoldB(int n, int m)
{
	if (B[n].h - B[n].w * 2 < D[m].h)
	{
		return 0;
	}
	if (B[n].d - B[n].w * 2 < D[m].d)
	{
		return 0;
	}
	return 1;
}
int Fit(int n, int m)
{
	int i, x, y, z;
	x = B[n].h;
	y = B[n].d;
	z = B[n].w;
	for (i = m + 1; i < 2 * N; i++)
	{
		if (x - z * 2 < D[i].h)
		{
			return 0;
		}
		if (y - z * 2 < D[i].d)
		{
			return 0;
		}
		x = D[i].h;
		y = D[i].d;
		z = D[i].w;
	}
	return 1;
}
int Recur(int ind1, int ind2, int level)
{
	int i, dif, res, d = ind2;
	dif = N - (level + ind2);
	res = N - ind1;
	if (dif > res)
	{
		return 0;
	}
	A[level] = D[ind1];
	if (level == N)
	{
		if (ind2 == N)
		{
			return 1;
		}
		else if (Fit(ind2, ind1))
		{
			for (i = ind1 + 1; i < 2 * N; i++)
			{
				B[++d] = D[i];
			}
			return 1;
		}
		return 0;
	}
	for (i = ind1 + 1; i < N * 2; i++)
	{
		if (Hold(level, i))
		{
			if (Recur(i, ind2, level + 1))
			{
				return 1;
			}
			else if (HoldB(ind2, i))
			{
				ind2++;
				B[ind2] = D[i];
			}
			else
			{
				return 0;
			}
		}
		else if (HoldB(ind2, i))
		{
			ind2++;
			if (ind2 > N)
			{
				return 0;
			}
			B[ind2] = D[i];
		}
		else
		{
			return 0;
		}
	}
	return 0;
}
void Print()
{
	int i;
	for (i = 1; i <= N; i++)
	{
		cout << A[i].h << " " << A[i].d << " " << A[i].w << endl;
	}
	cout << "-\n";
	for (i = 1; i <= N; i++)
	{
		cout << B[i].h << " " << B[i].d << " " << B[i].w << endl;
	}
	cout << "\n";
}
void Cal()
{
	B[0].h = B[0].d = 1000000;
	B[0].w = 0;
	Recur(0, 0, 1);
	Print();
}
int main()
{
	int i;
	while (cin >> N)
	{
		if (!N)
		{
			break;
		}
		for (i = 0; i < 2 * N; i++)
		{
			cin >> D[i].h >> D[i].d >> D[i].w;
		}
		qsort(D, N * 2, sizeof(ss), com);
		Cal();
	}
	return 0;
}
