#include <bits/stdc++.h>

using namespace std;

int p[2000000];

int main()
{
	string line;
	while (getline(cin, line))
	{
		int numPeople = atoi(line.c_str());
		if (numPeople == 0)
		{
			break;
		}
		getline(cin, line);
		istringstream sin(line);
		int i = 0;
		while (sin >> p[i++])
			;
		sort(p, p + numPeople);
		for (int i = 0; i < numPeople - 1; ++i)
		{
			printf("%d ", p[i]);
		}
		printf("%d\n", p[numPeople - 1]);
	}
	return 0;
}
