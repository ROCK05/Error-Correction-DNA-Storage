#include "autocorrectImple.h"
#include <bits/stdc++.h>
using namespace std;

string toLowerString(string str);

string spellingCorrector(string word) {
		AutoCorrect AC("autoCorrectPackage/dictionary/words_alpha.txt");
		AC.setWord(toLowerString(word));
		if(!AC.checkSpelling())
		{
    		srand(time(NULL));
			bool exchanged = AC.checkExchangedLetters();
			bool missing = AC.checkMissingLetters();//, &missing2 = AC.checkMissingLetters(2), &missing3 = AC.checkMissingLetters(3);
			bool MandE = AC.checkMissingAndExtraLetters();// &MandE2 = AC.checkMissingAndExtraLetters(2), &MandE3 = AC.checkMissingAndExtraLetters(1, 2), &MandE4 = AC.checkMissingAndExtraLetters(2, 2);

			if(exchanged or missing or MandE)
			{
				return AC.ans[rand()%(AC.ans).size()];
			}
		}
	return word;
}

string toLowerString(string str){
	transform(str.begin(), str.end(), str.begin(), [](const unsigned char &ch){ return tolower(ch); });
	return str;
}
