#include <bits/stdc++.h>

using namespace std;

char x[101], y[101];
int arr1[26], arr2[26];

int main()
{
	while(scanf("%s%s", x, y) == 2)
	{
		int len = strlen(x);
		for (int i = 0; i < 26; i++)
		{
			arr1[i] = arr2[i] = 0;
		}

		for (int i = 0; i < len; i++)
		{
			arr1[x[i] - 65]++;
			arr2[y[i] - 65]++;
		}

		sort(arr1, arr1 + 26);
		sort(arr2, arr2 + 26);

		bool flag = true;
		for (int i = 0; i < 26; i++)
		{
			if (arr1[i] != arr2[i])
			{
				flag = false;
				break;
			}
		}

		printf(flag ? "YES\n" : "NO\n");
	}
	return 0;
}
