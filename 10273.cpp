#include <bits/stdc++.h>

using namespace std;

#define inf 1000000

vector<int> t[1000];
bool eaten[1000];
int n, result, lastTime, currentTime, elapsedTime;

int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return GCD(b, a % b);
}

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		t[i].clear();
		int ti;
		cin >> ti;
		for (int j = 0; j < ti; j++)
		{
			int x;
			cin >> x;
			t[i].push_back(x);
		}
	}
}

int LCM()
{
	int lcm = 1, gcd;
	for (int i = 0; i < n; i++)
		if (!eaten[i])
		{
			gcd = GCD(lcm, t[i].size());
			lcm = lcm / gcd * t[i].size();
		}
	return lcm;
}

void process()
{
	memset(eaten, false, sizeof(eaten));
	currentTime = 0;
	elapsedTime = LCM();
	lastTime = 0;
	result = 0;
	while (elapsedTime > 0)
	{
		int minV = inf, minP = -1, count = 0;
		for (int i = 0; i < n; i++)
			if (!eaten[i])
			{
				int k = t[i][currentTime % t[i].size()];
				if (minV >= k)
				{
					if (minV > k)
					{
						minV = k;
						minP = i;
						count = 1;
					}
					else
					{
						count++;
					}
				}
			}
		currentTime++;
		if (count == 1)
		{
			//cout << "Eat " << minP << endl;
			result++;
			lastTime = currentTime;
			eaten[minP] = true;
			elapsedTime = LCM();
			continue;
		}
		elapsedTime--;
	}
}

void output()
{
	cout << (n - result) << " " << lastTime << endl;
}

int main()
{
	int ntest;
	cin >> ntest;
	while (0 < ntest--)
	{
		input();
		process();
		output();
	}
	return 0;
}
