#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/115/11536.html
// Runtime : 0.896s
// Tag : dp

// @BEGIN_OF_SOURCE_CODE

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long

int seq[N + 10];
int nextPos[N + 10];

int main()
{
	int testCase;
	scanf("%d", &testCase);
	int cases = 0;
	while (testCase--)
	{
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		seq[0] = 1;
		seq[1] = 2;
		seq[2] = 3;
		for (int i = 3; i < n; i++)
		{
			seq[i] = (seq[i - 1] + seq[i - 2] + seq[i - 3]) % m + 1;
		}
		int pos[1000 + 5];
		memset(pos, -1, sizeof(pos));
		for (int i = n - 1; i >= 0; i--)
		{
			nextPos[i] = pos[seq[i]];
			pos[seq[i]] = i;
		}
		bool freq[1000 + 5];
		memset(freq, false, sizeof(freq));
		int cnt = 0;
		int left = 0;
		int right = -1;
		for (int i = 0; i < n; i++)
		{
			if (seq[i] <= k && !freq[seq[i]])
			{
				freq[seq[i]] = true;
				cnt++;
			}
			if (cnt == k)
			{
				right = i;
				break;
			}
		}
		if (right == -1)
		{
			printf("Case %d: sequence nai\n", ++cases);
			continue;
		}
		int minWindow = right - left + 1;
		while (left < right)
		{
			if (seq[left] > k)
			{
				left++;
			}
			else if (nextPos[left] == -1)
			{
				break;
			}
			else if (nextPos[left] <= right)
			{
				left++;
			}
			else
			{
				right = nextPos[left];
				left++;
			}
			if (minWindow > right - left + 1)
			{
				minWindow = right - left + 1;
			}
		}
		printf("Case %d: %d\n", ++cases, minWindow);
	}
	return 0;
}

// @END_OF_SOURCE_CODE
