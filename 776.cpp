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
#include <ctime>
#include <sstream>
using namespace std;

#define FOI(i, A, B) for (i = A; i <= B; i++)
#define FOD(i, A, B) for (i = A; i >= B; i--)

vector< vector< string > > Vec;
int Mat[101][101];
int M = 0, N = 0;

int count(int Val) {
	int C = 0;
	while (Val > 0) {
		C++;
		Val /= 10;
	}
	return C;
}

int dI[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dJ[] = {-1, 0, 1, 1, 1, 0, -1, -1};
void bfs(int I, int J, int Max, string C) {
	if (I < 0 || I >= M) return;
	if (J < 0 || J >= N) return;
	if (Mat[I][J] != -1) return;
	if (Vec[I][J] != C)  return;
	
	Mat[I][J] = Max;
	int i, j;
	FOI(i, 0, 7)
		bfs(I + dI[i], J + dJ[i], Max, C);
}

void print() {
	int i, j;
	int Max = 1;
	
	memset(Mat, -1, sizeof Mat);
	
	FOI(i, 0, M-1) {
		FOI(j, 0, N-1) {
			if (Mat[i][j] == -1) {
				bfs(i, j, Max, Vec[i][j]);
				++Max;
			}
		}
	}
	
	int Dig[N];
	memset(Dig, 0, sizeof Dig);
	
	FOI(j, 0, N-1) {
		int D = 0;
		FOI(i, 0, M-1)
			D = max(D, count(Mat[i][j]));
		Dig[j] = D;
	}
	
	FOI(i, 0, M-1) {
		FOI(j, 0, N-1) {
			if (j > 0)
				printf(" ");
			cout << setw(Dig[j]) << Mat[i][j];
		}
		cout << endl;
	}
	cout << "%" << endl;
}

int main() {
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	string str;
	
	while (getline(cin, str)) {
		if (str == "%") {
			if (Vec.size() > 0) {
				M = Vec.size();
				N = Vec[0].size();
				print();
			}
			Vec.clear();
			continue;
		}
		string S;
		vector< string > V;
		stringstream ss(str);
		while (ss >> S) {
			V.push_back(S);
		}
		Vec.push_back(V);
	}
	if (Vec.size() > 0) {
		M = Vec.size();
		N = Vec[0].size();
		print();
	}
	return 0;
}
