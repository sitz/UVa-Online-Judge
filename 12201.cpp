#include <bits/stdc++.h>

using namespace std;

bool igual(char a, char b)
{
	return (tolower(a) == tolower(b));
}

string reverso(string s)
{
	int n = s.size();
	string ret = "";
	for (int i = n - 1; i >= 0; i--)
		if ((s[i] - 'a') >= 0)
		{
			ret += s[i] + 'A' - 'a';
		}
		else
		{
			ret += s[i] - 'A' + 'a';
		}
	return ret;
}

string rota(string s, int n)
{
	string ret = s.substr(n);
	return ret + s.substr(0, n);
}

string cortapega(string s, int corte, int pega1, int pega2)
{
	//corte es la posicion de la letra siguiente a donde se hace el corte
	//[0, 1, ...., pega1, ...., corte - 1, corte, ..., pega2, ..., n-1]
	string s1 = s.substr(0, pega1);
	string s2 = s.substr(pega1 + 1, corte - 1 - pega1);
	string s3 = s.substr(corte, pega2 - corte);
	string s4 = s.substr(pega2 + 1);
	char letra = tolower(s[pega1]);
	string ret1 = s2 + letra + s1;
	string ret2 = s4 + (char)toupper(letra) + s3;
	if (s[pega1] == s[pega2])
	{
		ret2 = reverso(ret2);
	}
	return ret1 + ret2;
}

string eliminaesferas(string s)
{
	int n = s.size();
	for (int i = 0; i < n - 1; i++)
		if (s[i] != s[i + 1] && igual(s[i], s[i + 1]))
		{
			return eliminaesferas(s.substr(0, i) + s.substr(i + 2));
		}
	if (n && s[0] != s[n - 1] && igual(s[0], s[n - 1]))
	{
		return eliminaesferas(s.substr(1, n - 2));
	}
	return s;
}

int p2, toros;

string eliminap2(string s)
{
	int n = s.size();
	for (int i = 0; i < n - 1; i++)
		if (s[i] == s[i + 1])
		{
			p2++;
			return eliminap2(s.substr(0, i) + s.substr(i + 2));
		}
	if (n && (s[0] == s[n - 1]))
	{
		p2++;
		return eliminap2(s.substr(1, n - 2));
	}
	return s;
}

string eliminatoros(string s)
{
	int n = s.size();
	if (n < 4)
	{
		return s;
	}
	string aux = s + s.substr(0, 3);
	for (int i = 0; i < n; i++)
		if (aux[i] != aux[i + 2] && igual(aux[i], aux[i + 2]))
			if (aux[i + 1] != aux[i + 3] && igual(aux[i + 1], aux[i + 3]))
			{
				s = rota(s, i);
				s = s.substr(4);
				toros++;
				return eliminatoros(s);
			}
	return s;
}

string encuentrap2(string s, int &pos)
{
	//devolvere un string en el que s[0] y s[pos] son iguales, salvo si pos = -1
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
			if (s[j] == s[0])
			{
				pos = j;
				return s;
			}
		s = rota(s, 1);
	}
	pos = -1;
	return s;
}

string encuentratoros(string s, int &pos1, int &pos2, int &pos3)
{
	//s = [a.....b......A......B...]
	//     0....pos1...pos2...pos3
	int n = s.size();
	for (int k = 0; k < n; k++)
	{
		int i, j;
		for (i = 1; i < n; i++)
			if (igual(s[0], s[i]))
			{
				break;
			}
		if (s[0] != s[i])
		{
			int a['z' - 'a' + 1];
			memset(a, 0, sizeof(a));
			for (j = 1; j < i; j++)
				if (s[j] >= 'a')
				{
					a[tolower(s[j]) - 'a']++;
				}
				else
				{
					a[tolower(s[j]) - 'a']--;
				}
			for (j = i + 1; j < n; j++)
				if (s[j] <= 'Z')
				{
					a[tolower(s[j]) - 'a']++;
				}
				else
				{
					a[tolower(s[j]) - 'a']--;
				}
			char letra = 0;
			for (j = 0; j < 'z' - 'a' + 1; j++)
				if (a[j] == 2 || a[j] == -2)
				{
					letra = (char)('a' + j);
					break;
				}
			if (letra != 0)
			{
				for (j = 1; j < i; j++)
					if (igual(s[j], letra))
					{
						pos1 = j;
					}
				for (j = i + 1; j < n; j++)
					if (igual(s[j], letra))
					{
						pos3 = j;
					}
				pos2 = i;
				return s;
			}
		}
		s = rota(s, 1);
	}
	pos1 = -1;
	return s;
}

string aislap2(string s, int pos)
{
	s = cortapega(s, pos, 0, pos);
	return s;
}

string aislatoros(string s, int pos1, int pos2, int pos3)
{
	int n = s.size();
	s = rota(s, 1);
	pos1--;
	pos2--;
	pos3--;
	s = cortapega(s, pos2, pos1, pos3);
	s = rota(s, pos2 - pos1);
	s = cortapega(s, n - pos3 + pos1 - 1, n - pos3 + pos1 - 2, n - pos3 + pos1);
	return s;
}

void haz(string s)
{
	while (s != "")
	{
		s = eliminaesferas(s);
		int pos, pos1, pos2, pos3;
		s = encuentrap2(s, pos);
		if (pos != -1)
		{
			s = aislap2(s, pos);
			s = eliminap2(s);
		}
		else
		{
			s = encuentratoros(s, pos1, pos2, pos3);
			if (pos1 != -1)
			{
				s = aislatoros(s, pos1, pos2, pos3);
				s = eliminatoros(s);
			}
		}
	}
	return;
}

int main()
{
	clock_t start, finish;
	start = clock();
	while (1)
	{
		string s;
		cin >> s;
		if (s == "END")
		{
			break;
		}
		p2 = 0;
		toros = 0;
		haz(s);
		if (!p2 && !toros)
		{
			cout << "none" << endl;
		}
		else if (p2 == 0)
		{
			cout << toros << " leg";
			if (toros > 1)
			{
				cout << "s";
			}
			cout << endl;
		}
		else
		{
			int total = p2 + 2 * toros;
			cout << total << " arm";
			if (total > 1)
			{
				cout << "s";
			}
			cout << endl;
		}
	}
	finish = clock();
	return 0;
}
