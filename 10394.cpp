#include <bits/stdc++.h>

using namespace std;

enum
{
	MAX = 20000000 + 1
};

bitset<MAX> p;

void sieve()
{
	p.flip();
	p[0] = p[1] = 0;
	for (int i = 3; i * i <= MAX; i += 2)// WA: i<=MAX
	{
		if (p[i])
			for (unsigned int j = i * i; j < MAX; j += i)
			{
				p[j] = 0;
			}
	}
}

int main()
{
	sieve();
	vector<pair<int, int>> twin;
	twin.push_back(make_pair(0, 0)); // skip twin[0]
	for (int i = 5; i < MAX; i += 2)
	{
		if (p[i] && p[i - 2])
		{
			twin.push_back(make_pair(i - 2, i));
		}
	}
	int no;
	while (scanf("%d", &no) == 1)
	{
		printf("(%d, %d)\n", twin[no].first, twin[no].second);
	}
	return 0;
}
