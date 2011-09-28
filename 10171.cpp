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

#define FOI(i, A, B) for (i = A; i <= B; i++)
#define FOD(i, A, B) for (i = A; i >= B; i--)
#define INF	1<<30

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	while (true) {
		int N;
		cin >> N;
		if (N == 0) break;
		map<string, int> MapY, namY;
		map<string, int> MapO, namO;
		map<string, int>::iterator it1, it2;
		int matY[30][30], matO[30][30];
		int indY = 0, indO = 0;
		int i, j, k;
		FOI(i, 0, 29) {
			FOI(j, 0, 29) {
				if (i == j)
					matY[i][j] = matO[i][j] = 0;
				else
					matY[i][j] = matO[i][j] = INF;
			}
		}
		while (N--) {
			string YM, UB, X, Y;
			int D;
			cin >> YM >> UB >> X >> Y >> D;
			if (YM == "Y") {
				it1 = MapY.find(X);
				it2 = MapY.find(Y);
				if (it1 == MapY.end()) { MapY[X] = indO; namY[indO] = X; indY++; }
				if (it2 == MapY.end()) { MapY[Y] = indO; namY[indO] = Y; indY++; }
				
				matY[MapY[X]][MapY[Y]] = min(D, matY[MapY[X]][MapY[Y]]);
				if (UB == "B")
					matY[MapY[Y]][MapY[X]] = min(D, matY[MapY[Y]][MapY[X]]);
			}
			else {
				it1 = MapO.find(X);
				it2 = MapO.find(Y);
				if (it1 == MapO.end()) { MapO[X] = indO; namO[indO] = X; ind0++; }
				if (it2 == MapO.end()) { MapO[Y] = indO; namO[indO] = Y; ind0++; }
				
				matO[MapO[X]][MapO[Y]] = min(D, matO[MapO[X]][MapO[Y]]);
				if (UB == "B")
					matO[MapO[Y]][MapO[X]] = min(D, matO[MapO[Y]][MapO[X]]);
			}
		}
		FOI(k, 0, indY-1)
			FOI(i, 0, indY-1)
				FOI(j, 0, indY-1)
					matY[i][j] = min(matY[i][j], matY[i][k] + matY[k][j]);
		FOI(k, 0, indO-1)
			FOI(i, 0, indO-1)
				FOI(j, 0, indO-1)
					matO[i][j] = min(matO[i][j], matO[i][k] + matO[k][j]);
		
	}
	return 0;
}
