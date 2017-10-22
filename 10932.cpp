#include <bits/stdc++.h>

using namespace std;

double table[30];			 // data as 'a'...'z'
char expression[10000];// input string
char opt[10000];			 // stack of operator
double data[10000];		 // stack of number
int Nopt, Ndata, Lexpr;
// used by question()
void calculate()
{
	Nopt--;
	Ndata--;
	switch (opt[Nopt])
	{
	case '+':
		if (Nopt > 0 && opt[Nopt - 1] == '-')
		{
			data[Ndata - 1] -= data[Ndata];
		}
		else
		{
			data[Ndata - 1] += data[Ndata];
		}
		break;
	case '-':
		if (Nopt > 0 && opt[Nopt - 1] == '-')
		{
			data[Ndata - 1] += data[Ndata];
		}
		else
		{
			data[Ndata - 1] -= data[Ndata];
		}
		break;
	case '*':
		data[Ndata - 1] *= data[Ndata];
		break;
	case '/':
		// Notice data[Ndata] == 0, but in this problem ignored
		data[Ndata - 1] /= data[Ndata];
		break;
	default:
		printf("error in calculate()\n");
		break;
	}
}
// calculate the expression
double question(char *expr)
{
	int Pexpr = 0;
	Lexpr = strlen(expr);
	Ndata = Nopt = 0;
	while (Pexpr < Lexpr)
	{
		switch (expr[Pexpr])
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
			opt[Nopt++] = expr[Pexpr++];
			break;
		case ')':
			Pexpr++;
			while (opt[Nopt - 1] != '(')
			{
				calculate();
			}
			Nopt--;
			while (opt > 0 && (opt[Nopt - 1] == '*' || opt[Nopt - 1] == '/'))
			{
				calculate();
			}
			break;
		default:
			if (expr[Pexpr] >= '0' && expr[Pexpr] <= '9')
			{
				double integer = 0;
				while (expr[Pexpr] >= '0' && expr[Pexpr] <= '9')
				{
					integer *= 10, integer += expr[Pexpr] - '0', Pexpr++;
				}
				data[Ndata++] = integer;
			}
			else if (expr[Pexpr] >= 'a' && expr[Pexpr] <= 'z')
			{
				data[Ndata++] = table[expr[Pexpr] - 'a'];
				Pexpr++;
			}
			else
			{
				printf("error in question()\n");
			}
			while (opt > 0 && (opt[Nopt - 1] == '*' || opt[Nopt - 1] == '/'))
			{
				calculate();
			}
			break;
		}
	}
	while (Nopt > 0)
	{
		calculate();
	}
	return data[0];
}
void attribution(char *expr)
{
	//  calculate X (expr[0]-'a') through question()
	table[expr[0] - 'a'] = question(expr + 2);
}
int main()
{
	for (int i = 0; i < 26; i++)
	{
		data[i] = 0;
	}
	while (gets(expression))
	{
		Lexpr = strlen(expression);
		if (Lexpr == 0)
		{
			continue;
		}
		if (expression[1] == '=')// expression is a attribution
		{
			attribution(expression);
		}
		else//            is a question
		{
			printf("%.2lf\n", question(expression));
		}
	}
	return 0;
}
