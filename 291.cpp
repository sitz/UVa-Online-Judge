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

bool adj[5][5];
int vec[10];

void backTrack(int ind, int cnt){
	vec[cnt] = ind;
	int i;
	if( cnt == 8 ){
		FOI(i, 0, 8)
			printf("%d", vec[i] + 1);
		printf("\n");
		return;
	}
	FOI(i, 0, 4){
		if( adj[ind][i] ){
			adj[ind][i] = adj[i][ind] = false;
			backTrack(i, cnt + 1);
			adj[ind][i] = adj[i][ind] = true;
		}
	}
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	memset(adj, false, sizeof adj);
	adj[0][1] = true; adj[1][0] = true;
	adj[0][2] = true; adj[2][0] = true;
	adj[0][4] = true; adj[4][0] = true;
	adj[1][2] = true; adj[2][1] = true;
	adj[1][4] = true; adj[4][1] = true;
	adj[2][3] = true; adj[3][2] = true;
	adj[2][4] = true; adj[4][2] = true;
	adj[3][4] = true; adj[4][3] = true;
	
	backTrack(0, 0);
	return 0;
}
