#include <bits/stdc++.h>

using namespace std;

int goal, left_[256], S[256], top, opleft_;

int doit()
{
	if (top > opleft_ + 1)
	{
		return 0;
	}
	if (top == 1 && S[top] == goal)
	{
		return 1;
	}
	if (top >= 2)
	{
		int a = S[top--];
		int b = S[top--];
#define X(c, op)       \
	if (left_[c] > 0)     \
	{                    \
		left_[c]--;         \
		opleft_--;          \
		S[++top] = a op b; \
		if (doit())        \
			return 1;        \
		top--;             \
		left_[c]++;         \
		opleft_++;          \
	}
		X('+', +)
		X('-', -) X('x', *)
#undef X
				S[++top] = b;
		S[++top] = a;
	}
	for (int d = '0'; d <= '9'; d++)
	{
		if (left_[d] == 0)
		{
			continue;
		}
		left_[d]--;
		S[++top] = d - '0';
		if (doit())
		{
			return 1;
		}
		top--;
		left_[d]++;
	}
	return 0;
}

int main()
{
	char buf[256];
	while (scanf(" %s %d", buf, &goal) == 2)
	{
		memset(left_, 0, sizeof(left_));
		for (int i = 0; buf[i]; i++)
		{
			left_[buf[i]]++;
		}
		opleft_ = left_['+'] + left_['-'] + left_['x'];
		top = 0;
		printf(doit() ? "solution\n" : "no solution\n");
	}
}
