#include <bits/stdc++.h>

using namespace std;

char s[256];
int queue_[1024];

int main()
{
	int current, pi, ri;
	unsigned head, tail, total;
	char *p;
	current = 0;
	head = 0;
	tail = 0;
	total = 0;
	for (;;)
	{
		if (!(p = gets(s)))
		{
			break;
		}
		if (!*p)
		{
			printf("%d\n", total + (tail - head + 1024) % 1024 - 1);
			total = 0;
			head = 0;
			tail = 0;
			continue;
		}
		pi = strtol(p, &p, 10);
		if (!pi)
		{
			queue_[tail] = current++;
			tail = (tail + 1) % 1024;
			if ((tail - head + 1024) % 1024 > 1012)
			{
				head = (head + 1) % 1024;
				total++;
			}
		}
		else
		{
			ri = strtol(p, &p, 10);
			while (current - queue_[(tail - 1) % 1024] < pi)
			{
				tail = (tail - 1) % 1024;
			}
			current += ri;
		}
	}
}
