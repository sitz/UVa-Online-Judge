#include <bits/stdc++.h>

using namespace std;

int T;
string s, min_;

int main() {
	scanf("%d", &T);
	while (T--) {
		min_ = "Z";
		cin >> s;
		int sz = s.size();
		s += s;
		for (int i = 0; i < sz; ++i) {
			min_ = min(min_, s.substr(i, sz));
		}
		printf("%s\n", min_.c_str());
	}
	return 0;
}
