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
#define LIM 1000001
int main(){
    static int64 vec[LIM], i;
    vec[3] =0;
    vec[4] = 1;
    for(i=5; i<LIM; i++){
             int64 b = i/2 + 1;
             int64 R = i*(i-1) -(i+1)*(i-b) -b*(b-1);
             vec[i] = vec[i-1] + R;
    }
    while(true){
                int ind;
                scanf("%d", &ind);
                if(ind < 3)
                       break;
                printf("%lld\n", vec[ind]);
    }
    return 0;
}
