#include <bits/stdc++.h>

using namespace std;

int main()
{
	int P, E, I, d, case_num = 1;
	while (cin >> P >> E >> I >> d)
	{
		if (P == -1)
		{
			break;
		}
		cout << "Case " << case_num++;
		while ((P - E) % 28 != 0)
		{
			P += 23;
		}
		while ((P - I) % 33 != 0)
		{
			P += 23 * 28;
		}
		while (P > d)
		{
			P -= 23 * 28 * 33;
		}
		while (P <= d)
		{
			P += 23 * 28 * 33;
		}
		cout << ": the next triple peak occurs in ";
		cout << (P - d) << " days." << endl;
	}
	return 0;
}
