#include <bits/stdc++.h>

using namespace std;

char *strrev(char *str)
{
	char *p1, *p2;
	if (!str || !*str)
	{
		return str;
	}
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
	{
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return str;
}
void codon2protein(char *codon)
{
	switch (codon[0])
	{
	case 'T':
		switch (codon[1])
		{
		case 'T':
			switch (codon[2])
			{
			case 'T':
				cout << "Phe";
				break;
			case 'C':
				cout << "Phe";
				break;
			case 'A':
				cout << "Leu";
				break;
			case 'G':
				cout << "Leu";
			}
			break;
		case 'C':
			cout << "Ser";
			break;
		case 'A':
			switch (codon[2])
			{
			case 'T':
				cout << "Tyr";
				break;
			case 'C':
				cout << "Tyr";
			}
			break;
		case 'G':
			switch (codon[2])
			{
			case 'T':
				cout << "Cys";
				break;
			case 'C':
				cout << "Cys";
				break;
			case 'G':
				cout << "Trp";
			}
		}
		break;
	case 'C':
		switch (codon[1])
		{
		case 'T':
			cout << "Leu";
			break;
		case 'C':
			cout << "Pro";
			break;
		case 'A':
			switch (codon[2])
			{
			case 'T':
				cout << "His";
				break;
			case 'C':
				cout << "His";
				break;
			case 'A':
				cout << "Gln";
				break;
			case 'G':
				cout << "Gln";
			}
			break;
		case 'G':
			cout << "Arg";
			break;
		}
		break;
	case 'A':
		switch (codon[1])
		{
		case 'T':
			switch (codon[2])
			{
			case 'G':
				cout << "Met";
				break;
			default:
				cout << "Ile";
			}
			break;
		case 'C':
			cout << "Thr";
			break;
		case 'A':
			switch (codon[2])
			{
			case 'T':
				cout << "Asn";
				break;
			case 'C':
				cout << "Asn";
				break;
			case 'A':
				cout << "Lys";
				break;
			case 'G':
				cout << "Lys";
			}
			break;
		case 'G':
			switch (codon[2])
			{
			case 'T':
				cout << "Ser";
				break;
			case 'C':
				cout << "Ser";
				break;
			case 'A':
				cout << "Arg";
				break;
			case 'G':
				cout << "Arg";
			}
		}
		break;
	case 'G':
		switch (codon[1])
		{
		case 'T':
			cout << "Val";
			break;
		case 'C':
			cout << "Ala";
			break;
		case 'A':
			switch (codon[2])
			{
			case 'T':
				cout << "Asp";
				break;
			case 'C':
				cout << "Asp";
				break;
			case 'A':
				cout << "Glu";
				break;
			case 'G':
				cout << "Glu";
			}
			break;
		case 'G':
			cout << "Gly";
			break;
		}
	}
}
void transcodes(char *dna, int codes)
{
	for (int i = 0; i < codes; i++)
	{
		char codon[4];
		strncpy(codon, dna + 3 * i, 3);
		codon[3] = '\0';
		codon2protein(codon);
		if (i < codes - 1)
		{
			cout << '-';
		}
	};
	cout << endl;
}
char *terminator(char *start)
{
	for (int i = 6; i < (int)strlen(start) - 2; i += 3)
		if (start[i] == 'T')
			switch (start[i + 1])
			{
			case 'A':
				if (start[i + 2] == 'A' || start[i + 2] == 'G')
				{
					return start + i;
				}
				break;
			case 'G':
				if (start[i + 2] == 'A')
				{
					return start + i;
				}
			}
	return NULL;
}
int translate(char *dna)
{
	char *start = strstr(dna, "ATG");
	while (start != NULL)
	{
		char *end = terminator(start);
		if (end != NULL)
		{
			transcodes(start + 3, (end - start - 3) / 3);
			return 1;
		}
		else
		{
			start = strstr(start + 1, "ATG");
		}
	}
	return 0;
}
void complement(char *dna)
{
	for (int i = 0; i < (int)strlen(dna); i++)
		switch (dna[i])
		{
		case 'A':
			dna[i] = 'T';
			break;
		case 'C':
			dna[i] = 'G';
			break;
		case 'G':
			dna[i] = 'C';
			break;
		case 'T':
			dna[i] = 'A';
		}
}
int main()
{
	char dna[256];
	while (true)
	{
		scanf("%s", dna);
		if (strcmp(dna, "*") == 0)
		{
			break;
		}
		int r1 = translate(dna);
		if (!r1)
		{
			int r2 = translate(strrev(dna));
			if (!r2)
			{
				complement(dna);
				int r3 = translate(dna);
				if (!r3)
				{
					int r4 = translate(strrev(dna));
					if (!r4)
					{
						printf("*** No translatable DNA found ***\n");
					}
				}
			}
		}
	}
	return 0;
}
