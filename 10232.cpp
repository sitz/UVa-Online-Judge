#include <bits/stdc++.h>

using namespace std;

int Com[34][34], N, B[35];
int comb(int n, int r)
{
	int sum;
	if (n == r)
	{
		return 1;
	}
	if (r == 0)
	{
		return 1;
	}
	if (r == 1)
	{
		return n;
	}
	if (Com[n][r])
	{
		return Com[n][r];
	}
	sum = comb(n - 1, r) + comb(n - 1, r - 1);
	Com[n][r] = sum;
	return sum;
}
void Gen()
{
	int i, j;
	for (i = 0; i <= 31; i++)
	{
		for (j = 0; j <= i; j++)
		{
			Com[i][j] = comb(i, j);
		}
	}
}
int bit_toal()
{
	int sum = 0;
	int i;
	for (i = 1; i; i++)
	{
		sum += Com[31][i];
		if (sum >= N)
		{
			break;
		}
	}
	return i;
}
int Dec()
{
	int i, sum = 0, p = 1;
	for (i = 1; i <= 31; i++)
	{
		sum += B[i] * p;
		p *= 2;
	}
	return sum;
}
int Left(int b)
{
	int sum = 0, i;
	for (i = 1; i < b; i++)
	{
		sum += Com[31][i];
	}
	return sum;
}
int bitpos(int sum, int n)
{
	int i, t = 0;
	for (i = n - 1; i; i++)
	{
		t += Com[i][n - 1];
		if (t >= sum)
		{
			return i + 1;
		}
	}
	return 0;
}
int Pre(int b, int n)
{
	int sum = 0, i;
	for (i = b; i <= n; i++)
	{
		sum += Com[i][b];
	}
	return sum;
}
void Cal()
{
	int b, limit = 31, Sum, n;
	for (n = 0; n < 32; n++)
	{
		B[n] = 0;
	}
	if (N <= 1)
	{
		cout << N;
		return;
	}
	b = bit_toal();
	if (b == 1)
	{
		B[N] = 1;
		limit = pow(2, N - 1);
		cout << limit;
		return;
	}
	Sum = N - Left(b);
	for (int i = b; i >= 1; i--)
	{
		if (Sum == 1)
		{
			B[i] = 1;
			continue;
		}
		if (i == 1)
		{
			B[Sum] = 1;
			break;
		}
		n = bitpos(Sum, i);
		B[n] = 1;
		Sum -= Pre(i - 1, n - 2);
	}
	cout << Dec();
}

int main()
{
	Gen();
	while (cin >> N)
	{
		Cal();
		cout << endl;
	}
	return 0;
}
