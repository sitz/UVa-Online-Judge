#include <bits/stdc++.h>

using namespace std;

#define END "ENDPROGRAM"
#define S "S"
#define IF "IF"
#define ELSE "ELSE"
#define ENDIF "END_IF"
unsigned int parse(string end)
{
	unsigned int ret = 1, temp = 0;
	string t;
	while (cin >> t)
	{
		//cout << t <<" " << end<<  endl;
		if (t == S)
		{
			continue;
		}
		if (t == end)
		{
			break;
		};
		if (t == IF)
		{
			temp = parse(ELSE);
			temp += parse(ENDIF);
			ret *= temp;
		}
	}
	return ret;
}
int main()
{
	int te;
	cin >> te;
	while (te--)
	{
		cout << parse(END) << endl;
		;
	}
	return 0;
}
