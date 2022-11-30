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
    ofstream encodedfile("Files/EncodedFile.txt",ios::out | ios::trunc);
    char c;
    int totalCharInInput = 0;
    if(encodedfile.is_open())
    {
        string line;
        string str = "";
        while(getline(input,line))
        {
            int i;
            for(int i = 0; i < line.size(); i++)
            {
                if(line[i] < 'A' and line [i] > 'Z' and book.find(line[i]) == book.end())
                {
                    std::cout << "'"<<line[i]<<"'" << " can not be encoded"<<endl;
                    exit(1);
                }
                str += getCode(line[i]);
                if(str.size() >= 180)
                {
                    encodedfile << str.substr(0,180);
                    encodedfile << endl;
                    if(str.size() > 180)
                    str = str.substr(180);
                    else
                    str = "";
                }
                totalCharInInput++;
            }
            
            //Add 'ENTER' string code if it is not end of file
            if(!input.eof())
            {
                if(input.eof())
                break;
                str += book['P'];
                if(str.size() == 180)
                {
                    encodedfile << str;
                    encodedfile <<endl;
                    str = "";
                }
                str += book['E'];
                if(str.size() == 180)
                {
                    encodedfile << str;
                    encodedfile << endl;
                    str = "";
                }
            }
        }

        if(str.size() != 0)
        {
            encodedfile << str;
            str = "";
        }
    }
    encodedfile.close();
}