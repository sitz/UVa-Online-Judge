#include <bits/stdc++.h>

using namespace std;

struct transition
{
	vector<int> in;
	vector<int> out;
};
int slove(int len, int *p, transition tem)
{
	int t[len];//cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;
	for (int i = 0; i < len; i++)
	{
		t[i] = 0;//cout<<len<<endl;
	}
	for (int i = 0; i < tem.in.size(); i++)
	{
		t[tem.in[i] - 1]++;
	}
	for (int i = 0; i < len; i++)
		if (t[i] && p[i] < t[i])
		{
			return 0;
		}
	return 1;
}
int main()
{
	int num_p;
	int cases = 1;
	while (cin >> num_p && num_p)
	{
		int p[num_p];
		for (int i = 0; i < num_p; i++)
		{
			cin >> p[i];
		}
		int num_t;
		cin >> num_t;
		transition t[num_t];
		for (int i = 0; i < num_t; i++)
		{
			int n;
			while (cin >> n && n)
				if (n > 0)
				{
					t[i].out.push_back(n);
				}
				else
				{
					t[i].in.push_back(-n);
				}
		}
		int max_t;
		cin >> max_t;
		int i;
		int num = 0;
		int m = 0;//cout<<sizeof(p)/sizeof(int)<<endl;
		//cout<<t[2].in.size()<<endl;
		for (i = 0; i < num_t; i++)
		{
			m = max(m, i);
			if (num >= max_t)
			{
				break;
			}
			if (slove(num_p, p, t[i]))//cout<<1;
			{
				for (int j = 0; j < t[i].in.size(); j++)
				{
					p[t[i].in[j] - 1]--;
					if (p[t[i].in[j] - 1] < 0)
					{
						p[t[i].in[j] - 1] = 0;
					}
				}
				for (int j = 0; j < t[i].out.size(); j++)
				{
					p[t[i].out[j] - 1]++;
				}
				i = -1;
				num++;
			}
		}
		//cout<<m<<endl;
		//cout<<num<<endl;
		if (i != num_t)
		{
			cout << "Case " << cases++ << ": still live after " << max_t << " transitions" << endl;
		}
		else
		{
			cout << "Case " << cases++ << ": dead after " << num << " transitions" << endl;
		}
		cout << "Places with tokens:";
		for (int i = 0; i < num_p; i++)
			if (p[i])
			{
				cout << " " << i + 1 << " "
						 << "(" << p[i] << ")";
			}
		cout << endl
				 << endl;
	}
	return 0;
}
