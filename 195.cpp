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

bool comp(char A, char B){
	char sa = tolower(A);
	char sb = tolower(B);
	if( sa == sb )
		return A < B;
	return sa < sb;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	while( test-- ){
		char str[10000];
		scanf("%s", str);
		int N = strlen(str);
		sort(str, str+N, comp);
		do{
			printf("%s\n", str);
		}while( next_permutation(str, str+N, comp) );
	}
	return 0;
}
