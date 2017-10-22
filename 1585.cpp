#include <bits/stdc++.h>

using namespace std;

#define MAXN 131072

char s[MAXN];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		int ret = 0, O = 0;
		for (int i = 0; s[i]; i++)
		{
			O = s[i] == 'O' ? O + 1 : 0;
			ret += O;
		}
		printf("%d\n", ret);
	}
	return 0;
}
