#include <bits/stdc++.h> 
#include "records.h"
using namespace std;

string error(string &encoded, double errorRate, record &obj)
{
    /* Initialize random seed */
    srand(time(NULL));

    string answer = "";
    int errorCount = 0;
    int totalChar = 0;
    int inError = 0, subError = 0, delError = 0;
    int noOfErrors = 100 * errorRate;


    int j = 0;
    while(j < encoded.size())
    {
        int temp = noOfErrors;
        for(int i = 0; i < 102 and j < encoded.size();i++)
        {
            char c;
            int numOfErrorInBase = 1;
            for(int k = 0; k < 6 and j < encoded.size(); k++)
            {
                c = encoded[j++];
                totalChar++;
                if(rand() % 100 == 0 and temp and numOfErrorInBase)
                {
                    //Generate type of error 
                    //1 -> Substituion 2 -> Insertion 3 -> Deletion
                    int num = rand() % 3 + 1;
                    if(num == 1) //Substitute
                    {
                        string str;
                        
                        if(c == 'A')
                        str = "CGT";
                        else if(c == 'C')
                        str = "AGT";
                        else if(c == 'G')
                        str = "ACT";
                        else
                        str = "ACG";

                        char subChar = str[rand() % 3];
                        answer.push_back(subChar);
                        subError++;
                    }
                    else if(num == 2) //Insertion
                    {
                        string str = "ACGT";
                        answer.push_back(str[rand() % 4]);
                        answer.push_back(c);
                        inError++;
                    }
                    else //Deletion
                    {
                        //No need to write char
                        delError++;
                    }
                    temp--;
                    errorCount++;
                    numOfErrorInBase--;
                } 
                else
                {
                    //Write char to errored string
                    answer.push_back(c);
                }
            }
        }
    }
    
    obj.insError += inError;
    obj.delError += delError;
    obj.subError += subError;
    obj.totalError += errorCount;

    return answer;

}