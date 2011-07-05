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
		int G;
		cin >> G;
		if (G == 0)
			break;
		string str, ret = "";
		cin >> str;
		int L = str.length();
		int N = L / G;
		int i, j;
		for (i = 0; i < L; i += N){
			string temp = "";
			FOI(j, i, i + N - 1)
				temp = str[j] + temp;
			ret += temp;
		}
		cout << ret << endl;
	}
	return 0;
}

