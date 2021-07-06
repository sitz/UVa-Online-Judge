#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

int N, J;
char Store[MAXN], Temp[MAXN], Temp1[MAXN];
struct LONGINT
{
	char Digit[MAXN];
	int Len;
} V[251];
void ADD(int s, int k)
{
	int i, n, m, carry = 0;
	int p = 0;
	int l = V[k].Len;
	J > l ? m = J : m = l;
	for (i = m - 1; i >= 0; i--)
	{
		n = V[k].Digit[i] + Temp1[i] + carry;
		Temp[p++] = n % 10;
		carry = n / 10;
	}
	if (carry)
	{
		Temp[p++] = carry;
	}
	m = 0;
	for (i = p - 1; i >= 0; i--)
	{
		V[s].Digit[m++] = Temp[i];
	}
	V[s].Len = m;
}
void MUL(int k)
{
	int i, n, carry = 0, f = 0;
	int l = V[k].Len;
	J = 0;
	for (i = l - 1; i >= 0; i--)
	{
		n = V[k].Digit[i] * 2 + carry;
		Store[J++] = n % 10;
		carry = n / 10;
	}
	if (carry)
	{
		Store[J++] = carry;
	}
	for (i = J - 1; i >= 0; i--)
	{
		Temp1[f++] = Store[i];
	}
}
void Print()
{
	int i;
	for (i = 0; i < V[N].Len; i++)
	{
		printf("%d", V[N].Digit[i]);
	}
	putchar('\n');
}
void Gen()
{
	int i;
	V[0].Digit[0] = V[1].Digit[0] = 1;
	V[0].Len = V[1].Len = 1;
	for (i = 2; i <= 250; i++)
	{
		MUL(i - 2);
		ADD(i, i - 1);
	}
}

int main()
{
	Gen();
	while (scanf("%d", &N) == 1)
	{
		Print();
	}
	return 0;
}
