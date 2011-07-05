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

int N, M;
char adjMat[105][105];

void floodFill(int X, int Y){
	if ( X < 0 || Y < 0 || X >= M || Y >= N )
		return;
	if ( adjMat[X][Y] == '*' )
		return;
	
	adjMat[X][Y] = '*';
	
	int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
	int j;
	FOI(j, 0, 7)
		floodFill(X + dx[j], Y + dy[j]);
}

int main(int argc, char **argv){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	while( true ){
		scanf( "%d%d", &M, &N );
		if( M == 0 )
			break;
		int i, j;
		int oil = 0;
		FOI(i, 0, M-1)
			scanf("%s", adjMat[i]);
		FOI(i, 0, M-1)
			FOI(j, 0, N-1)
			if ( adjMat[i][j] == '@' ){
				oil++;
				floodFill(i, j);
			}
				
		printf("%d\n", oil);
	}
	return 0;
}
