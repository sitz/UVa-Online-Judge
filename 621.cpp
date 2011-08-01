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

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int N;
	cin >> N;
	while (N--) {
		  string S;
		  cin >> S;
		  if (S == "1" || S == "4" || S == "78") {
		  	 cout << "+\n";
		 	  continue;
  	 	  }
  	 	  int L = S.length() - 1;
  	 	  if (S[L - 1] == '3' && S[L] == '5') {
		  	 cout << "-\n";
 	  		 continue;
  	 	  }
  	 	  if (S[0] == '9' && S[L] == '4') {
		  	 cout << "*\n";
		  	 continue;
	   	  }
	   	  if (S[0] == '1' && S[1] == '9' && S[2] == '0') 
	   	  	 cout << "?\n";
 	}
	//system("pause");
    return 0;
}
