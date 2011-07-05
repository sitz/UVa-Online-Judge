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

typedef long long int64;
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define MAX 1000000

int main(){
	freopen("testI.txt", "r", stdin);
	freopen("testO.txt", "w", stdout);
	int T, t, i;
	scanf("%d\n", &T);
	FOI(t, 1, T){
		double avg = 0.0, temp;
		FOI(i, 1, 12){
			scanf("%lf", &temp);
			avg += temp;
		}
		avg /= 12.0;
		string str = format(avg);
		printf("%d $%.2lf\n", t, avg/12.0);
	}
	return 0;
}
