#include <bits/stdc++.h>

using namespace std;

const int base = 1000000000;
class BigNumber
{
	int d[200], size;

public:
	BigNumber()
	{
		size = 0;
	}
	BigNumber(int n)
	{
		d[0] = n;
		size = 1;
	}
	BigNumber &operator=(const BigNumber &rhs)
	{
		size = rhs.size;
		for (int i = 0; i < size; i++)
		{
			d[i] = rhs.d[i];
		}
		return *this;
	}
	BigNumber operator+(const BigNumber &rhs)
	{
		BigNumber ans;
		int carry = 0, p, len = size, rhslen = rhs.size;
		for (p = 0; p < len && p < rhslen; p++)
		{
			int temp = d[p] + rhs.d[p] + carry;
			ans.d[p] = temp % base;
			carry = temp / base;
		}
		for (; p < len; p++)
		{
			int temp = d[p] + carry;
			ans.d[p] = temp % base;
			carry = temp / base;
		}
		for (; p < rhslen; p++)
		{
			int temp = rhs.d[p] + carry;
			ans.d[p] = temp % base;
			carry = temp / base;
		}
		if (carry)
		{
			ans.d[p++] = carry;
		}
		ans.size = p;
		return ans;
	}
	void print()
	{
		printf("%d", d[size - 1]);
		for (int i = size - 2; i >= 0; i--)
		{
			printf("%09d", d[i]);
		}
		puts("");
	}
} f[2][901], t[901];
void init()
{
	t[0] = BigNumber(1), t[1] = BigNumber(1), t[2] = BigNumber(2);
	f[0][1] = BigNumber(1), f[0][2] = BigNumber(2);
	for (int i = 3; i <= 900; i++)
	{
		int p = (i + 1) & 1, n = i & 1;
		f[n][1] = f[p][i - 1];
		for (int j = 2; j <= i; j++)
		{
			f[n][j] = f[p][j - 1] + f[n][j - 1];
		}
		t[i] = f[n][i];
	}
}
int main()
{
	init();
	int n;
	while (scanf("%d", &n), n)
	{
		printf("%d, ", n);
		t[n].print();
	}
	return 0;
}
