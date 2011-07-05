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
typedef unsigned long long uint64;

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)

int EditDistance(string A, string B){
	int i, j;
	int N = A.length();
	int d[N+1][N+1];
	
	FOI(i, 0, N){
		d[i][0] = 0;
		d[0][i] = 0;
	}

	FOI(i, 1, N)
		FOI(j, 1, N){
			if( A[i-1] == B[j-1] )
				d[i][j] = d[i-1][j-1];
			else
				d[i][j] = min( min( d[i-1][j], d[i][j-1] ), d[i-1][j-1] ) + 1;
		}
	return d[N][N];
}


int main(){
    //freopen("Test.txt", "r", stdin);
    //freopen("TestO.txt", "w", stdout);
    int T, i, j, t;
    cin >> T;
    FOI(t, 1, T){
    	string sA, sB;
    	cin >> sA;
 		sB = sA;	reverse(sB.begin(), sB.end());
 		//cout << sA << " " << sB << endl;
 		
    	int cost = ( EditDistance(sB, sA) + 1 )/ 2;
 
    	cout << "Case " << t << ": " << cost << endl;
    }
    return 0;
}
