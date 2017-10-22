#include <bits/stdc++.h>

using namespace std;

char line[2048];

string init_word[] =
		{
				"var", "end", "for", "then", "else", "case", "goto", "const",
				"label", "while", "begin", "until", "repeat", "downto", "function",
				"procedure"};

map<string, int> src;

int main()
{
	int n_case = 0;
	gets(line);
	sscanf(line, "%d", &n_case);
	while (--n_case >= 0)
	{
		gets(line);//blank..
		src.clear();
		for (int m = 0; m < 16; m++)
		{
			src[init_word[m]] = m;
		}
		bool canExit = false;
		do
		{
			gets(line);
			if (strcmp(line, "end.") == 0)
			{
				canExit = true;
			}
			for (int p = 0; line[p] != 0;)
			{
				if (!isalpha(line[p]) && !isdigit(line[p]))
				{
					putchar(line[p]);
					p++;
					continue;
				}
				int q = p + 1;
				while (isalpha(line[q]) || isdigit(line[q]))
				{
					q++;
				}
				if (q - p < 3)
				{
					putchar(line[p]);
					if (q - p == 2)
					{
						putchar(line[p + 1]);
					}
					p = q;
					continue;
				}
				char save = line[q];
				line[q] = 0;
				string tmp(line + p);
				map<string, int>::iterator f = src.find(tmp);
				if (f == src.end())//not found..
				{
					printf(line + p);
					int no = src.size();
					src[tmp] = no;
				}
				else
				{
					printf("&%d", (*f).second);
				}
				line[q] = save;
				p = q;
			}
			putchar('\n');
		} while (!canExit);
		if (n_case)
		{
			printf("\n");
		}
	}
	return 0;
}
