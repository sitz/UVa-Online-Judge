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
    int t;
    for(t=1; ; t++){
                int N, M, i, j;
                cin>>N;
                if(N == 0)
                     break;
                int64 vec[N];
                FOI(i, 0, N-1)
                       cin>>vec[i];
                vector <int64> mat;
                FOI(i, 0, N-1){
                       FOI(j, 0, N-1){
                              if(i != j)
                                   mat.push_back(vec[i]+vec[j]);
                       }
                }
                int SZ = mat.size();
                cin>>M;
                cout<<"Case "<<t<<":\n";
                while(M--){
                           int64 K;
                           cin>>K;
                           int64 diff = INT_MAX, val=vec[0];
                           FOI(i, 1, SZ-1){
                                  int64 temp = abs(mat[i] - K);
                                  if(temp < diff){
                                          diff = temp;
                                          val = mat[i];
                                  }
                           }
                           cout<<"Closest sum to "<<K<<" is "<<val<<".\n";
                }
    }
    return 0;
}
