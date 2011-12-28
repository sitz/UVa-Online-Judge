#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Contestant {
	bool solved[10];
	int attempt[10];
	int penalty, count;
};

map<int, Contestant> Contest;
vector< int > Index;

bool comp(int A, int B) {
	if (Contest[A].count != Contest[B].count)
		return (Contest[A].count > Contest[B].count);
	if (Contest[A].penalty != Contest[B].penalty)
		return (Contest[A].penalty < Contest[B].penalty);
	return (A < B);
}

int main() {
	int T;
	stringstream ss;
	string str;
	getline(cin, str);
	//cout << str << endl;
	ss.clear();
	ss << str;
	ss >> T;
	//cout << T << endl;
	getline(cin, str);
	//cout << str << endl;
	while (T--) {
		//cout << "T--\n";
		Contest.clear();
		Index.clear();
		while (getline(cin, str)) {
			//cout << str << endl;
			if (str.empty()) break;
			int A, B, C;
			string D;
			ss.clear();
			ss << str;
			ss >> A >> B >> C >> D;
			//cout << A << " " << B << " " << C << " " << D << endl;
			
			if (Contest.find(A) == Contest.end()) {
				Contestant Con;
				memset(Con.solved, false, sizeof Con.solved);
				memset(Con.attempt, 0, sizeof Con.attempt);
				Con.penalty = 0;
				Con.count = 0;
				
				Index.push_back(A);
				Contest[A] = Con;
			}
			if (D == "C" || D == "I") {
				if (Contest[A].solved[B]) continue;
				
				if (D == "C") {
					Contest[A].solved[B] = true;
					Contest[A].penalty += (20 * Contest[A].attempt[B] + C);
					Contest[A].count += 1;
				}
				else {
					Contest[A].attempt[B] += 1;
				}
			}
		}
		sort(Index.begin(), Index.end(), comp);
		for (int i = 0; i < Index.size(); i++) {
			cout << Index[i] << " " << Contest[Index[i]].count << " " << Contest[Index[i]].penalty << endl;
		}
		if (T) cout << endl;
	}
	return 0;
}
