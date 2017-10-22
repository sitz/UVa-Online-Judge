#include <bits/stdc++.h>

using namespace std;

int f[13], t[7], s, k[7];
void DFS(int depth, int sum)
{
	if (depth == 7 && sum == 2)
	{
		int temp = f[2], temp1 = f[5];
		for (int i = 1; i <= 6; i++)
		{
			temp /= f[k[i]], temp1 /= f[(t[i] - k[i]) / 2];
		}
		s += temp * temp1;
	}
	if (depth == 7)
	{
		return;
	}
	for (int i = 0; i <= t[depth]; i++)
		if (sum + i <= 2 && (t[depth] - i) % 2 == 0)
		{
			k[depth] = i;
			DFS(depth + 1, i + sum);
		}
	return;
}
int main()
{
	f[0] = 1;
	for (int i = 1; i < 13; i++)
	{
		f[i] = f[i - 1] * i;
	}
	int times;
	scanf("%d", &times);
	while (times--)
	{
		for (int i = 1; i <= 6; i++)
		{
			t[i] = 0;
		}
		for (int i = 1; i < 13; i++)
		{
			int p;
			scanf("%d", &p);
			t[p]++;
		}
		int sum = 0, temp = f[12];
		for (int i = 1; i <= 6; i++)
		{
			temp /= f[t[i]];
		}
		sum += temp;
		bool flag = true;
		for (int i = 1; i <= 6; i++)
			if (t[i] % 4)
			{
				flag = false;
			}
		if (flag)
		{
			temp = 6 * f[3];
			for (int i = 1; i <= 6; i++)
			{
				temp /= f[t[i] / 4];
			}
			sum += temp;
		}
		else
		{
			flag = true;
		}
		for (int i = 1; i <= 6; i++)
			if (t[i] % 2)
			{
				flag = false;
			}
		if (flag)
		{
			temp = 3 * f[6];
			for (int i = 1; i <= 6; i++)
			{
				temp /= f[t[i] / 2];
			}
			sum += temp;
		}
		else
		{
			flag = true;
		}
		for (int i = 1; i <= 6; i++)
			if (t[i] % 3)
			{
				flag = false;
			}
		if (flag)
		{
			temp = 8 * f[4];
			for (int i = 1; i <= 6; i++)
			{
				temp /= f[t[i] / 3];
			}
			sum += temp;
		}
		else
		{
			flag = true;
		}
		s = 0;
		DFS(1, 0);
		sum += 6 * s;
		printf("%d\n", sum / 24);
	}
}
