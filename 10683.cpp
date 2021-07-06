#include <bits/stdc++.h>

using namespace std;

/*
10683
The decadary watch
*/
char ss[100];
typedef long long xx;
void Cal()
{
	xx a, b, c, d, e, f;
	a = (ss[0] - '0') * 10 + (ss[1] - '0');
	b = (ss[2] - '0') * 10 + (ss[3] - '0');
	c = (ss[4] - '0') * 10 + (ss[5] - '0');
	d = (ss[6] - '0') * 10 + (ss[7] - '0');
	e = ((a * 3600) + (b * 60) + c) * 100 + d;
	f = (e * 125);
	f = f / 108;
	printf("%07lld\n", f);
}
int main()
{
	while (gets(ss))
	{
		if (!strcmp(ss, "0000000"))
		{
			printf("%s\n", ss);
			continue;
		}
		Cal();
	}
	return 0;
}
