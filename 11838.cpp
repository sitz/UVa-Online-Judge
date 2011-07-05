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

int main(){
    while(true){
                int N, test;
                int i, j, k;
                cin>>N>>test;
                if(N==0 && test==0)
                        break;
                bool mat[N][N];
                memset( mat, false, sizeof(bool)*N*N );
                while(test--){
                              int X, Y, ctr;
                              cin>>X>>Y>>ctr;
                              if(ctr == 1)
                                     mat[X-1][Y-1] = true;
                              else{
                                   mat[X-1][Y-1] = true;
                                   mat[Y-1][X-1] = true;
                              }
                }
                for(i=0; i<N; i++){
                         queue<int> que;
                         bool stat[N][N];
                         memset( stat, false, sizeof(bool)*N*N );
                         for(j=0; j<N; j++){
                                  if(mat[i][j] && !stat[i][j] && i!=j){
                                               que.push(j);
                                               stat[i][j]=true;
                                  }
                         }
                         while(!que.empty()){
                                           int ind = que.front();
                                           mat[i][ind] = true;
                                           for(j=0; j<N; j++){
                                                    if(mat[ind][j] && !stat[ind][j] && ind!=j){
                                                                   que.push(j);
                                                                   stat[ind][j]=true;
                                                    }
                                           }
                                           que.pop();
                         }
                }
                int cnt=0;
                for(i=0; i<N; i++)
                         for(j=0; j<N; j++)
                                  cnt+=mat[i][j];
                if(cnt == N*N)
                       cout<<"1\n";
                else
                    cout<<"0\n";
    }
    return 0;
}
