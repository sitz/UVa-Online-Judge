#include <bits/stdc++.h>

using namespace std;

void Sub_sentence(void);
void Sub_trans_sentence(void);
void Sub_intrans_sentence(void);
void Sub_subject(void);
void Sub_object(void);
void Sub_noun_phrase(void);
void Sub_modified_noun(void);
void Sub_modifier(void);
void Sub_verb_phrase(void);
void Sub_intrans_verb_phrase(void);
void Sub_prep_phrase(void);
void Sub_noun(void);
void Sub_trans_verb(void);
void Sub_intrans_verb(void);
void Sub_article(void);
void Sub_adjective(void);
void Sub_adverb(void);
void Sub_preposition(void);
void Sub_empty(void);

int cnt = 0, word = 0;

void Sub_sentence(void)
{
	//<trans-sentence> | <intrans-sentence>
	switch ((cnt++) % 2)
	{
	case 0:
		Sub_trans_sentence();
		break;
	case 1:
		Sub_intrans_sentence();
		break;
	}
}

void Sub_trans_sentence(void)
{
	//<subject> <verb-phrase> <object> <prep-phrase>
	Sub_subject();
	Sub_verb_phrase();
	Sub_object();
	Sub_prep_phrase();
}

void Sub_intrans_sentence(void)
{
	//<subject> <intrans-verb-phrase> <prep-phrase>
	Sub_subject();
	Sub_intrans_verb_phrase();
	Sub_prep_phrase();
}

void Sub_subject(void)
{
	//<noun-phrase>
	Sub_noun_phrase();
}

void Sub_object(void)
{
	//<noun-phrase>
	Sub_noun_phrase();
}

void Sub_noun_phrase(void)
{
	//<article> <modified-noun>
	Sub_article();
	Sub_modified_noun();
}

void Sub_modified_noun(void)
{
	//<noun> | <modifier> <noun>
	switch ((cnt++) % 2)
	{
	case 0:
		Sub_noun();
		break;
	case 1:
		Sub_modifier();
		Sub_noun();
		break;
	}
}

void Sub_modifier(void)
{
	//<adjective> | <adverb> <adjective>
	switch ((cnt++) % 2)
	{
	case 0:
		Sub_adjective();
		break;
	case 1:
		Sub_adverb();
		Sub_adjective();
		break;
	}
}

void Sub_verb_phrase(void)
{
	//<trans-verb> | <adverb> <trans-verb>
	switch ((cnt++) % 2)
	{
	case 0:
		Sub_trans_verb();
		break;
	case 1:
		Sub_adverb();
		Sub_trans_verb();
		break;
	}
}

void Sub_intrans_verb_phrase(void)
{
	//<intrans-verb> | <adverb> <intrans-verb>
	switch ((cnt++) % 2)
	{
	case 0:
		Sub_intrans_verb();
		break;
	case 1:
		Sub_adverb();
		Sub_intrans_verb();
		break;
	}
}

void Sub_prep_phrase(void)
{
	//<preposition> <noun-phrase> | <empty>
	switch ((cnt++) % 2)
	{
	case 0:
		Sub_preposition();
		Sub_noun_phrase();
		break;
		//  case 1: Sub_empty(); break;
	}
}

void Sub_noun(void)
{
	if (word)
	{
		printf(" ");
	}
	else
	{
		word++;
	}
	//man | dog | fish | computer | waves
	char *out[] = {"man", "dog", "fish", "computer", "waves"};
	printf(out[(cnt++) % 5]);
}

void Sub_trans_verb(void)
{
	if (word)
	{
		printf(" ");
	}
	else
	{
		word++;
	}
	//struck | saw | bit | took
	char *out[] = {"struck", "saw", "bit", "took"};
	printf(out[(cnt++) % 4]);
}

void Sub_intrans_verb(void)
{
	if (word)
	{
		printf(" ");
	}
	else
	{
		word++;
	}
	//slept | jumped | walked | swam
	char *out[] = {"slept", "jumped", "walked", "swam"};
	printf(out[(cnt++) % 4]);
}

void Sub_article(void)
{
	if (word)
	{
		printf(" ");
	}
	else
	{
		word++;
	}
	//the | a
	char *out[] = {"the", "a"};
	printf(out[(cnt++) % 2]);
}

void Sub_adjective(void)
{
	if (word)
	{
		printf(" ");
	}
	else
	{
		word++;
	}
	//green | small | rabid | quick
	char *out[] = {"green", "small", "rabid", "quick"};
	printf(out[(cnt++) % 4]);
}

void Sub_adverb(void)
{
	if (word)
	{
		printf(" ");
	}
	else
	{
		word++;
	}
	//nearly | suddenly | restlessly
	char *out[] = {"nearly", "suddenly", "restlessly"};
	printf(out[(cnt++) % 3]);
}

void Sub_preposition(void)
{
	if (word)
	{
		printf(" ");
	}
	else
	{
		word++;
	}
	//on | over | through
	char *out[] = {"on", "over", "through"};
	printf(out[(cnt++) % 3]);
}

void Sub_empty(void)
{
}

int main()
{
	char line[32];
	char *left[] = {"sentence", "trans-sentence", "intrans-sentence",
									"subject", "object", "noun-phrase", "modified-noun", "modifier",
									"verb-phrase", "intrans-verb-phrase", "prep-phrase", "noun",
									"trans-verb", "intrans-verb", "article", "adjective", "adverb",
									"preposition", "empty"};
	void (*func[])(void) = {Sub_sentence, Sub_trans_sentence,
													Sub_intrans_sentence, Sub_subject, Sub_object, Sub_noun_phrase,
													Sub_modified_noun, Sub_modifier, Sub_verb_phrase,
													Sub_intrans_verb_phrase, Sub_prep_phrase, Sub_noun, Sub_trans_verb,
													Sub_intrans_verb, Sub_article, Sub_adjective, Sub_adverb,
													Sub_preposition, Sub_empty};
	cnt = 1;
	while (scanf("%s", line) == 1)
	{
		int i;
		for (i = 0; i < 19; i++)
			if (strcmp(line, left[i]) == 0)
			{
				break;
			}
		//  if (i==19) while(1); //debug..no
		word = 0;
		func[i]();
		printf("\n");
	}
	return 0;
}
