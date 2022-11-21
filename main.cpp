#include <bits/stdc++.h>
#include "D:\DNAproject\errorGenerator.h"
#include "D:\DNAproject\decode.h"
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
     error(encodedFile, 0.05);
     encodedFile.close();

    ifstream erroredFile("D:/DNAproject/ErroredFile.txt");
    decoding(erroredFile);
    erroredFile.close();
    return 0;
}