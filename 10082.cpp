#include <bits/stdc++.h>

using namespace std;

int main()
{
	string keys = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char c;
	while (cin.get(c))
	{
		if (c == '\n' || c == ' ')
		{
			printf("%c", c);
		}
		else
		{
			size_t found = keys.find(c);
			printf("%c", keys[found - 1]);
		}
	}
	return 0;
}
