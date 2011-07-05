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

#define FOI(i, A, B) for(i=A; i<B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define REP(i, N) for(i=1; i<=N; i++)

int main(){
    while(true){
                string str, temp="";
                getline(cin, str);
                if(str == "*")
                       break;
                vector <string> S;
                int i, len=str.length();
                for(i=0; i<len; i++){
                         if(!isalpha(str[i]) && temp!=""){
                                             S.push_back(temp);
                                             temp = "";
                         }
                         else if(isalpha(str[i]))
                             temp += tolower(str[i]);
                }
                if(isalpha(str[len-1]) && temp!="")
                                       S.push_back(temp);
                int cnt = S.size();
                //FOI(i, 0, cnt)
                //       cout<<S[i]<<" ";
                if(cnt == 1){
                       cout<<"Y\n";
                       continue;
                }
                bool stat=true;
                for(i=1; i<cnt; i++){
                         if(S[i][0] != S[i-1][0]){
                                    stat = false;
                                    break;
                         }
                }
                if(stat)
                        cout<<"Y\n";
                else
                    cout<<"N\n";
    }
    return 0;
}
