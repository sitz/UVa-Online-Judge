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
#define INF		1LL<<60
#define EPS		1e-9
#define sqr(x)	(x)*(x)

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int64 M, N;
	while (scanf("%lld%lld", &M, &N) != EOF){
		int64 mat[M][N], pre[M][N];
		int64 i, j;
		FOI(i, 0, M-1){
			FOI(j, 0, N-1){
				scanf("%lld", &mat[i][j]);
				pre[i][j] = INF;
			}
		}
		FOD(j, N-2, 0){
			FOI(i, 0, M-1){
				int64 A = (M + i - 1) % M;
				int64 B = (M + i) % M;
				int64 C = (M + i + 1) % M;
			
				int64 mi   = min(mat[A][j+1], min(mat[B][j+1], mat[C][j+1]));
				mat[i][j] += mi;
			
				if (mi == mat[A][j+1])
					pre[i][j]  = min(pre[i][j], A);
				if (mi == mat[B][j+1])
					pre[i][j]  = min(pre[i][j], B);
				if (mi == mat[C][j+1])
					pre[i][j]  = min(pre[i][j], C);
			}
		}
		int64 minm = INF, inR = 0, inC = N - 1;
		FOI(i, 0, M-1){
			if (minm > mat[i][0]){
				inR  = i;
				minm = mat[i][0];
			}
		}
		vector< int64 > V;
		FOI(inC, 0, N-1){
			V.push_back(inR);
			inR = pre[inR][inC];
		}
		FOI(i, 0, V.size()-1){
			printf("%lld", V[i] + 1);
			if (i < V.size() - 1)
				printf(" ");
		}
		printf("\n%lld\n", minm);
	}
	return 0;
}

