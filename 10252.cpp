#include <bits/stdc++.h>

using namespace std;

char line1[1010], line2[1010];

int main()
{
	while (cin.getline(line1, 1010))
	{
		cin.getline(line2, 1010);
		int i;
		int cnt1[26], cnt2[26];
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		for (i = 0; line1[i]; i++)
		{
			line1[i] = tolower(line1[i]);
			if (isalpha(line1[i]))
			{
				cnt1[line1[i] - 'a']++;
			}
		}
		for (i = 0; line2[i]; i++)
		{
			line2[i] = tolower(line2[i]);
			if (isalpha(line2[i]))
			{
				cnt2[line2[i] - 'a']++;
			}
		}
		for (i = 0; i < 26; i++)
		{
			if (cnt1[i] && cnt2[i])
			{
				int j;
				int min;
				min = cnt1[i] < cnt2[i] ? cnt1[i] : cnt2[i];
				for (j = 0; j < min; j++)
				{
					cout << (char)(i + 'a');
				}
			}
		}
		cout << endl;
	}
	return 0;
}
