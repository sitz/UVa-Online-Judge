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

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define INF		1LL<<50

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int64 T;
	cin >> T;
	while (T--){
		vector< string > vec;
		string str;
		cin >> str;
		int64 i, j, k;
		int64 N = str.length();
		vec.push_back(str);
		FOI(i, 1, N-1){
			cin >> str;
			vec.push_back(str);
		}
		int64 mat[N][N];
		FOI(i, 0, N-1){
			FOI(j, 0, N-1){
				if (vec[i][j] == '1')
					mat[i][j] = 1;
				else
					mat[i][j] = -1 * INF;
			}
		}
					
		FOI(i, 1, N-1)
			FOI(j, 0, N-1)
				mat[i][j] += mat[i-1][j];
				
		int64 maxSum = -1 * INF;
		FOI(i, 0, N-1){
			FOI(j, i, N-1){
				int64 arr[N];
				FOI(k, 0, N-1)
					arr[k] = mat[j][k];
				if (i > 0)
					FOI(k, 0, N-1)
						arr[k] -= mat[i-1][k];
					
				int64 curSum = 0;
				FOI(k, 0, N-1){
					curSum += arr[k];
					maxSum = max(curSum, maxSum);
					if (curSum < 0)
						curSum = 0;
				}
			}
		}
		maxSum = max(0LL, maxSum);
		cout << maxSum << endl;
		if (T)
			cout << endl;
	}
	return 0;
}

