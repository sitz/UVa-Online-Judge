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
    int test;
    cin>>test;
    for(int t=1; t<=test; t++){
            int N, line;
            int i, j, k;
            cin>>N>>line;
            int mat[N][N];
            for(i=0; i<N; i++){
                     for(j=0; j<N; j++){
                              if(i==j)
                                      mat[i][j]=0;
                              else
                                  mat[i][j]=999999999;
                     }
            }
            while(line--){
                          int s, d;
                          cin>>s>>d;
                          mat[s][d]=1;
                          mat[d][s]=1;
            }
            for(k=0; k<N; k++)
                         for(i=0; i<N; i++)
                                  for(j=0; j<N; j++)
                                           mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
            int S, D;
            cin>>S>>D;
            int tot=0;
            for(i=0; i<N; i++)
                     tot = max(tot, mat[S][i]+mat[i][D]);
            cout<<"Case "<<t<<": "<<tot<<endl;
    }
    return 0;
}
