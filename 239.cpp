#include <bits/stdc++.h>

using namespace std;

int primes[900], no;
int factor[900], temp[900];
void init()
{
	primes[0] = 2;
	no = 1;
	for (int i = 3; i < 7000; i += 2)
	{
		bool flag = true;
		for (int j = 0; primes[j] * primes[j] <= i && flag; j++)
			if (i % primes[j] == 0)
			{
				flag = false;
			}
		if (flag)
		{
			primes[no++] = i;
		}
	}
}
void solve(int n)
{
	int queue[7000], front = -1, rear = n - 1;
	int alter[7000];
	int stack1[5], stack5[12], stackh[12];
	int top1 = 0, top5 = 0, toph = 0;
	bool v[7000];
	int ans[10];
	memset(v, false, sizeof(v));
	memset(factor, 0, sizeof(factor));
	for (int i = 0; i < n; i++)
	{
		queue[i] = i;
	}
	for (int t = 1; t <= 1440; t++)
	{
		stack1[top1++] = queue[front = (front + 1) % 7000];
		if (top1 == 5)
		{
			for (int i = 3; i >= 0; i--)
			{
				queue[rear = (rear + 1) % 7000] = stack1[i];
			}
			stack5[top5++] = stack1[4];
			top1 = 0;
		}
		if (top5 == 12)
		{
			for (int i = 10; i >= 0; i--)
			{
				queue[rear = (rear + 1) % 7000] = stack5[i];
			}
			stackh[toph++] = stack5[11];
			top5 = 0;
		}
		if (toph == 12)
		{
			for (int i = 10; i >= 0; i--)
			{
				queue[rear = (rear + 1) % 7000] = stackh[i];
			}
			queue[rear = (rear + 1) % 7000] = stackh[11];
			toph = 0;
		}
	}
	for (int i = 0, j = (front + 1) % 7000; i < n; i++, j = (j + 1) % 7000)
	{
		alter[queue[j]] = i;
	}
	for (int i = 0; i < n; i++)
		if (!v[i])
		{
			int len = 0, s = i;
			do
			{
				v[s] = true;
				s = alter[s];
				len++;
			} while (!v[s]);
			memset(temp, 0, sizeof(temp));
			for (int j = 0; j < no && len != 1; j++)
			{
				while (len % primes[j] == 0)
				{
					len /= primes[j];
					temp[j]++;
				}
				if (temp[j] > factor[j])
				{
					factor[j] = temp[j];
				}
			}
		}
	memset(ans, 0, sizeof(ans));
	ans[0] = 1;
	for (int i = 0; i < no; i++)
	{
		for (int j = 0; j < factor[i]; j++)
		{
			int carry = 0;
			for (int k = 0; k < 10; k++)
			{
				ans[k] = ans[k] * primes[i] + carry;
				carry = ans[k] / 10000;
				ans[k] %= 10000;
			}
		}
	}
	int p;
	for (p = 9; ans[p] == 0; p--)
		;
	printf("%d", ans[p]);
	for (p--; p >= 0; p--)
	{
		printf("%04d", ans[p]);
	}
}
int main()
{
	int n;
	init();
	while (scanf("%d", &n) == 1, n)
	{
		printf("%d balls cycle after ", n);
		solve(n);
		puts(" days.");
	}
}
