#include <bits/stdc++.h>

using namespace std;

int M, ST;
struct ss
{
	int val;
	char flag;
} V[21];
int com(const void *a, const void *s)
{
	ss *x = (ss *)a;
	ss *y = (ss *)s;
	return (y->val - x->val);
}
int OK(int k)
{
	if (V[k - 1].flag == 0)
	{
		return 1;
	}
	if (V[k - 1].flag == 1 && (V[k].val == V[k - 1].val))
	{
		return 0;
	}
	return 1;
}
int Recur(int index, int level, int sum, int av, int c, int st)
{
	int i;
	sum += V[index].val;
	if (sum > av)
	{
		return 0;
	}
	if (sum == av)
	{
		sum = 0;
		c++;
		if (c == 3)
		{
			return 1;
		}
		V[index].flag = 0;
		for (i = 1; i < M; i++)
			if (V[i].flag == 1)
			{
				break;
			}
		if (Recur(i, level + 1, sum, av, c, 1) == 1)
		{
			return 1;
		}
	}
	V[index].flag = 0;
	if (level == M - 1)
	{
		return 0;
	}
	for (i = st; i < M; i++)
	{
		if (V[i].flag == 1 && OK(i))
		{
			if (Recur(i, level + 1, sum, av, c, i + 1) == 1)
			{
				return 1;
			}
		}
	}
	V[index].flag = 1;
	return 0;
}
void Cal(int sum, int max)
{
	int av = 0, d, i = 0;
	av = sum / 4;
	d = Recur(0, 0, 0, av, 0, 0);
	if (d == 1)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
}

int main()
{
	int kase, i, sum, max;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d", &M);
		max = 0;
		sum = 0;
		for (i = 0; i < M; i++)
		{
			V[i].flag = 1;
			scanf("%d", &V[i].val);
			sum += V[i].val;
			if (V[i].val > max)
			{
				max = V[i].val;
			}
		}
		if ((sum % 4) != 0)
		{
			printf("no\n");
			continue;
		}
		qsort(V, M, sizeof(V[0]), com);
		Cal(sum, max);
	}
	return 0;
}
