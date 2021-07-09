#include<iostream>
using namespace std;
class Digit{
    int digit;
    public:
    Digit(){
        setDigit(0);
    }
    Digit(int d){
        setDigit(d);
    }
    void setDigit(int d){
        if(d>0&&d<10){
            digit=d;
        }
        else{
            digit=0;
        }
    }
    int getDigit(){
        return digit;
    }
};
