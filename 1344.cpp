#include <bits/stdc++.h>

using namespace std;

int n;
int a[1005], b[1005];
int main()
{
	int i;
	while (scanf("%d", &n) != EOF && n)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d", &b[i]);
		}
		sort(a, a + n);
		sort(b, b + n);
		int star1, star2;
		star1 = star2 = 0;
		int end1, end2;
		end1 = end2 = n - 1;
		int sum = 0;
		int num = n;
		while (num)
		{
			if (a[end1] > b[end2])
			{
				sum += 200;
				end1--;
				end2--;
			}
			else if (a[end1] < b[end2])
			{
				sum -= 200;
				star1++;
				end2--;
			}
			else
			{
				if (a[star1] > b[star2])
				{
					sum += 200;
					star1++;
					star2++;
				}
				else if (a[star1] < b[star2])
				{
					sum -= 200;
					star1++;
					end2--;
				}
				else
				{
					if (a[star1] == b[end2])
					{
						break;
					}
					else
					{
						sum -= 200;
						star1++;
						end2--;
					}
				}
			}
			num--;
		}
		printf("%d\n", sum);
	}
	return 0;
}
