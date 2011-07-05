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
	freopen("testI.txt", "r", stdin);
	freopen("testO.txt", "w", stdout);
	bool stat = false;
	while (true){
		int N, i, j;
		cin >> N;
		if (N == 0)
			break;
		if (stat)
			cout << endl;
		stat = true;
		cout << "Original number was " << N << endl;
		vector < int > V;
		while (true){
			vector < int > vec;
			while (N){
				vec.push_back(N % 10);
				N /= 10;
			}
			sort(vec.begin(), vec.end());
			int A = 0, B = 0;
			FOD(i, vec.size() - 1, 0)
				A = A * 10 + vec[i];
			FOI(i, 0, vec.size() - 1)
				B = B * 10 + vec[i];
			N = A - B;
			cout << A << " - " << B << " = " << N << endl;
			V.push_back(N);
			int S = V.size();
			if (N == 0 || S > 1){
				if (N == 0){
					cout << "0 - 0 = 0\n";
					cout << "Chain length " << S + 1 << endl;
					break;
				}
				else{
					bool flag = false;
					FOI(i, 0, S - 2)
						if (V[i] == V[S - 1]){
							cout << "Chain length " << S << endl;
							flag = true;
							break;
						}
					if (flag)
						break;
				}
			}
		}
	}
	return 0;
}

