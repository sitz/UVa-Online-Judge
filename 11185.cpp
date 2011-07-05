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
string ref = "0123456789";
int main(){
    while(true){
                int64 N;
                cin>>N;
                if(N < 0)
                     break;
                else if(N == 0)
                     cout<<"0\n";
                else{
                string ter="";
                while(N>0){
                           int64 rem = N%3;
                           ter = ref[rem] + ter;
                           N /= 3;
                }
                cout<<ter<<endl;
                }
    }
    return 0;
}
