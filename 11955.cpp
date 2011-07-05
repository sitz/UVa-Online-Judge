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

typedef long long int64;
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define MAX 1000000

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T, t;
	scanf("%d\n", &T);
	FOI(t, 1, T){
		string str, temp = "";
		string A, B, K;
		getline(cin, str);
		int i, j;
		FOI(i, 0, str.length()-1){
			if(str[i] == '(' || str[i] == ' ')
				continue;
			else if(str[i] == '+'){
				A = temp;
				temp = "";
			}
			else if(str[i] == ')'){
				B = temp;
				temp = "";
			}
			else if(str[i] == '^')
				continue;
			else
				temp += str[i];
		}
		K = temp;
		//cout << A << " " << B << " " << K << endl;
		/*
		A[0] = 'a'; A[1] = '\0';
		B[0] = 'b'; B[1] = '\0';
		K[0] = '2'; K[1] = '\0';
		*/
		int k = atoi(K.c_str());
		int64 cof[k+1];
		cof[0] = 1;
		FOI(i, 1, k)
			cof[i] = (cof[i-1] * (k - i + 1)) / i;
		printf("Case %d: ", t);
		FOI(i, 0, k){
			if( cof[i] > 1 )
				printf("%lld*", cof[i]);
			if(k - i > 0)
				printf("%s", A.c_str());
			if(k - i > 1)
				printf("^%d", k-i);
			if((cof[i] > 1 || k - i > 0) && i > 0)
				printf("*");
			if(i > 0)
				printf("%s", B.c_str());
			if(i > 1)
				printf("^%d", i);
			if(i < k)
				printf("+");
		}
		printf("\n");
	}
	return 0;
}
