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

int64 G[3]; 
void Ext_gcd(int64 a,int64 b) { 
    if(b == 0){ 
        G[0] = a; G[1] = 1; G[2] = 0;
        return; 
    } 
    Ext_gcd(b,a%b); 
    int64 x = G[1]; 
    G[0] = G[0]; G[1] = G[2]; G[2] = (x - ((a/b)*G[2])); 
}

int main(){
    int64 A, B;
    while(cin>>A>>B){
                     Ext_gcd(A, B);
                     cout<<G[1]<<" "<<G[2]<<" "<<G[0]<<endl;
    }
    return 0;
}
