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

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	while (true){
		int N;
		scanf("%d", &N);
		if (N == 0)
			break;
		double Max = 0;
		int Ind = 1, i;
		FOI(i, 1, N){
			double A, B, T;
			scanf("%lf%lf", &A, &B);
			T = A;
			A = min(T, B);
			B = max(T, B);
			double val = max( min(A, B/4.0), min(A/2.0, B/2.0) );
			if (val > Max){
				Max = val;
				Ind  = i;
			}
		}
		printf("%d\n", Ind);
	}
	return 0;
}

