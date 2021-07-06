#include <bits/stdc++.h>

using namespace std;

#define ss "%lld"
typedef long long Long;
Long getSum(Long n)
{
	Long k = (4 * n + 4) * n;
	return k / 2;
}
Long Cal(Long n)
{
	Long myrange = n / 2 - 1;
	if (n == 1)
	{
		return 1;
	}
	else if (n == 3)
	{
		//return 15;
	}
	Long first = (myrange + 1) * 2 + getSum(myrange) + 1;
	Long last = (myrange * 2 + 2) * 2 + first;
	Long result = last + (last - 2) + (last - 4);
	return result;
}
int main()
{
	Long n;
	while (scanf(ss, &n) == 1)
	{
		printf(ss, Cal(n));
		puts("");
	}
	return 0;
}
