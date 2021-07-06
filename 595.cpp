#include <bits/stdc++.h>

using namespace std;

const char *data[][7] = {
		{"Ab", "Bb", "C", "Db", "Eb", "F", "G"},
		{"A", "B", "C#", "D", "E", "F#", "G#"},
		{"Bb", "C", "D", "Eb", "F", "G", "A"},
		{"B", "C#", "D#", "E", "F#", "G#", "A#"},
		{"Cb", "Db", "Eb", "Fb", "Gb", "Ab", "Bb"},
		{"C", "D", "E", "F", "G", "A", "B"},
		{"C#", "D#", "E#", "F#", "G#", "A#", "B#"},
		{"Db", "Eb", "F", "Gb", "Ab", "Bb", "C"},
		{"D", "E", "F#", "G", "A", "B", "C#"},
		{"Eb", "F", "G", "Ab", "Bb", "C", "D"},
		{"E", "F#", "G#", "A", "B", "C#", "D#"},
		{"F", "G", "A", "Bb", "C", "D", "E"},
		{"F#", "G#", "A#", "B", "C#", "D#", "E#"},
		{"Gb", "Ab", "Bb", "Cb", "Db", "Eb", "F"},
		{"G", "A", "B", "C", "D", "E", "F#"}};

int main()
{
	char str1[16], str2[16];
	bool fst = true;
	while (1)
	{
		scanf("%s", str1);
		if (*str1 == '*')
		{
			break;
		}
		else
		{
			if (fst)
			{
				fst = false;
			}
			else
			{
				printf("\n");
			}
		}
		scanf("%s", str2);
		if (*str2 == '*')
		{
			break;
		}
		int from, to;
		for (from = 0; from < 15; from++)
		{
			if (strcmp(data[from][0], str1) == 0)
			{
				break;
			}
		}
		if (from == 15)
		{
			printf("Key of %s is not a valid major key\n", str1);
		}
		for (to = 0; to < 15; to++)
		{
			if (strcmp(data[to][0], str2) == 0)
			{
				break;
			}
		}
		if (from < 15 && to == 15)
		{
			printf("Key of %s is not a valid major key\n", str2);
		}
		if (from < 15 && to < 15)
		{
			printf("Transposing from %s to %s:\n", str1, str2);
		}
		while (1)
		{
			scanf("%s", str2);
			if (*str2 == '*')
			{
				break;
			}
			if (from == 15 || to == 15)
			{
				continue;
			}
			int j;
			for (j = 0; j < 7; j++)
			{
				if (strcmp(data[from][j], str2) == 0)
				{
					break;
				}
			}
			if (j == 7)
			{
				printf("  %s is not a valid note in the %s major scale\n",
							 str2, str1);
			}
			else
			{
				printf("  %s transposes to %s\n", str2, data[to][j]);
			}
		}
	}
	return 0;
}
