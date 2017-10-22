#include <bits/stdc++.h>
#include <strstream>

using namespace std;

// @ http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
string rtrim(string str)
{
	auto it1 = find_if(str.rbegin(), str.rend(), [](char ch) { return !isspace<char>(ch, locale::classic()); });
	str.erase(it1.base(), str.end());
	return str;
}

int main()
{
	int fst = 1;
	char name[13];
	while (cin >> name)
	{
		if (!fst)
		{
			printf("\n");
		}
		fst = 0;
		char marks[4];
		unsigned nxtMark = 0, score = 0, frame = 1, ball = 0, bonus = 0, pinsUp, prevPinsUp = 10;
		ostrstream line1, line2;
		line1.setf(ios::left);
		line1 << setw(12) << name << " ";
		line2 << setw(12) << " ";
		while (cin >> pinsUp)
		{
			unsigned pinsDowned = prevPinsUp - pinsUp;
			if (bonus % 2 == 1)
			// this ball completes the scoring in some other frame
			{
				score += 10 + pinsDowned;
				line2 << setw(4) << score;
				--bonus;
			}
			if (bonus == 2)
			// the previous frame was a strike; this is ball 0
			{
				score += pinsDowned;
				bonus = 1;
			}
			marks[nxtMark++] = (pinsUp ? "-123456789"[pinsDowned] : "X/"[ball]);
			if (ball == 0 && pinsUp)
			{
				ball = 1;
			}
			else// ball == 1 || !pinsUp
			{
				if (!pinsUp)// strike or spare
				{
					bonus += 2 - ball;
				}
				else// open frame
				{
					score += 10 - pinsUp;
					line2 << setw(4) << score;
				}
				if (frame < 10)
				{
					marks[nxtMark++] = '\0';
					line1 << setw(4) << marks;
					nxtMark = 0;
				}
				ball = 0;
				pinsUp = 10;
				++frame;
			}
			prevPinsUp = pinsUp;
		}
		marks[nxtMark++] = '\0';
		line1 << setw(4) << marks;
		line1 << endl
					<< ends;
		line2 << endl
					<< ends;
		string l1 = rtrim(string(line1.str()));
		string l2 = rtrim(string(line2.str()));
		cout << l1 << endl
				 << l2 << endl;
		cin.clear();
	}
	return 0;
}
