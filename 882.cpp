#include <bits/stdc++.h>

using namespace std;

const int MAX_K = 10;
const int MAX_M = 100;
const int INF = 1 << 29;

int K, M;
bool visited[MAX_K + 1][MAX_M + 2][MAX_M + 2];
int memo[MAX_K + 1][MAX_M + 2][MAX_M + 2];

int rec(const int k, const int low, const int high)
{
	if (visited[k][low][high])
	{
		return memo[k][low][high];
	}
	visited[k][low][high] = true;
	int &ret = memo[k][low][high];
	ret = INF;
	if (low > high)
	{
		return ret = 0;
	}
	if (low == high)
	{
		return ret = 0;
	}
	if (k == 0 && low != high)
	{
		return ret = INF;
	}
	for (int i = low; i <= high; i++)
	{
		ret = min(ret, i + max(rec(k, i + 1, high), rec(k - 1, low, i)));
	}
	return ret;
}

void init()
{
	scanf("%d%d", &K, &M);
	memset(visited, false, sizeof(visited));
}

int solve()
{
	return rec(K, 1, M + 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (; T--;)
	{
		init();
		printf("%d\n", solve());
	}
	return 0;
}
