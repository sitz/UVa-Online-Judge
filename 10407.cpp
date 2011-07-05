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

int gcd(int a, int b){
    if(b > a) return gcd(b, a);
    if(b==0) return a;
    else return gcd(b, a%b);
}
int main(){
    while(true){
            int arr[1000], i=0, n=1;
            cin>>arr[0];
            if(arr[0]==0)
                    break;
            while(true){
                        cin>>arr[n];
                        if(arr[n] == 0)
                                  break;
                        n++;
            }
            int gd = gcd(arr[0], arr[1]);
            if(arr[0]==arr[1] && n==2){
                              cout<<gd<<endl;
                              continue;
            }
            for(i=1; i<n; i++)
                     arr[i] = (int)abs(arr[i] - arr[i-1]);
            for(i=2; i<n; i++)
                     gd = gcd(gd, arr[i]);
            cout<<gd<<endl;
    }
    return 0;
}
