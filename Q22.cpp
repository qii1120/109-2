#include<iostream>
using namespace std;
class Fraction
{
    int denominator,numerator;
    public:
    Fraction(){
        setNumerator(0);
        setDenominator(0);
    }
    Fraction(int n,int d){
        setNumerator(n);
        setDenominator(d);
    }
    int getNumerator(){
        return numerator;
    }
    int getDenominator(){
        return denominator;
    }
    void setNumerator(int n){
        numerator=n;
    }
    void setDenominator(int d){
        denominator=d;
    }
    void display(){
        int frac=1;
        for(int i=2;i<=denominator;i++){
            if(numerator%i==0&&denominator%i==0){
                frac=i;
            }
        }
        numerator=numerator/frac;
        denominator=denominator/frac;
        if(denominator==1){
            cout<<"("<<numerator<<")";
        }
        else{
            cout<<"("<<numerator<<"/"<<denominator<<")";
        }
    }
};
