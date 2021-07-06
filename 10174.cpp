#include <bits/stdc++.h>

using namespace std;

int N, M;

void Single()
{
	if (N % 2)
	{
		printf("%.lf %.lf\n", ceil((double)N / 2), floor((double)N / 2));
	}
	else if (N % 4 == 0)
	{
		N = N / 2;
		printf("%d %d\n", N / 2 + 1, N / 2 - 1);
	}
	else
	{
		printf("Bachelor Number.\n");
	}
}
void Double()
{
	int Tm, Teven, Tb = 0, b = 0, Tdiv4;
	Tm = M - N + 1;
	if (Tm % 2)
	{
		b = 1;
	}
	Teven = Tm / 2;
	if (N % 2 == 0)
	{
		Tb = Teven += b;
	}
	while (N % 4)
	{
		N++;
		if (N > M)
		{
			goto done;
		}
	}
	while (M % 4)
	{
		M--;
		if (M < N)
		{
			goto done;
		}
	}
	Tdiv4 = (M - N) / 4 + 1;
	Tb = Teven - Tdiv4;
done:;
	printf("%d\n", Tb);
}

int main()
{
	char input[100];
	int k;
	while (gets(input))
	{
		k = sscanf(input, "%d%d", &N, &M);
		if (k == 1)
		{
			Single();
		}
		else
		{
			Double();
		}
	}
	return 0;
}
