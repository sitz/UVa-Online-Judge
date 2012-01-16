#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

typedef long long int64;
const int64 MAXM =  1 * 1LL<<60;
const int64 MINM = -1 * 1LL<<60;

int main() {
	//cout << MAXM << " " << MINM << endl;
	
	int64 T, t;
	scanf("%lld", &T);
	for (t = 1; t <= T; t++) {
		int64 p, q;
		scanf("%lld %lld", &p, &q);
		
		q = 1LL<<q;
		int64 Min = MAXM;
		int64 Max = MINM;
		for (int64 i = 0; i <= 1LL<<p; i++) {
			int64 val = 0, mul = 1;
			for (int64 j = 0; j < p; j++) {
				if (i & 1LL<<j) val += (mul * 2);
				else val += (mul * 1);
				
				mul *= 10;
			}
			if (val % q == 0) {
				Min = min(Min, val);
				Max = max(Max, val);
			}
		}
		if (Min == MAXM && Max == MINM) {
			printf("Case %lld: impossible\n", t);
		}
		else if (Min == Max) {
			printf("Case %lld: %lld\n", t, Min);
		}
		else {
			printf("Case %lld: %lld %lld\n", t, Min, Max);
		}
	}
	return 0;
}
