#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a;
	vector<int> num;
	vector<int> jin;
	vector<int> temp;
	while (scanf("%d", &a) == 1)
	{
		num.clear();
		jin.clear();
		temp.clear();
		for (int i = 1; i < a; i++)
		{
			temp.clear();
			jin.clear();
			temp.push_back(i);
			jin.push_back(0);
			while (true)
			{
				int j = temp.size() - 1;
				int k = (temp[j] * 2 + jin[j]) % a;
				int l = (temp[j] * 2 + jin[j]) / a;
				if (k == i && l == 0)
				{
					break;
				}
				temp.push_back(k);
				jin.push_back(l);
			}
			if (i == 1)
			{
				num = temp;
			}
			else
			{
				if (num.size() > temp.size())
				{
					num = temp;
				}
				else if (num.size() == temp.size())
				{
					for (int j = num.size() - 1; j >= 0; j--)
					{
						if (num[j] > temp[j])
						{
							num = temp;
							break;
						}
						else if (num[j] < temp[j])
						{
							break;
						}
					}
				}
			}
			//cout<<"Begins with "<<i<<endl;
			//for(int i=num.size()-1;i>=0;i--) cout<<num[i]<<" ";
			//cout<<endl;
		}
		printf("For base %d the double-trouble number is\n", a);
		for (int i = num.size() - 1; i >= 0; i--)
		{
			printf("%d ", num[i]);
		}
		putchar(10);
	}
	return 0;
}
