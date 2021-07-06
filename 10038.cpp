#include <bits/stdc++.h>

using namespace std;

bool flag[3010];

int main()
{
	int n, value, rec;
	while (cin >> n)
	{
		memset(flag, 0, sizeof(flag));
		int loop;
		for (loop = 0; loop < n; loop++)
		{
			cin >> value;
			if (loop == 0)
			{
				flag[(int)fabs(value)] = true;
				rec = value;
			}
			else
			{
				int temp;
				temp = (int)fabs(value - rec);
				if (temp <= 3000)
				{
					flag[temp] = true;
					rec = value;
				}
			}
		}
		bool Joly = true;
		for (loop = 1; loop < n; loop++)
		{
			if (flag[loop] == false)
			{
				cout << "Not jolly" << endl;
				Joly = false;
				break;
			}
		}
		if (Joly)
		{
			cout << "Jolly" << endl;
		}
	}
	return 0;
}
