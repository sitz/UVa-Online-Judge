#include <bits/stdc++.h>

using namespace std;

const int MAX_N = (int)1e5;

int N;
int as[MAX_N];

void init()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", as + i);
	}
}

int solve()
{
	int ans = 0;
	set<int> lefts;
	lefts.insert(as[0]);
	for (int i = 1; i < N; i++)
	{
		if (!lefts.insert(as[i]).second)
		{
			lefts.clear();
			lefts.insert(as[i]);
			ans++;
		}
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		init();
		printf("%d\n", solve());
	}
	return 0;
}
