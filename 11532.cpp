#include <bits/stdc++.h>

using namespace std;

// @BEGIN_OF_SOURCE_CODE

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long

LL powerOf2(int b)
{
	LL ret = 1;
	for (int i = 1; i <= b; i++)
	{
		ret *= 2;
	}
	return ret;
}

void makeDecimal(string s)
{
	LL ret = 0;
	for (size_t i = 0; i < s.length(); i++)
	{
		ret += (powerOf2(i) * (s.at(i) - '0'));
	}
	cout << ret << endl;
}

int main()
{
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		int p, q;
		scanf("%d %d", &p, &q);
		string str = "";
		while (p >= 2 && q >= 1)
		{
			str += "101";
			p -= 2;
			q--;
		}
		if (p == 1 && q >= 1)
		{
			str = "01" + str;
			p--;
			q--;
		}
		for (int i = 0; i < p; i++)
		{
			str += "1";
		}
		reverse(str.begin(), str.end());
		makeDecimal(str);
	}
	return 0;
}

// @END_OF_SOURCE_CODE
