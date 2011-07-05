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

#define INF 1 << 30
#define EPS 1e-9

struct Rec{
	double inc;
	double exp;
};

int main(){
	freopen("testI.txt", "r", stdin);
	freopen("testO.txt", "w", stdout);
	int test, t, i, j, k;
    cin >> test;
    FOI(t, 1, test){
		int N, R;
		double P;
		cin >> N >> R >> P;
		Rec mat[N][N];
		FOI(i, 0, N-1){
			FOI(j, 0, N-1){
				mat[i][j].inc = -1;
				mat[i][j].exp = INF;
			}
		}
		while(R--){
			int inX, inY;
			double I, E;
			cin >> inX >> inY >> I >> E;
			mat[inX][inY].inc = max(mat[inX][inY].inc, I);
			mat[inX][inY].exp = min(mat[inX][inY].exp, E);
		}
		FOI(k, 0, N-1)
			FOI(i, 0, N-1)
				FOI(j, 0, N-1){
					double P1 = (mat[i][j].inc / mat[i][j].exp);
					double P2 = (mat[i][k].inc + mat[k][j].inc) / (mat[i][k].exp + mat[k][j].exp);
					if (P1 <= P2){
						mat[i][j].inc = mat[i][k].inc + mat[k][j].inc;
						mat[i][j].exp = mat[i][k].exp + mat[k][j].exp;
					}
				}
		bool stat = false;
		FOI(i, 0, N-1)
			if(mat[i][i].inc / mat[i][i].exp >= P){
				stat = true;
				break;
			}
		if (stat)
			cout << "Case " << t << ": YES\n";
		else
			cout << "Case " << t << ": NO\n";
	}
	return 0;
}
