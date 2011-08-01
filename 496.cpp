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
#include <sstream>
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

vector< int > extract(string S) {
		stringstream ss;
		vector< int > V;
		int I;
		ss << S;
		while (ss >> I) V.push_back(I);
		return V;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	string str;
	while (getline(cin, str)) {
		  vector< int > A = extract(str);
		  getline(cin, str);
		  vector< int > B = extract(str);
		  
		  int N = A.size() + B.size();
		  
		  vector< int > amb(N), bma(N), aob(N), aib(N);
		  vector< int >::iterator it1, it2, it3, it4;
		  
		  sort(A.begin(), A.end());
		  sort(B.begin(), B.end());
		  
		  it1 = set_difference(A.begin(), A.end(), B.begin(), B.end(), amb.begin());
		  it2 = set_difference(B.begin(), B.end(), A.begin(), A.end(), bma.begin());
		  it3 = set_intersection(A.begin(), A.end(), B.begin(), B.end(), aib.begin());
		  it4 = set_union(A.begin(), A.end(), B.begin(), B.end(), aob.begin());
		  
 		if (int(it3 - aib.begin()) == A.size() && int(it3 - aib.begin()) == B.size())
		  	 cout << "A equals B" << endl;
		 else if (int(it1 - amb.begin()) == 0)
		 	  cout << "A is a proper subset of B" << endl;
		 else if (int(it2 - bma.begin()) == 0)
		 	  cout << "B is a proper subset of A" << endl;
  		 else if (int(it4 - aob.begin()) == N)
  		 	  cout << "A and B are disjoint" << endl;
	 	 else
	 	 	 cout << "I'm confused!" << endl;
 	}
	//system("pause");
    return 0;
}
