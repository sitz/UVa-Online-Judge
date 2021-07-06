#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 29)
#define SET(a) memset(a, -1, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define CLR(a) memset(a, 0, sizeof(a))
#define FILL(a, v) memset(a, v, sizeof(a))
#define PB push_back
#define FOR(i, n) for (int i = 0; i < n; i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a, b) make_pair(a, b)
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define LL long long
#define MX 100010
#define MOD 1000000007

int failur[MX], length;
char pattern[MX];

void FailureFunction(int i, int j)
{
	while (i < length)
	{
		if (pattern[i] == pattern[j])
		{
			j++;
			failur[i] = j;
			i++;
		}
		else if (j > 0)
		{
			j = failur[j - 1];
		}
		else
		{
			failur[i] = 0;
			i++;
		}
	}
}

int main()
{
	int t, kk = 1, n, arr[MX];
	bool found, chk;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		if (arr[0] != 0)
		{
			cout << "Case " << kk++ << ": -1" << endl;
			continue;
		}
		chk = true;
		failur[0] = 0;
		length = 1;
		pattern[0] = 'a';
		for (int i = 1; i < n; i++)
		{
			length = i + 1;
			found = false;
			for (int j = 0; j < 16; j++)
			{
				pattern[i] = j + 'a';
				FailureFunction(i, failur[i - 1]);
				if (failur[i] == arr[i])
				{
					found = true;
					break;
				}
			}
			if (!found)
			{
				chk = false;
				break;
			}
		}
		if (!chk)
			cout << "Case " << kk++ << ": -1" << endl;
		else
		{
			cout << "Case " << kk++ << ": ";
			for (int i = 0; i < n; i++)
				cout << pattern[i];
			cout << endl;
		}
	}
	return 0;
}
