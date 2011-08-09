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

int N;
vector< int > P(25);
stack < int > tmp;
stack < int > S[25];

void moveOnto(int A, int B) {
	while (S[P[A]].top() != A) {
		int t = S[P[A]].top();
		S[t].push(t);
		P[t] = t;
		S[P[A]].pop();
	}
	while (S[P[B]].top() != B) {
		int t = S[P[B]].top();
		S[t].push(t);
		P[t] = t;
		S[P[B]].pop();
	}
	S[P[B]].pop();
	P[B] = B;
	S[B].push(B);
	S[B].push(S[P[A]].top());
	S[P[A]].pop();
	P[A] = B;
}

void moveOver(int A, int B) {
	while (S[P[A]].top() != A) {
		int t = S[P[A]].top();
		S[t].push(t);
		P[t] = t;
		S[P[A]].pop();
	}
	S[P[B]].push(S[P[A]].top());
	S[P[A]].pop();
	P[A] = P[B];
}

void pileOnto(int A, int B) {
	while (S[P[B]].top() != B) {
		int t = S[P[B]].top();
		S[t].push(t);
		P[t] = t;
		S[P[B]].pop();
	}
	S[P[B]].pop();
	P[B] = B;
	S[B].push(B);
	
	while (S[P[A]].top() != A) {
		tmp.push(S[P[A]].top());
		S[P[A]].pop();
	}
	tmp.push(S[P[A]].top());
	S[P[A]].pop();
	
	while (!tmp.empty()) {
		int t = tmp.top();
		S[P[B]].push(t);
		P[t] = P[B];
		tmp.pop();
	}
}

void pileOver(int A, int B) {
	while (S[P[A]].top() != A) {
		tmp.push(S[P[A]].top());
		S[P[A]].pop();
	}
	tmp.push(S[P[A]].top());
	S[P[A]].pop();
	
	while (!tmp.empty()) {
		int t = tmp.top();
		S[P[B]].push(t);
		P[t] = P[B];
		tmp.pop();
	}
}

void quit() {
	int i, j;
	FOI(i, 0, N-1) {
		cout << i << ":";
		while (!S[i].empty()) {
			tmp.push(S[i].top());
			S[i].pop();
		}
		while (!tmp.empty()) {
			cout << " " << tmp.top();
			tmp.pop();
		}
		cout << endl;
	}
}

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	cin >> N;
	int i, j;
	FOI(i, 0, N-1) {
		S[i].push(i);
		P[i] = i;
	}
	while (true) {
		string A, B;
		int I, J;
		cin >> A;
		if (A == "quit")
			break;
		cin >> I >> B >> J;
		if (I == J || P[I] == P[J])
			continue;
		if (A == "move" && B == "onto") {
			moveOnto(I, J);
			continue;
		}
		if (A == "move" && B == "over") {
			moveOver(I, J);
			continue;
		}
		if (A == "pile" && B == "onto") {
			pileOnto(I, J);
			continue;
		}
			pileOver(I, J);
	}
	quit();
	return 0;
}
