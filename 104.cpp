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
    int N;    
    while(cin>>N){
                  double best[20][20][20];
                  int path[20][20][20];
                  int i, j, k, steps;
                  memset(best, 0, sizeof(double)*20*20*20);
                  for(i=0; i<N; i++){
                           for(j=0; j<N; j++){
                                    path[i][j][0] = i;
                                    if(i==j)
                                            best[i][j][0] = 1.0;
                                    else
                                        cin>>best[i][j][0];
                           }
                  }
                  bool stat=false;
                  for(steps=1; steps<N; steps++){
                            for(k=0; k<N; k++){
                                     for(i=0; i<N; i++){
                                              for(j=0; j<N; j++){
                                                       double tmp = best[i][k][steps-1] * best[k][j][0];
                                                       if (tmp > best[i][j][steps]){
                                                               best[i][j][steps] = tmp;
                                                               path[i][j][steps] = k;
                                                       }
                                              }
                                     }
                            }
                  }
                  for(steps=1; steps<N; steps++){
                  for(i=0; i<N; i++){
                           if(best[i][i][steps] > 1.01){
                                                int seq[steps];
                                                seq[steps]=path[i][i][steps];
                                                for(j=steps-1; j>=0; j--)
                                                      seq[j]=path[i][seq[j+1]][j];
                                                for(j=0;j<=steps;j++)
                                                      cout<<seq[j]+1<<" ";
                                                cout<<seq[0]+1<<endl;
                                                stat = true;
                                                break;
                           }
                  }
                   if(stat)
                           break;
                  }
                  if(!stat)
                           cout<<"no arbitrage sequence exists\n";
    }
    return 0;
}
