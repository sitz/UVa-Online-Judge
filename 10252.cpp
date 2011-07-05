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

string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	string A, B;
	while (getline(cin, A) && getline(cin, B)) {
		int arr[26], brr[26] ;
		memset(arr, 0, sizeof arr);
		memset(brr, 0, sizeof brr);
		int aL = A.length() - 1;
		int bL = B.length() - 1;
		int i, j;
		FOI(i, 0, aL) ++arr[A[i] - 'a'];
		FOI(i, 0, bL) ++brr[B[i] - 'a'];
		FOI(i, 0, 25){
			int M = min(arr[i], brr[i]) - 1;
			FOI(j, 0, M) cout << alpha[i];
		}
		cout << endl;
	}
	return 0;
}

