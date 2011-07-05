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

double power(int N){
	if( N == 0 )
		return 1.0;
	if( N == 1 )
		return 2.0;
	double val = power(N/2);
	val = val * val;
	if( N % 2 == 0 )
		return val;
	else
		return val * 2.0;
}

int main(){
	freopen("testI.txt", "r", stdin);
	freopen("testO.txt", "w", stdout);
	int T, test;
	scanf("%d", &T);
	FOI(test, 1, T){
		int i, N;
		scanf("%d", &N);
		--N;
		double num[N+1], coef[N+1], val = 0.0;
		FOI(i, 0, N)
			scanf("%lf", &num[i]);
		coef[0] = 1;
		FOI(i, 1, N)
			coef[i] = ( coef[i-1] * (N - i + 1) ) / i;
		FOI(i, 0, N)
			val += coef[i] *  num[i];
		val /= power(N);
		printf("Case #%d: %.3lf", test, val );
		if( T > 0 )
			printf("\n");
	}
	return 0;
}
