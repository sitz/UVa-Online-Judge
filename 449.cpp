#include <bits/stdc++.h>

using namespace std;

inline char next(char c) { return c == 'G' ? 'A' : ++c; }

int main()
{
	const string note[] = {"C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"},
							 scale[] = {"", "SECOND", "THIRD", "FOURTH", "FIFTH", "SIXTH", "SEVENTH", "OCTAVE"};
	string begin, major[12], in, dir, degree;
	const int deg[] = {0, 2, 4, 5, 7, 9, 11, 12};

	while (getline(cin, begin))
	{
		for (int index = find(note, note + 12, begin) - note, i = 0; i < 8; ++i)
			major[i] = note[(index + deg[i]) % 12];
		for (int i = 1; i < 8; ++i)
			if (major[i][0] != next(major[i - 1][0]))
				if (major[i].size() == 2)
					major[i][0] = next(major[i - 1][0]), major[i][1] = '#';
				else
					major[i][0] = next(major[i][0]), major[i].push_back('b');

		getline(cin, in);
		replace(in.begin(), in.end(), ';', ' ');
		stringstream ss(in);

		cout << "Key of " << begin << endl;
		while (ss >> begin >> dir >> degree)
		{
			int index = find(major, major + 12, begin) - major, jump = find(scale, scale + 8, degree) - scale;
			if (index == 12)
				cout << begin << ": invalid note for this key\n";
			else if (dir == "UP")
				cout << begin << ": " << dir << ' ' << degree << " > " << major[(index + jump) % 7] << endl;
			else
				cout << begin << ": " << dir << ' ' << degree << " > " << major[(index - jump + 7) % 7] << endl;
		}
		cout << endl;
	}
}
