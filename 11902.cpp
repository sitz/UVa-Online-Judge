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
#define REP(i, N)    for(i=1; i<=N; i++)
#define INF    INT_MAX
#define EPS    1e-10
#define sqr(x) (x)*(x)

int main(){
    int T, t;
    cin >> T;
    FOI(t, 1, T){
           int N, i, j, k;
           cin >> N;
           int mat[N][N];
           FOI(i, 0, N-1)
                  FOI(j, 0, N-1)
                         cin >> mat[i][j];
           FOI(k, 0, N-1)
                  FOI(i, 0, N-1)
                         FOI(j, 0, N-1)
                                mat[i][j] = min ( mat[i][j], mat[i][k] + mat[k][j] );
           FOI(i, 0, N-1){
                  FOI(j, 0, N-1)
                         cout << mat[i][j] << " ";
                  cout << endl;
           }
    }
    system("pause");
    return 0;
}
