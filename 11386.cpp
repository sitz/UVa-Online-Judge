#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
	int64 N;
	while (scanf("%lld", &N) != EOF)
	{
		int64 I = 0, T = 0;
		map<int64, int64> Map;
		map<int64, int64>::iterator ii, jj;
		for (int64 i = 0; i < N; i = i + 1)
		{
			scanf("%lld", &I);
			++Map[I];
		}
		for (ii = Map.begin(); ii != Map.end(); ii++)
		{
			for (jj = ii; jj != Map.end(); jj++)
			{
				int64 A1 = (*ii).first;
				int64 A2 = (*ii).second;
				int64 B1 = (*jj).first;
				int64 B2 = (*jj).second;
				int64 temp = 0;
				if (A1 == B1)
				{
					temp += (A2 * (A2 - 1)) / 2;
				}
				else
				{
					temp += (A2 * B2);
				}
				if (Map.find(A1 + B1) != Map.end())
				{
					T += (temp * Map[A1 + B1]);
				}
			}
		}
		printf("%lld\n", T);
	}
}
