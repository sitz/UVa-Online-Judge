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

	map<string, string> Dic;
	map<string, string>::iterator it;
	
	string A, B;
	while (true){
		cin >> A;
		if (A == "XXXXXX")
			break;
		B = A;
		sort(B.begin(), B.end());
		Dic[A] = B;
	}
	while (true){
		cin >> A;
		if (A == "XXXXXX")
			break;
		B = A;
		sort(B.begin(), B.end());
		bool stat = true;
		for (it = Dic.begin(); it != Dic.end(); it++){
			if ((*it).second == B){
				cout << (*it).first << endl;
				stat = false;
			}
		}
		if (stat)
			cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}
	return 0;
}

