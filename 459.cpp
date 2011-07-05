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
char adjMat[30][30];
bool visit[30][30];

string rem(string s){
	   int L = s.length(), i;
	   string str = "";
	   FOI(i, 0, L-1){
	   		  if( isalpha(s[i]) )	str += s[i];	  
      }
 	   return str;
}

void floodFill(int X, int Y){
	if ( X < 0 || Y < 0 || X >= N || Y >= N ) return;
	if ( !visit[X][Y] ) return;
	
	visit[X][Y] = false;
	
	int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
	int j;
	FOI(j, 0, 7)
		floodFill(X + dx[j], Y + dy[j]);
}

int main(int argc, char **argv){
	freopen("testI.txt", "r", stdin);
	freopen("testO.txt", "w", stdout);
	int T;
	scanf("%d\n", &T);
	cout << T << endl;
	while( T-- ){
		char ch;
		int i, j;
		int comp = 0;
		string str;
		getline(cin, str);
		str = rem(str);
		cout << str << endl;
		N = str[0] - 'A' + 1;
		memset( visit, false, sizeof (visit) );
		while( getline(cin, str) ){
            str = rem(str);
            cout << str << endl;
			if( str == "" )	break;
			
			visit[str[0]-'A'][str[1]-'A'] = true;
			visit[str[1]-'A'][str[0]-'A'] = true;
		}
		FOI(i, 0, N-1){
			   FOI(j, 0, N-1)
			   		  cout << visit[i][j] << " ";
 			  cout << endl;
       }
		FOI(i, 0, N-1){
			FOI(j, 0, N-1){
				if( visit[i][j] ){
					comp++;
					floodFill(i, j);
				}
			}
		}
		cout << comp << endl;
		if ( T > 0 )
			cout << endl;
	}
	return 0;
}
