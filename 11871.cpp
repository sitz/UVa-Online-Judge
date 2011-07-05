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

#define LIM 10000001
int main(){
    //clock_t t1, t2;
    //t1=clock();
    static int num[LIM][10];
    memset(num, 0, sizeof(int)*LIM*10);
    int i, j;
    FOI(i, 1, LIM){
           int N = i;
           while(N > 0){
                   num[i][N%10]++;
                   N /= 10;
           }
           FOI(j, 0, 10)
                  num[i][j] += num[i-1][j];
    }
    while(true){
                int A, B;
                cin>>A>>B;
                if(A==0 && B==0)
                        break;
                        
                int cnt[10];
                memset(cnt, 0, sizeof(cnt));
                FOI(i, 0, 10){
                         cout<<num[B][i] - num[A-1][i];
                         if(i<9)
                                cout<<" ";
                         else
                             cout<<endl;
                }
    }
    //t2=clock();
    //cout<<t2-t1;
    //system("pause");
    return 0;
}
