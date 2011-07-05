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
#define EPS    1e-10
#define sqr(x) (x)*(x)

int main(){
    int T, t;
    cin >> T;
    FOI(t, 1, T){
               int N, P, Q, i;
               cin >> N >> P >> Q;
               int vec[N];
               FOI(i, 0, N-1)
                      cin >> vec[i];
               int wet = 0, cnt = 0;
               for(i=0; i<min(N, P); i++){
                        if( wet + vec[i] > Q )
                                      break;
                        wet += vec[i];
                        cnt++;
               }
               cout << "Case " << t << ": " << cnt << endl;
    }
    //system("pause");
    return 0;
}
