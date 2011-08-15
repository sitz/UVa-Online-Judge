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

struct Play {
	double T;
	double W;
};

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	bool flag = false;
	while (true) {
		int N, K;
		int i, j;
		cin >> N;
		if (N == 0) break;
		cin >> K;
		K = (K * N * (N - 1) )/ 2;
		Play P[N + 1];
		FOI(i, 0, N) {
			P[i].T = 0.0;
			P[i].W = 0.0;
		}
		while (K--) {
			int p1, p2;
			string m1, m2;
			cin >> p1 >> m1 >> p2 >> m2;
			if (m1 != m2) {
				P[p1].T += 1.0;
				P[p2].T += 1.0;
			   if ( (m1 == "paper" && m2 == "rock") || (m1 == "scissors" && m2 == "paper") || (m1 == "rock" && m2 == "scissors"))
					P[p1].W += 1.0;
				else
					P[p2].W += 1.0;
			}
		}
		if (flag) cout << endl;
		FOI(i, 1, N) {
			if (P[i].T > 0)
				printf("%.3lf\n", P[i].W / P[i].T);
			else
				printf("-\n");
		}
		flag = true; 
	}
	return 0;
}
