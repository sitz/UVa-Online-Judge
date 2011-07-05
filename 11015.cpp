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
    for(int t=1; ; t++){
                int N, M;
                int i, j, k;
                cin>>N;
                if(N==0)
                        break;
                cin>>M;
                string name[N];
                for(i=0; i<N; i++)
                         cin>>name[i];
                int mat[N][N];
                for(i=0; i<N; i++)
                         for(j=0; j<N; j++){
                                  if(i==j)
                                          mat[i][j] = 0;
                                  else
                                      mat[i][j] = 999999999;
                         }
                while(M--){
                           int val;
                           cin>>i>>j>>val;
                           i--; j--;
                           mat[i][j] = val;
                           mat[j][i] = val;
                }
                for(k=0; k<N; k++)
                         for(i=0; i<N; i++)
                                  for(j=0; j<N; j++)
                                           mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                int arr[N];
                for(i=0; i<N; i++){
                         int tot=0;
                         for(j=0; j<N; j++)
                                  tot += mat[j][i];
                         arr[i] = tot;
                }
                int ind=0, minm=arr[0];
                for(i=1; i<N; i++){
                         if(arr[i] < minm){
                                   minm = arr[i];
                                   ind = i;
                         }
                }
                cout<<"Case #"<<t<<" : "<<name[ind]<<endl;
    }
    return 0;
}
