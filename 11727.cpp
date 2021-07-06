#include <bits/stdc++.h>

using namespace std;

bool func(int a, int b)
{
	return (a < b);
}

int main()
{
	int testcase;
	cin >> testcase;
	for (int p = 0; p < testcase; p++)
	{
		vector<int> V;
		int a, b, c;
		V.clear();
		cin >> a >> b >> c;
		V.push_back(a);
		V.push_back(b);
		V.push_back(c);
		sort(V.begin(), V.end(), func);
		cout << "Case " << p + 1 << ": " << V[1] << endl;
	}
	return 0;
}
