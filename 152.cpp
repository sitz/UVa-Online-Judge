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

#define sq(X) ((X)*(X))
#define FOI(i, A, B) for (i = A; i <= B; i++)
#define FOD(i, A, B) for (i = A; i >= B; i--)

struct Tree {
	int X, Y, Z;
	Tree() { }
	Tree(int _X, int _Y, int _Z) { X = _X; Y = _Y; Z = _Z; }
};

bool comp(Tree A, Tree B) {
	if (A.X != B.X) return A.X < B.X;
	if (A.Y != B.Y) return A.Y < B.Y;
	return A.Z < B.Z;
}

int main(){
	freopen("testI.txt", "r", stdin);
	freopen("testO.txt", "w", stdout);
	vector< Tree > tree;
	int A, B, C;
	int i, j;
	while (true) {
		cin >> A >> B >> C;
		if (A == 0 && B == 0 && C == 0)
			break;
		tree.push_back(Tree(A, B, C));
	}
	sort(tree.begin(), tree.end(), comp);
	int N = tree.size() - 1;
	int arr[10];
	memset(arr, 0, sizeof arr);
	
	FOI(i, 0, N) {
		int S = max(0, tree[i].X - 10);
		int E = min(N, tree[i].X + 10);
		FOI(j, 0, N) {
			if (i == j) continue;
			int Ind = (int) floor( sqrt( sq(tree[i].X - tree[j].X) + sq(tree[i].Y - tree[j].Y) + sq(tree[i].Z - tree[j].Z) ) );
			++arr[Ind];
		}
	}
	FOI(i, 0, 9)
		printf("%4d", arr[i]);
	return 0;
}
