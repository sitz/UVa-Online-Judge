#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);
char cmd[100];
int numOfSet, r1, r2, t;
bool oneInput;

bool check(char *buf)
{
	int i;
	for (i = 0; i < strlen(buf); i++)
		if (isspace(buf[i]) && isdigit(buf[i - 1]))
		{
			return true;
		}
	return false;
}

void input()
{
	cin.getline(cmd, 100);
	if (check(cmd))
	{
		oneInput = false;
		char *p;
		p = strtok(cmd, " ");
		if (p)
		{
			r1 = atoi(p);
		}
		p = strtok(NULL, " ");
		if (p)
		{
			r2 = atoi(p);
		}
	}
	else
	{
		oneInput = true;
		t = atoi(cmd);
	}
}

void solve()
{
	if (oneInput)
	{
		printf("%.4lf\n", PI * t * t / 8.0);
	}
	else
	{
		printf("%.4lf\n", PI * 2 * r1 * r2);
	}
}

int main()
{
	while (cin >> numOfSet)
	{
		cin.get();
		int case_i;
		for (case_i = 0; case_i < numOfSet; case_i++)
		{
			input();
			solve();
		}
	}
	return 0;
}
