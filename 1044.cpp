#include <bits/stdc++.h>

using namespace std;

int N, num[100];
char dir[100][10];
int arr[100000];
int getdir(char c)
{
	switch (c)
	{
	case 'N':
		return 0;
	case 'E':
		return 1;
	case 'S':
		return 2;
	case 'W':
		return 3;
	}
}
bool cmpfinish(int st, int nst, int limitlen)
{
	int k;
	for (k = 0; k < limitlen; k++)
		if (arr[st + k] != (arr[nst + limitlen - 1 - k] + 2) % 4)
		{
			break;
		}
	if (k < limitlen)
	{
		return false;
	}
	return true;
}

bool cmpone(int st, int nst, int limitlen, int flag)
{
	//printf("%d %d %d %d\n",st,nst,limitlen,flag);
	int i, j, k;
	int num0[4], num1[4];
	memset(num0, 0, sizeof(num0));
	memset(num1, 0, sizeof(num1));
	for (i = st, j = nst; i < st + limitlen; i++, j++)
	{
		num0[arr[i]]++;
		num1[(arr[j] + 2) % 4]++;
		for (k = 0; k < 4; k++)
			if (num0[k] != num1[k])
			{
				break;
			}
		if (k < 4)
		{
			continue;
		}
		for (k = 0; k < i - st; k++)
			if (arr[st + k] != (arr[j - k] + 2) % 4)
			{
				break;
			}
		if (k < i - st)
		{
			continue;
		}
		if (flag == 0)
			if (cmpone(i + 1, j + 1, st + limitlen - i - 1, 1))
			{
				return true;
			}
		if (cmpfinish(i + 1, j + 1, st + limitlen - i - 1))
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int i, j, tcas = 1, st;
	while (scanf("%d", &N) && N)
	{
		for (i = 0; i < N; i++)
		{
			scanf("%s%d", dir[i], &num[i]);
		}
		int div = num[0];
		for (i = 1; i < N; i++)
		{
			div = __gcd(div, num[i]);
		}
		int tot = 0;
		for (i = 0; i < N; i++)
		{
			num[i] /= div;
			int c = getdir(dir[i][0]);
			for (j = 0; j < num[i]; j++)
			{
				arr[tot++] = c;
			}
		}
		printf("Polygon %d: ", tcas++);
		for (i = 0; i < tot; i++)
		{
			arr[tot + i] = arr[i];
		}
		// for (i=0;i<tot;i++) printf("%d ",arr[i]);
		//printf("\n");
		if (tot & 1)
		{
			printf("Impossible\n");
			continue;
		}
		int len = tot / 2;
		bool res = false;
		int num1[4], num2[4];
		for (st = 0; st < len; st++)
		{
			int nst = st + len;
			if (st == 0)
			{
				memset(num1, 0, sizeof(num1));
				memset(num2, 0, sizeof(num2));
				for (i = st; i < st + len; i++)
				{
					num1[arr[i]]++;
				}
				for (i = nst; i < nst + len; i++)
				{
					num2[(arr[i] + 2) % 4]++;
				}
			}
			for (i = 0; i < 4; i++)
				if (num1[i] != num2[i])
				{
					break;
				}
			if (i == 4)
			{
				res = cmpone(st, nst, len, 0);
				if (res)
				{
					break;
				}
			}
			num1[arr[st]]--;
			num1[arr[st + len]]++;
			num2[(arr[nst] + 2) % 4]--;
			num2[(arr[nst + len] + 2) % 4]++;
		}
		if (res)
		{
			printf("Possible\n");
		}
		else
		{
			printf("Impossible\n");
		}
	}
}
