#include <bits/stdc++.h>

using namespace std;

int L[128] = {0}, S[120], B[120];
char in[120];
int main()
{
	int len, i, j, s, b, n;
	L['K'] = L['A'] = L['C'] = L['E'] = 1;
	L['N'] = 2;
	L['p'] = L['q'] = L['r'] = L['s'] = L['t'] = 3;
	while (gets(in))
	{
		if (in[0] == '0')
		{
			break;
		}
		s = b = n = 0;
		for (i = 0; in[i]; i++)
		{
			switch (L[in[i]])
			{
			case 1:
				B[b++] = in[i];
				break;
			case 2:
				n++;
				break;
			case 3:
				S[s++] = in[i];
			}
		}
		if (s == 0)
		{
			printf("no WFF possible\n");
			continue;
		}
		while (n--)
		{
			printf("N");
		}
		s--;
		len = ((s < b) ? s : b);
		for (i = 0; i < len; i++)
		{
			printf("%c%c", B[i], S[i]);
		}
		printf("%c\n", S[i]);
	}
	return 0;
}
