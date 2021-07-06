#include <bits/stdc++.h>

using namespace std;

const int maxfile = 256;

int dataset = 0;

void front(int n)
{
	for (; n > 0; n--)
	{
		cout << "|     ";
	}
}

bool first = true;

bool mapping(int n, const char *dirname)
{
	char list[maxfile][80];
	int sort[maxfile];
	int files = 0;
	cin >> list[files];
	if (strchr(list[files], '#'))
	{
		return false;
	}
	if (n == 0)
	{
		if (!first)
		{
			cout << endl;
		}
		cout << "DATA SET " << ++dataset << ':' << endl;
	}
	first = false;
	front(n);
	cout << dirname << endl;
	while (true)
	{
		if (list[files][0] == '*' || list[files][0] == ']')
		{
			int i, j, t;
			for (i = 0; i < files; i++)
			{
				sort[i] = i;
			}
			for (i = 0; i < files - 1; i++)
				for (j = i + 1; j < files; j++)
					if (strcmp(list[sort[i]], list[sort[j]]) > 0)
					{
						t = sort[i];
						sort[i] = sort[j];
						sort[j] = t;
					}
			for (i = 0; i < files; i++)
			{
				front(n);
				cout << list[sort[i]] << endl;
			}
			//      if( n == 0 ) cout << endl;
			return true;
		}
		if (list[files][0] == 'd')
		{
			mapping(n + 1, list[files]);
		}
		else
		{
			files++;
		}
		cin >> list[files];
	}
}

int main()
{
	while (mapping(0, "ROOT"))
		;
	return 0;
}
