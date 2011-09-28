#include <map>
#include <cmath>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
using namespace std;

const long long MAX = 32800;
bool prime[MAX + 1];
vector< long long > P;


void sieve() {
	memset(prime, true, sizeof prime);
	prime[0] = false;
	prime[1] = false;

	for (long long i = 2; i <= MAX; i++) {
		if (prime[i]) {
			P.push_back(i);
			for (long long j = i * i; j <= MAX; j += i) {
				prime[j] = false;
			}
		}
	}
}

int main() {
	sieve();
	while (true) {
		string str;
		getline(cin, str);
		stringstream ss;
		long long A, B, N = 1;
		ss << str;
		ss >> A;
		if (A == 0) break;
		ss >> B;
		do {
			N = N * pow(A, B);
		} while( ss >> A >> B);
		--N;
		
		map<long long, long long> Map;
		map<long long, long long>::iterator it;
		map<long long, long long>::reverse_iterator rit;
		for (long long i = 0; i < P.size(); i++) {
			if (N == 1) break;
			while (N % P[i] == 0) {
				++Map[P[i]];
				N /= P[i];
			}
		}
		if (N > 1) ++Map[N];
		
		for (rit = Map.rbegin(); rit != Map.rend(); rit++) {
			if (rit != Map.rbegin())
				cout << " ";
			cout << (*rit).first << " " << (*rit).second;
		}
		cout << endl;
	}
	return 0;
}
