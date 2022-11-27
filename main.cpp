#include <bits/stdc++.h>
#include "decodeLevel2.h"
// #include <D:\DNAproject\vcpkg\packages\hunspell_x86-windows\include\hunspell.cxx>
using namespace std;
int main()
{
    setCodebook();
    ifstream inputFile("D:/DNAproject/tempInput.txt");
    if(inputFile)
    {
        encoding(inputFile);
    }
    else //error
    {
        cout << "Error in opening Input file";
    }
    inputFile.close();

     ifstream encodedFile("D:/DNAproject/Encodedfile.txt");
     //error(encodedFile, 0.01);
     
     level2(encodedFile, 0.05);
     encodedFile.close();
     
    // ifstream erroredFile("D:/DNAproject/ErroredFile.txt");
    // decoding(erroredFile);
    // erroredFile.close();

    // ifstream finalInput("D:/DNAproject/Encodefile.txt");
    // ifstream finalOutput("D:/DNAproject/EncodedfileTemp.txt");

    // int wrong = 0;
    // char in,out;
    // while(!finalInput.eof() and !finalOutput.eof())
    // {
    //     finalInput.get(in);
    //     finalOutput.get(out);

    //     if(finalInput.eof() or finalOutput.eof())
    //     break;
    //     if(in != out)
    //     wrong++;
    // }

    // while(!finalInput.eof())
    // {
    //     finalInput.get(in);
    //     if(finalInput.eof())
    //     break;
    //     wrong++;
    // }

    // while(!finalOutput.eof())
    // {
    //     finalOutput.get(in);
    //     if(finalOutput.eof())
    //     break;
    //     wrong++;
    // }
    
    //cout << "Wrong decoded characters: " << wrong <<endl;
    // Hunspell obj("D:/DNAproject/index.aff","D:/DNAproject/dectionary.dic");
    // vector<string> ans;
    // if(!obj.spell("helo"))
    // {
    //     ans = obj.suggest("helo");
    // }
    // cout << ans[0];
    // return 0;
}