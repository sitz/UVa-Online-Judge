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

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 PINF =  999999999;
int64 NINF = -999999999;

int main(){
    while(true){
                int64 N, M, i, j, k;
                cin>>N>>M;
                if(N==0 && M==0)
                        break;
                int64 mat[N][N], minm = NINF;
                for(i=0; i<N; i++){
                         for(j=0; j<N; j++){
                                  mat[i][j] = PINF;
                         }
                }
                for(i=0; i<M; i++){
                         int64 X, Y, val;
                         cin>>X>>Y>>val;
                         mat[X][Y] = val;
                         mat[Y][X] = val;
                }
                for(k=0; k<N; k++){
                         for(i=0; i<N; i++){
                                  for(j=0; j<N; j++){
                                           mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                                  }
                         }
                }
                for(i=0; i<N; i++){
                         for(j=0; j<N; j++){
                                  minm = max(minm, mat[i][j]);
                         }
                }
                if(minm < PINF)
                        cout<<minm<<endl;
                else
                    cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
