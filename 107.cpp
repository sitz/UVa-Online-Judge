#include <bits/stdc++.h>

using namespace std;

inline void find(int init_height, int kitten)
{
	for (int n = 2; n <= init_height; ++n)
	{
		int curr_height = init_height;
		int now_cat = 1;
		int total = 0, notWorkCat = 0;
		while ((curr_height % n) == 0)
		{
			total += curr_height * now_cat;
			notWorkCat += now_cat;
			curr_height = curr_height / n;
			now_cat = now_cat * (n - 1);
		}
		if (now_cat == kitten)
		{
			total += now_cat;
			printf("%d %d\n", notWorkCat, total);
			break;
		}
	}
}

int main()
{
	int init_height, kitten;
	while (scanf("%d%d", &init_height, &kitten) == 2)
	{
		if (init_height == 0 || kitten == 0)
		{
			break;
		}
		if (init_height == 1 && kitten == 1)
		{
			printf("0 1\n");
		}
		else if (init_height == 1)
		{
			printf("1 %d\n", kitten);
		}
		find(init_height, kitten);
	}
	return 0;
}
