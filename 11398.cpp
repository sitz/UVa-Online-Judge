#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/113/11398.html
// Runtime: 0.008s
// Tag: Binary conversion, Adhoc

// @BEGIN_OF_SOURCE_CODE

#define INF 2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long

#define For(i, a, b) for (int i = (a); i < (b); i++)
#define Fors(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fore(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define Set(a, s) memset(a, s, sizeof(a))
#define Dump(x)                                               \
	for (typeof(x.begin()) it = x.begin(); it != x.end(); it++) \
		cout << *it << " ";                                       \
	cout << endl;

int power(int b, int p)
{
	int ret = 1;
	for (int i = 1; i <= p; i++)
	{
		ret *= b;
	}
	return ret;
}

int binaryToDecimal(vector<int> &v)
{
	reverse(v.begin(), v.end());
	int ret = 0;
	Fors(i, v)
	{
		ret += power(2, i) * v[i];
	}
	return ret;
}

int main()
{
	char inp[100];
	int flag;
	vector<int> v;
	while (scanf("%s", inp))
	{
		if (!strcmp(inp, "~"))
		{
			break;
		}
		v.clear();
		while (strcmp(inp, "#"))
		{
			int len = strlen(inp);
			if (len == 1)
			{
				flag = 1;
			}
			else if (len == 2)
			{
				flag = 0;
			}
			else
				for (int i = 2; i < len; i++)
				{
					v.push_back(flag);
				}
			// Dump(v);
			scanf("%s", inp);
		}
		printf("%d\n", binaryToDecimal(v));
	}
	return 0;
}

// @END_OF_SOURCE_CODE
