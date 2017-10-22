#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[])
{
	int n;
	while (cin >> n && n)
	{
		int **t = new int *[n + 1];
		for (int i = 0; i != n; ++i)
		{
			t[i] = new int[3];
			int mom, dd, hh, mm;
			long long num;
			char im, s;
			cin >> mom >> s >> dd >> s >> hh >> s >> mm >> num >> im;
			t[i][0] = mm + hh * 100 + dd * 10000 + mom * 1000000;
			t[i][1] = (im == '+' ? 1 : 0);
		}
		t[n] = new int[3];
		t[n][0] = 99999999;
		t[n][1] = 0;
		t[n][2] = 2012;
		t[n - 1][2] = 2012;
		for (int i = n - 2; i != -1; --i)
		{
			if (t[i][0] >= t[i + 1][0])
			{
				t[i][2] = t[i + 1][2] - 1;
			}
			else
			{
				t[i][2] = t[i + 1][2];
			}
		}
		int pre_ptr = -1;
		int remain = 0;
		int last = 0;
		for (int i = 0; i != n; ++i)
		{
			//find the first important
			if (t[i][1])
			{
				// this is the first important record
				if (pre_ptr == -1)
				{
					pre_ptr = i;
					++remain;
					last = i;
					//                  cout <<"case1:"<< i << endl;
				}
				else if (t[pre_ptr][2] == t[i][2])
				{
					// is the same year
					pre_ptr = i;
					++remain;
					last = i;
					//                  cout <<"case2:"<< i << endl;
				}
				else if (t[pre_ptr][2] != t[i][2])
				{
					int pre = pre_ptr;
					for (int j = pre_ptr + 1; j != i; ++j)
					{
						// the case is like this 2007,2008,2009
						// the record must be kept
						if (t[pre][2] == t[j + 1][2] - 2)
						{
							++remain;
							pre = j;
							last = j;
							//                          cout <<"case3:"<< j << endl;
						}
						else if (t[pre][2] == t[j + 1][2])
						{
							// the case is like this: 2007,2007,2007
							// the record can be drop
							continue;
						}
						else
						{
							// the case is like this: 2007,2007,2008
							if (t[pre][0] < t[j + 1][0])
							{
								++remain;
								pre = j;
								last = j;
								//                              cout <<"case4:"<< j << endl;
							}
							else
							{
								continue;
							}
						}
					}
					pre_ptr = i;
					++remain;
					last = i;
					//                  cout << "case5:"<<i<<endl;
				}
			}
			else
			{
				continue;
			}
		}
		//      cout << "last:" << last << endl;
		if (t[last][2] != t[n - 1][2])
		{
			int pre = last;
			for (int j = last + 1; j != n; ++j)
			{
				// the case is like this 2007,2008,2009
				// the record must be kept
				if (t[pre][2] == t[j + 1][2] - 2)
				{
					++remain;
					pre = j;
					//                  cout <<"case6:"<< j << endl;
				}
				else if (t[pre][2] == t[j + 1][2])
				{
					// the case is like this: 2007,2007,2007
					// the record can be drop
					continue;
				}
				else
				{
					// the case is like this: 2007,2007,2008
					if (t[pre][0] < t[j + 1][0])
					{
						++remain;
						pre = j;
						//                      cout <<"case7:"<< j << endl;
					}
					else
					{
						continue;
					}
				}
			}
		}
		cout << remain << endl;
		// testing
		//      for (int i=0; i!=n; ++i)
		//        cout << setw(8) << t[i][0] <<' '<<t[i][1]<<' '<<t[i][2]<<endl;
	}
	return 0;
}
