#include <bits/stdc++.h>

using namespace std;

//HKUST - ZHANG Xiongqi
//Using C++

vector<int> people;
int main()
{
	int count = 1;
	int num;
	int luck;
	int N;
	while (scanf("%d", &num) == 1)
	{
		people.clear();
		scanf("%d", &luck);
		for (int i = 1; i <= num; i++)
		{
			people.push_back(i);
		}
		bool fin = false;
		if (num == luck)
		{
			fin = true;
		}
		for (int i = 0; i < 20; i++)
		{
			scanf("%d", &N);
			if (fin)
			{
				continue;
			}
			int loc = 0;
			while (loc < people.size() && !fin)
			{
				loc += N - 1;
				if (loc < people.size())
				{
					people.erase(people.begin() + loc);
				}
				if (int(people.size()) == luck)
				{
					fin = true;
				}
			}
		}
		printf("Selection #%d\n", count);
		count++;
		printf("%d", people[0]);
		for (int i = 1; i < people.size(); i++)
		{
			printf(" %d", people[i]);
		}
		putchar(10);
		putchar(10);
	}
	return 0;
}
