/*
106
Fermat Vs Pythagoras
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#define min(a, b) (a<b?a:b)

typedef long long INT;
INT n, total;

char ss[1000002];

INT gcd(INT a, INT b) { return b?gcd(b,a%b):a; }

void Cal() {
	INT m , r, s, x, y, k, z;
	INT up;
	INT tri = 0, total = 0;
	m = (INT)sqrt(n);
	if(m*m < n) m++;
	for(r = 1; r<= m; r++) {
		up = min((n - r*r),r-1);
		for(s = 1; s<= up; s++) {
			x = r*r - s*s;
			y = 2*r*s;
			z = r*r + s*s;
			if(x*x + y*y == z*z && z<=n) {
				if(gcd(x,y) == 1) {
					tri++;
					for(k = 1; k*z<=n; k++) {
						ss[k*x] = 1;
						ss[k*y] = 1;
						ss[k*z] = 1;
					}
				}
			}
		}
	}
	for(k = 1; k<= n; k++) {
		if(ss[k] == 0) total++;
		ss[k] = 0;
	}
	printf("%lld %lld\n",tri, total);
}


int main() {
	while(scanf("%lld",&n) == 1) {
		Cal();
	}
	return 0;
}
