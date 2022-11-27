#include <bits/stdc++.h>
#include "errorGenerator.h"
#include "decode.h"

using namespace std;

void level2(ifstream &encodedFile, double errorRate)
{
    if(encodedFile.is_open())
    {
        string line;
        string answer;
        char shift = 'G';
        ofstream decodedFilelevel2("DecodedFileLevel2.txt",ios::out | ios::trunc);
        if(decodedFilelevel2.is_open())
        {
            while(getline(encodedFile,line))
            {
                //multiple reads of sequence
                int numberOfReads = 20;
                string reads[numberOfReads];
                int maxLen = 0, maxFreqShift = 0;
                unordered_map<char,int> shiftFreq;
                for(int i = 0; i < numberOfReads; i++)
                {
                    char currShift = shift;
                    string erroredLine = error(line,errorRate);
                    reads[i] = decoding(erroredLine,currShift);
                    
                    shiftFreq[currShift]++;                        
                    if(maxLen < reads[i].size())
                    maxLen = reads[i].size();
                }

                //Making length same of all alignment
                for(int i = 0; i < numberOfReads; i++)
                {
                    while(reads[i].size() != maxLen)
                    {
                        reads[i].push_back('>');
                    }
                }
                
                //alignment of read
                string answer = "";
                for(int j = 0; j < maxLen; j++)
                {
                    unordered_map<char,int> m; //key = character --- value = frequency
                    int maxi = 0;
                    char decodedChar;
                    for(int i = 0; i < numberOfReads; i++)
                    {
                        m[reads[i][j]]++;
                        if(m[reads[i][j]] > maxi)
                        {
                            maxi =  m[reads[i][j]];
                            decodedChar = reads[i][j];
                        }
                    }
                    answer.push_back(decodedChar);
                }

                //Appending final string in file
                for(int i = 0; i < answer.size() and answer[i] != '>'; i++)
                {
                    if(answer[i] == '$')
                    decodedFilelevel2 << endl;
                    else
                    decodedFilelevel2 << answer[i];
                }

                //detecting shift for next sequence
                for(auto &i : shiftFreq)
                {
                    if(maxFreqShift < i.second)
                    {
                        maxFreqShift = i.second;
                        shift = i.first;
                    }
                }

            }
        }
        decodedFilelevel2.close();
    }
    else
    {
        cout << "Error in opening encoded file"<<endl;
    }
    return;
}