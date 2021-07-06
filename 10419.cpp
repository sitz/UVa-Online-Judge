#include <bits/stdc++.h>

using namespace std;

char buf[100], *token;
int isPrime[2000], prime[2000], sol[20], used[2000], target, n, total, sum, find_, flag;

void reverse(char *s)
{
	int size = strlen(s), i;
	char temp;
	for (i = 0; i < size / 2; ++i)
	{
		temp = s[i];
		s[i] = s[size - 1 - i];
		s[size - 1 - i] = temp;
	}
}

int cmp(const void *a, const void *b)
{
	int d1 = *(int *)a, d2 = *(int *)b, i;
	char n1[6], n2[6];
	for (i = 0; d1; ++i)
	{
		n1[i] = d1 % 10 + '0';
		d1 /= 10;
	}
	n1[i] = 0;
	for (i = 0; d2; ++i)
	{
		n2[i] = d2 % 10 + '0';
		d2 /= 10;
	}
	n2[i] = 0;
	reverse(n1);
	reverse(n2);
	return strcmp(n1, n2);
}
void initial()
{
	int i, j;
	memset(isPrime, 0, sizeof(isPrime));
	for (i = 3; i < 2000; i += 2)
	{
		isPrime[i] = 1;
	}
	for (i = 3; i < 2000; i += 2)
	{
		for (j = 2; i * j < 2000; ++j)
		{
			isPrime[i * j] = 0;
		}
	}
	total = 0;
	for (i = 3; i < 300; ++i)
		if (isPrime[i])
		{
			prime[total++] = i;
		}
	qsort(prime, total, sizeof(int), cmp);
}
void back(int x, int k)
{
	int i;
	if (find_)
	{
		return;
	}
	if (x == n)
	{
		if (!target)
		{
			find_ = 1;
			if (flag)
			{
				qsort(sol, n, sizeof(int), cmp);
			}
			printf("%d", sol[0]);
			for (i = 1; i < n; ++i)
			{
				printf("+%d", sol[i]);
			}
			putchar('\n');
		}
		return;
	}
	for (i = k; i < total; ++i)
	{
		if (target - prime[i] >= 0 && used[prime[i]] < 2)
		{
			target -= prime[i];
			sol[x] = prime[i];
			++used[prime[i]];
			back(x + 1, i);
			if (find_)
			{
				return;
			}
			target += prime[i];
			--used[prime[i]];
		}
	}
}

int main()
{
	int t = 0;
	initial();
	while (gets(buf))
	{
		token = strtok(buf, " ");
		target = atoi(token);
		token = strtok(NULL, " ");
		n = atoi(token);
		if (!target && !n)
		{
			break;
		}
		if (target == 2 && n == 1)
		{
			printf("CASE %d:\n2\n", ++t);
			continue;
		}
		printf("CASE %d:\n", ++t);
		find_ = 0;
		flag = 0;
		sum = 0;
		memset(used, 0, sizeof(used));
		if (target % 2 ^ n % 2)
		{
			flag = 1;
			sol[0] = 2;
			sum = 2;
			target -= 2;
			back(1, 0);
		}
		else
		{
			back(0, 0);
		}
		if (!find_)
		{
			puts("No Solution.");
		}
	}
	return 0;
}
