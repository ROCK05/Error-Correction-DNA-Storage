#include <bits/stdc++.h>
#include "decodeLevel3.h"
using namespace std;
int main()
{
    setCodebook();
    cout << "Choose option given below \n 1.Run for one time \n 2.Multiple times for same error rate \n 3.For error rate from 0.01 to 0.05 \n Choice of option: ";
    int choice;
    cin >> choice;
    while(choice != 1 and choice != 2 and choice != 3)
    {
        cout << "Choose valid option: ";
        cin >> choice;
    }

    cout << "\n Running...\n";
    ifstream inputFile("Files/InputFile.txt");
    if(inputFile)
    {
        encoding(inputFile);
    }
    else //error
    {
        cout << "Error in opening Input file" << endl;
        exit(1);
    }
    inputFile.close();

    //Delete files if there any
    for(int i = 1; i <= 10; i++)
    {
        string temp = "Files/DecodedFile" + to_string(i) + ".txt";
        const char* path = temp.c_str();
        remove(path);
    }

    if(choice == 1)
    {
        ifstream encodedFile("Files/EncodedFile.txt");
        cout << "\nResults for error rate 0.02:\n";
        level2(encodedFile, 0.02,1);
        encodedFile.close();
    }
    else if(choice == 2)
    {
        for(int i = 1; i <= 10; i++)
        {
            ifstream encodedFile("Files/EncodedFile.txt");
            cout << "\nResult " << i<< ":\n";
            level2(encodedFile, 0.02,i);
            encodedFile.close();
        }
    }
    else
    {
        double errorRates[] = {0.01, 0.02, 0.03, 0.04, 0.05};
        for(int i = 1; i <= 5; i++)
        {
            ifstream encodedFile("Files/EncodedFile.txt");
            cout << "\nResults for error rate " << errorRates[i-1] << "\n";
            level2(encodedFile, errorRates[i-1], i);
            cout << "\n\n";
            encodedFile.close();
        }
    }

    // Level3 - Spelling correction
    // ifstream decodedFileLevel2("Files/DecodedFile1.txt");
    // cout << "\n\nRunning...\n";
    // level3(decodedFileLevel2);
    // decodedFileLevel2.close();
    exit(0);
}