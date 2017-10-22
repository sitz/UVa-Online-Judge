#include <bits/stdc++.h>

using namespace std;

#define abs(a) (a < 0 ? -a : a)

struct Signal
{
	float L;
	int c[3];
} s[10];
bool operator<(const Signal &a, const Signal &b)
{
	return a.L < b.L;
}
int N, top, v, t = 0;
int goodSpeeds[50];
int goodSpeed(int v)
{
	float lastPos = 0;
	float clock = 0;
	for (int sig = 0; sig < N; sig++)
	{
		float distance = s[sig].L - lastPos;
		lastPos += distance;
		clock += distance / float(v) * 60 * 60;
		float sum = s[sig].c[0] + s[sig].c[1] + s[sig].c[2];
		double remaining = fmod(clock, sum);
		if (remaining > s[sig].c[0] + s[sig].c[1])
		{
			return 0;
		}
	}
	return true;
}
int main()
{
	while (scanf("%d", &N) && N != -1)
	{
		for (int i = 0; i < N; ++i)
		{
			scanf("%f %d %d %d", &(s[i].L), &(s[i].c[0]), &(s[i].c[1]), &(s[i].c[2]));
		}
		sort(s, s + N);
		for (top = 0, v = 30; v < 61; v++)
			if (goodSpeed(v))
			{
				goodSpeeds[top++] = v;
			}
		vector<int> seq;
		int comma = 0, count = 0;
		printf("Case %d:", ++t);
		if (top == 0)
		{
			printf(" No acceptable speeds.");
		}
		else
			for (int i = 0; i < top; i++)
			{
				if (!seq.empty() && seq.back() + 1 != goodSpeeds[i])
				{
					count++;
					if (seq.size() == 1)
					{
						printf(" %d", seq[0]);
					}
					else
					{
						printf(" %d-%d", seq.front(), seq.back());
					}
					if (i != top - 1)
					{
						printf(",");
					}
					comma = (i != top - 1);
					seq.clear();
				}
				seq.push_back(goodSpeeds[i]);
			}
		if (seq.size())
		{
			if (!comma && count)
			{
				printf(",");
			}
			if (seq.size() == 1)
			{
				printf(" %d", seq[0]);
			}
			else
			{
				printf(" %d-%d", seq.front(), seq.back());
			}
		}
		printf("\n");
	}
	return 0;
}
