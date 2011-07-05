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
#define REP(i, N) for(i=1; i<=N; i++)

#define INF (int64)1e10

int main(){
    while(true){
                int N, i, j, k;
                cin>>N;
                if(N == 0)
                     break;
                int64 floyd[N][N];
                FOI(i, 0, N-1){
                       FOI(j, 0, N-1){
                              floyd[i][j] = INF;
                       }
                }
                
                FOI(i, 1, N-1){
                       int Ai;
                       int64 Li;
                       cin>>Ai>>Li;
                       floyd[i][Ai] = Li;
                       floyd[Ai][i] = Li;
                }
                
                FOI(k, 0, N-1){
                       FOI(i, 0, N-1){
                              FOI(j, 0, N-1){
                                     floyd[i][j] = min( floyd[i][j], floyd[i][k]+floyd[k][j] );
                              }
                       }
                }
                int Q;
                cin>>Q;
                FOI(i, 1, Q){
                       int inI, inJ;
                       cin>>inI>>inJ;
                       cout<<floyd[inI][inJ];
                       if(i < Q)
                            cout<<" ";
                }
                //system("pause");
                cout<<endl;
    }
    return 0;
}
