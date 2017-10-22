#include <bits/stdc++.h>

using namespace std;

char line[100005];
int digits, erase, curr, queue_[10][100000], head[10], tail[10], i, toshow, last;

int main()
{
	while (scanf("%d %d\n", &digits, &erase) && digits)
	{
		gets(line);
		for (i = 0; i < 10; i++)
		{
			head[i] = tail[i] = 0;
		}
		for (i = 0; i < digits; i++)
		{
			curr = line[i] - '0';
			queue_[curr][tail[curr]++] = i;
		}
		for (last = 0, toshow = digits - erase; toshow;)
		{
			for (i = 9; i > -1; i--)
			{
				while (head[i] != tail[i] && queue_[i][head[i]] < last)
				{
					head[i]++;
				}
				if (head[i] != tail[i] && queue_[i][head[i]] <= digits - toshow)
				{
					toshow--;
					putchar(i + '0');
					last = queue_[i][head[i]++];
					break;
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
