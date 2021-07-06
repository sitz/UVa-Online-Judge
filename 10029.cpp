#include <bits/stdc++.h>

using namespace std;

const int N = 26000;

char str[N][20];
int dp[N];

void dele(char *str, char *res, int pos)
{
	int len = strlen(str), cnt = 0;
	for (int i = 0; i < len; i++)
		if (i != pos)
			res[cnt++] = str[i];
	res[cnt] = '\0';
}

void repla(char *str, char *res, int pos, char letter)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (i == pos)
		{
			res[i] = letter;
		}
		else
		{
			res[i] = str[i];
		}
	}
	res[len] = '\0';
}

void add(char *str, char *res, int pos, char letter)
{
	int len = strlen(str), cnt = 0;
	for (int i = 0; i <= len; i++)
	{
		if (i == pos)
			res[cnt++] = letter;
		if (i < len)
			res[cnt++] = str[i];
	}
	str[cnt] = '\0';
}

int bin_srch(int start, int end, char *a)
{
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		int res = strcmp(a, str[mid]);
		if (res < 0) // smaller
		{
			end = mid - 1;
		}
		else if (res == 0) // equal: found val
		{
			return mid;
		}
		else // larger
		{
			start = mid + 1;
		}
	}
	return -1;
}

void fun(char *a, int pos)
{
	int pre = bin_srch(0, pos - 1, a);
	if (pre != -1)
	{
		dp[pos] = max(dp[pos], dp[pre] + 1);
	}
}

int main()
{
	int n = 0, imax = 0;
	while (scanf("%s", str[n]) != EOF)
	{
		n++;
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < n; i++)
	{
		int len = strlen(str[i]);
		for (int j = 0; j <= len; j++)
		{
			char temp[20] = {0};
			for (char k = 'a'; k <= 'z'; (int)k++)
			{
				if (j < len)
				{
					repla(str[i], temp, j, k);
					fun(temp, i);
				}
				add(str[i], temp, j, k);
				fun(temp, i);
			}
			if (j < len)
			{
				dele(str[i], temp, j);
				fun(temp, i);
			}
		}
		imax = max(imax, dp[i]);
	}
	printf("%d\n", imax + 1);
	return 0;
}
