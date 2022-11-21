#include <bits/stdc++.h>
using namespace std;
vector<pair<char,string>> ch = {
{'a',"TAACCG"},{'p',"TAAGGC"},{'e',"ATCACG"},
{'y',"ATGAGC"},{'g',"ATGGAG"},{'k',"TACCAC"},
{'b',"ATCCGT"},{'v',"ATGCCA"},{'r',"TAGCGA"},
{'t',"TAGGCT"},{'w',"ACATCG"},{'n',"ACTTGC"},
{'m',"TCTACG"},{'l',"ACACAC"},{'i',"ACTCTG"},
{'j',"TCAGAG"},{'x',"ACAGGT"},{'f',"ACTGCA"},
{'s',"AGACCT"},{'h',"TCTCGT"},{'c',"TCGAAC"},
{'o',"ACGACT"},{'z',"CATTCG"},{'q',"CTACAG"},
{'d',"CAACGT"},{'u',"CAGACA"}};

vector<pair<char,string>> pun = {
{'@',"TAACCG"},{')',"TAAGGC"},{'.',"ATCACG"},
{',',"ATGAGC"},{'*',"ATGGAG"},{'/',"TACCAC"},
{'(',"ATCCGT"},{':',"ATGCCA"},{39,"TAGCGA"},
{'[',"TAGGCT"},{';',"ACATCG"},{']',"ACTTGC"},
{'}',"ACACAC"},{'"',"ACTCTG"},
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
    {'E', "TCTACG"}, //Enter
    {'U', "TGCATA"}, //Upper case
    {'D', "CTTGTC"}, //Digit 
    {'P', "GTATGA"}, //Punctuation
    {'S', "CGGTAT"}  //Space
};

unordered_map<char, string> book;

void setCodebook()
{
    for(int i = 0; i < ch.size(); i++)
    {
        book[ch[i].first] = ch[i].second;
    }

    for(int i = 0; i < pun.size(); i++)
    {
        book[pun[i].first] = pun[i].second;
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