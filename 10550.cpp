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
    while(true){
                int A, B, C, D, tot=0;
                cin>>A>>B>>C>>D;
                if(A==0 & B==0 & C==0 & D==0)
                        break;
                tot += 80;
                if(B >= A)
                     tot += (B-A);
                else
                     tot += (40 - A + B);
                tot += 40;
                if(C <= B)
                     tot += (B-C);
                else
                    tot += (40 - C + B);
                if(D >= C)
                     tot += (D-C);
                else
                    tot += (40 - C + D);
                cout<< 3240 - tot*9 <<endl;
    }
    return 0;
}
