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
#define INF 999999999

using namespace std;

struct node{
       string str;
       int dis;
       node (string s, int d){
            str = s;
            dis = d;
       }
};

int bfs( string fr, string to, map<string, vector<string> > adj ){
    map <string, int> m;
    map <string, int>::iterator it;
    queue <node> q;
    node source(fr, 0);
    q.push(source);
    while(!q.empty()){
                      node n = q.front();
                      if(n.str == to)
                               return n.dis;
                      q.pop();
                      m[n.str] = n.dis;
                      for(int i=0; i<adj[n.str].size(); i++){
                               it = m.find(adj[n.str][i]);
                               if(it == m.end())
                                     q.push(node(adj[n.str][i], n.dis+1));
                      }
    }
    return INF;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
    int test, t, i, j;
    cin >> test;
    cout<< "SHIPPING ROUTES OUTPUT\n\n";
    for(t=1; t<=test; t++){
             cout << "DATA SET  "<<t<<"\n\n";
             int M, N, P;
             cin >> M >> N >> P;
             map < string, vector <string> > adj;
             for(i=0; i<M; i++){
                      string str;
                      vector <string> nul;
                      cin >> str;
                      adj[str] = nul;
             }
             for(i=0; i<N; i++){
                      string strA, strB;
                      cin >> strA >> strB;
                      adj[strA].push_back(strB);
                      adj[strB].push_back(strA);
             }
             for(i=0; i<P; i++){
                      int val;
                      string fr, to;
                      cin >> val >> fr >> to;
                      int cost = bfs(fr, to, adj);
                      if(cost == INF)
                              cout << "NO SHIPMENT POSSIBLE" << endl;
                      else
                          cout << "$" << val*cost*100 << endl;
             }
             cout << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}
