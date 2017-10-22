#include <bits/stdc++.h>

using namespace std;

struct List
{
	//Data Information:
	char Title[50], FirstName[50], LastName[50];
	char HomeAddress[100];
	char Department[100], HomePhone[100], WorkPhone[100], CampusBox[100];
};

void PrintList(List p)
{
	cout << "----------------------------------------" << endl;
	cout << p.Title << ' ' << p.FirstName << ' ' << p.LastName << endl;
	cout << p.HomeAddress << endl;
	cout << "Department: " << p.Department << endl;
	cout << "Home Phone: " << p.HomePhone << endl;
	cout << "Work Phone: " << p.WorkPhone << endl;
	cout << "Campus Box: " << p.CampusBox << endl;
}

int sort_function(const void *a, const void *b)
{
	List *aa, *bb;
	aa = (List *)a;
	bb = (List *)b;
	return (strcmp(aa->LastName, bb->LastName));
}

int main()
{
	List test[4100];
	int n, t, i, ListNum = 0;
	char data[5000], depart[5000];
	scanf("%d\n", &n);
	for (t = 0; t < n; t++)
	{
		cin.getline(depart, 5000);
		while (1)
		{
			cin.getline(data, 5000);
			if (strcmp(data, "\0") == 0)
			{
				break;
			}
			//Seperate Information :
			char *p;
			strcpy(test[ListNum].Department, depart);
			p = strtok(data, ",");
			//          p = strtok(NULL, ",");
			if (p)
			{
				strcpy(test[ListNum].Title, p);
			}
			p = strtok(NULL, ",");
			if (p)
			{
				strcpy(test[ListNum].FirstName, p);
			}
			p = strtok(NULL, ",");
			if (p)
			{
				strcpy(test[ListNum].LastName, p);
			}
			p = strtok(NULL, ",");
			if (p)
			{
				strcpy(test[ListNum].HomeAddress, p);
			}
			p = strtok(NULL, ",");
			if (p)
			{
				strcpy(test[ListNum].HomePhone, p);
			}
			p = strtok(NULL, ",");
			if (p)
			{
				strcpy(test[ListNum].WorkPhone, p);
			}
			p = strtok(NULL, ",");
			if (p)
			{
				strcpy(test[ListNum].CampusBox, p);
			}
			ListNum++;
			//End Seperate;
		}
	}
	//  cout<<ListNum<<endl;
	qsort((void *)test, ListNum, sizeof(test[0]), sort_function);
	for (i = 0; i < ListNum; i++)
	{
		PrintList(test[i]);
	}
	//print result:
	return 0;
}
