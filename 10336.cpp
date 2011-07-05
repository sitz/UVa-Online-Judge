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

int R, C;
string mat[500];

int dI[] = {0, -1, 0, 1};
int dJ[] = {-1, 0, 1, 0};

void floodFill(int I, int J, char ch){
	if( I < 0 || I >= R )
		return;
	if( J < 0 || J >= C )
		return;
	if( mat[I][J] != ch )
		return;
	mat[I][J] = '-';
	int k;
	FOI(k, 0, 3)
		floodFill(I + dI[k], J + dJ[k], ch);
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> R >> C;
		int i, j;
		FOI(i, 0, R-1)
			cin >> mat[i];
		int alp[26];
		FOI(i, 0, 25)
			alp[i] = 0;
		FOI(i, 0, R-1){
			FOI(j, 0, C-1){
				if( isalpha( mat[i][j] ) ){
					alp[mat[i][j] - 'a']++;
					floodFill(i, j, mat[i][j]);
				}
			}
		}
		cout << "World #" << t << endl;
		FOI(i, 0, 25){
			int ind = 0;
			FOI(j, 0, 25){
				if( alp[ind] < alp[j] ){
					ind = j;
				}
			}
			if( alp[ind] > 0 ){
				cout << (char)('a' + ind) << ": " << alp[ind] << endl;
				alp[ind] = 0;
			}
		}
	}
	return 0;
}
