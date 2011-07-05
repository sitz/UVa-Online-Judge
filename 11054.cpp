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

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	while( true ){
		int N;
		scanf("%d", &N);
		if( N == 0 )
			break;
		int64 arr[N + 1], T = 0;
		int i;
		FOI(i, 0, N-1)
			scanf("%lld", &arr[i]);
		FOI(i, 0, N-1){
			T += abs(arr[i]);
			arr[i + 1] += arr[i];
			
		}
		printf("%lld\n", T);
	}
	return 0;
}

