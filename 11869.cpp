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

#define FOI(i, A, B) for(i=A; i<B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define REP(i, N) for(i=1; i<=N; i++)

int main(){
    while(true){
                int N, B, i, j;
                cin>>N>>B;
                if(N==0 && B==0)
                        break;
                bool stat[N+1];
                int ball[B];
                memset(stat, false, sizeof(stat));
                FOI(i, 0, B){
                       cin>>ball[i];
                       stat[ball[i] % (N+1)] = true;
                }
                FOI(i, 0, B-1){
                       FOI(j, i+1, B){
                              int ind = abs(ball[i]-ball[j]);
                              stat[ind % (N+1)] = true;
                       }
                }
                bool flag=true;
                FOI(i, 0, N+1){
                       if(!stat[i]){
                                  flag = false;
                                  break;
                       }
                }
                if(flag)
                        cout<<"Y\n";
                else
                    cout<<"N\n";
    }
    return 0;
}
