#include <bits/stdc++.h>

using namespace std;

map<string, set<string>> server;

char line[5120];

int main()
{
	while (gets(line))
	{
		char *p = strtok(line, " \t");
		//      if (p==NULL) while(1); //debug..no
		if (*p == '*')
		{
			break;
		}
		//skip first "MTA"
		string host(strtok(NULL, " \t"));
		int n = atoi(strtok(NULL, " \t"));
		set<string> id;
		while (--n >= 0)
		{
			id.insert(strtok(NULL, " \t"));
		}
		server[host] = id;
	}
	while (gets(line))
	{
		char *p = strtok(line, " @\t");
		//      if (p==NULL) { int q=0; q/=q; } //debug..no
		if (*p == '*')
		{
			break;
		}
		string id(p);
		string host(strtok(NULL, " @\t"));
		vector<string> addr;
		while ((p = strtok(NULL, " @\t")) != NULL)
		{
			addr.push_back(p);
		}
		gets(line);//"*"
		//      if (*line!='*') { int q=0; q/=q; } //debug..no
		vector<string> data;
		bool isFirst = true;
		while (1)
		{
			gets(line);
			if (*line == '*')
			{
				break;
			}
			if (*line == 0 && isFirst)
			{
			}
			else
			{
				data.push_back(line);
				isFirst = false;
			}
		}
		//output
		while (!addr.empty())
		{
			string now(addr[1]);
			printf("Connection between %s and %s\n", host.c_str(), now.c_str());
			printf("     HELO %s\n", host.c_str());
			printf("     250\n");
			printf("     MAIL FROM:<%s@%s>\n", id.c_str(), host.c_str());
			printf("     250\n");
			map<string, set<string>>::iterator it = server.find(now);
			//          if (it==server.end()) while(1); //debug..no
			set<string> &t = (*it).second;
			bool isSuccess = false;
			set<string> send;
			for (int i = 0; i < addr.size(); i += 2)
			{
				if (addr[i + 1] != now)
				{
					continue;
				}
				if (send.find(addr[i]) != send.end())//already send
				{
					continue;
				}
				send.insert(addr[i]);
				printf("     RCPT TO:<%s@%s>\n", addr[i].c_str(), now.c_str());
				if (t.find(addr[i]) == t.end())
				{
					printf("     550\n");
				}
				else
				{
					printf("     250\n");
					isSuccess = true;
				}
			}
			for (int i = addr.size() - 1; i >= 0; i -= 2)
			{
				if (addr[i] != now)
				{
					continue;
				}
				addr.erase(addr.begin() + i);
				addr.erase(addr.begin() + (i - 1));
			}
			if (isSuccess)
			{
				printf("     DATA\n");
				printf("     354\n");
				for (int i = 0; i < data.size(); i++)
				{
					printf("     %s\n", data[i].c_str());
				}
				printf("     .\n");
				printf("     250\n");
			}
			printf("     QUIT\n");
			printf("     221\n");
		}
	}
	return 0;
}
