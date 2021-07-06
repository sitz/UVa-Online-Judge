#include <bits/stdc++.h>

using namespace std;

int T, trid, item;
char mode, s[100];

int main()
{
	for (scanf("%d\n", &T); T--; gets(s))
	{
		set<int> ignore;
		map<int, int> mutex;
		map<int, set<int> > shared;

		while (gets(s) && *s != '#')
		{
			sscanf(s, "%c%d%d", &mode, &trid, &item);
			if (ignore.find(trid) != ignore.end())
			{
				printf("IGNORED\n");
			}
			else if (mode == 'S')
			{
				if (mutex.find(item) != mutex.end())
				{
					if (mutex[item] != trid)
					{
						printf("DENIED\n");
						ignore.insert(trid);
					}
					else
					{
						printf("GRANTED\n");
					}
				}
				else
				{
					printf("GRANTED\n");
					shared[item].insert(trid);
				}
			}
			else if (shared.find(item) != shared.end())
			{
				// X
				if (shared[item].size() > 1 || *shared[item].begin() != trid)
				{
					printf("DENIED\n"), ignore.insert(trid);
				}
				else
				{
					printf("GRANTED\n"), mutex[item] = trid;
				}
			}
			else if (mutex.find(item) == mutex.end() || mutex[item] == trid)
			{
				// not in shared
				printf("GRANTED\n");
				mutex[item] = trid;
			}
			else
			{
				printf("DENIED\n");
				ignore.insert(trid);
			}
		}
		if (T)
		{
			printf("\n");
		}
	}
}
