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
	int T;
	scanf("%d", &T);
	while (T--){
		int N, i;
		scanf("%d", &N);
		vector <int> ind(N);
		FOI(i, 0, N-1)
			ind[i] = i + 1;
		FOI(i, 0, N-1){
			int I;
			scanf("%d", &I);
			printf("%d", ind[I]);
			ind.erase(ind.begin() + I);
			if (i < N-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}

