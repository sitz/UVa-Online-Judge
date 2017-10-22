#include <bits/stdc++.h>

using namespace std;

char line[1024];
set<string> palin;

int isPalin(int l, int r)
{
	while (l < r && line[l] == line[r])
	{
		l++, r--;
	}
	if (l >= r)
	{
		return 1;
	}
	return 0;
}

int main()
{
	while (scanf("%s", line) == 1)
	{
		int str_len = strlen(line);
		string str(line);
		palin.clear();
		//  int counter=0;
		for (int len = 3; len <= 4; len++)//len<=4 !!
		{
			int s = 0, e = len - 1;
			if (e >= str_len /*|| counter==2*/)
			{
				break;
			}
			//    int found=0;
			for (; e < str_len; s++, e++)
			{
				if (!isPalin(s, e))
				{
					continue;
				}
				string now(str.substr(s, len));
				if (palin.find(now) != palin.end())
				{
					continue;
				}
				//      found++;
				//      for (int i=palin.size()-1; i>=0; i--)
				set<string>::iterator i;
				for (i = palin.begin(); i != palin.end(); ++i)
				{
					//        printf("[%s,%s]",now.c_str(),palin[i].c_str());
					//        if (now.find(palin[i])>=len)
					if (now.find(*i) >= len)
					{
						printf("%s\n", line);
						goto End;
					}
				}
				//      printf("[%s]",now.c_str());
				//      palin.push_back(now);
				palin.insert(now);
			}
			//    if (found==0) counter++;
		}
	//  printf("\n");
	End:
		str_len--;
	}
	return 0;
}
