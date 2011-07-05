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
		int N, i;
		cin >> N;
		if (N == 0)
			break;
		vector< int > arr;
		FOI(i, 1, N){
			int I;
			cin >> I;
			if (I > 0)
				arr.push_back(I);
		}
		int S = arr.size();
		FOI(i, 0, S-1){
			cout << arr[i];
			if (i < S-1)
				cout << " ";
		}
		if (S == 0)
			cout << "0";
		cout << endl;
	}
	return 0;
}

