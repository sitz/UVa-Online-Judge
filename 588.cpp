#include <bits/stdc++.h>

using namespace std;

// @judge_id: 13345pf 588 c++

int top, down, le, ri;
int cases = 0;

struct posi
{
	int x;
	int y;
};

void work(posi s, posi e)
{
	if (s.x == e.x)
		if (s.y < e.y)
		{
			if (s.x > le)
			{
				le = s.x;
			}
		}
		else
		{
			if (s.x < ri)
			{
				ri = s.x;
			}
		}
	else if (s.x < e.x)
	{
		if (s.y < top)
		{
			top = s.y;
		}
	}
	else
	{
		if (s.y > down)
		{
			down = s.y;
		}
	}
}

bool input()
{
	int n;
	cin >> n;
	if (n == 0)
	{
		return false;
	}
	top = ri = 32767;
	down = le = -32768;
	posi s, e, start;
	cin >> e.x >> e.y;
	start = e;
	while (--n)
	{
		s = e;
		cin >> e.x >> e.y;
		work(s, e);
	}
	work(e, start);
	cout << "Floor #" << ++cases << endl;
	cout << "Surveillance is ";
	if (top < down || ri < le)
	{
		cout << "impossible.";
	}
	else
	{
		cout << "possible.";
	}
	cout << endl
			 << endl;
	return true;
}

int main()
{
	while (input())
		;
	return 0;
}
