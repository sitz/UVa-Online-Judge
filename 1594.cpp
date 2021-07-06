#include <bits/stdc++.h>

using namespace std;

int main()
{
	int grp, n, num;
	scanf("%d", &grp);
	for (int i = 1; i <= grp; i++)
	{
		vector<int> nums, nums_tmp;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &num);
			nums.push_back(num);
			nums_tmp.push_back(num);
		}
		for (int k = 0; k < 1000; k++)
		{
			int total = 0;
			for (int j = 0; j < n; j++)
			{
				total += nums[j];
			}
			if (total == 0)
			{
				printf("ZERO\n");
				break;
			}
			for (int j = 0; j < n; j++)
			{
				if (j == n - 1)
				{
					nums_tmp[j] = abs(nums[j] - nums[0]);
				}
				else
				{
					nums_tmp[j] = abs(nums[j] - nums[j + 1]);
				}
			}
			for (int j = 0; j < n; j++)
			{
				nums[j] = nums_tmp[j];
			}
		}
		int total = 0;
		for (int j = 0; j < n; j++)
		{
			total += nums[j];
		}
		if (total != 0)
		{
			printf("LOOP\n");
		}
	}
	return 0;
}
