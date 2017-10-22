#include <bits/stdc++.h>

using namespace std;

#define N 100001

char arr[2 * N + 1];
int len;
long M1 = 2147483647, B1 = 1000000007, right_[N], left_[N], modPow[N];

long mod(long a, long b)
{
	return (a % b + b) % b;
}

long calcHash_L(int l, int r)
{
	long res = left_[l];
	if (r < len - 1)
	{
		res = mod(res - (left_[r + 1] * modPow[r - l + 1]) % M1, M1);
	}
	return res;
}

long calcHash_R(int l, int r)
{
	long res = right_[r];
	if (l > 0)
	{
		res = mod(res - (right_[l - 1] * modPow[r - l + 1]) % M1, M1);
	}
	return res;
}

int isPalindrome(int l, int r)
{
	int len = l - r + 1;
	if (len == 1)
	{
		return 1;
	}
	return calcHash_R(l, r) == calcHash_L(l, r);
}

int main()
{
	int i, j, tc;
	modPow[0] = 1;
	for (i = 1; i < N; i++)
	{
		modPow[i] = (B1 * modPow[i - 1]) % M1;
	}
	while (gets(arr))
	{
		len = strlen(arr);
		right_[0] = arr[0];
		left_[len - 1] = arr[len - 1];
		for (i = 1; i < len; i++)
		{
			right_[i] = (right_[i - 1] * B1 + arr[i]) % M1;
		}
		for (i = len - 2; i >= 0; i--)
		{
			left_[i] = (left_[i + 1] * B1 + arr[i]) % M1;
		}
		for (i = 0; i < len; i++)
		{
			if (isPalindrome(i, len - 1))
			{
				for (j = i - 1; j >= 0; j--)
					arr[len++] = arr[j];
				arr[len] = 0;
				break;
			}
		}
		puts(arr);
	}
	return 0;
}
