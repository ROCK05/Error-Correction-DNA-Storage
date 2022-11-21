#include "codebook.h"

//Get string code
string getCode(char ch)
{
    string ans = "";
    
    if(ch >= 'A' and ch <= 'Z') //Upper case
        ans = book['U'] + book[tolower(ch)]; 
    else if(ch >= '0' and ch <= '9')  //Digit
        ans = book['D'] + book[ch];
    else if(ch >= 'a' and ch <= 'z') //Lower case
        ans = book[ch];
    else if(ch == ' ') //Space
        ans = book[' '];
    else //Punctuation
        ans = book['P'] + book[ch];
    
    //Note: Enter is handled in encoding function itself
    return ans;
}

//Function for Encoding text
void encoding(ifstream &input)
{
    ofstream encodedfile("Encodedfile.txt",ios::out | ios::trunc);
    char c;
    if(encodedfile.is_open())
    {
        string line;
        while(getline(input,line))
        {
            for(int i = 0; i < line.size(); i++)
            {
                encodedfile << getCode(line[i]);
            }

            //Add enter string code if it is not end of file
            if(!input.eof())
            {
                encodedfile << book['P'];
                encodedfile << book['E'];
            }
        }
    }
    encodedfile.close();
}