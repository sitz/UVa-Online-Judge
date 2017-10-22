#include <bits/stdc++.h>

using namespace std;

struct TERM
{
	int cof;
	int xe;
	int ye;
	TERM(int c, int x, int y) : cof(c), xe(x), ye(y) {}
};

bool GreaterTerm(const TERM &t1, const TERM &t2)
{
	return (t1.xe > t2.xe || (t1.xe == t2.xe && t1.ye < t2.ye));
}

void ParsePolynomial(char *pStr, vector<TERM> &Terms)
{
	for (int nNum; *pStr != 0;)
	{
		TERM Term(*pStr == '-' ? -1 : 1, 0, 0);
		pStr += (*pStr == '-' || *pStr == '+') ? 1 : 0;
		if (*pStr == '0')
		{
			for (++pStr; *pStr != '\0' && *pStr != '+' && *pStr != '-'; ++pStr)
				;
			continue;
		}
		for (nNum = 0; isdigit(*pStr); nNum = nNum * 10 + *pStr++ - '0')
			;
		for (Term.cof *= (nNum == 0) ? 1 : nNum; isalpha(*pStr);)
		{
			int *pe = (*pStr == 'x') ? &Term.xe : &Term.ye;
			for (; isdigit(*++pStr); *pe = *pe * 10 + *pStr - '0')
				;
			*pe = (*pe == 0) ? 1 : *pe;
		}
		Terms.push_back(Term);
	}
}

int main()
{
	for (string str1, str2; cin >> str1 && str1 != "#";)
	{
		cin >> str2;
		if (str1.empty() || str2.empty())
		{
			continue;
		}
		const int nMaxLen = 100;
		char szBuf1[nMaxLen], szBuf2[nMaxLen];
		vector<TERM> Poly1, Poly2, Result;
		strcpy(szBuf1, str1.c_str());
		strcpy(szBuf2, str2.c_str());
		ParsePolynomial(szBuf1, Poly1);
		ParsePolynomial(szBuf2, Poly2);
		vector<TERM>::iterator i, j;
		for (i = Poly1.begin(); i != Poly1.end(); ++i)
		{
			for (j = Poly2.begin(); j != Poly2.end(); ++j)
			{
				TERM Term(i->cof * j->cof, i->xe + j->xe, i->ye + j->ye);
				Result.push_back(Term);
			}
		}
		sort(Result.begin(), Result.end(), GreaterTerm);
		fill(&szBuf1[0], &szBuf1[nMaxLen], ' ');
		fill(&szBuf2[0], &szBuf2[nMaxLen], ' ');
		int nPos = 0;
		for (i = Result.begin(); i != Result.end(); ++i)
		{
			for (j = i + 1; j < Result.end() &&
											i->xe == j->xe && i->ye == j->ye;)
			{
				i->cof += j->cof;
				j = Result.erase(j);
			}
			if (i->cof != 0)
			{
				if (nPos > 0)
				{
					++nPos;
					szBuf2[nPos++] = i->cof > 0 ? '+' : '-';
					szBuf2[nPos++] = ' ';
				}
				else
				{
					szBuf2[0] = '-';
					nPos += (i->cof < 0);
				}
				i->cof = abs(i->cof);
				if (i->cof != 1 || (i->xe == 0 && i->ye == 0))
				{
					nPos += sprintf(&szBuf2[nPos], "%d", i->cof);
					szBuf2[nPos] = ' ';
				}
				if (i->xe > 0)
				{
					szBuf2[nPos++] = 'x';
					if (i->xe > 1)
					{
						nPos += sprintf(&szBuf1[nPos], "%d", i->xe);
						szBuf1[nPos] = ' ';
					}
				}
				if (i->ye > 0)
				{
					szBuf2[nPos++] = 'y';
					if (i->ye > 1)
					{
						nPos += sprintf(&szBuf1[nPos], "%d", i->ye);
						szBuf1[nPos] = ' ';
					}
				}
			}
		}
		if (nPos == 0)
		{
			szBuf2[nPos++] = '0';
		}
		szBuf1[nPos] = szBuf2[nPos] = '\0';
		cout << szBuf1 << '\n'
				 << szBuf2 << endl;
	}
	return 0;
}
