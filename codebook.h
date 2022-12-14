#include <bits/stdc++.h>
using namespace std;
vector<pair<char,string>> chr = {
{'a',"TAACCG"},{'p',"TAAGGC"},{'e',"ATCACG"},
{'y',"ATGAGC"},{'g',"ATGGAG"},{'k',"TACCAC"},
{'b',"ATCCGT"},{'v',"ATGCCA"},{'r',"TAGCGA"},
{'t',"TAGGCT"},{'w',"ACATCG"},{'n',"ACTTGC"},
{'m',"TCTACG"},{'l',"ACACAC"},{'i',"ACTCTG"},
{'j',"TCAGAG"},{'x',"ACAGGT"},{'f',"ACTGCA"},
{'s',"AGACCT"},{'h',"TCTCGT"},{'c',"TCGAAC"},
{'o',"ACGACT"},{'z',"CATTCG"},{'q',"CTACAG"},
{'d',"CAACGT"},{'u',"CAGACA"}
};

vector<pair<char,string>> pun = {
{'@',"TAACCG"},{')',"TAAGGC"},{'.',"ATCACG"},
{',',"ATGAGC"},{'*',"ATGGAG"},{'/',"TACCAC"},
{'(',"ATCCGT"},{':',"ATGCCA"},{39,"TAGCGA"},
{'[',"TAGGCT"},{';',"ACATCG"},{']',"ACTTGC"},
{'}',"ACACAC"},{'"',"ACTCTG"},{'E',"TCTACG"}, //Enter
{'%',"TCAGAG"},{'{',"ACAGGT"},{'~',"ACTGCA"},
{'+',"AGACCT"},{'-',"TCTCGT"},{'?',"TCGAAC"},
{'!',"ACGACT"},{'&',"CATTCG"},{'=',"CTACAG"},
{'_',"CAACGT"},{'#',"CAGACA"}
};

vector<pair<char,string>> digit = {
   {'0',"AGACCT"},{'1',"TCGAAC"},{'2',"ATCACG"},
   {'3',"TAGCGA"},{'4',"TAACCG"},{'5',"ACTCTG"},
   {'6',"ACACAC"},{'7',"CAGACA"},{'8',"ATGAGC"},
   {'9',"ACTGCA"}
};

vector<pair<char,string>> shadow = {
    {'U', "TGCATA"}, //Upper case
    {'D', "CTTGTC"}, //Digit 
    {'P', "GTATGA"}, //Punctuation
    {' ', "CGGTAT"}  //Space
};

unordered_map<char, string> book;
unordered_set<char> punMap; //used for level3
void setCodebook()
{
    for(int i = 0; i < chr.size(); i++)
    {
        book[chr[i].first] = chr[i].second;
    }

    for(int i = 0; i < pun.size(); i++)
    {
        book[pun[i].first] = pun[i].second;
        if(pun[i].first != 'E')
        punMap.insert(pun[i].first);
    }

    for(int i = 0; i < shadow.size(); i++)
    {
        book[shadow[i].first] = shadow[i].second;
    }

    for(int i = 0; i < digit.size(); i++)
    {
        book[digit[i].first] = digit[i].second;
    }
}