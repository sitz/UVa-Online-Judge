#include <bits/stdc++.h>

using namespace std;

#define LEN 12
#define RNG 11

int SubMolecules(const vector<string> &moles)
{
	int ret = 0;
	for (int a = 1; a < RNG; ++a)
	{
		for (int b = 1; b < RNG; ++b)
		{
			if (moles[0][a] == moles[1][b])
			{
				for (int bc = b + 2; bc < RNG; ++bc)
				{
					for (int c = 1; c < RNG; ++c)
					{
						if (moles[1][bc] == moles[2][c])
						{
							int da_max = min(RNG - c, RNG - a);
							for (int da = 2; da < da_max; ++da)
							{
								for (int d = 1; d < RNG - (bc - b); ++d)
								{
									if (moles[0][a + da] == moles[3][d] &&
											moles[3][d + (bc - b)] == moles[2][(a + da) - (a - c)])
									{
										int ad_len = da - 1;
										int bc_len = bc - b - 1;
										ret = max(ret, bc_len * ad_len);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return ret;
}

int Molecules(const vector<string> &moles)
{
	int ret = 0;
	int a[] = {0, 1, 2, 3};
	ret = max(ret, SubMolecules(moles));
	while (next_permutation(a, a + 4))
	{
		vector<string> perm_mole(moles.begin(), moles.end());
		for (int i = 0; i < 4; ++i)
		{
			perm_mole[i] = moles[a[i]];
		}
		ret = max(ret, SubMolecules(perm_mole));
	}
	return ret;
}

int main()
{
	while (true)
	{
		vector<string> moles;
		for (int i = 0; i < 4; ++i)
		{
			string s;
			cin >> s;
			moles.push_back(s);
			if (moles[i].find('Q') != string::npos)
			{
				return 0;
			}
		}
		cout << Molecules(moles) << endl;
	}
	return 0;
}
