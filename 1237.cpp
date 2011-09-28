#include <string>
#include <iostream>
using namespace std;

struct Car {
	string name;
	int L, H;
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		Car db[N];
		for (int i = 0; i < N; i++)
			cin >> db[i].name >> db[i].L >> db[i].H;
		int Q;
		cin >> Q;
		while (Q--) {
			int P, C = 0;
			string Ans = "";
			cin >> P;
			for (int i = 0; i < N; i++) {
				if (db[i].L <= P && db[i].H >= P) {
					++C;
					Ans = db[i].name;
				}
				if (C > 1) break;
			}
			if (C == 1) cout << Ans << endl;
			else cout << "UNDETERMINED\n";
		}
		if (T) cout << endl;
	}
	return 0;
}
