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

struct compare {
  bool operator()(const int& l, const int& r) {
      return l > r;
  }
};

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	while (true){
		int64 N;
		scanf("%lld", &N);
		if (N == 0)
			break;
		priority_queue <int64, vector<int64>, compare> pq;
		int64 i, T = 0, I;
		FOI(i, 1, N){
			scanf("%lld", &I);
			pq.push(I);
		}
		while (pq.size() > 1){
			int64 V = 0;
			V += pq.top(); pq.pop();
			V += pq.top(); pq.pop();
			T += V;
			pq.push(V);
		}
		printf("%lld\n", T);
	}
	return 0;
}

