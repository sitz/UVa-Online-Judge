#include <bits/stdc++.h>

using namespace std;

/*
10689
Yet another number sequence
*/
int Matrix[33][4], B[40], bi;
int St[4];
void Gen()
{
	int temp[4] = {0, 1, 1, 1}, i;
	Matrix[1][0] = 0;
	Matrix[1][1] = 1;
	Matrix[1][2] = 1;
	Matrix[1][3] = 1;
	for (i = 2; i <= 32; i++)
	{
		Matrix[i][0] = (Matrix[i - 1][0] * Matrix[i - 1][0] + Matrix[i - 1][1] * Matrix[i - 1][2]) % 10000;
		Matrix[i][1] = (Matrix[i - 1][0] * Matrix[i - 1][1] + Matrix[i - 1][1] * Matrix[i - 1][3]) % 10000;
		Matrix[i][2] = Matrix[i][1];
		Matrix[i][3] = (Matrix[i - 1][2] * Matrix[i - 1][1] + Matrix[i - 1][3] * Matrix[i - 1][3]) % 10000;
	}
}
void Binary(int n)
{
	bi = 0;
	while (n)
	{
		B[bi++] = n % 2;
		n /= 2;
	}
}
void Set()
{
	int i, k = 1, temp[4];
	St[0] = 1;
	St[1] = 0;
	St[2] = 0;
	St[3] = 1;
	for (i = 0; i < bi; i++)
	{
		if (B[i])
		{
			temp[0] = (Matrix[i + 1][0] * St[0] + Matrix[i + 1][1] * St[2]) % 10000;
			temp[1] = (Matrix[i + 1][0] * St[1] + Matrix[i + 1][1] * St[3]) % 10000;
			temp[2] = temp[1];
			temp[3] = (Matrix[i + 1][2] * St[1] + Matrix[i + 1][3] * St[3]) % 10000;
			St[0] = temp[0];
			St[1] = temp[1];
			St[2] = temp[2];
			St[3] = temp[3];
		}
	}
}
void Cal(int a, int b, int n, int digit)
{
	int x, p = int(pow(10, digit));
	Binary(n);
	Set();
	x = (St[0] * a) % p + (St[1] * (b)) % p;
	x %= p;
	printf("%d\n", x);
}
int main()
{
	int a, b, n, digit, kases, k = 1;
	Gen();
	scanf("%d", &kases);
	while (kases--)
	{
		scanf("%d%d%d%d", &a, &b, &n, &digit);
		Cal(a, b, n, digit);
	}
	return 0;
}
