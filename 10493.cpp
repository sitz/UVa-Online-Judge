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
                int64 M, N;
                cin>>N>>M;
                if(N==0 && M==0)
                        break;
                int64 num = M*N - 1;
                int64 den = N - 1;
                if(N==1 && M==1)
                        cout<<N<<" "<<M<<" Multiple\n";
                else if((N==1 && M>1) || (num%den!=0))
                         cout<<N<<" "<<M<<" Impossible\n";
                else
                    cout<<N<<" "<<M<<" "<<num/den<<endl;
    }
    return 0;
}
