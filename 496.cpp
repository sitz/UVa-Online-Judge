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
    string strA, strB;
    while(getline(cin, strA) && getline(cin, strB)){
                       set <string> setA, setB;
                       int lenA=strA.length(), lenB=strB.length();
                       int i;
                       string temp="";
                       for(i=0; i<lenA; i++){
                                if(isdigit(strA[i]))
                                                    temp += strA[i];
                                else if(temp != ""){
                                     setA.insert(temp);
                                     temp = "";
                                }
                       }
                       if(isdigit(strA[lenA-1]))
                                                setA.insert(temp);
                       temp = "";
                       for(i=0; i<lenB; i++){
                                if(isdigit(strB[i]))
                                                    temp += strB[i];
                                else if(temp != ""){
                                     setB.insert(temp);
                                     temp = "";
                                }
                       }
                       if(isdigit(strB[lenB-1]))
                                                setB.insert(temp);
                       set <string> comp;
                       set_intersection( setA.begin(), setA.end(), setA.begin(), setB.end(), 
                                         inserter(comp, comp.begin()) );
                       if(setA == setB)
                               cout<<"A equals B\n";
                       else if(comp.empty())
                            cout<<"A and B are disjoint\n";
                       else if(comp == setA)
                            cout<<"B is a proper subset of A\n";
                       else if(comp == setB)
                            cout<<"A is a proper subset of B\n";
                       else
                           cout<<"I'm confused!\n";
    }
    return 0;
}
