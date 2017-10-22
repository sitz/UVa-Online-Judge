#include <bits/stdc++.h>

using namespace std;

char *trimwhitespace(char *str)
{
	char *end;
	// Trim leading space
	while (isspace(*str))
	{
		str++;
	}
	if (*str == 0)// All spaces?
	{
		return str;
	}
	// Trim trailing space
	end = str + strlen(str) - 1;
	while (end > str && isspace(*end))
	{
		end--;
	}
	// Write new null terminator
	*(end + 1) = 0;
	return str;
}
int main()
{
	char word[100][24];
	char line[256], text[256], text2[256], *ptr, *p;
	int n_word = 0, len, count, max, max_count, i, r;
	while (true)
	{
		fgets(line, 256, stdin);
		if (!sscanf(line, "%[^\n]", text) || *text == '#')
		{
			break;
		}
		sprintf(word[n_word++], " %s ", text);
	}
	fgets(line, 256, stdin);
	sscanf(line, "%[^\n]", text);
	len = strlen(text);
	text2[0] = ' ';
	strcpy(text2 + 1, text);
	text2[len + 1] = ' ';
	text2[len + 2] = 0;
	count = 0;
	max_count = max = -1;
	do
	{
		r = 0;
		for (i = 0; i < n_word; i++)
			if (strstr(text2, word[i]))
			{
				r++;
			}
		if (r > max)
		{
			max = r, max_count = count;
		}
		if (++count == 27)
		{
			break;
		}
		for (i = 1; i <= len; i++)
			if (text2[i] == ' ')
			{
				text2[i] = 'A';
			}
			else if (++text2[i] == 'Z' + 1)
			{
				text2[i] = ' ';
			}
	} while (true);
	if (max_count)
		for (i = 0; i < len; i++)
		{
			if (text[i] == ' ')
			{
				text[i] = 'A' + max_count - 1;
			}
			else
			{
				text[i] += max_count;
			}
			if (text[i] == 'Z' + 1)
			{
				text[i] = ' ';
			}
			else if (text[i] > 'Z')
			{
				text[i] = 'A' + text[i] - 'Z' - 2;
			}
		}
	ptr = text;
	while (true)
	{
		if (len <= 60)
		{
			printf("%s\n", trimwhitespace(ptr));
			break;
		}
		p = ptr + 60;
		while (*p != ' ')
		{
			p--;
		}
		*p = 0;
		printf("%s\n", trimwhitespace(ptr));
		len -= p - ptr;
		ptr = p + 1;
	}
}
