#include <bits/stdc++.h>

using namespace std;

/*   @JUDGE_ID:   2905EH   426   C++ "easy!!"  */
//2001/5/8 a_q426.cpp <ACCEPTED P.E.>

struct AccountStruct
{
	string date;
	int id;
	double value;
	bool operator<(const AccountStruct &p) const
	{
		return id < p.id;
	}
};

vector<AccountStruct> acc;

char line[2000];

void PrintAccount(int i)
{
	printf("%4d%c %9.2lf %s", acc[i].id,
				 (i > 0 && acc[i].id > acc[i - 1].id + 1) ? '*' : ' ',
				 acc[i].value, acc[i].date.c_str());
}

int main()
{
	gets(line);
	int n_case;
	sscanf(line, "%d", &n_case);
	gets(line);//blank
	for (int x = 0; x < n_case; x++)
	{
		if (x)
		{
			puts("");
		}
		while (1)
		{
			if (gets(line) == NULL)
			{
				break;
			}
			if (strcmp(line, "") == 0)
			{
				break;
			}
			char *p = strtok(line, " \t\b\r");
			if (p == NULL)
			{
				break;//blank..
			}
			AccountStruct tmp;
			tmp.date = p;
			p = strtok(NULL, " \t\b\r");
			//      if (p==NULL) while(1); //debug..no
			if (!p)
			{
				tmp.id = 0;
			}
			else
			{
				tmp.id = atoi(p);
			}
			p = strtok(NULL, " \t\n\b\r");
			//      if (p==NULL) while(1); //debug..no
			if (!p)
			{
				tmp.value = 0.0;
			}
			else
			{
				tmp.value = atof(p);
			}
			acc.push_back(tmp);
		}
		//  if (acc.size()==0) while(1); //debug..no
		//process..
		sort(acc.begin(), acc.end());
		int n_row = acc.size() / 3;
		if (acc.size() % 3 != 0)
		{
			n_row++;
		}
		int start0 = 0, start1 = n_row, start2 = n_row * 2;
		while (--n_row >= 0)
		{
			PrintAccount(start0++);
			if (start1 < acc.size())
			{
				printf("   ");
				PrintAccount(start1++);
			}
			if (start2 < acc.size())
			{
				printf("   ");
				PrintAccount(start2++);
			}
			printf("\n");
		}
		//init..
		acc.clear();
	}
}
/*@END_OF_SOURCE_CODE*/
