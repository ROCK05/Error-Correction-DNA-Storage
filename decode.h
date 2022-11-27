#include <bits/stdc++.h>
#include "encode.h"
using namespace std;

int hamming(string s, char &ch, char shift)
{
    int mini = 10;
    vector<pair<char,string>> checkFrom;
    if(shift == 'D')
    {
        checkFrom = digit;
    }
    else if(shift == 'U')
    {
        checkFrom = chr;
    }
    else if(shift == 'P')
    {
        checkFrom = pun;
    }
    else //lower case, upper case, shadow
    {
        checkFrom = chr;
        for(int i = 0; i < shadow.size(); i++)
        checkFrom.push_back({shadow[i].first,shadow[i].second});
    }

    for(auto &i : checkFrom)
    {
        string s1 = i.second;
        int dis = 0;
        for(int j = 0; j < 6 and j < s.size(); j++)
        {
            if(s[j] != s1[j])
                dis++;
        }   
        if(dis < mini)
        {
            mini = dis;
            ch = i.first;
        }
        if(mini == 0)
        break;
    }
    return mini + (6 - s.size());
}

int kHammingSum(string s, int k)
{
    int sum = 0;
    int count = 0;
    int i = 0;
    while(i < s.size() and count < k)
    {
        char temp;
        if(s.size() - i < 6)
        sum += hamming(s.substr(i),temp,'G');
        else
        sum += hamming(s.substr(i,6),temp,'G');

        count++;
        i+=6;
    }
    return sum;
}

string errorType(string &slices, int k)
{
    //Calculate sum of hamming distance of k-1 subsequent slices before detecting the error
    int eH = kHammingSum(slices.substr(6),k-1);

    //Insertion error
    /*
    If insertion is there in slice, so to detect it we need to delete single char from 
    the first slice so first character of next slice will become part of first slice 
    So, now calculate hamming distance of k-1 - Subsequent slices which will start from
    index = 7 beacuse we considered one char is deleted from first slice and character 
    at index 6th became part of first slice
    */
    int insertionHamming = kHammingSum(slices.substr(7),k-1);

    //Deletion error
    /*
    If deletion is there in slice, so to detect it we need to add single char to 
    the first slice so last character of first slice will become part of second slice 
    So, now calculate hamming distance of k-1 - Subsequent slices which will start from
    index = 5 beacuse we considered one char is inserted to first slice and character 
    at index 5th became part of second slice
    */
    int deletionHammnig = kHammingSum(slices.substr(5),k-1);

   //Substitution error
   /*
   For substitution error sum of hamming distance remains same as eH
   */

  //Delta for all errors
  int deltaInsertion = insertionHamming - eH;
  int deltaDeletion = deletionHammnig - eH;
  int deltaSubstitution = 0; //No change in hamming distance

//   cout << "deltaInsertion " <<deltaInsertion<<endl;
//   cout << "deltaDeletion " << deltaDeletion <<endl;

  int minimumDelta = min({deltaInsertion,deltaDeletion,deltaSubstitution});

  if(minimumDelta == deltaSubstitution)
  return "Substitution";
  else if(minimumDelta == deltaInsertion)
  return "Insertion";
  else //minimumDelta == deltaDeletion)
  return "Deletion";
}

char correctError(string slice, string errortype, char shift)
{
    vector<char> arr{'A','C','G','T'};
    char decodedChar;
    int mini = 10;
    if(errortype == "Substitution")
    {
        for(int j = 0; j < 4; j++)
        {
            for(int i = 0; i < slice.size(); i++)
            {
                char temp = slice[i];
                slice[i] = arr[j];
                char ch;
                int distance = hamming(slice,ch,shift);
                slice[i] = temp;
                if(distance < mini)
                {
                    mini = distance;
                    decodedChar = ch;
                }
                if(mini == 0)
                return decodedChar;
            }
        }
    }
    else if(errortype == "Insertion")
    {
        for(int i = 0; i < slice.size(); i++)
        {
            string p1 = slice.substr(0,i);
            string p2 = slice.substr(i+1);
            char ch;
            int distance = hamming(p1+p2,ch,shift);
            if(distance < mini)
            {
                mini = distance;
                decodedChar = ch;
            }
            if(mini == 0)
            return decodedChar;
        }
    }
    else  //Deletion
    {
        for(int j = 0; j < 4; j++)
        {
            for(int i = 0; i < slice.size(); i++)
            {
                string p1 = slice.substr(0,i);
                p1.push_back(arr[j]);
                string p2 = slice.substr(i);
                char ch;
                int distance = hamming(p1+p2,ch,shift);
                if(distance < mini)
                {
                    mini = distance;
                    decodedChar = ch;
                }
                if(mini == 0)
                return decodedChar;
            }
        }
    }
    return decodedChar;
}

string decoding(string &input, char &shift)
{
    string answer = "";

   // ofstream decodedFile("DecodedFile.txt",ios::out | ios::trunc);
    //if(decodedFile.is_open())
    {
        //reading first k=10 slices
        string slices = "";
        int k = 10;
        char c;
        int index = 0;
        for(int i = 0; i < 6*k and index < input.size(); i++)
        {
            c = input[index++];
            //input.get(c);
            //if(input.eof()) break;
            slices.push_back(c);
        }
        //cout << slices << " ";

        //char shift = 'G';
        while(true)
        {
            char decodedChar;
            //last slice
            if(slices.size() <= 6)
                break;     //Break of while

            //Calculate hamming distance of single slices
            int distance = hamming(slices.substr(0,6), decodedChar, shift);
            if(distance != 0) //Error slice
            {
                //Detect type of error
                string errortype = errorType(slices,k);
                string errorSlice;
                if(errortype == "Insertion")
                {
                    errorSlice = slices.substr(0,7); //7 characters
                    slices = slices.substr(7);//7th Index
                } 
                else if(errortype == "Deletion")
                {
                    errorSlice = slices.substr(0,5); //5 characters
                    slices = slices.substr(5); //5th Index
                }
                else //errortype == "Substitution"
                {
                    errorSlice = slices.substr(0,6); //6 charcters
                    slices = slices.substr(6); //6th Index
                }

                //Update decoded character
                decodedChar = correctError(errorSlice,errortype,shift);
            }

            //Remove 1st slice from string
            if(distance == 0)
            slices = slices.substr(6);

            //Append decoded character to file 
            if(decodedChar == 'U' or decodedChar == 'D' or decodedChar == 'P')
            {
                shift = decodedChar;
            }
            else
            {
                if(decodedChar == 'E')
                answer.push_back('$'); //used $ for detecting new line
                else
                {
                    if(shift == 'U')
                    decodedChar = toupper(decodedChar);
                    
                    //decodedFile << decodedChar;
                    answer.push_back(decodedChar);
                }
                shift = 'G';
            }

            //Add next slice to the end of string
            for(int j = 0; j < 6 and index < input.size(); j++)
            {
                c = input[index++];
                slices.push_back(c);
                // input.get(c);
                // if(input.eof()) break;
                // slices.push_back(c);

            }
        }

        if(slices.size() <= 6 and slices.size() != 0)
        {
            char decodedChar;
            hamming(slices,decodedChar,shift);
            // cout << " "<<decodedChar<<" ";

            if(decodedChar == 'U' or decodedChar == 'D' or decodedChar == 'P')
            {
                shift = decodedChar;
            }
            else
            {
                if(decodedChar == 'E')
                answer.push_back('$');            //decodedFile << endl;
                else
                {
                    if(shift == 'U')
                    decodedChar = toupper(decodedChar);
                    
                    answer.push_back(decodedChar);//decodedFile << decodedChar;
                }
                shift = 'G';
            }
        }
    }
    return answer;
}