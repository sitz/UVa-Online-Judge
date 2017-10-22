#include <bits/stdc++.h>

using namespace std;

/**
 * Verify every even cycle length must have even multiplicity
 */

int main()
{
	char str[42];
	int t, l, i, j, f[42], b;
	for (scanf("%d", &t); scanf("%s", str), t--; printf("%s\n", b ? "No" : "Yes"))
		for (memset(f, i = 0, sizeof(f)); i <= 26; ++i, ++f[l])
			if (i < 26)
				for (l = 0, j = i; !l || j != i; ++l, j = str[j] - 'A')
					;
			else
				for (l = b = 0; (l += 2) <= 26;)
				{
					b |= f[l] / l & 1;
				}
	return 0;
}
