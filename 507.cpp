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
#define PI		acos(-1.0)
#define INF		1<<30
#define EPS		1e-9
#define sqr(x)	(x)*(x)

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T, t;
	cin >> T;
	FOI(t, 1, T){
		int N, i, j;
		cin >> N;
		--N;
		int arr[N];
		FOI(i, 0, N-1)
			cin >> arr[i];
		int maxSum = -INF, maxSta = 0, maxEnd = 0;
		int curSum = 0, curSta = 0, curEnd = 0;
		FOI(curEnd, 0, N-1){
			curSum += arr[curEnd];
			if (curSum > maxSum ||
			   ((curSum == maxSum && ((curEnd - curSta > maxEnd - maxSta) || (curEnd - curSta == maxEnd - maxSta && curSta < maxSta))))){
				maxSum = curSum;
				maxSta = curSta;
				maxEnd = curEnd;
			}
			if (curSum < 0){
				curSum = 0;
				curSta = curEnd + 1;
			}
		}
		if (maxSum <= 0)
			cout << "Route " << t << " has no nice parts" << endl;
		else
			cout << "The nicest part of route " << t << " is between stops " << maxSta + 1 << " and " << maxEnd + 2 << endl;
	}
	return 0;
}

