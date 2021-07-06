#include <bits/stdc++.h>

using namespace std;

string J, nJ, O, nO;
int N;

void AddJ(string ss)
{
	int i;
	ss += "\n";
	J += ss;
	for (i = 0; i < ss.length(); i++)
	{
		if (isdigit(ss[i]))
		{
			nJ += ss[i];
		}
	}
}

void AddO(string ss)
{
	int i;
	ss += "\n";
	O += ss;
	for (i = 0; i < ss.length(); i++)
	{
		if (isdigit(ss[i]))
		{
			nO += ss[i];
		}
	}
}

void Cal()
{
	if (J.compare(O) == 0)
	{
		cout << "Accepted" << endl;
		return;
	}
	if (nJ.compare(nO) == 0)
	{
		cout << "Presentation Error" << endl;
		return;
	}
	cout << "Wrong Answer" << endl;
}

int main()
{
	char ss[200];
	int r = 1;
	while (1)
	{
		gets(ss);
		N = atoi(ss);
		if (!N)
		{
			break;
		}
		J = O = "";
		nJ = nO = "";
		while (N--)
		{
			gets(ss);
			AddJ(ss);
		}
		gets(ss);
		N = atoi(ss);
		while (N--)
		{
			gets(ss);
			AddO(ss);
		}
		cout << "Run #" << r++ << ": ";
		Cal();
	}
	return 0;
}
