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

#define FOI(i, A, B)	for(i=A; i<=B; i++)
#define FOD(i, A, B)	for(i=A; i>=B; i--)
#define EPS				1e-9

int GCD(int A, int B){
	if( B == 0 )
		return A;
	if( B > A )
		return GCD(B, A);
	return GCD(B, A%B);
}

int main(){
	while( true ){
		int N;
		cin >> N;
		if( N == 0 )
			break;
		int vec[N];
		int i, j;
		FOI(i, 0, N-1)	cin >> vec[i];
		double num = 3.0 * N * (N - 1);
		double den = 0.0;
		FOI(i, 0, N-1)
			FOI(j, i+1, N-1)
				if( GCD(vec[i], vec[j]) == 1 )
					den += 1.0;
		if( den < EPS || num < EPS )
			printf("No estimate for this data set.\n");
		else
			
			printf("%.6lf\n", sqrt(num / den));
	}
	return 0;
}
