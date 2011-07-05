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
#define PI		acos(-1.0)
#define INF		1<<30
#define EPS		1e-9
#define sqr(x)	(x)*(x)

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	for (int t = 1; ; t++){
		int C, S, Q;
		scanf("%d%d%d", &C, &S, &Q);
		if (C == 0 && S == 0 && Q == 0)
			break;
		int mat[C][C];
		int i, j, k;
		FOI(i, 0, C-1)
			FOI(j, 0, C-1)
				mat[i][j] = INF;
		FOI(i, 1, S){
			int C1, C2, D;
			scanf("%d%d%d", &C1, &C2, &D);
			--C1; --C2;
			mat[C1][C2] = D;
			mat[C2][C1] = D;
		}
		FOI(k, 0, C-1)
			FOI(i, 0, C-1)
				FOI(j, 0, C-1)
					mat[i][j] = min(mat[i][j], max(mat[i][k], mat[k][j]));
		if (t > 1)
			printf("\n");
		printf("Case #%d\n", t);
		while (Q--){
			int C1, C2;
			scanf("%d%d", &C1, &C2);
			--C1; --C2;
			if (mat[C1][C2] == INF)
				printf("no path\n");
			else
				printf("%d\n", mat[C1][C2]);
		}
	}
	return 0;
}

