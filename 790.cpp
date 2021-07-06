#include <bits/stdc++.h>

using namespace std;

struct Team
{
	int solve, time, fail[10], id;
	bool sol[10];
} t[26];
struct Record
{
	int id, problem, time, yes;
} r[1000];
int len, ptr;
void init()
{
	for (int i = 0; i < 26; i++)
	{
		t[i].solve = t[i].time = 0;
		t[i].id = i;
		for (int j = 0; j < 10; j++)
		{
			t[i].sol[j] = false, t[i].fail[j] = 0;
		}
	}
	len = ptr = 0;
}
bool compare(int i, int j)
{
	if (t[j].solve > t[i].solve)
	{
		return true;
	}
	if ((t[j].solve == t[i].solve) && (t[j].time < t[i].time))
	{
		return true;
	}
	if ((t[j].solve == t[i].solve) && (t[j].time == t[i].time) && (t[j].id < t[i].id))
	{
		return true;
	}
	return false;
}
int compare1(const void *a, const void *b)
{
	Record *c = (Record *)a, *d = (Record *)b;
	if (c->time != d->time)
	{
		return ((Record *)a)->time - ((Record *)b)->time;
	}
	return c->yes - d->yes;
}
char str[1000], problem, yes;
int main()
{
	int times, id, min, sec;
	gets(str);
	sscanf(str, "%d", &times);
	gets(str);
	for (int x = 0; x < times; x++)
	{
		if (x)
		{
			puts("");
		}
		init();
		while (gets(str))
		{
			if (sscanf(str, "%d %c %d:%d %c", &id, &problem, &min, &sec, &yes) != 5)
			{
				break;
			}
			if (id > ptr)
			{
				ptr = id;
			}
			r[len].id = id;
			r[len].problem = problem - 'A';
			r[len].time = min * 60 + sec;
			r[len].yes = yes;
			len++;
		}
		qsort(r, len, sizeof(Record), compare1);
		for (int i = 0; i < len; i++)
		{
			if (t[r[i].id].sol[r[i].problem])
			{
				continue;
			}
			if (r[i].yes == 'N')
			{
				t[r[i].id].fail[r[i].problem]++;
			}
			else
			{
				t[r[i].id].sol[r[i].problem] = true;
				t[r[i].id].solve++;
				t[r[i].id].time += r[i].time;
				t[r[i].id].time += t[r[i].id].fail[r[i].problem] * 20;
			}
		}
		for (int i = 1; i <= ptr; i++)
			for (int j = i + 1; j <= ptr; j++)
				if (compare(i, j))
				{
					Team temp = t[i];
					t[i] = t[j];
					t[j] = temp;
				}
		int rank = 1;
		printf("RANK TEAM PRO/SOLVED TIME\n");
		for (int i = 1; i <= ptr; i++)
		{
			if (i && t[i].solve == t[i - 1].solve && t[i].time == t[i - 1].time)
			{
				printf("%4d %4d", rank, t[i].id);
			}
			else
			{
				printf("%4d %4d", i, t[i].id);
				rank = i;
			}
			if (t[i].solve)
			{
				printf(" %4d       %4d", t[i].solve, t[i].time);
			}
			printf("\n");
		}
	}
	return 0;
}
