#include <bits/stdc++.h>

using namespace std;

/****
10400
****/
#define MAXN 64002
char ss[] = "0+-*/";
char F[101][MAXN];
int N, R, C, MX;
int V[101];
int Rec[101];
void Print()
{
	int i, j = 1, k;
	if (Rec[0] == 2)
	{
		printf("-");
	}
	printf("%d", V[0]);
	for (i = 1; i < N; i++)
	{
		k = Rec[j++];
		printf("%c%d", ss[k], V[i]);
	}
	printf("=%d\n", R);
}
int GetVal(int sum, int op, int level, int index)
{
	if (level == 0 && (op == 3 || op == 4))
	{
		C = 0;
		return 0;
	}
	switch (op)
	{
	case 1:
		sum += V[index];
		if (sum > 32000 || sum < -32000)
		{
			C = 0;
			return 0;
		}
		break;
	case 2:
		sum -= V[index];
		if (sum > 32000 || sum < -32000)
		{
			C = 0;
			return 0;
		}
		break;
	case 3:
		sum *= V[index];
		if (sum > 32000 || sum < -32000)
		{
			C = 0;
			return 0;
		}
		break;
	case 4:
		if (V[index] == 0)
		{
			C = 0;
			return 0;
		}
		if (sum % V[index])
		{
			C = 0;
			return 0;
		}
		sum /= V[index];
		break;
	}
	return sum;
}
int Recur(int level, int index, int sum, int op)
{
	int temp;
	C = 1;
	sum = GetVal(sum, op, level, index);
	if (C == 0)
	{
		return 0;
	}
	if (level == N)
	{
		if (sum == R)
		{
			return 1;
		}
		return 0;
	}
	temp = sum + 32000;
	if (temp > MX)
	{
		MX = temp;
	}
	if (level && F[level][temp] == 1)
	{
		return 0;
	}
	F[level][temp] = 1;
	for (int i = 1; i <= 4; i++)
	{
		Rec[level] = i;
		if (Recur(level + 1, index + 1, sum, i))
		{
			return 1;
		}
	}
	return 0;
}
void Cal()
{
	int d;
	d = Recur(0, -1, 0, -1);
	if (d)
	{
		Print();
	}
	else
	{
		printf("NO EXPRESSION\n");
	}
}
int main()
{
	int i, kase;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			scanf("%d", &V[i]);
		}
		scanf("%d", &R);
		MX = -65000;
		Cal();
		for (i = 0; i <= N; i++)
		{
			memset(F[i], 0, MX);
		}
	}
	return 0;
}
