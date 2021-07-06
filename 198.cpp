#include <bits/stdc++.h>

using namespace std;

string order[100];
string var[100];
bool used[100];
bool undef;
int loc1;

void printvar(const int &num);
int getvalue(string varname);
int getexp(string exp);

void printvar(const int &num)
{
	for (int i = 0; i < 100; i++)
	{
		used[i] = false;
	}
	undef = false;
	int result;
	result = getvalue(var[num]);
	if (undef)
	{
		cout << "UNDEF" << endl;
		return;
	}
	cout << result << endl;
	return;
}
int getvalue(string varname)
{
	while (true)
	{
		if (varname[0] == ' ')
		{
			varname = varname.substr(1);
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		if (varname[varname.size() - 1] == ' ')
		{
			varname = varname.substr(0, varname.size() - 1);
		}
		else
		{
			break;
		}
	}
	bool num = true;
	for (int i = 0; i < varname.size(); i++)
	{
		if (varname[i] >= '0' && varname[i] <= '9')
		{
			continue;
		}
		else
		{
			num = false;
			break;
		}
	}
	if (num)
	{
		int number = 0;
		for (int i = 0; i < varname.size(); i++)
		{
			number *= 10;
			number += varname[i] - '0';
		}
		return number;
	}
	int locvar = 101;
	for (int i = 0; i < loc1; ++i)
		if (varname == var[i])
		{
			locvar = i;
			break;
		}
	if (locvar == 101)
	{
		undef = true;
		return 0;
	}
	else
	{
		if (used[locvar] == true)
		{
			undef = true;
			return 0;
		}
		else
		{
			used[locvar] = true;
			int result = getexp(order[locvar]);
			used[locvar] = false;
			return result;
		}
	}
}
int getexp(string exp)
{
	while (true)
	{
		if (exp.size() > 0 && exp[0] == ' ')
		{
			exp = exp.substr(1);
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		if (exp.size() > 0 && exp[exp.size() - 1] == ' ')
		{
			exp = exp.substr(0, exp.size() - 1);
		}
		else
		{
			break;
		}
	}
	if (exp == "")
	{
		return 0;
	}
	int sit;
	int zkh[100], ykh[100];
	int khzs = 0, khjs = 0;
	bool khcz;
	khcz = false;
	for (int i = 0; i < exp.size(); i++)
	{
		if (exp[i] == '(')
		{
			khcz = true;
			khjs++;
			if (khjs == 1)
			{
				zkh[khzs] = i;
			}
		}
		else if (exp[i] == ')')
		{
			if (khjs == 1)
			{
				ykh[khzs] = i;
				khzs++;
			}
			khjs--;
		}
	}
	sit = exp.size();
	while ((sit = exp.rfind('+', sit - 1)) > 0)
	{
		int check = sit - 1;
		bool valid = true;
		for (; check >= 0; check--)
		{
			if (exp[check] == '+' || exp[check] == '-' || exp[check] == '*')
			{
				valid = false;
				break;
			}
			else if (exp[check] == ' ')
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if (valid)
		{
			if (!khcz)
			{
				int result = getexp(exp.substr(0, sit)) + getexp(exp.substr(sit + 1));
				return result;
			}
			else
			{
				bool ok = true;
				for (int i = 0; i < khzs; i++)
					if (sit > zkh[i] && sit < ykh[i])
					{
						ok = false;
						break;
					}
				if (ok)
				{
					int result = getexp(exp.substr(0, sit)) + getexp(exp.substr(sit + 1));
					return result;
				}
			}
		}
	}
	sit = exp.size();
	while ((sit = exp.rfind('-', sit - 1)) > 0)
	{
		int check = sit - 1;
		bool valid = true;
		for (; check >= 0; check--)
		{
			if (exp[check] == '+' || exp[check] == '-' || exp[check] == '*')
			{
				valid = false;
				break;
			}
			else if (exp[check] == ' ')
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if (valid)
		{
			if (!khcz)
			{
				int result = getexp(exp.substr(0, sit)) - getexp(exp.substr(sit + 1));
				return result;
			}
			else
			{
				bool ok = true;
				for (int i = 0; i < khzs; i++)
					if (sit > zkh[i] && sit < ykh[i])
					{
						ok = false;
						break;
					}
				if (ok)
				{
					int result = getexp(exp.substr(0, sit)) - getexp(exp.substr(sit + 1));
					return result;
				}
			}
		}
	}
	sit = exp.size();
	while ((sit = exp.rfind('*', sit - 1)) > 0)
	{
		if (!khcz)
		{
			int result = getexp(exp.substr(0, sit)) * getexp(exp.substr(sit + 1));
			return result;
		}
		else
		{
			bool ok = true;
			for (int i = 0; i < khzs; i++)
				if (sit > zkh[i] && sit < ykh[i])
				{
					ok = false;
					break;
				}
			if (ok)
			{
				int result = getexp(exp.substr(0, sit)) * getexp(exp.substr(sit + 1));
				return result;
			}
		}
	}
	sit = exp.find('+');
	if (sit == 0)
	{
		int result = getexp(exp.substr(1));
		return result;
	}
	sit = exp.find('-');
	if (sit == 0)
	{
		int result = -1 * getexp(exp.substr(1));
		return result;
	}
	if (khcz)
	{
		int result = getexp(exp.substr(1, exp.size() - 2));
		return result;
	}
	int result = getvalue(exp);
	return result;
}
int main()
{
	string now;
	now = " ";
	loc1 = 0;
	while (getline(cin, now, '\n'))
	{
		while (true)
		{
			if (now.size() > 0 && now[0] == ' ')
			{
				now = now.substr(1);
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			if (now.size() > 0 && now[now.size() - 1] == ' ')
			{
				now = now.substr(0, now.size() - 1);
			}
			else
			{
				break;
			}
		}
		if (int(now.find(':')) >= 0)
		{
			string temp = now.substr(0, int(now.find(':')));
			while (true)
			{
				if (temp.size() > 0 && temp[temp.size() - 1] == ' ')
				{
					temp = temp.substr(0, temp.size() - 1);
				}
				else
				{
					break;
				}
			}
			int i = 101;
			for (int j = 0; j < loc1; j++)
			{
				if (var[j] == temp)
				{
					i = j;
					break;
				}
			}
			if (i == 101)
			{
				var[loc1] = temp;
				order[loc1] = now.substr(int(now.find('=')) + 1);
				loc1++;
			}
			else
			{
				var[i] = temp;
				order[i] = now.substr(int(now.find('=')) + 1);
			}
		}
		else
		{
			if (int(now.find("PRINT")) >= 0)
			{
				string temp = now.substr(6);
				while (true)
				{
					if (temp[0] == ' ')
					{
						temp = temp.substr(1);
					}
					else
					{
						break;
					}
				}
				int i = 101;
				for (int j = 0; j < loc1; j++)
					if (var[j] == temp)
					{
						i = j;
						break;
					}
				if (i == 101)
				{
					cout << "UNDEF" << endl;
				}
				else
				{
					printvar(i);
				}
				continue;
			}
			else if (int(now.find("RESET")) >= 0)
			{
				loc1 = 0;
			}
		}
	}
}
