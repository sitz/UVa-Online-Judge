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

#define FOI(i, A, B) for (i = A; i <= B; i++)
#define FOD(i, A, B) for (i = A; i >= B; i--)
#define PI     acos(-1.0)
#define INF    1<<30
#define EPS    1e-9
#define sqr(x) (x)*(x)
#define MAX		225

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	map<int, pair<int, int> > Map;
	map<int, pair<int, int> >::iterator it;
	
	int i, j;
	FOI(i, 0, MAX)
 		FOI(j, 0, MAX)
 			   Map[i * i + j * j] = make_pair(i, j);
 			   
    int T;
    cin >> T;
    while (T--) {
		  int N;
		  bool stat = false;
		  cin >> N;
		  int M = (int) sqrt(N);
		  FOI(i, 0, M) {
		  		 int V = N - i * i;
		  		 it = Map.find(V);
		  		 if (it != Map.end()) {
				 		int arr[] = {((*it).second).first, ((*it).second).second, i};
				 		sort(arr, arr + 3);
				 		cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
				 		stat = true;
				 		break;
				 }
 		  }
 		  if (!stat)
 		  	 cout << "-1\n";
	}
    //system("pause");
    return 0;
}
