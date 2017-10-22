#include <bits/stdc++.h>

using namespace std;

// problem: find numbers that has the property like 1260 = 60*21
// solution: bruteforce a,b => c = a*b , determine c's digits
// are the same as a's digits + b's digits

set<int> s4, s6, s8;
int acc[2][10];

void pre(int n)
{
	set<int> v;
	int i, bound, bigger;
	if (n == 4)
	{
		i = 10;
		bound = 100;
		bigger = 1000;
	}
	else if (n == 6)
	{
		i = 100;
		bound = 1000;
		bigger = 100000;
	}
	else if (n == 8)
	{
		i = 1000;
		bound = 10000;
		bigger = 10000000;
	}
	for (; i < bound; i++)
		for (int j = i; j < bound; j++)
		{
			memset(acc, false, sizeof(acc));
			int mul, ti, tj;
			ti = i;
			tj = j;
			if (ti % 10 == 0 && tj % 10 == 0)
			{
				continue; // no trailing zero
			}
			mul = i * j;
			if ((mul / bigger) == 0 || mul & 1)
			{
				continue;
			}
			while (ti)
			{
				acc[0][ti % 10]++;
				ti /= 10;
			}
			while (tj)
			{
				acc[0][tj % 10]++;
				tj /= 10;
			}
			while (mul)
			{
				acc[1][mul % 10]++;
				mul /= 10;
			}
			for (ti = 0; ti < 10; ti++)
				if (acc[0][ti] != acc[1][ti])
				{
					break;
				}
			if (ti == 10)
			{
				v.insert(i * j);
			}
		}
	if (n == 4)
	{
		s4 = v;
	}
	else if (n == 6)
	{
		s6 = v;
	}
	else
	{
		s8 = v;
	}
}

int main()
{
	int n;
	bool first = true;
	set<int>::iterator iter1, iter2;
	pre(4);
	pre(6);
	pre(8);
	while (cin >> n)
	{
		if (n == 4)
		{
			iter1 = s4.begin();
			iter2 = s4.end();
		}
		else if (n == 6)
		{
			iter1 = s6.begin();
			iter2 = s6.end();
		}
		else
		{
			iter1 = s8.begin();
			iter2 = s8.end();
		}
		for (; iter1 != iter2; iter1++)
		{
			cout << *iter1 << endl;
		}
		printf("\n");
	}
	return 0;
}
