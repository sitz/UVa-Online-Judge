#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for (int i = 0; i < n; ++i)

const int MAXN = 128;

bool v[MAXN];
int rank_[MAXN][MAXN];
int m;								  // #voters
int n;								  // #candidates

bool wins(int a, int b) // ret true if a beats b in an election
{
	int score = 0;
	FOR(i, m)
	score += rank_[i][a] < rank_[i][b];
	return score > m - score;
}
void dfs(int x)
{
	v[x] = 1;
	FOR(i, n)
	if (!v[i] && wins(x, i))
	{
		dfs(i);
	}
}

int main()
{
	for (int w, z; scanf("%d%d%d", &n, &m, &w) && n;)
	{
		bool possible = true;
		FOR(i, n)
		v[i] = false;
		FOR(i, m)
		FOR(j, n)
		{
			scanf("%d", &z);
			rank_[i][--z] = j;
		}
		dfs(--w);
		FOR(i, n)
		possible &= v[i];
		puts(possible ? "yes" : "no");
	}
	return 0;
}
