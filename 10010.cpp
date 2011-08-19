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

string low(string S) {
	int i, L = S.length() - 1;
	FOI(i, 0, L)
		S[i] = tolower(S[i]);
	return S;
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--)  {
		int M, N;
		int i, j, k;
		cin >> M >> N;
		string str[M];
		FOI(i, 0, M-1) {
			cin >> str[i];
			str[i] = low(str[i]);
		}
		int Q;
		cin >> Q;
		while (Q--) {
			string S;
			cin >> S;
			S = low(S);
			int L = S.length();
			bool flag = false;
			FOI(i, 0, M-1) {
				FOI(j, 0, N-1) {
					string A = "", B = "", C = "", D = "", E = "", F = "", G = "", H = "";
					FOI(k, 0, L-1) {
						if (j + k < N)				 A += str[i][j + k];
						if (i + k < M && j + k < N)	 B += str[i + k][j + k];
						if (i + k < M)				 C += str[i + k][j];
						if (i + k < M && j - k >= 0) D += str[i + k][j - k];
						if (j - k >= 0)				 E += str[i][j - k];
						if (i - k >= 0 && j - k >=0) F += str[i - k][j - k];
						if (i - k >= 0)				 G += str[i - k][j];
						if (i - k >= 0 && j + k < N) H += str[i - k][j + k];
					}
					if (A == S || B == S || C == S || D == S || E == S || F == S || G == S || H == S) {
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
			cout << i + 1 << " " << j + 1 << endl;
		}
		if (T) cout << endl;
	}
	return 0;
}
