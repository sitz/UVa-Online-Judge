#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	stack<char> s;
	char c;
	double a, b, sum;
	while (cin >> a)
	{
		sum = 0;
		for (;;)
		{
			c = getchar();
			if (c == '\n')
			{
				if (s.empty())
				{
					sum += a;
				}
				else
				{
					char t = s.top();
					s.pop();
					if (t == '+')
					{
						sum += a;
					}
					else
					{
						sum -= a;
					}
				}
				break;
			}
			cin >> b;
			if ((c == '+') || (c == '-'))
			{
				if (s.empty())
				{
					s.push(c);
					sum += a;
					a = b;
				}
				else
				{
					char t = s.top();
					s.pop();
					s.push(c);
					if (t == '+')
					{
						sum += a;
					}
					else
					{
						sum -= a;
					}
					a = b;
				}
			}
			else if (c == '*')
			{
				a *= b;
			}
			else if (c == '/')
			{
				a /= b;
			}
		}
		cout << setprecision(3) << setiosflags(ios::fixed) << sum << endl;
	}
	return 0;
}
