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

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define REP(i, N) for(i=1; i<=N; i++)

int main(){
    char temp[200];
    cin.getline(temp, 200);
    int test=atoi(temp);
    while(test--){
                  stack <char> stak;
                  string str;
                  getline(cin, str, '\n');
                  int len = str.length(), i;
                  bool flag = true;
                  FOI(i, 0, len-1){
                         if(str[i]=='(' || str[i]=='[')
                                        stak.push(str[i]);
                         else if(str[i]==')' || str[i]==']'){
                              if(stak.empty()){
                                               flag = false;
                                               break;
                              }
                              else if(str[i]==')'){
                                   if(stak.top()=='(')
                                                      stak.pop();
                                   else{
                                        flag = false;
                                        break;
                                   }
                              }
                              else if(str[i]==']'){
                                   if(stak.top()=='[')
                                                      stak.pop();
                                   else{
                                        flag = false;
                                        break;
                                   }
                              }
                         }
                  }
                  if(!stak.empty() || !flag)
                                   cout<<"No\n";
                  else
                      cout<<"Yes\n";
    }
    return 0;
}
