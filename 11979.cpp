#include <bits/stdc++.h>

using namespace std;

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long

#define For(i, a, b) for (int i = (a); i < (b); i++)
#define Fors(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fore(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define Set(a, s) memset(a, s, sizeof(a))

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main()
{
	int testCase;
	scanf("%d", &testCase);
	int cases = 0;
	while (testCase--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int mat[2000 + 5][10 + 5];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &mat[i][j]);
		int arr[2000 + 5];
		int cnt = 0;
		for (int j = 0; j < m; j++)
		{
			for (int i = 0; i < n; i++)
				arr[i] = mat[i][j];
			sort(arr, arr + n);
			for (int i = 0; i < n; i++)
				cnt += abs(arr[i] - i);
		}
		printf("Case %d: %d\n", ++cases, cnt);
	}
	return 0;
}
