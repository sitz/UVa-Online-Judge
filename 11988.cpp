#include <bits/stdc++.h>

using namespace std;

#define db(a) cout << #a << " = " << a << endl

deque<string> deq;
void insert(bool pos, string &s)
{
	if (pos)
	{
		deq.push_back(s);
	}
	else
	{
		deq.push_front(s);
	}
	s = "";
}
int main()
{
	string aux;
	bool end = true;
	char c;
	while (c = getchar())
	{
		if (c == EOF)
		{
			break;
		}
		if (c == '\n')
		{
			insert(end, aux);
			while (deq.size())
			{
				printf("%s", deq.front().c_str());
				deq.pop_front();
			}
			printf("\n");
			deq.clear();
			aux = "";
			end = true;
		}
		else if (c == '[')
		{
			if (aux != "")
			{
				insert(end, aux);
			}
			end = false;
		}
		else if (c == ']')
		{
			if (aux != "")
			{
				insert(end, aux);
			}
			end = true;
		}
		else
		{
			aux += c;
		}
	}
	return 0;
}
