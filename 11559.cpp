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
#define INF	1<<30
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int N, B, H, W;
	while (cin >> N >> B >> H >> W){
		bool stat = false;
		int amt = INF;
		while (H--){
			int price, bed = 0, mbed = 0, w;
			cin >> price;
			FOI(w, 1, W){
				cin >> bed;
				mbed = max(mbed, bed);
			}
			if (mbed >= N){
				int V = N * price;
				if (V <= B){
					amt = min(amt, V);
					stat = true;
				}
			}
		}
		if (stat)
			cout << amt << endl;
		else
			cout << "stay home" << endl;
	}
	return 0;
}
