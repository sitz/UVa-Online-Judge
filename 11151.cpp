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

int LCSLength(string X, string Y){
    int m = X.length();
    int n = Y.length();
    int c[m+1][n+1], i, j;
    for(i=1; i<m; i++)
             c[i][0] = 0;
    for(j=0; j<n; j++)
             c[0][j] = 0;
    for(i=1; i<=m; i++){
             for(j=1; j<=n; j++){
                      if(X[i-1] == Y[j-1])
                                c[i][j] = c[i-1][j-1] + 1;
                      else if(c[i-1][j] >= c[i][j-1])
                           c[i][j] = c[i-1][j];
                      else
                           c[i][j] = c[i][j-1];
             }
    }
    return c[m][n];
}
int main(){
    char t[10];
    cin.getline(t, 10);
    int test = atoi(t);
    while(test--){
                  string oStr, rStr="";
                  getline(cin, oStr, '\n');
                  int len = oStr.length(), mLen = 1, i, j;
                  if(len==0 || len==1){
                         printf("%d\n", len);
                         continue;
                  }
                  for(i=0; i<len; i++)
                           rStr = oStr[i] + rStr;
                  cout<<rStr<<endl;
                  mLen = LCSLength(oStr, rStr);
                  printf("%d\n", mLen);
    }
    return 0;
}
