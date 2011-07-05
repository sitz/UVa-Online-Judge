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

struct Item{
       string name;
       double PST, GST, HST;
};

int main(){
    int test;
    cin>>test;
    while(test--){
                  int N, M, i, j;
                  cin>>N>>M;
                  Item item[N];
                  for(i=0; i<N; i++){
                           char *ch1, *ch2, *ch3;
                           scanf("%s%s%s%s", &item[i].name, &ch1, &ch2, ch3);
                           item[i].PST = atof(ch1);
                           item[i].GST = atof(ch2);
                           item[i].HST = atof(ch3);
                  }
                  for(i=0; i<M; i++){
                           string nam;
                           double amt;
                           char ch;
                           scanf("%s$%lf", &nam, &amt);
                           for(j=0; j<N; j++)
                                    if(nam == item[j].name)
                                           break;
                           double val = (item[j].HST - item[j].GST - item[j].PST)*amt;
                           printf("%.2lf\n", val);
                  }
    }
    return 0;
}
