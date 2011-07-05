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
#define MAX 1000000

vector<string> Mat;
int N;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int i, int j){
	if(i < 0 || i >= N || j < 0 || j >= N)
		return;
	if(Mat[i][j] == '.')
		return;
	Mat[i][j] = '.';
	int I;
	FOI(I, 0, 4)
		dfs(i + dx[I], j + dy[I]);
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int t, T;
	cin >> T;
	FOI(t, 1, T){
		Mat.clear();
		cin >> N;
		int i, j;
		int cnt = 0;
		FOI(i, 0, N-1){
			string str;
			cin >> str;
			Mat.push_back(str);
		}
		FOI(i, 0, N-1)
			FOI(j, 0, N-1)
				if( Mat[i][j] == 'x' ){
					cnt++;
					dfs(i, j);
				}
		cout << "Case " << t << ": " << cnt << endl;
	}
	return 0;
}
