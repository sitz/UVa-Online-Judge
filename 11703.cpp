#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long int64;

#define FOI(i, A, B) for (i = A; i <= B; i++)
#define FOD(i, A, B) for (i = A; i >= B; i--)

#define MAX 1000000

int dp[MAX + 1];

int memo(int I) {
	if (dp[I] != -1)
		return dp[I];
	int A = memo(int(I - sqrt(I))) % MAX;
	int B = memo(int(log(I))) % MAX;
	int C = memo(int(I * sin(I) * sin(I))) % MAX;
	dp[I] = (A + B + C) % MAX;
	return dp[I];
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	memset(dp, -1, sizeof dp);
	dp[0] = 1;
	while (true) {
		int N;
		scanf("%d", &N);
		if (N == -1) break;
		printf("%d\n", memo(N));
	}
	return 0;
}
