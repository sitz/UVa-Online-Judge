#include <bits/stdc++.h>

using namespace std;

bool is_dna(string s)
{
	return s == "A" || s == "B" || s == "C" || s == "D";
}

bool cmp(const pair<string, string> &a, const pair<string, string> &b)
{
	return a.first < b.first;
}

int main()
{
	int n;
	bool t_fst = true;
	string input;

	while (scanf("%d", &n) == 1)
	{
		if (t_fst)
		{
			t_fst = false;
		}
		else
		{
			printf("\n");
		}

		map<string, string> assignments;
		vector<string> fst, snd;

		for (int i = 0; i < n; i++)
		{
			cin >> input;
			fst.push_back(input);
		}

		for (int i = 0; i < n; i++)
		{
			cin >> input;
			snd.push_back(input);
		}

		bool ok = true;
		while (1)
		{
			bool changed = false;

			for (int i = 0; i < n; i++)
			{
				bool dna1 = is_dna(fst[i]);
				bool dna2 = is_dna(snd[i]);

				if (dna1 && dna2)
				{
					if (fst[i] != snd[i])
					{
						ok = false;
						break;
					}
				}
				else if (!dna1 && dna2)
				{
					if (assignments.find(fst[i]) == assignments.end())
					{
						assignments[fst[i]] = snd[i];
						changed = true;
					}
					else
					{
						if (assignments[fst[i]] != snd[i])
						{
							ok = false;
							break;
						}
					}
				}
				else if (dna1 && !dna2)
				{
					if (assignments.find(snd[i]) == assignments.end())
					{
						assignments[snd[i]] = fst[i];
						changed = true;
					}
					else
					{
						if (assignments[snd[i]] != fst[i])
						{
							ok = false;
							break;
						}
					}
				}
				else if (!dna1 && !dna2)
				{
					if (fst[i] != snd[i])
					{
						if (assignments.find(fst[i]) == assignments.end() && assignments.find(snd[i]) != assignments.end())
						{
							assignments[fst[i]] = assignments[snd[i]];
							changed = true;
						}
						else if (assignments.find(fst[i]) != assignments.end() && assignments.find(snd[i]) == assignments.end())
						{
							assignments[snd[i]] = assignments[fst[i]];
							changed = true;
						}
						else if (assignments.find(fst[i]) != assignments.end() && assignments.find(snd[i]) != assignments.end())
						{
							if (assignments[fst[i]] != assignments[snd[i]])
							{
								ok = false;
								break;
							}
						}
					}
				}
			}

			if (!changed)
			{
				break;
			}
		}

		if (ok)
		{
			vector<pair<string, string> > res;
			for (map<string, string>::iterator it = assignments.begin(); it != assignments.end(); it++)
			{
				res.push_back(make_pair(it->first, it->second));
			}
			sort(res.begin(), res.end(), cmp);
			printf("YES\n");
			for (int i = 0; i < res.size(); i++)
			{
				printf("%s %s\n", res[i].first.c_str(),res[i].second.c_str());
			}
		}
		else
		{
			printf("NO\n");
		}
	}

	return 0;
}
