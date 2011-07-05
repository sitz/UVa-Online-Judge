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
    freopen("test.txt", "r", stdin);
    while(true){
                int N, i, j, I, J;
                cin>>N;
                if(N == 0)
                        break;
                vector<int> rel;
                FOI(i, 1, N)
                         rel.push_back(i);

                while(true){
                            bool in=true;
                            vector<int> act(rel.begin(), rel.end());
                            vector<int> req;
                            FOI(i, 1, N){
                                   int num;
                                   cin>>num;
                                   if(num==0){
                                              in=false;
                                              break;
                                   }
                                   req.push_back(num);
                            }
                            if(!in){
                                   break;
                            }
                            stack<int> stak;
                            bool flag = true;
                            while(true){
                                   if(req.front()==act.front()){
                                                      req.erase(req.begin());
                                                      act.erase(act.begin());
                                   }
                                   else if(!stak.empty()){
                                        if(req.front()==stak.top()){
                                                                   stak.pop();
                                                                   req.erase(req.begin());
                                        }
                                   }
                                   else{
                                        while(req.begin()!=act.begin()){
                                                              stak.push(act.front());
                                                              act.erase(act.begin());
                                                              if(act.empty()){
                                                                       break;
                                                              }
                                        }
                                   }
                                   if(act.empty() && stak.top() != req.front())
                                           flag = false;
                                   if(req.empty() || !flag)
                                           break;
                            }
                            if(!flag)
                                     cout<<"No\n";
                            else
                                cout<<"Yes\n";
                }
    }
    return 0;
}
