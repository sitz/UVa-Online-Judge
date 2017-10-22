#include <bits/stdc++.h>

using namespace std;

string conj_[6] = {"eu        ", "tu        ", "ele/ela   ", "nos       ", "vos       ", "eles/elas "};
string suffix[3][6] = {{"o", "as", "a", "amos", "ais", "am"}, {"o", "es", "e", "emos", "eis", "em"}, {"o", "es", "e", "imos", "is", "em"}};

int main()
{
	bool fst = true;
	string v1, v2, root;
	int n;

	conj_[3][1] = (char)243;
	conj_[4][1] = (char)243;

	while (cin >> v1 >> v2)
	{
		if (!fst)
		{
			printf("\n");
		}
		cout << v1 << " (to " << v2 << ")" << endl;
		if (v1.size() < 2)
		{
			printf("Unknown conjugation\n");
			fst = false;
			continue;
		}
		if (v1[v1.size() - 2] == 'a' && v1[v1.size() - 1] == 'r')
		{
			n = 0;
		}
		else if (v1[v1.size() - 2] == 'e' && v1[v1.size() - 1] == 'r')
		{
			n = 1;
		}
		else if (v1[v1.size() - 2] == 'i' && v1[v1.size() - 1] == 'r')
		{
			n = 2;
		}
		else
		{
			printf("Unknown conjugation\n");
			fst = false;
			continue;
		}
		root = string(v1.begin(), v1.begin() + v1.size() - 2);
		for (int i = 0; i < 6; i++)
		{
			printf("%s%s%s\n", conj_[i].c_str(), root.c_str(), suffix[n][i].c_str());
		}
		fst = false;
	}
	return 0;
}
