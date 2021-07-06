#include <bits/stdc++.h>

using namespace std;

int kase = 1;

int main()
{
	long long N;
	while (cin >> N && N)
	{
		cout << "Case " << kase++ << ": " << (long long)ceil((3.0 + sqrt(9.0 + 8.0 * N)) / 2.0) << endl;
	}
	return 0;
}
