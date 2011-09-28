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
#include <ctime>
#include <sstream>
using namespace std;

#define INF 1<<30

int main() {
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	while (true) {
		int I;
		vector< int > V(2);
		
		cin >> V[0] >> V[1];
		while (cin >> I && I != 0) V.push_back(I);
		if (V.size() == 2 && !V[0] && !V[1]) break;
		
		int N = V.size();
		int Min = *min_element(V.begin(), V.end()) - 5;
		bool flag = false;
		
		for (int i = Min; i <= 18000; i++) {
			int Cnt = 0;
			for (int j = 0; j < N; j++) {
				if (i % (2 * V[j]) < V[j] - 5) ++Cnt;
				else break;
			}
			if (Cnt == N) {
				int S = i % 60; i /= 60;
				int M = i % 60; i /= 60;
				int H = i % 24;
				printf("%02d:%02d:%02d\n", H, M, S);
				flag = true;
				break;
			}
		}
		if (!flag)
			printf("Signals fail to synchronise in 5 hours\n");
		//cout << "Iteration Complete !" << endl;
	}
	return 0;
}
