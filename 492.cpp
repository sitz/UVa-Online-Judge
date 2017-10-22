#include <bits/stdc++.h>

using namespace std;

/**
 * UVa 492 Pig-Latin (AC)
 * Author: chchwy
 * Last Modified: 2010.02.06
 */

bool isVowel(char c)
{
	switch (c)
	{
	case 'A':
	case 'a':
	case 'E':
	case 'e':
	case 'I':
	case 'i':
	case 'O':
	case 'o':
	case 'U':
	case 'u':
		return true;
	default:
		return false;
	}
}
int main()
{
	char buf[4096];
	int bufIndex = 0;
	bool isWord = false;//the state
	char c;
	while ((c = getchar()) != EOF)
	{
		/* finite state machine */
		switch (isWord)
		{
		case false:
			if (isalpha(c))
			{
				bufIndex = 0;//clear buf
				buf[bufIndex++] = c;
				isWord = true;
			}
			else
			{
				putchar(c);
			}
			break;
		case true:
			if (isalpha(c))
			{
				buf[bufIndex++] = c;
			}
			else
			{
				/* print word */
				if (isVowel(buf[0]))
				{
					buf[bufIndex] = NULL;//NULL end
					printf(buf);
					printf("ay");
				}
				else
				{
					buf[bufIndex] = NULL;
					printf(buf + 1);
					putchar(buf[0]);
					printf("ay");
				}
				putchar(c);
				isWord = false;
			}
			break;
		}
	}
	return 0;
}
