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

int main(){
    while(true){
                int i, j;
                int ser[3], pri[2];
                cin>>ser[0]>>ser[1]>>ser[2];
                cin>>pri[0]>>pri[1];
                if(ser[0]==0 && ser[1]==0 && ser[2]==0 && pri[0]==0 && pri[1]==0)
                                                             break;
                sort(ser, ser+3);
                sort(pri, pri+2);
                bool stat[53];
                bool flag=true;
                bool gfla=true;
                int ind = -1;
                memset(stat, true, sizeof(stat));
                
                stat[ser[0]] = false;
                stat[ser[1]] = false;
                stat[ser[2]] = false;
                FOI(i, 0, 2){
                       if(pri[1]>ser[i] && stat[pri[1]]==true)
                                        stat[pri[1]] = false;
                       else if(pri[0]>ser[i] && stat[pri[0]]==true)
                                         stat[pri[0]] = false;
                       else{
                            if(!flag){
                                      gfla = false;
                                      break;
                            }
                            flag = false;
                            bool ifla = true;
                            
                            FOI(j, ser[i]+1, 52){
                                  if(stat[j]){
                                             ind = max(ind, j);
                                             ifla = false;
                                             break;
                                  }
                           }
                           if(ifla){
                                    gfla = false;
                                    break;
                           }
                       }
                }
                if(!gfla)
                         cout<<"-1\n";
                else
                    cout<<ind<<endl;
    }
    return 0;
}
