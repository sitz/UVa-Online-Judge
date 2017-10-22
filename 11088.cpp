#include <bits/stdc++.h>

using namespace std;

#define MAXN 17

int A[MAXN], N, tri, maximum, ter;
char Fg[MAXN];

struct ss
{
	int a, b, c;
};
ss Tri[500];

int com(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

void Make()
{
	int i, j, k, sum;
	tri = 0;
	for (i = 0; i <= N - 3; i++)
	{
		if (A[i] + A[i + 1] + A[i + 2] < 20)
			break;
		for (j = i + 1; j <= N - 2; j++)
		{
			if (A[i] + A[j] + A[j + 1] < 20)
				break;
			for (k = j + 1; k < N; k++)
			{
				sum = A[k] + A[i] + A[j];
				if (sum < 20)
					break;
				if (sum >= 20)
				{
					Tri[tri].a = i;
					Tri[tri].b = j;
					Tri[tri++].c = k;
				}
			}
		}
	}
}

int Recur(int ind, int level)
{
	int i, d = 0;
	if (level > maximum)
		maximum = level;
	if (level == ter)
		return 1;
	Fg[Tri[ind].a] = 1;
	Fg[Tri[ind].b] = 1;
	Fg[Tri[ind].c] = 1;
	for (i = ind + 1; i < tri; i++)
	{
		if (Fg[Tri[i].a] || Fg[Tri[i].b] || Fg[Tri[i].c])
			continue;
		d = Recur(i, level + 1);
		if (d)
			break;
	}
	Fg[Tri[ind].a] = 0;
	Fg[Tri[ind].b] = 0;
	Fg[Tri[ind].c] = 0;
	if (d)
		return 1;
	return 0;
}

void Find()
{
	int i;
	ter = N / 3;
	maximum = 0;
	for (i = 0; i < tri; i++)
		if (Recur(i, 1))
			break;
	cout << maximum << endl;
}

void Cal()
{
	int n = N;
	if (N < 3)
	{
		cout << 0 << endl;
		return;
	}
	qsort(A, N, sizeof(int), com);
	Make();
	Find();
}

int main()
{
	int i, k = 1;
	while (cin >> N && N)
	{
		for (i = 0; i < N; i++)
			cin >> A[i];
		cout << "Case " << k++ << ": ";
		Cal();
	}
	return 0;
}
