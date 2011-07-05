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

struct Team{
       string name;
       int att;
       int def;
};

bool mainComp(Team A, Team B){
     if(A.att != B.att)
              return (A.att > B.att);
     else if(A.def != B.def)
          return (A.def < B.def);
     else
         return (A.name < B.name);
}
bool supComp(Team A, Team B){
     return (A.name < B.name);
}
int main(){
    int test;
    cin>>test;
    for(int t=1; t<=test; t++){
            Team team[10];
            int i;
            for(i=0; i<10; i++)
                     cin>>team[i].name>>team[i].att>>team[i].def;
            sort(team, team+10, mainComp);
            cout<<"Case "<<t<<":\n";
            sort(team, team+5, supComp);
            cout<<"("<<team[0].name<<", "<<team[1].name<<", "<<team[2].name<<", "<<team[3].name<<", "<<team[4].name<<")\n";
            sort(team+5, team+10, supComp);
            cout<<"("<<team[5].name<<", "<<team[6].name<<", "<<team[7].name<<", "<<team[8].name<<", "<<team[9].name<<")\n";
    }
    return 0;
}
