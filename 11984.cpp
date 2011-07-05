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
#define PI	acos(-1.0)
#define INF	1<<30
#define EPS	1e-9
#define sqr(x)	(x)*(x)

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T, t;
	scanf("%d", &T);
	FOI(t, 1, T){
		double C, dF, F;
		scanf("%lf%lf", &C, &dF);
		F = C * 9.0/5.0 + 32;
		F += dF;
		C = (F - 32)*5.0/9.0;
		printf("Case %d: %.2lf\n", t, C);
	}
	return 0;
}

