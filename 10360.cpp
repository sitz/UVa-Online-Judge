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

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)

int mat[1027][1027];
#define M	1025

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while( T-- ){
		int D, N;
		scanf("%d%d", &D, &N);
		memset(mat, 0, sizeof(mat) );
		while( N-- ){
			int I, J, V;
			scanf("%d%d%d", &I, &J, &V);
			mat[I][J] = V;
		}
		int gmax = 0, codX = 0, codY = 0;
		int i, j, x, y;
		FOI(i, 1, M){
			FOI(j, 1, M){
				int lmax = 0;
				FOI(x, max(1, i-D), min(M, i+D))
					FOI(y, max(1, j-D), min(M, j+D))
						lmax += mat[y][x];
				if( gmax < lmax ){
					gmax = lmax;
					codX = i;
					codY = j;
				}
			}
		}
		printf("%d %d %d\n", codX, codY, gmax);
	}
	return 0;
}
