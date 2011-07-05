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
    string orig;
    while(cin>>orig){
                    bool pal=false, mir=true;
                    string dup=orig ,mirr="";
                    reverse(dup.begin(), dup.end());
                    if(dup == orig)
                           pal=true;
                    int len=orig.length(), i;
                    map <char, char> palin;
                    map <char, char>::iterator it;
                    palin['A']='A';
                    palin['E']='3';
                    palin['H']='H';
                    palin['I']='I';
                    palin['J']='L';
                    palin['L']='J';
                    palin['M']='M';
                    palin['O']='O';
                    palin['S']='2';
                    palin['T']='T';
                    palin['U']='U';
                    palin['V']='V';
                    palin['W']='W';
                    palin['X']='X';
                    palin['Y']='Y';
                    palin['Z']='5';
                    palin['1']='1';
                    palin['2']='S';
                    palin['3']='E';
                    palin['5']='Z';
                    palin['8']='8';
                    for(i=0; i<len; i++){
                             it = palin.find(dup[i]);
                             if(it==palin.end()){
                                                 mir = false;
                                                 break;
                             }
                             mirr += it->second;
                    }
                    if(mirr != orig)
                           mir = false;
                    
                    if(pal && mir)
                           cout<<orig<<" -- is a mirrored palindrome.\n\n";
                    else if(pal && !mir)
                         cout<<orig<<" -- is a regular palindrome.\n\n";
                    else if(!pal && mir)
                         cout<<orig<<" -- is a mirrored string.\n\n";
                    else
                        cout<<orig<<" -- is not a palindrome.\n\n";
    }
    return 0;
}
