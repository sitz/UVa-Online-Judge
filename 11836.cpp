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

struct Point{
       double x;
       double y;
       double z;
};

double distC(Point A, Point B){
       return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) + (A.z-B.z)*(A.z-B.z));
}
int main(){
    int test;
    cin>>test;
    while(test--){
                  Point defend[4], attack[4];
                  double minm = 1000000000;
                  int i=0, j=0;
                  for(i=0; i<4; i++)
                           cin>>defend[i].x>>defend[i].y>>defend[i].z;
                  for(i=0; i<4; i++)
                           cin>>attack[i].x>>attack[i].y>>attack[i].z;
                  for(i=0; i<4; i++){
                           for(j=0; j<4; j++){
                                    double dist = distC(defend[i], attack[j]);
                                    minm = (minm < dist) ? minm : dist;
                           }
                  }
                  printf("%.2lf\n", minm);
    }
    return 0;
}
