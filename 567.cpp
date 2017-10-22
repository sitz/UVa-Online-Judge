#include <bits/stdc++.h>

using namespace std;

#define LLU long long unsigned int
#define LLD long long double
#define FOR(i, N) for (int i = 0; i < (N); i++)
#define MAX_INT (numeric_limits<int>::max() / 3)
int NO, from, to, cnt_inp;
int ans[22][22], how;
char c;
bool first;
string str;
void init()
{
	FOR(i, 22)
	FOR(j, 22)
	ans[i][j] = MAX_INT;
	FOR(i, 22)
	ans[i][i] = 0;
}
void calc()
{
	FOR(k, 22)
	FOR(i, 22)
	FOR(j, 22)
	ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
}
int main()
{
	first = true;
	NO = 1;
	while (cin >> how)
	{
		init();
		FOR(i, 19)
		{
			if (i != 0)
			{
				cin >> how;
			}
			from = i + 1;
			FOR(j, how)
			{
				cin >> to;
				ans[from][to] = 1;
				ans[to][from] = 1;
			}
		}
		calc();
		cin >> cnt_inp;
		cout << "Test Set #" << NO++ << endl;
		FOR(i, cnt_inp)
		{
			cin >> from >> to;
			printf("%2d to %2d: %d\n", from, to, ans[from][to]);
		}
		cout << endl;
	}
}
