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
string mat[50];

int dI[] = {0, -1, 0, 1};
int dJ[] = {-1, 0, 1, 0};

bool comp(pair<char, int> A, pair<char, int> B){
	if( A.second != B.second )
		return A.second > B.second;
	if( A.first != B.first )
		return A.first < B.first;
	return false;
}

int floodFill(int I, int J, char ch){
	if( I < 0 || I >= R )
		return 0;
	if( J < 0 || J >= C )
		return 0;
	if( mat[I][J] != ch )
		return 0;
	mat[I][J] = '.';
	int k, sum = 1;
	FOI(k, 0, 3)
		sum += floodFill(I + dI[k], J + dJ[k], ch);
	return sum;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	for (int t = 1; ; t++){
		cin >> R >> C;
		if(R == 0 && C == 0)
			break;
		int i, j;
		FOI(i, 0, R-1)
			cin >> mat[i];
		vector< pair<char, int> > vec;
		FOI(i, 0, R-1)
			FOI(j, 0, C-1)
				if( isalpha( mat[i][j] ) ){
					char c = mat[i][j];
					int hole = floodFill(i, j, mat[i][j]);
					vec.push_back( make_pair(c, hole) );
				}
		sort(vec.begin(), vec.end(), comp);
		cout << "Problem " << t << ":" << endl;
		FOI(i, 0, vec.size()-1)
			cout << vec[i].first << " " << vec[i].second << endl;
	}
	return 0;
}
