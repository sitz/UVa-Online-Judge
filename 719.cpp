#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)

// find lexicographically min cyclic str in O(len)
inline int min_expr(string s)
{
	s += s;
	int len = (int)s.length(), i = 0, j = 1, k = 0;
	while (i + k < len && j + k < len)
	{
		if (s[i + k] == s[j + k])
		{
			k++;
		}
		else if (s[i + k] > s[j + k])
		{
			i += k + 1;
			if (i <= j)
			{
				i = j + 1;
			}
			k = 0;
		}
		else if (s[i + k] < s[j + k])
		{
			j += k + 1;
			if (j <= i)
			{
				j = i + 1;
			}
			k = 0;
		}
	}
	return min(i, j);
}

int N;
char A[10005];

int main()
{
	scanf("%d", &N);
	FOR(n, 0, N)
	{
		scanf("%s", A);
		string s(A);
		int pos = min_expr(s);
		printf("%d\n", pos + 1);// 1-based idx
	}
	return 0;
}
