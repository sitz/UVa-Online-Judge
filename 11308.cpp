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

map<string, int> Ing;
map<string, int>::iterator iit;
map<string, int> Cost;
map<string, int>::iterator cit;
vector< string > Ans;
		
bool comp(string A, string B){
	if (Cost[A] != Cost[B])
		return Cost[A] < Cost[B];
	return A < B;
}

string Upper(string S){
	int L = S.length() - 1, i;
	string R = "";
	FOI(i, 0, L) R += toupper(S[i]);
	return R;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T;
	string S;
	cin >> T;
	getline(cin, S);
	while (T--){
		Ing.clear(); Cost.clear(); Ans.clear();
		int i, j, k;
		string binder;
		getline(cin, binder);
		cout << Upper(binder) << endl;
		int M, N, B;
		cin >> M >> N >> B;
		getline(cin, S);
		int I, K;
		while (M--){
			cin >> S >> I;
			Ing[S] = I;
			getline(cin, S);
		}
		string R;
		while (N--){
			getline(cin, R);
			Cost[R] = 0;
			cin >> K;
			getline(cin, S);
			while (K--){
				cin >> S >> I;
				Cost[R] += (I * Ing[S]);
				getline(cin, S);
			}
			if (Cost[R] < B)
				Ans.push_back(R);
		}
		sort(Ans.begin(), Ans.end(), comp);
		int SZ = Ans.size();
		if (SZ == 0)
			cout << "Too expensive!" << endl;
		else
			FOI(i, 0, SZ-1)
				cout << Ans[i] << endl;
		cout << endl;
	}
	return 0;
}

