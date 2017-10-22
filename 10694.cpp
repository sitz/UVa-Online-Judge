#include <bits/stdc++.h>

using namespace std;

class BigNumber
{
	vector<int> d;

public:
	BigNumber()
	{
		d.clear();
	}
	BigNumber(int n)
	{
		d.clear();
		d.push_back(n);
	}
	BigNumber(int *array, int len)
	{
		d.clear();
		for (int i = 0; i < len; i++)
		{
			d.push_back(array[i]);
		}
	}
	void operator=(BigNumber ref)
	{
		d.clear();
		for (int i = 0; i < ref.d.size(); i++)
		{
			d.push_back(ref.d[i]);
		}
	}
	BigNumber operator+(BigNumber ref)
	{
		int temp[25], len, carry = 0;
		memset(temp, 0, sizeof(temp));
		for (int i = 0; i < d.size(); i++)
		{
			temp[i] = d[i];
		}
		for (int i = 0; i < ref.d.size(); i++)
		{
			temp[i] += ref.d[i];
		}
		for (int i = 0; i < 25; i++)
		{
			int t = temp[i] + carry;
			carry = t / 1000000000;
			temp[i] = t % 1000000000;
		}
		for (len = 24; temp[len] == 0; len--)
			;
		return BigNumber(temp, len + 1);
	}
	void print()
	{
		printf("%d", d[d.size() - 1]);
		for (int i = d.size() - 2; i >= 0; i--)
		{
			printf("%09d", d[i]);
		}
		printf("\n");
	}
} f[1001], s[1001], ans[1001];
void init()
{
	f[1] = BigNumber(1);
	f[2] = BigNumber(1);
	s[1] = BigNumber(1);
	s[2] = BigNumber(2);
	ans[1] = BigNumber(1);
	ans[2] = BigNumber(3);
	for (int i = 3; i <= 1000; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		s[i] = s[i - 1] + f[i];
		ans[i] = ans[i - 1] + s[i];
	}
}
int main()
{
	int t, n;
	init();
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		if (n <= 0)
		{
			puts("0");
		}
		else
		{
			ans[n].print();
		}
	}
}
