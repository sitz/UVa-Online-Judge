#include <bits/stdc++.h>

using namespace std;

#define MN(a, b) (a > b ? b : a)
#define MAXN 20000000
#define MAX 1270649

typedef long long ss;

char Temp[MAXN + 2];
ss Prime[10];
int Store[MAX], N, M, K, P;
int Tw[] = {6, 2, 4, 8};
int Th[] = {1, 3, 9, 7};
int Fo[] = {6, 4};
int Se[] = {1, 7, 9, 3};
int Ei[] = {6, 8, 4, 2};
int Ni[] = {1, 9};

void Prime_table()
{
	int i, j, max = 0;
	for (i = 2; i * i <= MAXN;)
	{
		for (j = i + i; j <= MAXN; j += i)
			Temp[j] = 1;
		for (++i; Temp[i]; i++)
			;
	}
	for (i = 2; i <= MAXN; i++)
		if (!Temp[i])
			Store[K++] = i;
}

int LastD(int b, int g)
{
	int r;
	if (g == 0)
		return 1;
	switch (b)
	{
	case 0:
		return 0;
	case 1:
		return 1;
	case 2:
		r = g % 4;
		return Tw[r];
	case 3:
		r = g % 4;
		return Th[r];
	case 4:
		r = g % 2;
		return Fo[r];
	case 5:
		return 5;
	case 6:
		return 6;
	case 7:
		r = g % 4;
		return Se[r];
	case 8:
		r = g % 4;
		return Ei[r];
	case 9:
		r = g % 2;
		return Ni[r];
	}
	return -1;
}

void Times(int n)
{
	int i;
	ss j;
	for (i = 0; i < 3; i++)
	{
		for (j = Store[i]; j <= N; j *= Store[i])
		{
			Prime[i] += N / j;
			Prime[i] -= n / j;
		}
	}
}

int Binary(int key)
{
	int lo = 0, up = K - 1, mid;
	mid = up / 2;
	if (key > Store[K - 1])
		return K - 1;
	while (Store[mid] != key)
	{
		if (Store[mid] > key)
		{
			if (Store[mid - 1] < key)
				return mid - 1;
			up = mid - 1;
		}
		else if (Store[mid] < key)
		{
			if (Store[mid + 1] > key)
				return mid;
			lo = mid + 1;
		}
		mid = (lo + up) / 2;
	}
	return mid;
}

void CalCulate(int n)
{
	ss i, t, j;
	int a[12] = {0}, ind1, k = 1;
	if (n == N)
	{
		printf("1\n");
		return;
	}
	t = MN(Prime[0], Prime[2]);
	Prime[0] -= t;
	Prime[2] -= t;
	for (i = 0; i <= 2; i++)
	{
		k *= LastD(Store[i] % 10, Prime[i]);
		k %= 10;
	}
	if (N <= 6)
	{
		printf("%d\n", k);
		return;
	}
	for (i = 3; Store[i] <= N && i < K; i++)
	{
		t = 0;
		for (j = Store[i]; j <= N; j *= Store[i])
		{
			t += N / j;
			t -= n / j;
		}
		if (t == 1)
		{
			k *= Store[i] % 10;
			k %= 10;
		}
		else if (t > 1)
		{
			k *= LastD(Store[i] % 10, t);
			k %= 10;
		}
	}
	printf("%d\n", k % 10);
}

int main()
{
	Prime_table();
	while (scanf("%d%d", &N, &M) == 2)
	{
		Times(N - M);
		CalCulate(N - M);
		for (int i = 0; i < 10; i++)
			Prime[i] = 0;
	}
	return 0;
}
