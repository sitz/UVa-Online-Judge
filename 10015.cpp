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
#define MAX 100000

bool isP[MAX + 1];
vector<int> Prime;

void seive(){
	memset(isP, true, sizeof isP);
	isP[0] = false; isP[1] = false;
	for (int i = 2; i <= MAX; i++){
		if (isP[i]){
			Prime.push_back(i);
			for (int j = 2 * i; j <= MAX; j += i)
				isP[j] = false;
		}
	}
	//cout << Prime.size() << endl;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	seive();
	while (true){
		int N, i;
		scanf("%d", &N);
		if (N == 0) break;
		vector<int> V(N);
		FOI(i, 0, N-1)
			V[i] = i + 1;
		int pos = 0;
		FOI(i, 0, N-2){
			pos = (pos + Prime[i] - 1) % V.size();
			//cout << Prime[i] << " " << pos << endl;
			V.erase(V.begin() + pos);
		}
		printf("%d\n", V[0]);
	}
	return 0;
}

