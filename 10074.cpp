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
	while (true){
		int64 M, N;
		cin >> M >> N;
		if (M == 0 && N == 0)
			break;
		int64 mat[M][N];
		int64 i, j, k;
		FOI(i, 0, M-1){
			FOI(j, 0, N-1){
				cin >> mat[i][j];
				if (mat[i][j] == 1)
					mat[i][j] = -1 * INF;
				else
					mat[i][j] = 1;
			}
		}
					
		FOI(i, 1, M-1)
			FOI(j, 0, N-1)
				mat[i][j] += mat[i-1][j];
				
		int64 maxSum = -1 * INF;
		FOI(i, 0, M-1){
			FOI(j, i, M-1){
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
	}
	return 0;
}

