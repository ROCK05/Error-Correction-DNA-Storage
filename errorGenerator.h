#include <bits/stdc++.h> 
using namespace std;
//void error(ifstream &encodedFile, double errorRate)
string error(string &encoded, double errorRate)
{
    /* Initialize random seed */
    srand(time(NULL));

    int errorsPer100char = 100 * errorRate;
    //cout << errorsPer100char<<endl;
   //ofstream erroredFile("ErroredFile.txt",ios::out | ios::trunc);
    string answer ="";
    int errorCount = 0;
    int totalChar = 0;
    int inError = 0, subError = 0, delError = 0;
    //if(erroredFile.is_open())
    {
        //while(!encodedFile.eof())
        int j = 0;
        while(j < encoded.size())
        {
            int temp = errorsPer100char;
            for(int i = 0; i < 100 and j < encoded.size();i++)
            {
                char c;
                //int numOfErrorInBase = 1;
                //for(int j = 0; j < 6 and i < 102 and !encodedFile.eof(); j++, i++)
                {
                    //Read char from encoded file
                    //c = encodedFile.get();
                     c = encoded[j++];
                    // if(encodedFile.eof())
                    // break;
                    totalChar++;
                    if(rand() % 100 == 0 and temp)// and numOfErrorInBase)
                    {
                        //cout << "HELLO";
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
                            //erroredFile << subChar;
                            subError++;
                        }
                        else if(num == 2) //Insertion
                        {
                            string str = "ACGT";
                            // erroredFile << str[rand() % 4];
                            // erroredFile << c;
                            answer.push_back(str[rand() % 4]);
                            answer.push_back(c);
                            inError++;
                        }
                        else //Deletion
                        {
                            //No need to write char to erroredFile
                            delError++;
                        }
                        temp--;
                        //numOfErrorInBase--;
                        errorCount++;
                    } 
                    else
                    {
                        //Write char to errored file
                        //erroredFile << c;
                        answer.push_back(c);
                    }
                }
            }
        }
    }
    
    //erroredFile.close();
    cout << totalChar << " " << errorCount <<endl;
    cout << "InsertionError " << inError<<endl;
    cout << "DeletionError " << delError << endl;
    cout << "SubError " << subError <<endl;

    return answer;

}