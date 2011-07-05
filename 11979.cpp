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

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define PI	acos(-1.0)
#define INF	1<<30
#define EPS	1e-9
#define sqr(x)	(x)*(x)

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T, t;
	scanf("%d", &T);
	FOI(t, 1, T){
		int N, M;
		int i, j;
		scanf("%d%d", &N, &M);
		int mat[N][M];
		FOI(i, 0, N-1)
			FOI(j, 0, M-1)
				scanf("%d", &mat[i][j]);
		printf("Case %d: %d\n", t, N * M);
	}
	return 0;
}

