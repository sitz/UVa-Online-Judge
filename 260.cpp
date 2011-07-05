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

int N;
char adjMat[205][205];
bool visit[205][205];
char output;

void dfs(int X, int Y, char cur){
	if ( X < 0 || Y < 0 || X >= N || Y >= N )
		return;
	if ( adjMat[X][Y] != cur || visit[X][Y] )
		return;
	
	if( X == N-1 && adjMat[X][Y] == 'b' ){
		output = 'B';
		return;
	}
	if( Y == N-1 && adjMat[X][Y] == 'w' ){
		output = 'W';
		return;
	}
	visit[X][Y] = true;
	
	int dx[] = {-1, -1, 0, 0, 1, 1};
	int dy[] = {-1, 0, -1, 1, 0, 1};
	int j;
	FOI(j, 0, 5)
		dfs(X + dx[j], Y + dy[j], cur);
}

int main(int argc, char **argv){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	for (int T = 1; ; T++){
		scanf("%d", &N);
		if( N == 0 )
			break;
		int i;
		FOI(i, 0, N-1)
			scanf("%s", adjMat[i]);
			
		memset( visit, false, sizeof (visit) );
		
		FOI(i, 0, N-1)
			if( !visit[0][i] && adjMat[0][i] == 'b' )
				dfs(0, i, 'b');
		FOI(i, 0, N-1)
			if( !visit[i][0] && adjMat[i][0] == 'w' )
				dfs(i, 0, 'w');
				
		printf("%d %c\n", T, output);
	}
	return 0;
}
