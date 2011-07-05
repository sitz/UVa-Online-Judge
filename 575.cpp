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
                string str;
                cin >> str;
                if(str == "0")
                       break;
                uint64 po=2, tot=0;
                int i, len = str.length();
                for(i=len-1; i>=0; i--){
                             tot += (str[i] - '0')*(po-1);
                             po *= 2;
                }
                cout<<tot<<endl;
    }
    return 0;
}
