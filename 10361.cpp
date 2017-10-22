#include <bits/stdc++.h>

using namespace std;

char line1[150], line2[150];
char s1[100], s2[100], s3[100], s4[100], s5[100];
int T;

void solveLine1()
{
	int i, j;
	for (i = 0, j = 0; line1[i] != '<'; i++)
	{
		s1[j++] = line1[i];
	}
	s1[j] = '\0';
	for (i++, j = 0; line1[i] != '>'; i++)
	{
		s2[j++] = line1[i];
	}
	s2[j] = '\0';
	for (i++, j = 0; line1[i] != '<'; i++)
	{
		s3[j++] = line1[i];
	}
	s3[j] = '\0';
	for (i++, j = 0; line1[i] != '>'; i++)
	{
		s4[j++] = line1[i];
	}
	s4[j] = '\0';
	for (i++, j = 0; line1[i]; i++)
	{
		s5[j++] = line1[i];
	}
	s5[j] = '\0';
	cout << s1 << s2 << s3 << s4 << s5 << endl;
}

void solveLine2()
{
	int i;
	for (i = 0; line2[i] != '.'; i++)
	{
		cout << line2[i];
	}
	cout << s4 << s3 << s2 << s5 << endl;
}

int main()
{
	cin >> T;
	cin.get();
	int t;
	for (t = 0; t < T; t++)
	{
		cin.getline(line1, 150);
		solveLine1();
		cin.getline(line2, 150);
		solveLine2();
	}
	return 0;
}
