#include <bits/stdc++.h>

using namespace std;

const int NN = 100048;

bool dead[NN];
int left_[NN], right_[NN];

int main()
{
	for (int b, s; scanf("%d%d", &s, &b) == 2 && s;)
	{
		for (int i = 0; i <= s + 1; ++i)
		{
			left_[i] = i - 1;
			right_[i] = i + 1;
			dead[i] = false;
		}
		int new_left_, new_right_;
		for (int i = 0, y, z; i < b; ++i)
		{
			scanf("%d %d", &y, &z);
			for (int j = y; j <= z; ++j)
			{
				dead[j] = true;
			}
			new_left_ = y;
			new_right_ = z;
			while (dead[new_left_])
			{
				new_left_ = left_[new_left_];
			}
			while (dead[new_right_])
			{
				new_right_ = right_[new_right_];
			}
			for (int j = y; j <= z; ++j)
			{
				left_[j] = new_left_;
				right_[j] = new_right_;
			}
			if (new_left_ > 0 && new_right_ <= s)
			{
				printf("%d %d\n", new_left_, new_right_);
			}
			else if (new_left_ > 0)
			{
				printf("%d *\n", new_left_);
			}
			else if (new_right_ <= s)
			{
				printf("* %d\n", new_right_);
			}
			else
			{
				puts("* *");
			}
		}
		puts("-");
	}
	return 0;
}
