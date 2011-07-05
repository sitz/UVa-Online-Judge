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

bool isPalin(string str){
     int len = str.length();
     for(int k=0; k<len; k++)
             if(str[k] != str[len-k-1])
                         return false;
     return true;
}

int main(){
    string str;
    while(cin>>str){
                    int len = str.length(), i, j, tot=0, K=0;
                    string palin[10000];
                    for(i=0; i<len; i++){
                             string test="";
                             for(j=i; j<len; j++){
                                      test += str[j];
                                      if(isPalin(test)){
                                                      palin[K++] = test;
                                      }
                             }
                    }
                    sort(palin, palin+K);
                    for(i=0; i<K; i++)
                             if(palin[i] != palin[i+1])
                                         tot++;
                    cout<<"The string '"<<str<<"' contains "<<tot<<" palindromes.\n";
    }
    return 0;
}
