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

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)

int valueOf(char c){
    switch(c){
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;

        default: return 0;
    }
}

int romToDec(char *p){
    int result = 0;
    
    for(; *p; p++){
        int current = valueOf(*p);
        int next = valueOf(*(p+1));

        if(current >= next) result += current;
        else result -= current;
    }
    
    return result;
}

string decToRom(string str){
	return NULL;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	char *str;
	while( cin >> str ){
		if( !isdigit(*str) ){
			cout << romToDec(str) << endl;
		}	
		else
			cout << decToRom(str) << endl;
	}
	return 0;
}
