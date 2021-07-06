#include <bits/stdc++.h>

using namespace std;

int L[128] = {0}, S[5];
char name[30];
int main()
{
	int i, len;
	L['B'] = L['P'] = L['F'] = L['V'] = 1;
	L['C'] = L['S'] = L['K'] = L['G'] = L['J'] = L['Q'] = L['X'] = L['Z'] = 2;
	L['D'] = L['T'] = 3;
	L['L'] = 4;
	L['M'] = L['N'] = 5;
	L['R'] = 6;
	printf("         NAME                     SOUNDEX CODE\n");
	while (gets(name))
	{
		for (i = 1, len = 0; name[i] && len < 3; i++)
		{
			if (L[name[i]] && L[name[i]] != L[name[i - 1]])
			{
				S[len++] = L[name[i]];
			}
		}
		while (name[i])
		{
			i++;
		}
		while (i < 25)
		{
			name[i++] = ' ';
		}
		name[i] = '\0';
		while (len < 3)
		{
			S[len++] = 0;
		}
		printf("         %s%c%d%d%d\n", name, name[0], S[0], S[1], S[2]);
	}
	printf("                   END OF OUTPUT\n");
	return 0;
}
