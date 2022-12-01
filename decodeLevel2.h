#include <bits/stdc++.h>
#include "errorGenerator.h"
#include "decode.h"

using namespace std;

void level2(ifstream &encodedFile, double errorRate, int index)
{
    if(encodedFile.is_open())
    {
        string line;
        string answer;
        char shift = 'G';
        string temp = to_string(index);
        string path = "Files/DecodedFile" + temp + ".txt";
        ofstream decodedFilelevel2(path,ios::out | ios::trunc);
        record totalErrorGenerated;
        record totalErrorCorrected;
        if(decodedFilelevel2.is_open())
        {
            while(getline(encodedFile,line))
            {
                //multiple reads of sequence
                int numberOfReads = 20;
                string reads[numberOfReads];
                int maxLen = 0, maxFreqShift = 0;
                unordered_map<char,int> shiftFreq;
                record perSeqErrorGenerated;
                record perSeqErrorCorrected;
                for(int i = 0; i < numberOfReads; i++)
                {
                    char currShift = shift;
                    string erroredLine = error(line,errorRate,perSeqErrorGenerated);
                    reads[i] = decoding(erroredLine,currShift,perSeqErrorCorrected);
                    shiftFreq[currShift]++;                        
                    if(maxLen < reads[i].size())
                    maxLen = reads[i].size();
                }
                perSeqErrorGenerated.avg(numberOfReads);
                perSeqErrorCorrected.avg(numberOfReads);

                totalErrorGenerated = totalErrorGenerated + perSeqErrorGenerated;
                totalErrorCorrected = totalErrorCorrected + perSeqErrorCorrected;
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

        cout << "-----Present Error-----"<<'\n';
        totalErrorGenerated.print();

        cout <<"\n-----Corrected Error-----\n";
        totalErrorCorrected.print();

        //cout << "\nCorrected error: " << 100*totalErrorCorrected.totalError/totalErrorGenerated.totalError<<'%'<<'\n';
        decodedFilelevel2.close();
    }
    else
    {
        cout << "Error in opening encoded file"<<endl;
        exit(1);
    }
    return;
}