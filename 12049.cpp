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

#define FOI(i, A, B) for (i = A; i <= B; i++)
#define FOD(i, A, B) for (i = A; i >= B; i--)

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		int M, N, I, i;
		scanf("%d%d", &M, &N);
		map<int, int> Map;
		map<int, int>::iterator it;
		for (i = 0; i < M; i++) {
			scanf("%d", &I);
			Map[I] += 1;
		}
		for (i = 0; i < N; i++) {
			scanf("%d", &I);
			Map[I] -= 1;
		}
		int tot = 0;
		for (it = Map.begin(); it != Map.end(); it++)
			tot += abs((*it).second);
		printf("%d\n", tot);
	}
	return 0;
}
