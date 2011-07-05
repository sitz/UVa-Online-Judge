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
	int N, t = 1;
	while( cin >> N ){
		int vec[N];
		int i, j, k;
		FOI(i, 0, N-1)
			cin >> vec[i];
		vector<int> V;
		V.push_back(vec[0]);
		FOI(i, 1, N-1){
			int SZ = V.size() - 1;
			FOI(j, 0, SZ)
				V.push_back(V[j] + vec[i]);
		}
		V.erase(V.begin());
		sort(V.begin(), V.end());
		bool isA = true;
		FOI(k, 0, N-1){
			if( binary_search(V.begin(), V.end(), vec[k]) ){
				isA = false;
				break;
			}
		}
		cout << "Case #" << t++ << ":";
		FOI(i, 0, N-1)
			cout << " " << vec[i];
		cout << endl;
		if( isA )
			cout << "This is an A-sequence.\n";
		else
			cout << "This is not an A-sequence.\n";
	}
	return 0;
}
