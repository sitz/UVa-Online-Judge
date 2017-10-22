#include <bits/stdc++.h>

using namespace std;

#define WHITE 0
#define BLACK 1

int color(int x, int y)
{
	return (int)(abs(x) + abs(y)) % 2 == 0 ? WHITE : BLACK;
}
int minimumStep(int x, int y)
{
	int step;
	x = abs(x);
	y = abs(y);
	if (x == 0 && y == 0)
	{
		return 0;
	}
	if (x == 1 && y == 0 || x == 0 && y == 1)
	{
		return 3;
	}
	if (x == 2 && y == 2)
	{
		return 4;
	}
	if (2 * x < y || 2 * y < x)
	{
		step = max(x, y) / 2;
		if (max(x, y) % 2 != 0)
		{
			++step;
		}
	}
	else
	{
		step = (x + y) / 3;
		if ((x + y) % 3 != 0)
		{
			++step;
		}
	}
	if (color(x, y) == color(0, 0))
	{
		if (step % 2 != 0)
		{
			++step;
		}
	}
	else if (color(x, y) != color(0, 0))
	{
		if (step % 2 == 0)
		{
			++step;
		}
	}
	return step;
}
int main()
{
	while (true)
	{
		int x, y;
		string s;
		getline(cin, s);
		if (s == "END")
		{
			break;
		}
		istringstream iss(s);
		iss >> x >> y;
		int ans = minimumStep(x, y);
		cout << ans << endl;
	}
	return 0;
}
