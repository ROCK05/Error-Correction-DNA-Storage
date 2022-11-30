#include<bits/stdc++.h>
class record 
{
    public:
    int insError, subError, delError,totalError;

    record()
    {
        insError=0;
        subError=0;
        delError=0;
        totalError=0;
    }

    void print()
    {
        std::cout << "Insertion Errors: " << insError<< '\n';
        std::cout << "Deletion Errors: " << delError << '\n';
        std::cout << "Substitution Errors: " << subError << '\n';
        std::cout << "Total Errors: " << totalError << '\n';
    }
    record operator+(record obj)
    {
        record result;
        result.insError = insError + obj.insError;
        result.subError = subError + obj.subError;
        result.delError = delError + obj.delError;
        result.totalError = totalError + obj.totalError;
        return result;
    }

    void avg(int &numberOfReads)
    {
        this -> insError = this -> insError / numberOfReads;
        this -> delError = this -> delError / numberOfReads;
        this -> subError = this -> subError / numberOfReads;
        this -> totalError = insError + delError + subError;
    }
};