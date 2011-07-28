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
	int t = 1;
	int i, j;
	vector< string > Vec;
	string str;
	bool stat = true;
	while (cin >> str) {
		if (str == "9") {
			int N = Vec.size() - 1;
			FOI(i, 0, N) {
				FOI(j, 0, N) {
					if (i == j) continue;
					if (int(Vec[j].find(Vec[i])) == 0) {
						stat = false;
						break;
					}
				}
				if (!stat) break;
			}
			if (stat)
				cout << "Set " << t++ << " is immediately decodable" << endl;
			else
				cout << "Set " << t++ << " is not immediately decodable" << endl;
			Vec.clear();
			stat = true;
		}
		else
			Vec.push_back(str);
	}
	return 0;
}
