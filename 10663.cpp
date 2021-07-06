#include <bits/stdc++.h>

using namespace std;

/*
10663
Non Powerful Subset
*/

#define maxn 499500
#define mxx 100000
char nonP[maxn + 2];
char Fg[maxn];
int St[mxx], Ind;
int T[mxx];
int R[1000], rInd;
int N, M;
void Remove()
{
	int i, j;
	for (i = 2; i * i <= maxn; i++)
	{
		for (j = i * i; j <= maxn; j *= i)
		{
			nonP[j] = 1;
		}
	}
}
int Dynamic(int n)
{
	int i, d, k = 0;
	for (i = Ind - 1; i >= 0; i--)
	{
		d = St[i] + n;
		if (nonP[d] == 1)
		{
			return 0;
		}
		if (Fg[d] == 0)
		{
			T[k++] = d;
		}
	}
	for (i = 0; i < k; i++)
	{
		St[Ind++] = T[i];
		Fg[T[i]] = 1;
	}
	if (Fg[n] == 0)
	{
		St[Ind++] = n;
		Fg[n] = 1;
	}
	return 1;
}
void Cal()
{
	int i, d;
	Ind = rInd = 0;
	for (i = N; i <= M; i++)
	{
		if (nonP[i])
		{
			continue;
		}
		if (Dynamic(i))
		{
			R[rInd++] = i;
		}
	}
	cout << R[0];
	for (i = 1; i < rInd; i++)
	{
		cout << " " << R[i];
	}
	cout << endl;
	for (i = 0; i < Ind; i++)
	{
		d = St[i];
		Fg[d] = 0;
	}
}
int main()
{
	Remove();
	while (cin >> N >> M)
	{
		Cal();
	}
	return 0;
}
