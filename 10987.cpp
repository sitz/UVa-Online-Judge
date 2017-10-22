#include <bits/stdc++.h>

using namespace std;

#define maxn 102
int N, C[maxn][maxn], Fg[maxn][maxn];

int Anty()
{
	int i, j, k;
	for (k = 1; k <= N; k++)
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				if (i != j && j != k && i != k)
				{
					if (C[i][k] + C[k][j] == C[i][j])
						Fg[i][j] = 1;
					if (C[i][k] + C[k][j] < C[i][j])
						return 1;
				}
	return 0;
}

int Count()
{
	int i, j, k = 0;
	for (i = 2; i <= N; i++)
		for (j = 1; j < i; j++)
			if (Fg[i][j] == 0)
				k++;
	return k;
}

void Print()
{
	int i, j;
	int d = Count();
	cout << d << endl;
	if (!d)
		return;
	for (i = 1; i < N; i++)
		for (j = i + 1; j <= N; j++)
			if (Fg[i][j] == 0)
				cout << i << " " << j << " " << C[i][j] << "\n";
}

void Cal()
{
	int d, i, j;
	d = Anty();
	if (d)
		cout << "Need better measurements.\n";
	else
		Print();
	for (i = 1; i <= N; i++)
		for (j = i + 1; j <= N; j++)
			Fg[i][j] = Fg[j][i] = 0;
}

int main()
{
	int i, c, ks, k = 1, j;
	cin >> ks;
	while (ks--)
	{
		cin >> N;
		for (i = 1; i < N; i++)
			for (j = 1; j <= i; j++)
			{
				cin >> c;
				C[i + 1][j] = C[j][i + 1] = c;
			}
		cout << "Case #" << k++ << ":\n";
		Cal();
		cout << endl;
	}
	return 0;
}
