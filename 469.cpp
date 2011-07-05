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

string mat[105];
bool used[105][105];
int R = 0, C = 0;

int dfs(int r, int c){
	if( r < 0 || r >= R )
		return 0;
	if( c < 0 || c >= C )
		return 0;
	if( !used[r][c] )
		return 0;
	
	used[r][c] = false;
	
	return 1 + dfs(r-1,c-1) + dfs(r-1,c) + dfs(r-1,c+1) + dfs(r,c+1) + dfs(r+1,c+1) + dfs(r+1,c) + dfs(r+1,c-1) + dfs(r,c-1);
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	string str;
	bool stat = false;
	int T;
	int i, j;
	cin >> T;
	if( T <= 0 )
		return 0;
	getline(cin, str);
	getline(cin, str);
	while( T-- ){
		if( stat )
			cout << endl;
		while( true ){
			getline(cin, str);
			if( str[0] != 'L' && str[0] != 'W' ){
				break;
			}
			mat[R++] = str;
		}
		C = mat[0].length();
		do{
			FOI(i, 0, R-1){
				FOI(j, 0, C-1){
					if( mat[i][j] == 'W' )
						used[i][j] = true;
					else
						used[i][j] = false;
				}
			}
			stringstream ss( str );
			int r, c;
			ss >> r >> c;
			r--; c--;
			cout << dfs(r, c) << endl;
		}while( getline(cin, str) && str.length() > 0 );
		stat = true;
	}
	return 0;
}
