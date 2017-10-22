#include <bits/stdc++.h>

using namespace std;

int code[30];
int code2[30];

void gray2(int len, int n)
{
	memset(code, 0, sizeof(code));
	for (int i = 0; i < len; i++)
		if ((n & (1 << i)) != 0)
		{
			code[i] = 1;
		}
	code2[len - 1] = code[len - 1];
	for (int i = len - 2; i >= 0; i--)
	{
		code2[i] = code[i] ^ code[i + 1];
	}
}

int main()
{
	int n, t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < (1 << n); i++)
		{
			gray2(n, i);
			int re = 0;
			if (i % 2 == 0)
				for (int j = n - 1; j >= 0; j--)
				{
					code2[j] = 1 - code2[j];
				}
			//for(int j = n-1;j >= 0;j--) cout << code2[j];
			for (int j = n - 1; j >= 0; j--)
			{
				re = re * 2 + code2[j];
			}
			printf("%d\n", re);
		}
	}
	return 0;
}
