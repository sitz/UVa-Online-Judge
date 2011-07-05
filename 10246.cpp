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

#define sqr(X) 			((X) * (X))
#define FOI(I, A, B)	for (I = A; I <= B; I++)
struct Cod{
       double X;
       double Y;
};

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
    for (int t = 1; ; t++){
		int N;
		cin >> N;
		if (N == 0)
			break;
		Cod frog[N];
		int i, j, k;
		FOI(i, 0, N-1)
			cin >> frog[i].X >> frog[i].Y;
		double mat[N][N];
		FOI(i, 0, N-1)
			FOI(j, 0, N-1)
				mat[i][j] = sqrt(sqr(frog[i].X - frog[j].X) + sqr(frog[i].Y - frog[j].Y));
		
		FOI(k, 0, N-1)
			FOI(i, 0, N-1)
				FOI(j, 0, N-1)
					mat[i][j] = min(mat[i][j], max(mat[i][k], mat[k][j]));
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", t, mat[0][1]);
    }
	return 0;
}
