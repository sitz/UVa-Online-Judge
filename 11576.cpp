#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/115/11576.html
// Runtime: 0.024s
// Tag: Adhoc

/*
 * File:   main.cpp
 * Author: shahab
 * Created on March 16, 2011, 7:16 PM
 */

// @BEGIN_OF_SOURCE_CODE

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long

#define For(i, a, b) for (int i = (a); i < (b); i++)
#define Fors(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Set(a, s) memset(a, s, sizeof(a))

string str;
string total;
int k, w;

bool isMatch(int pos)
{
	for (int i = pos; i < total.size(); i++)
	{
		if (total[i] != str[i - pos])
		{
			return false;
		}
	}
	return true;
}

void minimize()
{
	int pos = total.size() - k;
	for (int i = pos; i < total.size(); i++)
	{
		if (isMatch(i))
		{
			for (int j = total.size() - i; j < str.size(); j++)
			{
				total += str[j];
			}
			return;
		}
	}
	total += str;
}

int main(int argc, char **argv)
{
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		scanf("%d %d", &k, &w);
		total = "";
		For(i, 0, w)
		{
			cin >> str;
			minimize();
		}
		cout << total.size() << endl;
	}
	return 0;
}

// @END_OF_SOURCE_CODE
