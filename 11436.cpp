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
#define MAX	50000

typedef long long int64;
typedef unsigned long long uint64;

int64 calc(double N, double K){
	double root1 = (-3*K + sqrt(12*N/K - 3*K*K))/6;
	double root2 = (-3*K - sqrt(12*N/K - 3*K*K))/6;
	if( root1 >= 0 )
		return (int64)root1;
	return (int64)root2;
}

int main(){
	while( true ){
		int64 N, K, k;
		cin >> N;
		if( N == 0 )
			break;
		K = (int64) ceil(pow(N, 1/3.0)) + 1;
		bool stat = false;
		FOI(k, 1, K){
			int64 Y = calc((double)N, (double)k);
			int64 X = k + Y;
			if( X >= 0 && Y >= 0 && X*X*X - Y*Y*Y == N ){
				cout << X << " " << Y << endl;
				stat = true;
				break;
			}
		}
		if ( !stat )
			cout << "No solution\n";
	}
	return 0;
}
