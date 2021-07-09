#include<iostream>
#include<sstream>
using namespace std;
class Fraction
{
    int numerator,denominator;
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
    void setDenominator( int d){
        denominator=d;
    }
    void display(){
        int frac=1;
        for(int i=2;i<=denominator;i++){
            if(numerator%i==0&&denominator%i==0){
                frac=i;
            }
        }
        denominator=denominator/frac;
        numerator=numerator/frac;
        if(denominator==1){
            cout<<"("<<numerator<<")";
        }
        else{
            cout<<"("<<numerator<<"/"<<denominator<<")";
        }
    }
    Fraction operator +(const Fraction &a)const{
        Fraction temp;
        temp.setDenominator(this->denominator*a.denominator);
        temp.setNumerator(this->numerator*a.denominator+a.numerator*this->denominator);
        return temp;
    }
    Fraction operator -(const Fraction &a)const{
        Fraction temp;
        temp.setDenominator(this->denominator*a.denominator);
        temp.setNumerator(this->numerator*a.denominator-a.numerator*this->denominator);
        return temp;
    }
    Fraction operator *(const Fraction &a)const{
        Fraction temp;
        temp.setDenominator(this->denominator*a.denominator);
        temp.setNumerator(this->numerator*a.numerator);
        return temp;
    }
    Fraction operator /(const Fraction &a)const{
        Fraction temp;
        temp.setDenominator(this->denominator*a.numerator);
        temp.setNumerator(this->numerator*a.denominator);
        return temp;
    }
    Fraction &operator =(const Fraction &a){
        this->setNumerator(a.numerator);
        this->setDenominator(a.denominator);
        return *this;
    }
    friend ostream &operator <<(ostream &out,Fraction temp){
        int frac=1;
        for(int i=2;i<=temp.denominator;i++){
            if(temp.numerator%i==0&&temp.denominator%i==0){
                frac=i;
            }
        }
        temp.denominator=temp.denominator/frac;
        temp.numerator=temp.numerator/frac;
        if(temp.denominator==1){
            out<<"("<<temp.numerator<<")";
        }
        else{
            out<<"("<<temp.numerator<<"/"<<temp.denominator<<")";
        }
        return out;
    }
};
