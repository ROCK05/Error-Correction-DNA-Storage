#include <bits/stdc++.h>
#include "D:\DNAproject\encode.h"
#include "D:\DNAproject\errorGenerator.h"
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
    error(encodedFile, 0.01);
    encodedFile.close();
    return 0;
}