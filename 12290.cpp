#include <bits/stdc++.h>

using namespace std;

#define N 100000
#define LL long long

int main()
{
	char a[10];
	set<int> s;
	for (int i = 7; i < N; i++)
	{
		sprintf(a, "%d", i);
		if (strchr(a, '7'))
			s.insert(i);
		if (i % 7 == 0)
			s.insert(i);
	}

	int n, m, k;
	while (scanf("%d %d %d", &n, &m, &k))
	{
		if (n == 0 && m == 0 && k == 0)
			break;
		int person = 1, action = 1;
		bool increase = true;
		set<int>::iterator it = s.begin();
		while (true)
		{
			if (*it == action)
			{
				it++;
				if (person == m)
					k--;
				if (!k)
				{
					printf("%d\n", action);
					break;
				}
			}
			action++;
			if (person == n)
				increase = false;
			else if (person == 1)
				increase = true;

			if (increase)
				person++;
			else
				person--;
		}
	}
	return 0;
}
