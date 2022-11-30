#include<bits/stdc++.h>
#include "decodeLevel2.h"
#include "autoCorrectPackage\autoCorrectMain.h"

using namespace std;
void level3(ifstream &decodedFileLevel2) 
{
    //Level 3
    ofstream finalFile("Files/OutputLevel3.txt",ios::out | ios::trunc);
    string word = "";
    while(!decodedFileLevel2.eof())
    {
        char c;
        decodedFileLevel2.get(c);
        if(decodedFileLevel2.eof()) break;

        if(c != ' ' and punMap.find(c) == punMap.end())
        {
            word.push_back(c);
        }
        else
        {
            if(word.size())
            {
                word = spellingCorrector(word);
                finalFile << word;
                word = "";
            }
            finalFile << c;
        }
    }
    finalFile.close();
}