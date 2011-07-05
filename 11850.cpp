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
                int N, i;
                cin>>N;
                if(N == 0)
                     break;
                vector <int> road;
                for(i=0; i<N; i++){
                         int dis;
                         cin>>dis;
                         road.push_back(dis);
                }
                sort(road.begin(), road.end());
                bool stat = true;
                for(i=1; i<N; i++){
                         if(road[i] - road[i-1] > 200){
                                    stat = false;
                                    break;
                         }
                }
                if(stat)
                        cout<<"POSSIBLE\n";
                else
                    cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
