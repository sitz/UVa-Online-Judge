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
    for(int t=1; ; t++){
                int N, i;
                cin>>N;
                bool stat[81];
                memset(stat, false, sizeof(stat));
                int tot = 0;
                for(i=0; i<N; i++){
                         int a, b, c, val;
                         cin>>a>>b>>c>>val;
                         if(!(stat[a] | stat[b] | stat[c]) && a!=b!=c)
                                      tot += val;
                         stat[a] = true;
                         stat[b] = true;
                         stat[c] = true;
                }
                if(tot > 0)
                       cout<<"Case "<<t<<": "<<tot<<endl;
                else
                    cout<<"Case "<<t<<": -1"<<endl;
    }
    return 0;
}
