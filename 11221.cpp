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
    int test;
    scanf("%d\n", &test);
    for(int t=1; t<=test; t++){
            string str="", demo;
            getline(cin, demo);
            int k=0, i=0, j=0;
            for(i=0; i<demo.length(); i++){
                     if(isalpha(demo[i])){
                                         str += demo[i];
                     }
            }
            int len = str.length();
            int slen = (int)sqrt(len);
            string nstr="";
            cout<<"Case #"<<t<<":\n";
            if(slen*slen < len){
                         cout<<"No magic :(\n";
                         continue;
            }
            char mat[slen][slen];
            for(i=0; i<slen; i++){
                     for(j=0; j<slen; j++){
                              mat[i][j] = str[k++];
                     }
            }
            for(j=0; j<slen; j++){
                     for(i=0; i<slen; i++){
                              nstr += mat[i][j];
                     }
            }
            if(nstr != str){
                    cout<<"No magic :(\n";
                    continue;
            }
            nstr = "";
            for(i=slen-1; i>=0; i--){
                          for(j=slen-1; j>=0; j--){
                                        nstr += mat[i][j];
                          }
            }
            if(nstr != str){
                    cout<<"No magic :(\n";
                    continue;
            }
            nstr = "";
            for(j=slen-1; j>=0; j--){
                          for(i=slen-1; i>=0; i--){
                                        nstr += mat[i][j];
                          }
            }
            if(nstr != str){
                    cout<<"No magic :(\n";
                    continue;
            }
            cout<<slen<<endl;
    }
    return 0;
}
