#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

typedef long long int64;

int main() {
	int64 T, t;
	scanf("%lld", &T);
	for (t = 1; t <= T; t++) {
		int64 N, Base = -2;
		string str = "";
		scanf("%lld", &N);
		while (N != 0) {
			int64 Rem = N % Base;
			N /= Base;
			if (Rem < 0) {
				N	+= 1;
				Rem += 2;
			}
			str = char('0' + Rem) + str;
		}
		if (str.empty()) str = "0";
		printf("Case #%lld: %s\n", t, str.c_str());
	}
	return 0;
}
