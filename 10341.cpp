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
#include <complex>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <ctime>
using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

#define PI				acos(-1.0)
#define EPSILON			1e-5
#define EPS				1e-15
#define INF				1<<30

#define FOI(I, A, B)	for (I=A; I<=B; I++)
#define FOD(I, A, B)	for (I=A; I>=B; I--)

double p, q, r, s, t, u;

double fun(double x){
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double der(double x){
	return -p * exp(-x) + q * cos(x) -r * sin(x) + s * 1/( cos(x) * cos(x) ) +	 2 * t * x;
}

double Bisection(double lo, double hi){
	double bot = fun(lo);
	double top = fun(hi);
	double mid = (lo + hi) / 2.0;
	double cen = fun(mid);
		
	if( bot * cen  < -EPS )
		return Bisection(lo, mid);
	else if( top * cen < -EPS )
		return Bisection(mid, hi);
	else
		return mid;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	while( scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u) != EOF ){

		double bot = fun(0.0);
		double top = fun(1.0);
		
		if( ( bot > EPS && top > EPS ) || ( bot < -EPS && top < -EPS ) )
			printf("No solution\n");
		
		else if( bot > -EPS && bot < EPS )
			printf("0.0000\n");
		
		else if( top > -EPS && top < EPS )
			printf("1.0000\n");
		
		else{
			double x = Bisection(0.0, 1.0);
			printf("%.4lf\n", x);
		}
	}
	return 0;
}
